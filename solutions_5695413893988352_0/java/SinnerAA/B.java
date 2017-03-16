import java.io.*;
import java.util.StringTokenizer;

public class B {

    final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void solve() throws IOException {
        int t = readInt();
        int i = 0;
        while (i++ < t) {
            System.err.println(i);
            out.print("Case #" + i + ": ");
            solveTest();
        }
    }

    char[] x;
    char[] y;
    char[] first;
    char[] second;
    int n;

    long resX;
    long resY;
    long resDiff;

    String rx;
    String ry;

    void dfs(int index, int curDif) {
        if(index == n) {
            String s1 = new String(x);
            String s2 = new String(y);
            long curX = Long.parseLong(s1);
            long curY = Long.parseLong(s2);
            long curDiff = Math.abs(curX - curY);
            if(curDiff < resDiff || resDiff == -1) {
                resDiff = curDiff;
                resX = curX;
                resY = curY;
                rx = s1;
                ry = s2;
            } else if(curDiff == resDiff) {
                if(curX < resX) {
                    resX = curX;
                    resY = curY;
                    resDiff = curDiff;
                    rx = s1;
                    ry = s2;
                } else if(curX == resX) {
                    if(curY < resY) {
                        resX = curX;
                        resY = curY;
                        resDiff = curDiff;
                        rx = s1;
                        ry = s2;
                    }
                }
            }
            return;
        }
        if(first[index] != '?' && second[index] != '?') {
            x[index] = first[index];
            y[index] = second[index];
            if(curDif != 0) dfs(index+1, curDif);
            else if(first[index] == second[index]) dfs(index+1, 0);
            else if(first[index] < second[index]) dfs(index+1, -1);
            else dfs(index + 1, 1);
        } else if(first[index] == '?' && second[index] != '?') {
            y[index] = second[index];
            if(curDif == -1) {
                x[index] = '9';
                dfs(index+1, curDif);
            } else if(curDif == 1) {
                x[index] = '0';
                dfs(index+1, curDif);
            } else {
                x[index] = y[index];
                dfs(index+1, curDif);

                if(y[index] != '9') {
                    x[index] = (char) (y[index] + 1);
                    dfs(index+1, 1);
                }
                if(y[index] != '0') {
                    x[index] = (char) (y[index] - 1);
                    dfs(index+1, -1);
                }
            }
        } else if(first[index] != '?' && second[index] == '?') {
            x[index] = first[index];
            if(curDif == -1) {
                y[index] = '0';
                dfs(index+1, curDif);
            } else if(curDif == 1) {
                y[index] = '9';
                dfs(index+1, curDif);
            } else {
                y[index] = x[index];
                dfs(index+1, curDif);
                if(x[index] != '9') {
                    y[index] = (char) (x[index] + 1);
                    dfs(index+1, -1);
                }
                if(x[index] != '0') {
                    y[index] = (char) (x[index] - 1);
                    dfs(index+1, 1);
                }
            }
        } else if(first[index] == second[index] && first[index] == '?') {
            if(curDif == -1) {
                x[index] = '9';
                y[index] = '0';
                dfs(index+1, curDif);
            } else if(curDif == 1) {
                x[index] = '0';
                y[index] = '9';
                dfs(index + 1, curDif);
            } else {
                x[index] = y[index] = '0';
                dfs(index+1, curDif);

                x[index] = '1';
                y[index] = '0';
                dfs(index+1, 1);

                x[index] = '0';
                y[index] = '1';
                dfs(index+1, -1);
            }
        }
    }

    String solveTest() throws IOException {
        first = readString().toCharArray();
        second = readString().toCharArray();
        n = first.length;
        x = new char[n];
        y = new char[n];
        resDiff = resX = resY = -1;
        rx = ry = null;
        dfs(0, 0);
        String res = rx + " " + ry;
        String res2 = stress(first, second);
        if(!res.equals(res2)) {
            throw new RuntimeException();
        }
        out.println(res);
        return res;
    }

    String stress(char[] x, char[] y){
        int maxDiff = -1;
        int maxX = -1;
        int maxY = -1;
        String res = "";
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                String f = Integer.toString(i);
                String s = Integer.toString(j);
                if(f.length() > x.length || s.length() > y.length) continue;
                while (f.length() < x.length) {
                    f = "0" + f;
                }
                while (s.length() < y.length) {
                    s = "0" + s;
                }
                boolean check = true;
                for(int k = 0; k < f.length(); k++) {
                    if(x[k] != '?' && x[k] != f.charAt(k)) check = false;
                }
                for(int k = 0; k < s.length(); k++) {
                    if(y[k] != '?' && y[k] != s.charAt(k)) check = false;
                }
                if(check) {
                    int curD = Math.abs(i - j);
                    int curX = i;
                    int curY = j;
                    if(maxDiff == -1 || curD < maxDiff) {
                        maxDiff = curD;
                        maxX = curX;
                        maxY = curY;
                        res = f + " " + s;
                    } else if(curD == maxDiff) {
                        if(curX < maxX) {
                            maxDiff = curD;
                            maxX = curX;
                            maxY = curY;
                            res = f + " " + s;
                        } else if(curX == maxX) {
                            if(curY < maxY) {
                                maxDiff = curD;
                                maxX = curX;
                                maxY = curY;
                                res = f + " " + s;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }



    void init() throws FileNotFoundException {
        if (ONLINE_JUDGE) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader("input.txt1"));
            out = new PrintWriter("output.txt");
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    int[] readArr(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = readInt();
        }
        return res;
    }

    long[] readArrL(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = readLong();
        }
        return res;
    }

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            init();
            solve();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Exception e) {
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }
}