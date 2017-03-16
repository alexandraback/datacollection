import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Alexander Gulko
 */
public class ProblemB {
    @SuppressWarnings("FieldCanBeLocal")
    private static int caseNumber;
    private static Scanner scan;
    private Map<Character, List<Integer>> left;
    private Map<Character, List<Integer>> right;
    private Map<Character, List<Integer>> center;

    private static final long MOD = 1000000007L;

    void solve() {
        int n = scan.nextInt();

        long res = 0;

        left = new HashMap<Character, List<Integer>>();
        right = new HashMap<Character, List<Integer>>();
        center = new HashMap<Character, List<Integer>>();

        Set<Character> chars = new HashSet<Character>();

        Set<Character> visited = new HashSet<Character>();


        boolean ok = true;

        String[] ss = new String[n];
        for (int i = 0; i < n; ++i) {
            String s = scan.next("\\w+");

            StringBuilder t = new StringBuilder();
            t.append(s.charAt(0));

            for (int k = 1; k < s.length(); ++k) {
                if (s.charAt(k) != s.charAt(k - 1)) {
                    t.append(s.charAt(k));
                }
            }

            int len = t.length();

            visited.add(t.charAt(0));
            visited.add(t.charAt(len - 1));

            if (t.length() > 2) {
                for (int k = 1; k < t.length() - 1; ++k) {
                    if (visited.contains(t.charAt(k))) {
                        ok = false;
                    } else {
                        visited.add(t.charAt(k));
                    }
                }
            }

            /*if (t.length() > 2) {
                t.delete(1, t.length() - 1);
            }

            if (t.length() == 2 && t.charAt(0) == t.charAt(1)) {
                t.deleteCharAt(1);
            }*/

            if (t.charAt(0) != t.charAt(len - 1)) {
                addToGroup(left, t.charAt(0), i);
                addToGroup(right, t.charAt(len - 1), i);

                chars.add(t.charAt(0));
                chars.add(t.charAt(len - 1));
            } else {
                addToGroup(center, t.charAt(0), i);
                chars.add(t.charAt(0));
                if (t.length() > 1) {
                    ok = false;
                }
            }

            ss[i] = t.toString();
        }

//        System.out.println(Arrays.toString(ss));

        if (!ok) {
            System.out.printf("%s\n", 0);
            return;
        }

        for (Map.Entry<Character, List<Integer>> entry : left.entrySet()) {
            Collections.sort(entry.getValue());

            List<Integer> r = right.get(entry.getKey());
            if (entry.getValue().size() > 1 && r == null) {
                ok = false;
            }
        }
        for (Map.Entry<Character, List<Integer>> entry : right.entrySet()) {
            Collections.sort(entry.getValue());

            List<Integer> l = left.get(entry.getKey());
            if (entry.getValue().size() > 1 && l == null) {
                ok = false;
            }
        }

        if (!ok) {
            System.out.printf("%s\n", 0);
            return;
        }

        List<Group> groups = new ArrayList<Group>();

        for (char c : chars) {
            List<Integer> ll = left.get(c);
            List<Integer> rr = right.get(c);
            List<Integer> cc = center.get(c);

            if (ll != null && ll.size() > 1) {
                ok = false;
                break;
            }
            if (rr != null && rr.size() > 1) {
                ok = false;
                break;
            }

            if (rr != null && ll != null) {
                int i1 = find(groups, rr.get(0));
                int i2 = find(groups, ll.get(0));
                if (i1 != -1 && i1 == i2) {
                    ok = false;
                    break;
                }
            }

            // ll.size == 1 || 0
            // rr.size == 1 || 0
            long count = cc != null ? fact(cc.size()) : 1;

            Group group = new Group();
            group.count = count;
            addToGroup(group, ll);
            addToGroup(group, cc);
            addToGroup(group, rr);

            if (ll != null) {
                int ind = ll.get(0);
                int k = find(groups, ind);
                if (k != -1) {
                    Group other = groups.get(k);
                    group.count = (group.count * other.count) % MOD;
                    addToGroup(group, other.indexes);
                    groups.remove(k);
                }
            }

            if (rr != null) {
                int ind = rr.get(0);
                int k = find(groups, ind);
                if (k != -1) {
                    Group other = groups.get(k);
                    group.count = (group.count * other.count) % MOD;
                    addToGroup(group, other.indexes);
                    groups.remove(k);
                }
            }

            groups.add(group);
        }

        if (ok) {
            res = fact(groups.size());
            for (Group group : groups) {
                res = (res * group.count) % MOD;
            }
            res %= MOD;
        }

        System.out.printf("%s\n", ok ? res : 0);
    }

    void addToGroup(Group group, Collection<Integer> indexes) {
        if (indexes != null) {
            group.indexes.addAll(indexes);
        }
    }

    int find(List<Group> groups, int ind) {
        for (int i = 0; i < groups.size(); i++) {
            Group group = groups.get(i);
            if (group.indexes.contains(ind)) {
                return i;
            }
        }

        return -1;
    }

    static class Group {
        Set<Integer> indexes = new HashSet<Integer>();
        long count;
    }

    long fact(long n) {
        long r = 1;
        for (long i = 2; i <= n; ++i) {
            r *= i;
            r %= MOD;
        }

        return r;
    }

    void addToGroup(Map<Character, List<Integer>> groups, char c, Integer ind) {
        List<Integer> group = groups.get(c);
        if (group == null) {
            group = new ArrayList<Integer>();
            groups.put(c, group);
        }
        group.add(ind);
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test-b";
//        String file = "B-small-attempt0";
//        String file = "B-small-attempt1";
//        String file = "B-small-attempt2";
        String file = "B-small-attempt3";

        String inFile = file + ".in";

        redirectToFile(file);

        scan = new Scanner(new File(inFile));

        int cases = scan.nextInt();
        for (caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            System.out.printf("Case #%s: ", caseNumber);
            new ProblemB().solve();
            System.out.flush();
        }

        scan.close();
    }

    static void redirectToFile(String file) throws Exception {
        System.setOut(new PrintStream(file + ".out"));
    }
}
