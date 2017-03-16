import java.io.*;
import java.util.*;

/**
 * @author Kazuki Nishiura
 */
public class PogoSmall {

    // debug flags
    private static final boolean debug = true;

    public static void main(String[] args) {
        PrintWriter writer = createWriter("Bsmall");
        Scanner scanner = createScanner("B-small-attempt0.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int testCaseNo = 1; testCaseNo <= numOfTestCase; testCaseNo++) {
            writer.print("Case #" + testCaseNo + ": " + solve(scanner.nextInt(), scanner.nextInt()));
            writer.println();
        }
        writer.close();
    }

    private static String solve(int x, int y) {
        StringBuilder builder = new StringBuilder();
        if (x > 0) {
            for (int i = 0; i < x; i++) {
                builder.append("WE");
            }
        } else {
            int negX = -x;
            for (int i = 0; i < negX; i++) {
                builder.append("EW");
            }
        }

        if (y > 0) {
            for (int i = 0; i < y; i++) {
                builder.append("SN");
            }
        } else {
            int negY = -y;
            for (int i = 0; i < negY; i++) {
                builder.append("NS");
            }
        }

        return builder.toString();
    }

    // Collections utils
    static class SetMultiMap<K, V> extends TreeMap<K, Set<V>> {
        public void add(K key, V value) {
            if (containsKey(key)) {
                get(key).add(value);
            } else {
                Set<V> set = new HashSet<V>();
                set.add(value);
                put(key, set);
            }
        }
    }

    static class ListMultiMap<K, V> extends TreeMap<K, List<V>> {
        public void add(K key, V value) {
            if (containsKey(key)) {
                get(key).add(value);
            } else {
                List<V> list = new ArrayList<V>();
                list.add(value);
                put(key, list);
            }
        }
    }

    static class Counter<K> extends HashMap<K, Integer> {
        public void addCount(K key) {
            if (containsKey(key)) {
                int currentCount = get(key);
                put(key, currentCount + 1);
            } else {
                put(key, 1);
            }
        }
    }

    static private void debugOut(Object o) {
        if (debug) {
            System.out.println(o);
        }
    }

    // IO Utils
    static private PrintWriter createWriter() {
        return createWriter(null);
    }

    static private PrintWriter createWriter(String fileNameSuffix) {
        if (fileNameSuffix == null) {
            return new PrintWriter(System.out);
        } else {
            try {
                return new PrintWriter(new BufferedWriter((new FileWriter(
                        new File("output_" + fileNameSuffix + ".txt")))));
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
        }
    }

    static private Scanner createScanner() {
        return createScanner(null);
    }

    static private Scanner createScanner(String fileName) {
        if (fileName == null) {
            return new Scanner(System.in);
        } else {
            File inFile = new File(fileName);
            try {
                return new Scanner(inFile);
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
        }
    }
}
