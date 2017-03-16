import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class B {

    private static  List<long[]> boxes = new ArrayList<long[]>();
    private static  List<long[]> toys = new ArrayList<long[]>();

    static HashMap<String, Long> c = new HashMap<String, Long>();
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
        PrintStream out = new PrintStream(new FileOutputStream("b.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            c.clear();
            String[] s1 = in.readLine().split(" ");
            int n = Integer.parseInt(s1[0]);
            int m = Integer.parseInt(s1[1]);
            boxes = new ArrayList<long[]>();
            toys = new ArrayList<long[]>();

            s1 = in.readLine().split(" ");
            for (int i = 0; i < s1.length; i+=2) {
                long q = Long.parseLong(s1[i]);
                int t = Integer.parseInt(s1[i + 1]);
                boxes.add(new long[]{q, t});
            }
            s1 = in.readLine().split(" ");
            for (int i = 0; i < s1.length; i+=2) {
                long q = Long.parseLong(s1[i]);
                int t = Integer.parseInt(s1[i + 1]);
                toys.add(new long[]{q, t});

            }
            out.print("Case #" + (cas + 1) + ": ");
            out.print(get(n - 2, boxes.get(n-1)[0], m - 2, toys.get(m-1)[0]));
            out.println();
        }
        out.flush();
        out.close();

    }

    static long get(int n, long en, int m, long em) {
        String key = n +"_"+ en + "_" + m + "_" + em;

        if (c.containsKey(key)) {
            return c.get(key);
        }
        long ans = 0;
        if ((n ==-1 && en ==0) || (m == -1 && em == 0)) {
            return 0;
        }

        //System.out.print(key + " ");

        long t1 = boxes.get(n+1)[1];
        long t2 = toys.get(m+1)[1];
        
        if (t1 == t2) {
            long min = Math.min(en, em);
            ans = min;
            boolean add= true;
                en -= min;
                em -= min;
                if (en == 0) {
                    if (n >=0) {
                        en = boxes.get(n)[0];
                        n--;
                    } else {
                        add = false;
                    }
                }
                if (em == 0) {
                    if (m>=0) {
                        em = toys.get(m)[0];
                        m--;
                    } else {
                        add = false;
                    }
                }
            if (add) {
                ans += get(n, en, m, em);
            }
        }  else {
            if (n >= 0) {
                ans = Math.max(get(n - 1, boxes.get(n)[0], m, em), ans);
            }
            if (m >= 0) {
                ans = Math.max(ans, get(n, en, m - 1, toys.get(m)[0]));
            }
        }

        //System.out.println(key + " " + ans);
        c.put(key, ans);
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
