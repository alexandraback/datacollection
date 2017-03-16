import java.io.*;

public class B {

    private static final String FILE_NAME = "B-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] split = in.readLine().split(" ");
            int a = Integer.parseInt(split[0]);
            int b = Integer.parseInt(split[1]);
            int k = Integer.parseInt(split[2]);

            int count = 0;
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((i&j) < k) {
                        ++count;
                    }
                }
            }
            out.write(String.format("Case #%d: %s\n", c, count));
        }
        out.close();
    }
}
