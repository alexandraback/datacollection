import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class B {

    static String[] answers;
    static AtomicInteger ready;

    static class Solver implements Runnable {

        int id;
        int x, y;
        String result;

        Solver(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }

        @Override
        public void run() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < x; i++) {
                sb.append("WE");
            }
            for (int i = x; i < 0; i++) {
                sb.append("EW");
            }
            for (int i = 0; i < y; i++) {
                sb.append("SN");
            }
            for (int i = y; i < 0; i++) {
                sb.append("NS");
            }
            result = sb.toString();
            answers[id] = result;
            ready.incrementAndGet();
            System.err.println(id + " ready " + result);
        }
    }

    void run() throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output_" + System.currentTimeMillis() + ".txt");
        ready = new AtomicInteger(0);
        int tests = in.nextInt();
        answers = new String[tests];
        Executor e = Executors.newFixedThreadPool(tests);
        for (int i = 0; i < tests; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            Solver s = new Solver(x, y, i);
            e.execute(s);
        }
        while (ready.get() < tests)
            ;
        for (int i = 0; i < tests; i++) {
            out.println("Case #" + (i+1) + ": " + answers[i]);
        }
        out.close();
        System.exit(0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }

    static Scanner in;
    static PrintWriter out;
}
