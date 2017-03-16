
import java.io.*;

public class Main {

    static final String FILE = "C-small-attempt0";
    static final String INPUT = FILE + ".in";
    static final String OUTPUT = FILE + ".out";
    //

    public static void main(String[] args) throws FileNotFoundException, IOException {
        int T, A, B, x, y;

        PrintWriter pw;
        try (BufferedReader br = new BufferedReader(new FileReader(INPUT))) {
            pw = new PrintWriter(OUTPUT);

            T = Integer.parseInt(br.readLine());
            for (x = 1; x <= T; x++) {
                y = 0;

                //
                String[] temp = br.readLine().split(" ");
                A = Integer.parseInt(temp[0]);
                B = Integer.parseInt(temp[1]);

                //
                for (int i = A; i <= B; i++) {
                    String n = Integer.toString(i);
                    String m = new String(n);
                    for (int j = 0; j < n.length() - 1; j++) {
                        m = m.charAt(m.length() - 1) + m;
                        m = m.substring(0, n.length());

                        if (Integer.parseInt(n) < Integer.parseInt(m) && Integer.parseInt(m) <= B) {
                            y++;
                        }
                    }
                }

                //
                System.out.println("Case #" + x + ": " + y);
                pw.println("Case #" + x + ": " + y);
            }
        }
        pw.close();
    }
}
