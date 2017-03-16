package round1b;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class C {
    private static Trie dict;
//    private static List<String> words = new ArrayList<String>();


    public static void main(String[] args) throws IOException {
        Kattio io;

//		io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("src/round1b/C-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1b/C-small-attempt0.in"), new FileOutputStream("src/round1b/C-small-0.out"));
		io = new Kattio(new FileInputStream("src/round1b/C-large.in"), new FileOutputStream("src/round1b/C-large.out"));

        loadDictionary();

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new C().solve(io);
        }
        io.close();
    }

    public static void loadDictionary() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("src/round1b/garbled_email_dictionary.txt")));
        String s;
        int nodes = 0;
        dict = new Trie();
        while ((s = reader.readLine()) != null) {
//            words.add(s);
            Trie current = dict;
            for (int i = 0; i < s.length(); i++) {
                int x = s.charAt(i) - 'a';
                if (current.children[x] == null) {
                    nodes++;
                    current.children[x] = new Trie();
                    current.children[x].index = nodes;
                }
                current = current.children[x];
            }
            current.endWord = true;
        }
        reader.close();

    }

    private static class Trie {
        public char c;
        public boolean endWord;
        public Trie[] children = new Trie[26];
        public int index = 0;
    }

    private String word;

	private void solve(Kattio io) {
        this.word = io.getWord();

        /*this.word = "";
        Random random = new Random(1);
        while (this.word.length() < 4000) {
            this.word += words.get(random.nextInt(words.size()));
        }
        char[] chars = this.word.toCharArray();

        for (int i = 0; i < 4000; i++) {
            if (random.nextDouble() < 0.3) {
                chars[i] = (char) (random.nextInt(26) + 'a');
                i += 4;
            }
        }

        this.word = new String(chars);*/


        memo = new HashMap<Long, Integer>();
        int min = go(0, dict, 0);
        io.println(min);
//        System.out.println("state size: " + memo.size());
    }

    private Map<Long, Integer> memo;

    private int go(int pos, Trie triePos, int lastChange) {
        if (pos == word.length()) {
            return triePos.endWord ? 0 : Integer.MAX_VALUE;
        }
        long state = (triePos.index * 5L + lastChange) * (long) (word.length() + 1) + pos;
        if (memo.containsKey(state)) return memo.get(state);

        int best = Integer.MAX_VALUE;
        if (triePos.endWord) {
            best = go(pos, dict, lastChange);
        }

        for (int i = 0; i < 26; i++) {
            boolean same = word.charAt(pos) - 'a' == i;
            if (!same && lastChange > 0) continue;
            if (triePos.children[i] != null) {
                int c = go(pos+1, triePos.children[i], same ? Math.max(0, lastChange - 1) : 4);
                if (c < Integer.MAX_VALUE && !same) c++;
                best = Math.min(best, c);
            }
        }

        memo.put(state, best);

        return best;
    }
}
