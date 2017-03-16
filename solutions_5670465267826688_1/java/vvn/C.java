import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    enum Letter {
        I,
        J,
        K
    }

    class State {
        Letter letter;
        boolean negative;

        State(Letter letter, boolean negative) {
            this.letter = letter;
            this.negative = negative;
        }

        void multiply(Letter mult) {
            if (letter == null) {
                letter = mult;
                return;
            }
            if (mult == null) {
                return;
            }
            if (mult == letter) {
                letter = null;
                negate();
            }

            // only non-equal IJK left
            if (letter == Letter.I && mult == Letter.J) {
                letter = Letter.K;
            } else if (letter == Letter.I && mult == Letter.K) {
                letter = Letter.J;
                negate();
            } else if (letter == Letter.J && mult == Letter.I) {
                letter = Letter.K;
                negate();
            } else if (letter == Letter.J && mult == Letter.K) {
                letter = Letter.I;
            } else if (letter == Letter.K && mult == Letter.I) {
                letter = Letter.J;
            } else if (letter == Letter.K && mult == Letter.J) {
                letter = Letter.I;
                negate();
            }
        }

        private void negate() {
            negative = !negative;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (negative != state.negative) return false;
            if (letter != state.letter) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = letter != null ? letter.hashCode() : 0;
            result = 31 * result + (negative ? 1 : 0);
            return result;
        }
    }

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int testcase = 1; testcase <= t; testcase++) {
            boolean res = solveCase();
            out.printf("Case #%d: ", testcase);
            out.println(res ? "YES" : "NO");
        }
    }

    private State multAll(Iterable<Letter> letters) {
        State state = new State(null, false);
        for (Letter letter : letters) {
            state.multiply(letter);
        }
        return state;
    }

    private boolean solveCase() {
        in.nextInt(); // don't need that
        long x = in.nextLong();
        String l = in.next();

        List<Letter> letters = new ArrayList<>(l.length());
        for (char ch : l.toCharArray()) {
            letters.add(Letter.valueOf(String.valueOf(ch).toUpperCase()));
        }

        int times = (int) (x % 4);
        List<Letter> all = new ArrayList<>();
        for (int i = 0; i < times; i++) {
            all.addAll(letters);
        }

        State finalResult = multAll(all);
        if (finalResult.letter != null || !finalResult.negative) {
            return false;
        }


        State iState = multAll(Arrays.asList(Letter.I));
        State ijState = multAll(Arrays.asList(Letter.I, Letter.J));
        List<State> statesToFind = new ArrayList<>(Arrays.asList(iState, ijState));

        State current = new State(null, false);

        long idx = 0;
        long lastFind = 0;
        long total = x * l.length();

        while (!statesToFind.isEmpty()) {
            if (idx >= total) {
                return false;
            }

            // actually looped after 4 repetitions, but let's be safe
            if (idx > lastFind + 10 * l.length()) {
                return false;
            }

            int at = (int) (idx % l.length());
            Letter letter = letters.get(at);
            current.multiply(letter);

            if (current.equals(statesToFind.get(0))) {
                statesToFind.remove(0);
                lastFind = idx;
            }

            idx++;
        }

        return true;
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("c-large.in"));
            out = new PrintWriter(new FileOutputStream("c-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }


        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] arg) {
        new C().run();
    }
}