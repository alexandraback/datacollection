package com.rocketfuel.kamran;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

/**
 * Hello world!
 *
 */
public class App
{

    private static class Pair {
        String A, B;

        public Pair(String A, String B) {
            this.A = A;
            this.B = B;
        }

        public Pair(String A, char B) {
            this.A = A;
            this.B = String.valueOf(B);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (!(o instanceof Pair)) {
                return false;
            }

            Pair pair = (Pair) o;

            if (A != null ? !A.equals(pair.A) : pair.A != null) {
                return false;
            }
            if (B != null ? !B.equals(pair.B) : pair.B != null) {
                return false;
            }

            return true;
        }

        @Override
        public int hashCode() {
            int result = A != null ? A.hashCode() : 0;
            result = 31 * result + (B != null ? B.hashCode() : 0);
            return result;
        }
    }

    private static Map<Pair, String> TRANSFORM = new HashMap<Pair, String>();

    static {
        TRANSFORM.put(new Pair("k", "k"), "1");
        TRANSFORM.put(new Pair("k", "j"), "i");
        TRANSFORM.put(new Pair("-k", "i"), "j");
        TRANSFORM.put(new Pair("k", "1"), "k");

        TRANSFORM.put(new Pair("j", "j"), "1");
        TRANSFORM.put(new Pair("-j", "k"), "i");
        TRANSFORM.put(new Pair("j", "1"), "j");
        TRANSFORM.put(new Pair("j", "i"), "k");

        TRANSFORM.put(new Pair("i", "i"), "1");
        TRANSFORM.put(new Pair("i", "1"), "i");
        TRANSFORM.put(new Pair("i", "k"), "j");
        TRANSFORM.put(new Pair("-i", "j"), "k");

        TRANSFORM.put(new Pair("1", "1"), "1");
        TRANSFORM.put(new Pair("-1", "i"), "i");
        TRANSFORM.put(new Pair("-1", "j"), "j");
        TRANSFORM.put(new Pair("-1", "k"), "k");
    }

    BufferedReader br;
    BufferedWriter bw;

    public App(BufferedReader br, BufferedWriter bw) {
        this.br = br;
        this.bw = bw;
    }

    public void run() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for (int ts=1; ts<=T; ++ts) {

            String line = br.readLine();
            String[] args = line.split(" ");

            int L = Integer.parseInt(args[0]);
            long X = Long.parseLong(args[1]);

            X = Math.min(X, X % 12L + 24L);

            String str = br.readLine();
            StringBuilder strBuilder = new StringBuilder();
            for (long i=1; i<=X; ++i) {
                strBuilder.append(str);
            }
            str = strBuilder.toString();

            int len = str.length();

            String search = "k";
            String cur = "k";
            for (int i=len-1; i>=0; --i) {
                char ch = str.charAt(i);
                String next = TRANSFORM.get(new Pair(cur, ch));
                if (next == null) {
                    cur = "-" + cur;
                    if (cur.startsWith("--"))
                        cur = cur.substring(2);
                    next = TRANSFORM.get(new Pair(cur, ch));
                    /*if (next == null) {
                        System.out.println("NULL");
                    }*/
                    cur = "-" + next;
                } else {
                    cur = next;
                }
                if (cur.startsWith("--"))
                    cur = cur.substring(2);
                if (cur.equals("1")) {
                    if (search.equals("k")) {
                        search = "j";
                        cur = search;
                    } else if (search.equals("j")) {
                        search = "i";
                        cur = search;
                    }
                }
                //System.out.println(i + ", " + search + ", " + cur);
            }

            String ans = "NO";
            if (search.equals("i") && cur.equals("1")) {
                ans = "YES";
            }
            String res = "Case #" + ts + ": " + ans + "\n";
            bw.write(res);
            bw.flush();
        }
        bw.close();
    }

    public static void main( String[] args )
    {
        BufferedReader br = null;
        BufferedWriter bw = null;
        if (System.getProperty("input.stdin").equals("true")) {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new PrintWriter(System.out));
        } else {
            ClassLoader classLoader = App.class.getClassLoader();
            try {
                br = new BufferedReader(new FileReader(
                        new File(classLoader.getResource("1.txt").getFile())));
                bw = new BufferedWriter(new FileWriter(
                        new File("src/main/resources/2.txt")
                ));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {

            }
        }
        try {
            new App(br, bw).run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
