package mp.kotter.challenges.gcj.qualification;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import mp.kotter.challenges.gcj.qualification.GarbledEmail.Index.FindResult;
import mp.kotter.challenges.utils.LineCaseSolution;

import org.apache.commons.io.IOUtils;

public class GarbledEmail extends LineCaseSolution {
    public static final int MIN_DISTANCE = 5;

    public static void main(final String[] args) throws Exception {
        (new GarbledEmail()).run(args);
    }

    private static final Index INDEX = new Index("C:\\Users\\tykhansk\\Downloads\\garbled_email_dictionary.txt");

    @Override
    protected String solveLine(final String line) {
        return "" + findMin(line);
    }

    private int findMin(final String line) {
        final Map<String, Integer> cache = new HashMap<String, Integer>();
        cache.put(getCacheKey(0, 0), 0);
        for(int offset = 0; offset < line.length(); offset ++) {
            for(int toChange = 0; toChange <= MIN_DISTANCE; toChange++) {
                expand(line, offset, toChange, cache);
            }
        }
        int minChange = Integer.MAX_VALUE;
        for(int toChange = 0; toChange <= MIN_DISTANCE; toChange++) {
            final Integer min = cache.get(getCacheKey(line.length(), toChange));
            if (min != null && min < minChange) {
                minChange = min;
            }
        }
        return minChange;
    }

    private void expand(final String line, final int offset, final int toChange, final Map<String, Integer> cache) {
        final String cacheKey = getCacheKey(offset, toChange);
        final Integer currentValue = cache.get(cacheKey);

        if (currentValue == null) {
            return;
        }

        final List<FindResult> results = INDEX.findAll(line, offset, toChange);

        for(final FindResult result : results) {
            final String nextKey = getCacheKey(offset + result.word.length(), result.toChange);
            final Integer oldValue = cache.get(nextKey);
            if (oldValue == null || oldValue > result.changes + currentValue) {
                cache.put(nextKey, result.changes + currentValue);
            }
        }
    }

    private String getCacheKey(final int offset, final int toChange) {
        return "" + offset + "#" + toChange;
    }

    static class Index {
        private final IndexNode root = new IndexNode();

        public Index(final String filename) {
            try {
                final InputStream stream = new FileInputStream(filename);
                for(final Object line : IOUtils.readLines(stream)) {
                    addToIndex(line.toString());
                }
                IOUtils.closeQuietly(stream);
            } catch (final IOException e) {
                throw new RuntimeException("IO error", e);
            }
        }

        private void addToIndex(final String string) {
            IndexNode node = this.root;
            for(int i=0; i<string.length(); i++) {
                final char ch = string.charAt(i);
                node = node.getOrCreate(ch);
            }
            node.word = string;
        }

        public List<FindResult> findAll(final String str, final int offset, final int toChange) {
            final List<IndexNodeSearch> nodes = Collections.singletonList(new IndexNodeSearch(this.root, toChange, 0));
            final List<FindResult> result = new ArrayList<FindResult>();

            find(str, offset, nodes, result);

            return result;
        }

        private void find(final String str, final int offset, final List<IndexNodeSearch> nodes, final List<FindResult> result) {
            if (nodes.isEmpty()) {
                return;
            }

            for(final IndexNodeSearch node : nodes) {
                if (node.node.word != null) {
                    result.add(new FindResult(node.node.word, node.toChange, node.changes));
                }
            }

            if (offset >= str.length()) {
                return;
            }

            final char ch = str.charAt(offset);

            final List<IndexNodeSearch> nextNodes = new ArrayList<IndexNodeSearch>();

            for(final IndexNodeSearch node : nodes) {
                if (node.node.word != null) {
                    result.add(new FindResult(node.node.word, node.toChange, node.changes));
                }

                if (node.toChange == 0) {
                    for(final Map.Entry<Character, IndexNode> next : node.node.nextNodes()) {
                        if (next.getKey() != ch) {
                            nextNodes.add(new IndexNodeSearch(next.getValue(), MIN_DISTANCE, node.changes + 1));
                        }
                    }
                }

                final IndexNode rightNode = node.node.get(ch);
                if (rightNode != null) {
                    nextNodes.add(new IndexNodeSearch(rightNode, Math.max(0, node.toChange - 1), node.changes));
                }
            }

            find(str, offset + 1, nextNodes, result);
        }

        static class IndexNode {
            private final Map<Character, IndexNode> links = new HashMap<Character, IndexNode>();
            public String word = null;

            public IndexNode getOrCreate(final char ch) {
                IndexNode result = this.links.get(ch);
                if (result != null) {
                    return result;
                }
                result = new IndexNode();
                this.links.put(ch, result);

                return result;
            }

            public IndexNode get(final char ch) {
                return this.links.get(ch);
            }

            public Iterable<Map.Entry<Character, IndexNode>> nextNodes() {
                return this.links.entrySet();
            }
        }

        static class IndexNodeSearch {
            public IndexNode node;
            public int toChange;
            public int changes;

            public IndexNodeSearch(final IndexNode node, final int toChange, final int changes) {
                this.node = node;
                this.toChange = toChange;
                this.changes = changes;
            }
        }

        public static class FindResult {
            public String word;
            public int toChange;
            public int changes;

            public FindResult(final String word, final int toChange, final int changes) {
                this.word = word;
                this.toChange = toChange;
                this.changes = changes;
            }

            @Override
            public String toString() {
                return this.word + "[" + this.toChange + "," + this.changes + "]";
            }
        }
    }
}
