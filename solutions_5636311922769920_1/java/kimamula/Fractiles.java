import java.io.*;

public class Fractiles {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());

        for (int i = 1; i <= t; i++) {
            String[] input = bi.readLine().split("\\s");
            int k = Integer.parseInt(input[0]);

            if (k == 1) {
                out.println("Case #" + i + ": 1");
                continue;
            }

            int c = Integer.parseInt(input[1]);
            int s = Integer.parseInt(input[2]);


            int checkedCount = 1;
            long index = 1;

            while (checkedCount < c) {
                checkedCount += 1;
                index = (index - 1) * k + checkedCount;
                if (checkedCount == k) {
                    break;
                }
            }

            int remain = k - checkedCount;
            if (remain >= s) {
                out.println("Case #" + i + ": IMPOSSIBLE");
                continue;
            }

            StringBuilder sb = new StringBuilder("Case #" + i + ":");
            for (int offset = 0; offset <= remain; offset++) {
                sb.append(" ").append(index + offset);
            }
            out.println(sb);
        }
        out.close();
    }
}
