package contests.GoogleCodeJam.GCJ2013.round1c;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

class ProblemA {
    static class Kattio extends PrintWriter {
        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasMoreTokens() {
            return peekToken() != null;
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public double getDouble() {
            return Double.parseDouble(nextToken());
        }

        public long getLong() {
            return Long.parseLong(nextToken());
        }

        public String getWord() {
            return nextToken();
        }

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
                }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }

    static class Pair implements Comparable<Pair> {
        public int left, right;

        public Pair(int anlong, int anlong1) {
            left = anlong;
            right = anlong1;
        }

        @Override
        public int compareTo(Pair pair) {
            if (pair.left < left)
                return 1;
            if (pair.left > left)
                return -1;

            if (pair.right < right)
                return -1;
            if (pair.right > right)
                return 1;

            return 0;
        }

      @Override
        public int hashCode() {
          return left * right;
        }

      @Override
      public boolean equals(Object t) {
        return compareTo((Pair) t) == 0;
      }
    }

    public static void main(String[] args) throws IOException {
      Kattio io = new Kattio(new FileInputStream("proba.in"), new FileOutputStream("proba.out"));

      int tests = io.getInt();

      for (int test = 1; test <= tests; test++) {
        int x = io.getInt();
        int y = io.getInt();

        Map<Pair, String> oldSet = new HashMap<Pair, String>();
        oldSet.put(new Pair(0, 0), "");
        int jump = 0;
        String result = null;
        while(result == null) {
          jump += 1;
          Map<Pair, String> newSet = new HashMap<Pair, String>();
          for (Map.Entry<Pair, String> sadf : oldSet.entrySet()) {
            Pair p = sadf.getKey();
            newSet.put(new Pair(p.left-jump, p.right), sadf.getValue() + "W");
            newSet.put(new Pair(p.left+jump, p.right), sadf.getValue() + "E");
            newSet.put(new Pair(p.left, p.right-jump), sadf.getValue() + "S");
            newSet.put(new Pair(p.left, p.right+jump), sadf.getValue() + "N");
          }
          result = newSet.get(new Pair(x, y));
          oldSet = newSet;
        }


        io.println("Case #" + test + ": " + result);
      }

      io.flush();
      io.close();
      System.exit(0);
    }

}
