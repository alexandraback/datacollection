import java.io.*;
import java.util.*;

public class GCJ2012QualA {
    public void run() throws IOException {
        String a = "yeq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
        String b = "aoz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
        char[] map = new char[128];
        boolean[] used = new boolean[128];
        
        for (int i = 0; i < a.length(); ++i) {
            map[a.charAt(i)] = b.charAt(i);
            used[b.charAt(i)] = true;
        }
        
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!used[i]) {
                assert map['z'] == 0;
                map['z'] = i;
            }
        }
        
        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            String line = in.readLine();
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < line.length(); ++j) {
                assert map[line.charAt(j)] != 0;
                sb.append(map[line.charAt(j)]);
            }
            
            out.println("Case #" + i + ": " + sb.toString());
        }
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012QualA.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012QualA().run();

        out.close();
    }

    public static StringTokenizer tokenizer;

    public static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
