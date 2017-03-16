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
        public long left, right;

        public Pair(long anlong, long anlong1) {
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
    }

    public static void main(String[] args) throws IOException {
      Kattio io = new Kattio(new FileInputStream("proba.in"), new FileOutputStream("proba.out"));

      int tests = io.getInt();

      for (int test = 1; test <= tests; test++) {
        String word = io.getWord();
        int n = io.getInt();
        String vowel = "aeiou";
        boolean mat[] = new boolean[word.length()];

        for(int i = 0; i < word.length(); i++) {
          char c = word.charAt(i);
          if(vowel.contains(""+c)) {
            mat[i] = false;
          } else {
            mat[i] = true;
          }
        }

        long count = 0;
        for(int i = 0; i < word.length(); i++){
          int cons = 0;
          for(int j = i; j < word.length(); j++) {
            if(mat[j]) {
              cons++;
            } else {
              cons = 0;
            }
            if(cons >= n) {
              count += word.length() - j;
              break;
            }
          }
        }

        io.println("Case #" + test + ": " + count);
      }

      io.flush();
      io.close();
      System.exit(0);
    }

}
