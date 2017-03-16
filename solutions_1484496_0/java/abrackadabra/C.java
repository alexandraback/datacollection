import java.io.*;
import java.util.*;
import java.math.*;

// 5/5/12 9:14 PM
// by Abrackadabra

public class C {
    public static void main(String[] args) throws IOException {
        if (args.length > 0 && args[0].equals("Abra")) debugMode = true;
        new C().run();
        /*new Thread(null, new Runnable() {
            public void run() {
                try {
                    new C().run();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 24).start();*/
    }

    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    boolean testBasedProblem = true;

    void solve() throws IOException {
        out.print("Case #" + testIndex + ": ");
        int n = nextInt();
        long[] a = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
            sum += a[i];
        }
        Arrays.sort(a);
        HashMap<Long, ArrayList<Integer>> map = new HashMap<Long, ArrayList<Integer>>();
        boolean ok = false;
        for (long s = 1; s < sum; s++) {
            for (int i = 0; i < n; i++) {
                long q = s - a[i];
                if (q == 0 || (map.containsKey(q) && map.get(q).get(0) < i)) {
                    if (!map.containsKey(s))
                        map.put(s, new ArrayList<Integer>());
                    map.get(s).add(i);
                }
            }
            if (map.containsKey(s) && map.get(s).size() > 1) {
                HashSet<Long> x = new HashSet<Long>();
                long z = s;
                x.add(a[map.get(s).get(0)]);
                z -= a[map.get(s).get(0)];
                while (z != 0) {
                    long q = a[map.get(z).get(map.get(z).size() - 1)];
                    x.add(q);
                    z -= q;
                }
                HashSet<Long> y = new HashSet<Long>();
                z = s;
                y.add(a[map.get(s).get(map.get(s).size() - 1)]);
                z -= a[map.get(s).get(map.get(s).size() - 1)];
                while (z != 0) {
                    long q = a[map.get(z).get(map.get(z).size() - 1)];
                    y.add(q);
                    z -= q;
                }
                HashSet<Long> intersect = new HashSet<Long>();
                for (long t : x)
                    if (y.contains(t))
                        intersect.add(t);
                for (long t : intersect) {
                    x.remove(t);
                    y.remove(t);
                }
                ok = true;
                out.println();
                for (long t : x)
                    out.print(t + " ");
                out.println();
                for (long t : y)
                    out.print(t + " ");
                out.println();
                break;
            }
        }
        if (!ok) out.println("Impossible");
    }

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;
    int testIndex;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console:");
        }

        int tests = testBasedProblem ? nextInt() : 1;
        for (testIndex = 1; testIndex <= tests; testIndex++)
            solve();

        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File input:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File output:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            con.println("Execution time: " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Used memory:    " + (finishMem - startMem) + " bytes");
            con.println("Total memory:   " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x * 1e9) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode && IOMode != 3) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
        if (!debugMode)
            con = new PrintStream(new OutputStream() {
                public void write(int b) throws IOException {
                } // to /dev/null
            });
        if ((IOMode == 1 && taskName.length() == 0) || (IOMode != 1 && taskName.length() != 0)) {
            System.err.println("Leha, check IO settings");
            System.err.flush();
            System.exit(0);
        }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}