import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbB {
    RW rw;
    private int all;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new ProbB().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    /*
    private void solve() {
        int t_num = rw.nextInt();

        main:
        for (int t_id = 0; t_id < t_num; ++t_id) {
            int k = rw.nextInt();
            int l = rw.nextInt();
            int s = rw.nextInt();

            char[] key = rw.next().toCharArray();
            char[] target = rw.next().toCharArray();
            int[] let = new int[26];
            int[] need = new int[26];

            String ts = new String(target);
            for (char c : key) {
                let[c - 'A']++;
            }
            for (char c : target) {
                need[c - 'A']++;
            }
            for (int i = 0; i < 26; ++i) {
                if (let[i] < need[i]) {
                    rw.println("Case #" + (t_id + 1) + ": 0.0");
                    continue main;
                }
            }
            char[] cur = new char[s];
            Arrays.fill(cur, '0');
            int count = 0;
            for (int i = 0; i < s; ++i) {
                if (cur[i] == '0') {
                    for (int j = i; j < s && j - i < l; ++j) {
                        cur[j] = target[j - i];
                    }
                    if (s - i >= l) {
                        ++count;
                    } else {
                        break;
                    }
                } else {
                    int id = -1;
                    for (int j = i; j < s && j - i < l; ++j) {
                        if (cur[j] == target[j - i]) {

                        } else if (cur[j] == '0') {
                            id = j;
                            break;
                        } else {
                            break;
                        }
                    }
                    if (id != -1) {
                        for (int j = id; j < s && j - i < l; ++j) {
                            cur[j] = target[j - i];
                        }
                        if (s - i >= l) {
                            ++count;
                        } else {
                            break;
                        }
                    }
                }
            }
            double ans = count;



            rw.println("Case #" + (t_id + 1) + ": " + ans);

        }
    }*/


    double ans;

    int max;

    void rec(String cur, char[] key, int len, String s1) {
        if (cur.length() == len) {
            all++;
            int m = 0;
            for (int i = 0; i < cur.length() - s1.length() + 1; ++i) {
                if (cur.substring(i, i + s1.length()).equals(s1)) {
                    ++m;
                    ++ans;
                }
            }
            max = Math.max(max, m);
            return;
        }

        for (char c : key) {
            rec(cur + c, key, len, s1);
        }
    }

    private void solve() {
        int t_num = rw.nextInt();

        main:
        for (int t_id = 0; t_id < t_num; ++t_id) {
            int k = rw.nextInt();
            int l = rw.nextInt();
            int s = rw.nextInt();

            char[] key = rw.next().toCharArray();
            char[] target = rw.next().toCharArray();
            int[] let = new int[26];
            int[] need = new int[26];

            for (char c : key) {
                let[c - 'A']++;
            }
            for (char c : target) {
                need[c - 'A']++;
            }
            for (int i = 0; i < 26; ++i) {
                if (let[i] == 0 && need[i] > 0) {
                    rw.println("Case #" + (t_id + 1) + ": 0.0");
                    continue main;
                }
            }

           /* char[] cur = new char[s];
            Arrays.fill(cur, '0');
            int count = 0;
            for (int i = 0; i < s; ++i) {
                if (cur[i] == '0') {
                    for (int j = i; j < s && j - i < l; ++j) {
                        cur[j] = target[j - i];
                    }
                    if (s - i >= l) {
                        ++count;
                    } else {
                        break;
                    }
                } else {
                    int id = -1;
                    for (int j = i; j < s && j - i < l; ++j) {
                        if (cur[j] == target[j - i]) {

                        } else if (cur[j] == '0') {
                            id = j;
                            break;
                        } else {
                            break;
                        }
                    }
                    if (id != -1) {
                        for (int j = id; j < s && j - i < l; ++j) {
                            cur[j] = target[j - i];
                        }
                        if (s - i >= l) {
                            ++count;
                        } else {
                            break;
                        }
                    }
                }
            }*/

            all = 0;
            ans = 0;
            max = 0;
            rec("", key, s, new String(target));
            ans = max - ans / all;
            rw.print("Case #" + (t_id + 1) + ": ");
            rw.out.printf("%.7f\n", ans);
        }
    }
}

