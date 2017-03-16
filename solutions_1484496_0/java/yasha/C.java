import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("c.in")));
        PrintStream out = new PrintStream(new FileOutputStream("c.out"));
        long n = readInt(in);
        for (int cas = 0; cas < n; cas++) {
            String[] s1 = in.readLine().trim().split(" ");
            out.println("Case #" + (cas + 1) + ":");
            Map<Integer, List<Integer>> m = new HashMap<Integer, List<Integer>>();
            List<Integer> list = new ArrayList<Integer>();
            list.add(0);
            m.put(0, list);
            for (int i = 1; i < s1.length - 1; i++) {
                int k = Integer.parseInt(s1[i]);
                Map<Integer, List<Integer>> m2 = new HashMap<Integer, List<Integer>>();
                for (Map.Entry<Integer, List<Integer>> entry : m.entrySet()) {
                    int v = entry.getKey() + k;
                    list = m2.get(v);
                    if (list == null) {
                        list = new ArrayList<Integer>();
                    }

                    for (int set : entry.getValue()) {
                        list.add(set + (1 << (i - 1)));
                    }
                    m2.put(v, list);
                }
                for (Map.Entry<Integer, List<Integer>> add : m2.entrySet()) {
                    list = m.get(add.getKey());
                    if (list == null) {
                        list = add.getValue();
                    } else {
                        list.addAll(add.getValue());
                    }
                    m.put(add.getKey(), list);
                }
            }

            String ans = null;

            for (List<Integer> a : m.values()) {
                if (a.size() < 2) {
                    continue;
                }
                for (int i = 0; i < a.size(); i++) {
                    int u = a.get(i);
                    for (int j = 0; j < a.size(); j++) {
                        int v = a.get(j);
                        if ((u & v) == 0) {
                            ans = getSet(s1, u) + getSet(s1, v); 
                        }
                    }
                    if (ans != null) {
                        break;
                    }
                    
                }
                if (ans != null) {
                    break;
                }

            }
            
            if (ans == null) {
                ans = "Impossible\n";
            }
            out.print(ans);

        }
        out.flush();
        out.close();

    }

    static String getSet(String[] s, int v) {
        String ans = "";
        for (int i = 1; i < s.length; i++) {
            if ((v & (1<<(i -1))) > 0) {
                ans += s[i] + " ";
            }
        }

        ans = ans.trim();
        ans +="\n";
        return ans;
    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }    
}
