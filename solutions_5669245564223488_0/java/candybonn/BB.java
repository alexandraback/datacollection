
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import java.util.StringTokenizer;

public class BB {

    private Pipe pipe = null;

    public BB(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new BB(args).start();
    }

    public void start() throws FileNotFoundException, IOException {
        int roundCount = pipe.ni();
        for (int round = 1; round <= roundCount; round++) {
            String result = solve();
            String outStr = "Case #" + round + ": " + result + "\n";
            pipe.print(outStr);
//            pipe.nline();
        }
        pipe.close();
    }

    int count = 0;

    public String solve() throws IOException {
        int N = pipe.ni();
        String line = pipe.nline();
        String cars[] = line.split(" ");
        Set<Integer> ss = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            ss.add(i);
        }
        count = 0;
//        count(N, cars, ss, "", new HashSet<String>());
        baoli(ss, cars, "");
        return count+"";
    }

    private void baoli(Set<Integer> ss, String[] cars, String s) {
        if(ss.isEmpty()) {
            if(ok(s)) {
                count++;
            }
        }
        
        for (Integer i : ss) {
            Set<Integer> aa = new HashSet<Integer>();
            aa.addAll(ss);
            aa.remove(i);
            baoli(aa, cars, s + cars[i]);
        }
    }
    
    private boolean ok(String s) {
        Set<Integer> set = new HashSet<Integer>();
        char p = s.charAt(0);
        set.add((int)p);
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != p) {
                if(!set.contains((int)s.charAt(i))) {
                    p = s.charAt(i);
                    set.add((int)p);
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    private void count(int N, String cars[], Set<Integer> ss, String prefix, Set<String> checker) {
        if (ss.isEmpty()) {
            count++;
        }
        for (Integer s : ss) {
            if (compact(prefix, cars[s], checker)) {
                Set<Integer> aa = new HashSet<Integer>();
                aa.addAll(ss);
                aa.remove(s);
                Set<String> sub = new HashSet<String>();
                sub.addAll(checker);
                for (int i = 0; i < cars[s].length(); i++) {
                    sub.add(cars[s].charAt(i) + "");
                }
                count(N - 1, cars, aa, prefix + cars[s], sub);
            }
        }
    }

    private boolean compact(String prefix, String s, Set<String> checker) {
        char p;
        if (prefix.length() == 0) {
            p = s.charAt(0);
        } else {
            p = prefix.charAt(prefix.length() - 1);
        }

        Set<String> copy = new HashSet<String>();
        copy.addAll(checker);

        for (int i = 0; i < s.length(); i++) {
            if (p != s.charAt(i)) {
                if (!copy.contains(s.charAt(i) + "")) {
                    p = s.charAt(i);
                    copy.add(p + "");
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    private String toM(int count) {
        if (count < 1000) {
            return "" + count;
        }
        String v = Integer.toString(count);
        StringBuilder sb = new StringBuilder();
        if (count > 1000 && count < 1000000) {
            for (int i = 0; i < v.length(); i++) {
                if (i == (v.length() - 3)) {
                    sb.append(',');
                }
                sb.append(v.charAt(i));
            }
            return sb.toString();
        } else {
            for (int i = 0; i < v.length(); i++) {
                if (i == (v.length() - 3) || i == (v.length() - 6)) {
                    sb.append(',');
                }
                sb.append(v.charAt(i));
            }
            return sb.toString();
        }
    }

    

    private class Pipe {

        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Pipe(String args[]) throws FileNotFoundException, IOException {
            if (args != null && args.length >= 1) {
                reader = new BufferedReader(new FileReader(args[0]));
                if (args.length == 2) {
                    writer = new BufferedWriter(new FileWriter(args[1]));
                }
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public String nline() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        public String ns() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int ni() throws IOException {
            return Integer.parseInt(ns());
        }

        public long nl() throws IOException {
            return Long.parseLong(ns());
        }

        public float nf() throws IOException {
            return Float.parseFloat(ns());
        }

        public double nd() throws IOException {
            return Double.parseDouble(ns());
        }

        public void print(String str) throws IOException {
            System.out.print(str);
            if (writer != null) {
                writer.write(str, 0, str.length());
            }
        }

        public void close() throws IOException {
            if (writer != null) {
                writer.close();
            }
        }
    }
}
