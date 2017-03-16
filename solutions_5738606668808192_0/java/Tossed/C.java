package google.code.jam.qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by chen on 4/9/16.
 */
public class C {

    public static void recur(List<String> list, int max, int oddCount, int evenCount, String st, int oddIndex, int evenIndex) {
        if (oddCount < 3) {
            for (int i = oddIndex; i < st.length() - 1; i += 2) {
                if (list.size() >= max) {
                    return;
                }
                recur(list, max, oddCount + 1, evenCount, st.substring(0, i) + "1" + st.substring(i + 1), i + 2, evenIndex);
            }
        }
        else if (evenCount < 3) {
            for (int i = evenIndex; i < st.length() - 1; i += 2) {
                if (list.size() >= max) {
                    return;
                }

                if (evenCount + 1 == 3) {
                    if (list.size() < max) {
                        list.add(st.substring(0, i) + "1" + st.substring(i + 1));
                    }
                }
                else {
                    recur(list, max, oddCount, evenCount + 1, st.substring(0, i) + "1" + st.substring(i + 1), oddIndex, i + 2);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("C.in"));
        PrintWriter out = new PrintWriter(new FileWriter("C.out"));

        int T = Integer.parseInt(in.readLine());

        for (int k = 1; k <= T; k ++) {
            String line = in.readLine();

            int N = Integer.parseInt(line.split(" ")[0]);
            int J = Integer.parseInt(line.split(" ")[1]);

            List<String> ans = new ArrayList<>();
            String base  = "";
            for (int i = 0; i < N - 2; i ++) {
                base += "0";
            }
            base = "1" + base + "1";

            recur(ans, J, (N + 1) % 2, 1 + N % 2, base, 1, 2);

            out.printf("Case #%d:\n", k);
            ans.stream().forEach(st -> out.printf("%s 3 2 3 2 7 2 3 2 3\n", st));
        }

        in.close();
        out.close();
    }
}
