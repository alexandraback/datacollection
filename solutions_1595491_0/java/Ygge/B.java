import java.io.*;

public class B {

    private static final String FILE = "B-small-attempt0";

    private static final boolean SAVE_OUT = true;

    public static void main(String[] args) throws IOException {
        BufferedReader in = createReader();
        FileWriter out;
        if (SAVE_OUT) {
            out = new FileWriter(FILE+".out");
        }
        int t = Integer.parseInt(in.readLine());
        int c = 0;
        while (t-- > 0) {
            String row = in.readLine();
            String[] split = row.split(" ");
            int n = Integer.parseInt(split[0]);
            int s = Integer.parseInt(split[1]);
            int p = Integer.parseInt(split[2]);
            int num = 0;
            for (int i = 0; i < n; ++i) {
                int k = Integer.parseInt(split[i+3]);
                if (k == 0) {
                    num += p == 0 ? 1 : 0;
                } else if (k == 1) {
                    num += p <= 1 ? 1 : 0;
                } else if (3*p-2 <= k) {
                    ++num;
                } else if (3*p-4 <= k && s > 0) {
                    ++num;
                    --s;
                }
            }
            String res = String.format("Case #%d: %d", ++c, num);
            System.out.println(res);
            if (SAVE_OUT) {
                out.append(res);
                out.append("\n");
            }
        }
        if (SAVE_OUT) {
            out.close();
        }
    }

    private static BufferedReader createReader() throws FileNotFoundException {
        return new BufferedReader(new FileReader(FILE+".in"));
    }
}
