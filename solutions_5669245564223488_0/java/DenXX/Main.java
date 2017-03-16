//package denxx;

import java.util.*;

public class Main {

    static final long MOD = 1000000007L;

    static boolean joined;

    static boolean dfs(String[] s, int cur, int[] color) {
        int n = s.length;
        color[cur] = 1;
        for (int i = 0; i < n; ++i) {
            if (s[cur].charAt(s[cur].length() - 1) == s[i].charAt(0) && (cur != i || s[cur].length() > 1)) {
                if (color[i] == 1) {
                    return false;
                } else if (color[i] == 0) {
                    if (!dfs(s, i, color))
                        return false;
                } else {
                    joined = true;
                }
            }
        }
        color[cur] = 2;
        return true;
    }

    static String[] simplify(String[] trains) {
        String[] res = new String[trains.length];
        for (int i = 0; i < trains.length; ++i) {
            StringBuilder s = new StringBuilder();
            s.append(trains[i].charAt(0));
            for (int j = 1; j < trains[i].length(); ++j) {
                if (trains[i].charAt(j) != trains[i].charAt(j - 1)) {
                    s.append(trains[i].charAt(j));
                }
            }
            res[i] = s.toString();
        }
        return res;
    }

    static boolean check(String[] t) {
        for (int i = 0; i < 27; ++i) {
            int seen = 0;
            boolean head = false;
            boolean tail = false;
            for (int j = 0; j < t.length; ++j) {
                for (int k = 0; k < t[j].length(); ++k) {
                    if (t[j].charAt(k) == ('a' + i)) {
                        if (seen > 1) {
                            return false;
                        } else if (seen == 1) {
                            if (k == 0) {
                                if (!tail) {
                                    return false;
                                }
                                head = true;
                            } else if (k == t[j].length() - 1) {
                                if (!head) {
                                    return false;
                                }
                                tail = true;
                            } else {
                                return false;
                            }
                            if (t[j].length() != 1)
                                ++seen;
                        } else {
                            if (t[j].length() != 1) {
                                seen = 1;
                            }
                            if (head && tail && k != 0 && k != t[j].length() - 1)
                                return false;
                            head = head || k == 0;
                            tail = tail || k == t[j].length() - 1;
                        }
                    }
                }
            }
        }
        return true;
    }

    static Map<Long, Long> mem = new HashMap<Long, Long>();
    static long fact(long a) {
        if (mem.containsKey(a)) {
           return mem.get(a);
        }
        long res = 1;
        for (int i = 2; i <= a; ++i) {
            res = (res * i) % MOD;
        }
        mem.put(a, res);
        return res;
    }

    public static void main(String[] args) {
	    Scanner stdin = new Scanner(System.in);
        int T = stdin.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = stdin.nextInt();
            String[] trains = new String[n];
            for (int i = 0; i < n; ++i) {
                trains[i] = stdin.next();
            }
            long res = 1;
            trains = simplify(trains);
            Arrays.sort(trains);
            List<String> newTrains = new ArrayList<String>();
            newTrains.add(trains[0]);
            int skipped = 0;
            for (int i = 1; i < n; ++i) {
                if (trains[i].length() != 1 || !trains[i].equals(trains[i-1])) {
                    res = (res * fact(skipped + 1)) % MOD;
                    newTrains.add(trains[i]);
                    skipped = 0;
                } else {
                    ++skipped;
                }
            }
            res = (res * fact(skipped + 1)) % MOD;
            n = newTrains.size();
            trains = newTrains.toArray(new String[newTrains.size()]);

            boolean fail = !check(trains);

            if (!fail) {
                int[] color = new int[n];
                int count = 0;
                for (int i = 0; i < n && !fail; ++i) {
                    if (color[i] == 0) {
                        joined = false;
                        fail = fail || !dfs(trains, i, color);
                        if (!joined)
                            ++count;
                    }
                }
                res = (res * fact(count)) % MOD;
            }

            if (fail) {
                System.out.println("Case #" + t + ": 0");
            } else {
                System.out.println("Case #" + t + ": " + res);
            }
        }
    }
}
