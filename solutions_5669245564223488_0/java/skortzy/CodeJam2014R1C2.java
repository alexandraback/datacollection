import java.io.*;

public class CodeJam2014R1C2 {

    private static boolean used[];
    private static String values[];

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("B-small.out"));
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("A-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                int N = Integer.parseInt(line);
                line = br.readLine();
                values = line.split(" ");
                used = new boolean[N];
                for (int j = 0; j < N; j++) {
                    used[j] = false;
                }

                if (validWords()) {
                    pw.println("Case #" + (i + 1) + ": " + count("", 0));
                } else {
                    pw.println("Case #" + (i + 1) + ": " + 0);
                }

            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static boolean validWords() {
        for (String value : values) {
            if (!validWord(value)) {
                return false;
            }
        }
        return true;
    }

    private static boolean validWord(String value) {
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            int j = i - 1;
            while (j >= 0 && value.charAt(j) == c) {
                j--;
            }
            while (j >= 0) {
                if (value.charAt(j) == c) {
                    return false;
                }
                j--;
            }
        }
        return true;
    }

    private static long count(String s, int step) {
        if (step == values.length) {
            return 1;
        }
        long total = 0;
        for (int i = 0; i < values.length; i++) {
            if (!used[i] && canAdd(s, values[i])) {
                used[i] = true;
                total += count(s + values[i], step + 1);
                used[i] = false;
            }
        }
        return total;
    }

    private static boolean canAdd(String s, String value) {
        char first = value.charAt(0);
        int last = s.length() - 1;
        while (last >= 0 && s.charAt(last) == first) {
            last--;
        }
        String tmp = s.substring(0, last + 1);
        for (char c : value.toCharArray()) {
            if (tmp.indexOf(c) != -1) {
                return false;
            }
        }
        return true;
    }

}
