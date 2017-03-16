import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class A {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
        PrintStream out = new PrintStream(new FileOutputStream("a.out"));
        long n = readInt(in);
        for (int cas = 0; cas < n; cas++) {
            String[] s1 = in.readLine().split(" ");
            int k = s1.length - 1;
            int[] s = new int[k];
            int[] below = new int[k];
            int[] db = new int[k];

            int sum = 0;
            for (int j = 0; j < s.length; j++) {
                s[j] = Integer.parseInt(s1[j + 1]);
                sum += s[j];
            }
            List<Integer>[] top = new List[k];
            for (int i = 0; i < top.length; i++) {
                top[i] = new ArrayList<Integer>();

            }


            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (s[i] <= s[j]) {
                        below[j]++;
                        db[j] += s[j] - s[i];
                    } else {
                        top[j].add(s[i]);
                    }
                }
            }
            for (int i = 0; i < top.length; i++) {
                Collections.sort(top[i]);

            }


            out.print("Case #" + (cas + 1) + ":");

            for (int j = 0; j < s.length; j++) {
                double ans = 0;
                if (db[j] <= sum) {
                    int left = sum - db[j];
                    double count = below[j];
                    double target = s[j] + left / count;
                    for (int i = 0; i < top[j].size(); i++) {
                        int next = top[j].get(i);
                        if (next >= target) {
                            break;
                        }

                        double oleft = left - (target - next) * count;
                        count++;
                        target = next + (left -oleft) / count;
                    }
                    ans = (target - s[j])*100d/sum;
                }

                out.print(" " + ans);
            }

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
