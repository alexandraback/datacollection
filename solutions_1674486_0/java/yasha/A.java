import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class A {

    private static List<Integer>[] m;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
        PrintStream out = new PrintStream(new FileOutputStream("a.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            int n = (int)readInt(in);
            m = new List[n];
            for (int i = 0; i < m.length; i++) {
                m[i] = new ArrayList<Integer>();
                String[] s1 = in.readLine().split(" ");
                for (int j = 1; j < s1.length; j++) {
                    m[i].add(Integer.parseInt(s1[j]) - 1);
                }
            }
            
            String ans = "No";
            for (int i = 0; i < m.length; i++) {
                List<Integer> t1 = m[i];
                List<Integer> top = new ArrayList<Integer>();
                
                top.addAll(t1);
                do {
                    List<Integer> t2 = new ArrayList<Integer>();
                    for (Integer v : t1) {
                        t2.addAll(m[v]);
                    }
                    top.addAll(t2);
                    t1 = t2;
                } while (!t1.isEmpty());
                Set<Integer> s = new HashSet<Integer>();
                s.addAll(top);
                if (s.size() < top.size()) {
                    ans = "Yes";
                    break;
                }
            }
            

            
            out.print("Case #" + (cas + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();

    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
