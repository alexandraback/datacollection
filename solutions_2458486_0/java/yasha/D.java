import java.io.*;
import java.util.*;

public class D {

    private static final String PREFIIX = D.class.getName().toLowerCase();

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(PREFIIX + ".in")));
        PrintStream out = new PrintStream(new FileOutputStream(PREFIIX + ".out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String[] data = in.readLine().split(" ");
            String ans = "IMPOSSIBLE";
            int k = Integer.parseInt(data[0]);
            int n = Integer.parseInt(data[1]);
            List<Short> keys = new ArrayList<Short>();
            data = in.readLine().split(" ");
            for (String s : data) {
                keys.add(Short.parseShort(s));
            }
            short[] open = new short[n];
            List<Short>[] c = new List[n];
            for (int i = 0; i < n; i++) {
                c[i] = new ArrayList<Short>();
                data = in.readLine().split(" ");
                open[i] = Short.parseShort((data[0]));
                for (int j = 2; j < data.length; j++) {
                    c[i].add(Short.parseShort(data[j]));
                }
            }
            LinkedList<Integer> pass = new LinkedList<Integer>();
            if (p(keys, open, c, pass)) {
                ans = "";
                for (int v : pass) {
                    ans += (v + 1) + " ";
                }
                ans = ans.trim();
            }

            out.print("Case #" + (cas + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();
    }

    static boolean check(List<Short> keys, short[] open, List<Short>[] c, Set<Integer> done) {
        if (done.size() == c.length) {
            return true;
        }

        boolean ans = false;

        for (int i = 0; i < open.length; i++) {
            if (!done.contains(i)&& keys.contains(open[i])) {
                ans = true;
                keys.addAll(c[i]);
                done.add(i);
            }
        }

        return ans && check(keys, open, c, done);
    }

    static boolean p(List<Short> keys, short[] open, List<Short>[] c, LinkedList<Integer> pass) {
        if (pass.size() == c.length) {
            return true;
        }

//        int[] s = new int[401];
//        for (int key : keys) {
//            s[key]++;
//        }

        Set<Integer> done = new HashSet<Integer>();
        done.addAll(pass);
        List<Short> kc = new ArrayList<Short>();
        kc.addAll(keys);
        if (!check(kc, open, c, done)) {
            return false;
        }

        kc.clear();
        kc.addAll(keys);

        if (!f(kc, open, c, pass)) {
            return false;
        }


        for (int i = 0; i < open.length; i++) {
            if (keys.contains(open[i]) && (!pass.contains(i))) {
                List<Short> k2 = new ArrayList<Short>();
                k2.addAll(keys);
                int ind = k2.indexOf(open[i]);
                k2.remove(ind);
                k2.addAll(c[i]);
                pass.add(i);
                if (p(k2, open, c, pass)) {
                    return true;
                } else {
                    pass.removeLast();
                }
            }
        }
        return false;
    }


    static boolean f(List<Short> keys, final short[] open, final List<Short>[] c, LinkedList<Integer> pass) {
        if (pass.size() == c.length) {
            return true;
        }

        List<Integer> tests = new ArrayList<Integer>();

        for (int i = 0; i < open.length; i++) {
            if (keys.contains(open[i]) && (!pass.contains(i))) {
                tests.add(i);
            }
        }

        for (int i : tests) {
            if (c[i].contains(open[i])) {
                return go(keys, open, c, pass, i);
            }
        }

        Map<Short, Integer> avail = new HashMap<Short, Integer>();
        for (Short key : keys) {
            int cur = avail.containsKey(key) ? avail.get(key) : 0;
            avail.put(key, cur + 1);
        }


        Map<Short, Integer> req = new HashMap<Short, Integer>();
        for (int i = 0; i < open.length; i++) {
            if (!pass.contains(i)) {
                int cur = req.containsKey(open[i]) ? req.get(open[i]) : 0;
                req.put(open[i], cur + 1);
            }
        }

        for (Short key : keys) {
            if (avail.containsKey(key) && req.containsKey(key)) {
                if (avail.get(key) >= req.get(key)) {
                    for (int i : tests) {
                        if (key == open[i]) {
                            return go(keys, open, c, pass, i);
                        }
                    }
                }
            }
        }



        List<Integer> remove = new ArrayList<Integer>();

        for (int t1 : tests) {
            if(remove.contains(t1)) {
                continue;
            }
            for (int t2 : tests) {
                if(remove.contains(t2)) {
                    continue;
                }
                if (t1 != t2) {
                    if (open[t1] == open[t2]) {
                        if (c[t1].containsAll(c[t2])) {
                            remove.add(t2);
                        }
                    }
                }
            }
        }
        for (int i : tests) {
            if (go(keys, open, c, pass, i)) {
                return true;
            }
        }

        return false;
    }

    private static boolean go(List<Short> keys, short[] open, List<Short>[] c, LinkedList<Integer> pass, int i) {
        List<Short> k2 = new ArrayList<Short>();
        k2.addAll(keys);
        int ind = k2.indexOf(open[i]);
        k2.remove(ind);
        k2.addAll(c[i]);
        pass.add(i);
        if (f(k2, open, c, pass)) {
            pass.removeLast();
            return true;
        } else {
            pass.removeLast();
        }
        return false;
    }


    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
