package round1c_2016;

        import java.io.*;
        import java.util.*;

public class SolutionB {

    private final static String FILENAME = "B-small-attempt6.in";
    private final static String PATH = System.getProperty("user.home") + "/codejam/" + FILENAME;

    public static void main(String[] args) throws IOException {
        new SolutionB()
                .initInputReader()
                .solveAllTestCases()
                .cleanup();
    }

    private SolutionB solveAllTestCases() throws IOException {
        int testCases = nextInt();

        for (int testCase = 0; testCase < testCases; testCase++) {
            StringBuilder sb = new StringBuilder();
            sb.append("Case #")
                    .append(testCase + 1)
                    .append(": ");

            solveTestCase(sb);

            sb.append("\n");
            System.out.print(sb.toString());
            out.write(sb.toString());
        }

        return this;
    }

    private void solveTestCase(StringBuilder sb) throws IOException {
        int b = nextInt(), m = nextInt();
        int[][] arr = new int[b][b];

        List<List<Integer>> lists = dfs(0, b - 1);
        if (lists.size() < m) {
            sb.append("IMPOSSIBLE");
            return;
        }

        Collections.sort(lists, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
//                for (int i = 0; i < Math.min(o1.size(), o2.size()); i++) {
//                    int a = o1.get(i);
//                    int b = o2.get(i);
//
//                    if (a == b)
//                        continue;
//
//                    if (a < b) {
//                        return -1;
//                    } else if (a > b) {
//                        return 1;
//                    }
//                }


                if (o1.size() < o2.size())
                    return -1;
                else if (o1.size() > o2.size())
                    return 1;

                for (int i = 0; i < o1.size(); i++) {
                    int a = o1.get(i);
                    int b = o2.get(i);

                    if (a == b)
                        continue;

                    if (a < b) {
                        return -1;
                    } else if (a > b) {
                        return 0;
                    }
                }

                return 0;
            }
        });
//        for (List<Integer> list : lists) {
//            System.out.println(list);
//        }

        for (int i = 0; i < lists.size(); i++) {
            if (i < m) {
                List<Integer> list = lists.get(i);

                for (int j = 0; j < list.size() - 1; j++) {
                    int dest = list.get(j);
                    int src = list.get(j + 1);

                    arr[src][dest] = 1;
                }
            } else {
                boolean valid = true;

                List<Integer> list = lists.get(i);

                for (int j = 0; j < list.size() - 1; j++) {
                    int dest = list.get(j);
                    int src = list.get(j + 1);

                    if (arr[src][dest] == 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
//                    for (List<Integer> list1: lists) { System.out.println(list1); }
//                    System.out.println(i + " " + m);
                    sb.append("IMPOSSIBLE");
                    return;
                }
            }
        }

        sb.append("POSSIBLE");
        for (int[] line : arr) {
            sb.append('\n');
            for (int i : line) {
                sb.append(i);
            }
        }
    }

    private List<List<Integer>> dfs(int cur, int target) {
        if (cur == target) {
            List<List<Integer>> listOfLists = new ArrayList<>();
            List<Integer> list = new ArrayList<>();
            list.add(target);
            listOfLists.add(list);
            return listOfLists;
        }

        List<List<Integer>> ret = new ArrayList<>();
        for (int i = cur + 1; i <= target; i++) {
            ret.addAll(dfs(i, target));
        }

        for (List<Integer> list : ret) {
            list.add(cur);
        }

        return ret;
    }

    private final static int MOD = 1000000007;

    /*
     * Methods for reading input
     */

    private BufferedReader br;
    private StringTokenizer st;
    private FileWriter out;

    private SolutionB initInputReader() throws IOException {
        br = new BufferedReader(new FileReader(
                new File(PATH)));
        out = new FileWriter(PATH + ".solution");
        st = new StringTokenizer(br.readLine());
        return this;
    }

    private void cleanup() throws IOException {
        br.close();
        out.flush();
        out.close();
    }

    private int nextInt() throws IOException {
        checkEmptyTokenizer();
        return Integer.parseInt(st.nextToken());
    }

    private long nextLong() throws IOException {
        checkEmptyTokenizer();
        return Long.parseLong(st.nextToken());
    }

    private double nextDouble() throws IOException {
        checkEmptyTokenizer();
        return Double.parseDouble(st.nextToken());
    }

    private String nextString() throws IOException {
        checkEmptyTokenizer();
        return st.nextToken();
    }

    private void checkEmptyTokenizer() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
    }

    /*
     * Convenience methods
     */

    // Provides a default value if map doesn't have the key
    private <K, V> V getFromMap(Map<K, V> map, K key, V def) {
        if (map.containsKey(key)) {
            return map.get(key);
        } else {
            map.put(key, def);
        }
        return def;
    }

    private void print(String line, Object... args) {
        System.out.println(String.format(line, args));
    }
}
