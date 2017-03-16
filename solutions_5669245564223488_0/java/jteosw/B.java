import java.util.*;
public class B {
    static Scanner s;
    static long mod = 1000000007;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %d\n", i, solve());
        }
    }

    public static long solve() {
        int n = s.nextInt();
        Map<Character, Integer> one = new HashMap<>();
        Map<Character, String> moreLeft = new HashMap<>();
        Map<Character, String> moreRight = new HashMap<>();
        Set<String> more = new HashSet<>();
        Map<String, Set<Character>> lookup = new HashMap<>();
        Set<Character> chars = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String next = s.next();
            Set<Character> set = new HashSet<>();
            char prev = ' ';
            for (int j = 0; j < next.length(); j++) {
                char c = next.charAt(j);
                if (prev != c && set.contains(c)) {
                    s.nextLine();
                    return 0;
                } else {
                    set.add(c);
                    prev = c;
                }
            }
            if (set.size() == 1) {
                char c = next.charAt(0);
                if (!one.containsKey(c)) {
                    one.put(c, 1);
                } else {
                    one.put(c, one.get(c) + 1);
                }
            } else {
                if (set.size() > 2) {
                    for (Character c : set) {
                        if (c == next.charAt(0) || c == next.charAt(next.length() - 1)) {
                            continue;
                        }
                        if (chars.contains(c)) {
                            s.nextLine();
                            return 0;
                        }
                    }
                }
                char c1 = next.charAt(0);
                char c2 = next.charAt(next.length() - 1);
                if (moreLeft.containsKey(c1) || moreRight.containsKey(c2)) {
                    s.nextLine();
                    return 0;
                } else {
                    moreLeft.put(c1, next);
                    moreRight.put(c2, next);
                    more.add(next);
                }
                lookup.put(next, set);
            }
            chars.addAll(set);
        }

        for (String st : more) {
            for (Character c : lookup.get(st)) {
                if (one.containsKey(c) && c != st.charAt(0) && c != st.charAt(st.length() - 1)) {
                    return 0;
                }
            }
        }

        long count = 1;
        for (Character c : one.keySet()) {
            count = (count * fact(one.get(c))) % mod;
        }
        // Append them
        boolean change = true;
        Set<Character> removeOne = new HashSet<>();
        while (change) {
            change = false;
            Set<String> remove = new HashSet<>();
            Map<String, Set<Character>> add = new HashMap<>();
            for (Character c : moreLeft.keySet()) {
                if (moreRight.containsKey(c)) {
                    String right = moreLeft.get(c);
                    String left = moreRight.get(c);
                    if (remove.contains(left) || remove.contains(right)) {
                        continue;
                    }
                    Set<Character> leftSet = lookup.get(left);
                    for (Character cc : lookup.get(right)) {
                        if (leftSet.contains(cc) && cc != c) {
                            return 0;
                        }
                        if (one.containsKey(cc) && cc != c && cc != right.charAt(right.length() - 1)) {
                            return 0;
                        }
                    }
                    for (Character cc : leftSet) {
                        if (one.containsKey(cc) && cc != c && cc != left.charAt(0)) {
                            return 0;
                        }
                    }
                    // Safe to append
                    if (one.containsKey(c)) {
                        removeOne.add(c);
                    }
                    remove.add(right);
                    remove.add(left);
                    Set<Character> tmp = new HashSet<>(lookup.get(left));
                    tmp.addAll(lookup.get(right));
                    add.put(left + right, tmp);
                    change = true;
                }
            }
            for (String st : remove) {
                moreLeft.remove(st.charAt(0));
                moreRight.remove(st.charAt(st.length() - 1));
            }
            for (String st : add.keySet()) {
                moreLeft.put(st.charAt(0), st);
                moreRight.put(st.charAt(st.length() - 1), st);
                lookup.put(st, add.get(st));
            }
        }
        for (Character c : removeOne) {
            one.remove(c);
        }
        for (Character c : moreLeft.keySet()) {
            if (one.containsKey(c)) {
                one.remove(c);
            }
        }
        for (Character c : moreRight.keySet()) {
            if (one.containsKey(c)) {
                one.remove(c);
            }
        }
        count = (count * fact(moreLeft.size() + one.size())) % mod;
        return (int) count;
    }

    public static long fact(int a) {
        long count = 1;
        for (int i = 1; i <= a; i++) {
            count = (count * i) % mod;
        }
        return count;
    }
}
