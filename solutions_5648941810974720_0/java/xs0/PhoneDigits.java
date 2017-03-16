import javax.swing.*;
import java.io.*;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class PhoneDigits {
    static LinkedHashMap<String, String> order = new LinkedHashMap<>();
    static {
        order.put("ZERO", "Z0");
        order.put("SIX", "X6");
        order.put("TWO", "W2");
        order.put("SEVEN", "S7");
        order.put("EIGHT", "G8");
        order.put("THREE", "H3");
        order.put("FIVE", "V5");
        order.put("FOUR", "F4");
        order.put("NINE", "I9");
        order.put("ONE", "O1");
    }

    static String solve(String input) {
        HashMap<Character, Integer> counts = new HashMap<>();
        for (char c : input.toCharArray())
            counts.compute(c, (a,b) -> (b == null ? 1 : b + 1));

        int[] res = new int[10];
        for (Map.Entry<String, String> o : order.entrySet()) {
            char c = o.getValue().charAt(0);
            int val = o.getValue().charAt(1) - '0';
            int count = counts.getOrDefault(c, 0);
            res[val] = count;

            if (count > 0)
                for (char r : o.getKey().toCharArray())
                    counts.compute(r, (a,b) -> b - count);
        }

        StringBuilder sb = new StringBuilder();
        for (int a = 0; a < 10; a++)
            while(res[a]-->0)
                sb.append(a);
        return sb.toString();
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
            String input = in.readLine().trim();

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
