import java.io.*;
import java.util.*;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class TheGreatWall {
    private static final boolean DEBUG_OUT = true;

    private final String inFile = getClass().getName() + ".in";
    private final String outFile = getClass().getName() + ".out";
    {
        ClassLoader.getSystemClassLoader().setDefaultAssertionStatus(true);
        Locale.setDefault(Locale.US);
    }

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;

    private void solveTest() throws IOException {
        nextLine();
        int n = readInt();
        final int cnt[] = new int[1];
        class Tribe implements Comparable<Tribe> {
            int i = cnt[0]++;
            int d = readInt();
            int n = readInt();
            int w = readInt();
            int e = readInt();
            int s = readInt();
            int deltaD = readInt();
            int deltaP = readInt();
            int deltaS = readInt();
            int currDay = d;
            int move = 0;

            public int compareTo(Tribe o) {
                return Integer.compare(currDay, o.currDay);
            }

            public boolean nextMove() {
                move++;
                if (move < n) {
                    currDay += deltaD;
                    w += deltaP;
                    e += deltaP;
                    s += deltaS;
                    return true;
                } else {
                    return false;
                }
            }
        }

        PriorityQueue<Tribe> Q = new PriorityQueue<Tribe>();
        for (int i = 0; i < n; i++) {
            nextLine();
            Q.add(new Tribe());
        }
        class Wall {
            int data[] = new int[80000];

            boolean attack(Tribe tr) {
                debugln("Attack " + (1+tr.i) + " "  + tr.currDay + "  W=" + tr.w + " E=" + tr.e + " S=" + tr.s + " M=" + tr.move + " N=" + tr.n);
                for (int i = tr.w * 2; i <= tr.e * 2; i++) {
                    if (data[i + 40000] < tr.s) {
                        debugln("SUCC");
                        return true;
                    }
                }
                debugln("FAIL");
                return false;
            }

            public void recover(Tribe tr) {
                for (int i = tr.w * 2; i <= tr.e * 2; i++) {
                    data[i + 40000] = Math.max(data[i + 40000], tr.s);
                }
            }
        }
        Wall wall = new Wall();
        int succ = 0;
        while (!Q.isEmpty()) {
            int day = -1;
            List<Tribe> dayTribes = new ArrayList<Tribe>();
            while (!Q.isEmpty()) {
                if (day == -1 || Q.peek().currDay == day) {
                    Tribe tr = Q.poll();
                    day = tr.currDay;
                    dayTribes.add(tr);
                } else {
                    break;
                }
            }
            for (Tribe tr : dayTribes) {
                if (wall.attack(tr)) {
                    succ++;
                }
            }
            for (Tribe tr : dayTribes) {
                wall.recover(tr);
            }

            for (Tribe tr : dayTribes) {
                if (tr.nextMove()) {
                    Q.add(tr);
                }
            }
        }
        out.println(succ);
        debugln("----");
    }

    private void solveNTests() throws IOException {
        nextLine();
        int nt = readInt();
        for (int t = 1; t <= nt; t++) {
            out.print("Case #" + t + ": ");
            solveTest();
        }
    }

    private String readLine() throws IOException {return in.readLine();}
    private void nextLine() throws IOException {tok = new StringTokenizer(readLine());}

    private String read() {return tok.nextToken();}
    private int readInt() {return Integer.parseInt(read());}
    private long readLong() {return Long.parseLong(read());}
    private double readDouble() {return Double.parseDouble(read());}

    private void debug(Object fmt, Object ...args) {
        if (!DEBUG_OUT) return;
        System.out.print(String.format(fmt.toString(), args));
    }
    private void debugln(Object fmt, Object ...args) {
        if (!DEBUG_OUT) return;
        System.out.println(String.format(fmt.toString(), args));
    }
    private void debugln() {
        if (!DEBUG_OUT) return;
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        new TheGreatWall().mainRun();
    }

    private void mainRun() {
        openFiles();
        solveNTestsAndCloseFiles();
        outputOutput();
    }

    private void openFiles() {
        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)), true);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }


    private void solveNTestsAndCloseFiles() {
        try {
            solveNTests();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        } finally {
            out.close();
            try {
                in.close();
            } catch (IOException e) {
                System.out.println(e);
                System.exit(1);
            }
        }
    }

    public String test(String input) {
        StringWriter resultOut = new StringWriter();
        in = new BufferedReader(new StringReader(input));
        out = new PrintWriter(resultOut);
        solveNTestsAndCloseFiles();
        return resultOut.getBuffer().toString().trim();
    }

    public String testOne(String input) {
        StringWriter resultOut = new StringWriter();
        in = new BufferedReader(new StringReader(input));
        out = new PrintWriter(resultOut);
        try {
            solveTest();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            out.close();
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return resultOut.getBuffer().toString().trim();
    }

    private void outputOutput() {
        try {
            FileInputStream input = new FileInputStream(outFile);
            byte []buf = new byte[1024];
            int r;
            while ((r = input.read(buf)) != -1) {
                System.out.write(buf, 0, r);
            }
            input.close();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }

    static class Test1 {
        public static void main(String[] args) {
            System.out.println(new TheGreatWall().testOne("INPUT"));
        }
    }
}
