package codejam.s2014.r1c.source;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

class Csmall0 {
    public static void main(String[] args) throws IOException {
        int t = Parser.nextInt();
        for (int tt = 1; tt <= t; tt++) {
            System.out.println("Case #" + tt + ": " + solve());
        }
    }

    private static String solve() throws IOException {
        int n = Parser.nextInt();
        int m = Parser.nextInt();
        int k = Parser.nextInt();
        int N = n * m;
        int res = N;
        for (int mask = 0; mask < (1 << N); mask++) {
            int ok[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                Arrays.fill(ok[i], 0);
            }
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    int pos = row * m + col;
                    if (((mask >> pos) & 1) > 0) {
                        ok[row][col] = 1;
                    }
                }
            }
            for (int row = 0; row < n; row++) {
                int f = findFirst(ok[row], 1);
                int l = findLast(ok[row], 1);
                if (f != -1) {
                    for (int i = f; i < l + 1; i++) {
                        if (ok[row][i] == 0) {
                            ok[row][i] = 2;
                        }
                    }
                }
            }
            for (int col = 0; col < m; col++) {
                int f = -1;
                int l = -1;
                for (int row = 0; row < n; row++) {
                    if (ok[row][col] == 1) {
                        f = row;
                        break;
                    }
                }
                for (int row = n - 1; row >= 0; row--) {
                    if (ok[row][col] == 1) {
                        l = row;
                        break;
                    }
                }
                if (f != -1) {
                    for (int i = f; i < l + 1; i++) {
                        if (ok[i][col] == 2) {
                            ok[i][col] = 3;
                        }
                    }
                }
            }
            int count = 0;
            int count1 = 0;
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    if (ok[row][col] == 1) {
                        count += 1;
                        count1 += 1;
                    } else if (ok[row][col] == 3) {
                        count += 1;
                    }
                }
            }
            if (count >= k) {
//                if (count1 < res) {
//                    System.out.println(Arrays.deepToString(ok));
//                }
                res = Math.min(res, count1);
            }
        }
        return String.valueOf(res);
    }

    private static int findFirst(int[] array, int k) {
        for (int col = 0; col < array.length; col++) {
            if (array[col] == k) {
                return col;
            }
        }
        return -1;
    }

    private static int findLast(int[] array, int k) {
        for (int col = array.length - 1; col >= 0; col--) {
            if (array[col] == k) {
                return col;
            }
        }
        return -1;
    }

    private static int perm(int i, String[] cars, ArrayList<Integer> pi) {
        if (i == cars.length) {
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < pi.size(); j++) {
                s.append(cars[pi.get(j)]);
            }
            if (valid(s.toString())) {
                return 1;
            } else {
                return 0;
            }
        } else {
            int res = 0;
            for (int j = 0; j < cars.length; j++) {
                if (!pi.contains(j)) {
                    pi.add(j);
                    res += perm(i + 1, cars, pi);
                    pi.remove(pi.size() - 1);
                    res %= 1000000007;
                }
            }
            return res;
        }
    }

    private static boolean valid(String s) {
        HashMap<Character, Integer> lastVisited = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            Integer lv = lastVisited.get(c);
            if (lv != null && lv < i - 1) {
                return false;
            }
            lastVisited.put(c, i);
        }
        return true;
    }

    private static class Parser {
        private static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        private static String line;
        private static ArrayList<String> stringArray = new ArrayList<String>();
        private static int arrayPosition = 0;

        private static Integer nextInt() throws IOException {
            if (arrayPosition == stringArray.size()) {
                if (readLine() == null) return null;
            }
            return Integer.parseInt(stringArray.get(arrayPosition++));
        }

        private static Long nextLong() throws IOException {
            if (arrayPosition == stringArray.size()) {
                if (readLine() == null) return null;
            }
            return Long.parseLong(stringArray.get(arrayPosition++));
        }

        private static String nextString() throws IOException {
            if (arrayPosition == stringArray.size()) {
                if (readLine() == null) return null;
            }
            return stringArray.get(arrayPosition++);
        }

        private static String nextLine() throws IOException {
            arrayPosition = stringArray.size();
            return in.readLine();
        }

        private static String readLine() throws IOException {
            line = in.readLine();
            if (line == null) {
                return null;
            } else {
                stringArray = new ArrayList<String>();
                arrayPosition = 0;

                int p, lastP = 0;
                while (true) {
                    p = line.indexOf(" ", lastP);
                    if (p == lastP) {
                        lastP++;
                    } else if (p != -1) {
                        stringArray.add(line.substring(lastP, p));
                        lastP = p + 1;
                    } else {
                        if (lastP < line.length()) {
                            stringArray.add(line.substring(lastP));
                        }
                        break;
                    }
                }
                return line;
            }
        }
    }

}
