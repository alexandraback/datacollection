import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QB {

    static final String TASK_ID = "qb";
    static BufferedReader reader;
    static PrintWriter writer;

    public static void main(String[] args) {
        try {
            long now = System.currentTimeMillis();
            reader = new BufferedReader(new FileReader(TASK_ID + ".in"));
            writer = new PrintWriter(TASK_ID + ".out");

            int numTests = Integer.parseInt(reader.readLine());

            for (int testId = 0; testId < numTests; testId++) {
                Solver solver = new Solver(testId);
                solver.readInput();
                solver.run();
                solver.printOutput();
            }

            reader.close();
            writer.close();
            System.out.println(System.currentTimeMillis() - now + "ms");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    static class Solver {

        private int testId;
        private int N, S, p;
        private int[] t;
        private int result;

        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            int normalOK = 3*p-2;
            int surprisingOK = 3*p-4;
            //if p=0, all dancers will pass
            //if p=1, normalOK=1, only zero will fail, so set surprisingOK so that no one will pass
            if (p==1) surprisingOK=99;

            for (int i=0; i<N; i++) {


                if (t[i]>=normalOK) {
                    result++;
                } else if (S>0 && t[i]>=surprisingOK) {
                    S--; //one less surprise to use
                    result++;
                }
            }
        }

        private void readInput() {
            try {
                String line = reader.readLine();
                StringTokenizer st = new StringTokenizer(line);                
                N = Integer.parseInt(st.nextToken());
                S = Integer.parseInt(st.nextToken());
                p = Integer.parseInt(st.nextToken());
                t = new int[N];
                for (int i=0; i<N; i++) {
                    t[i] = Integer.parseInt(st.nextToken());
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void printOutput() {
            writer.println("Case #"+(testId+1)+": "+ result);
        }
    }
}
