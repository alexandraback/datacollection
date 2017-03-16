import java.io.*;
import java.util.*;

/**
 * @author Kazuki Nishiura
 */
public class Consonants {

    // debug flags
    private static final boolean debug = true;

    public static void main(String[] args) {
        PrintWriter writer = createWriter("A1-large");
        Scanner scanner = createScanner("A-large.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int testCaseNo = 1; testCaseNo <= numOfTestCase; testCaseNo++) {
            String[] tokens = scanner.nextLine().split(" ");
            NCalculator nCalculator = new NCalculator(tokens[0], Integer.parseInt(tokens[1]));
            writer.print("Case #" + testCaseNo + ": " + nCalculator.calc());
            writer.println();
        }
        writer.close();
    }

    static class NCalculator {
        int n;
        String name;

        public NCalculator(String name, int n) {
            this.n = n;
            this.name = name;
        }

        public int calc() {
            List<Integer> startNConsonants = new ArrayList<Integer>();
            int continus = 0;
            for (int i = 0; i < name.length(); i++) {
                char ch = name.charAt(i);
                if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o') {
                    continus = 0;
                } else {
                    continus++;
                    if (continus >= n) {
                        startNConsonants.add(i - n + 1);
                    }
                }
            }

            int num = 0;
            int smallestStartIndex = 0;
            if (startNConsonants.size() == 0) {
                return 0;
            }

            int smallestStart = startNConsonants.get(smallestStartIndex);
            for (int start = 0; start <= name.length() - n; start++) {
                if (smallestStart < start) {
                    smallestStartIndex++;
                    if (startNConsonants.size() == smallestStartIndex) {
                        break;
                    }
                    smallestStart = startNConsonants.get(smallestStartIndex);
                }
                for (int end = name.length() - 1; end >= start + n - 1 ;end--) {
                    if (end < smallestStart + n - 1) {
                        break;
                    }
                    num++;
                }
            }
            return num;
        }
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