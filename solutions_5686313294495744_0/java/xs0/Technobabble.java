import javax.swing.*;
import java.io.*;
import java.util.HashMap;
import java.util.HashSet;

public class Technobabble {
    static boolean isValid(String[][] pairs, int fakes) {
        HashSet<String> lefts = new HashSet<>();
        HashSet<String> rights = new HashSet<>();
        for (int a = 0; a < pairs.length; a++) {
            if ((fakes & (1 << a)) == 0) {
                lefts.add(pairs[a][0]);
                rights.add(pairs[a][1]);
            }
        }
        for (int a = 0; a < pairs.length; a++) {
            if (!lefts.contains(pairs[a][0]) || !rights.contains(pairs[a][1]))
                return false;
        }
        return true;
    }

    static int solve(String[][] pairs) {
        int n = 1 << pairs.length;
        int best = 0;
        for (int fakes = 0; fakes < n; fakes++) {
            if (isValid(pairs, fakes)) {
                if (Integer.bitCount(fakes) > best)
                    best = Integer.bitCount(fakes);
            }
        }
        return best;
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("c:\\codejam\\data"));
        jfc.showOpenDialog(null);

        LineNumberReader in = new LineNumberReader(new InputStreamReader(new FileInputStream(jfc.getSelectedFile()), "UTF-8"));
        FileOutputStream fos = new FileOutputStream(new File(jfc.getSelectedFile().toString() + ".out"));
        OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");

        int T = Integer.parseInt(in.readLine());
        for (int c = 1; c <= T; c++) {
            int n = Integer.parseInt(in.readLine());

            String[][] input = new String[n][];
            for (int a = 0; a < n; a++)
                input[a] = in.readLine().split(" ");

            Writer writer = line -> {
                System.out.println(line);
                out.write(line + "\n");
            };

            writer.write("Case #" + c + ": " + solve(input));
        }

        out.flush();
        fos.close();
    }

    interface Writer {
        void write(String s) throws Exception;
    }
}
