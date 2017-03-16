import jdk.nashorn.internal.ir.ReturnNode;

import javax.swing.*;
import java.io.*;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class CloseMatch {
    static long diff(String[] s) {
        return Math.abs(Long.parseLong(s[0]) - Long.parseLong(s[1]));
    }

    static String[] best(String[]... opts) {
        long best = diff(opts[0]);
        int bestI = 0;
        for (int i = 1; i < opts.length; i++) {
            long diff = diff(opts[i]);
            if (diff < best) {
                best = diff;
                bestI = i;
            }
        }
        return opts[bestI];
    }

    static String[] solve(String a, String b) {
        if (a.isEmpty()) return new String[] { "", "" };

        if (a.startsWith("??") && b.startsWith("??")) {
            String[] tmp = solve(a.substring(1), b.substring(1));
            tmp[0] = "0" + tmp[0];
            tmp[1] = "0" + tmp[1];
            return tmp;
        } else
        if (a.startsWith("?")) {
            if (b.startsWith("?")) {
                return best(
                    solve("0" + a.substring(1), "0" + b.substring(1)),
                    solve("0" + a.substring(1), "1" + b.substring(1)),
                    solve("1" + a.substring(1), "0" + b.substring(1)),
                    solve("1" + a.substring(1), "1" + b.substring(1))
                );
            } else {
                int cb = b.charAt(0) - '0';
                String tries;
                if (cb == 0) tries = "01"; else
                if (cb == 9) tries = "89"; else
                             tries = "" + (cb - 1) + (cb) + (cb + 1);

                String[][] tmps = new String[tries.length()][];
                for (int i = 0; i < tries.length(); i++)
                    tmps[i] = solve(tries.charAt(i) + a.substring(1), b);
                return best(tmps);
            }
        } else {
            if (b.startsWith("?")) {
                int cb = a.charAt(0) - '0';
                String tries;
                if (cb == 0) tries = "01"; else
                if (cb == 9) tries = "89"; else
                    tries = "" + (cb - 1) + (cb) + (cb + 1);

                String[][] tmps = new String[tries.length()][];
                for (int i = 0; i < tries.length(); i++)
                    tmps[i] = solve(a, tries.charAt(i) + b.substring(1));
                return best(tmps);
            } else {
                if (a.charAt(0) < b.charAt(0)) {
                    return new String[] { a.replace('?', '9'), b.replace('?', '0') };
                } else
                if (a.charAt(0) > b.charAt(0)) {
                    return new String[] { a.replace('?', '0'), b.replace('?', '9') };
                } else {
                    String[] tmp = solve(a.substring(1), b.substring(1));
                    return new String[] {
                        a.charAt(0) + tmp[0],
                        a.charAt(0) + tmp[1]
                    };
                }
            }
        }
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
            String[] input = in.readLine().trim().split(" ");

            Writer writer = line -> {
                System.out.println(line);
                out.write(line + "\n");
            };

            String[] sol = solve(input[0], input[1]);
            writer.write("Case #" + c + ": " + sol[0] + " " + sol[1]);
        }

        out.flush();
        fos.close();
    }

    interface Writer {
        void write(String s) throws Exception;
    }
}
