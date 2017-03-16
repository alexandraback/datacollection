import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Jam1AA {

    static final String TASK_ID = "jam1aa";
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
        private int A, B;
        private double[] pcorrect;
        private double result;

        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            //enter right away
            result = B+2;
            
            System.out.println("right away ="+result);

            //with backspaces
            double probYES=1;
            for (int back=A; back>=0; back--) {
                int left = A-back;
                int strokesYES = back+back+B-A+1;
                int strokesNO = strokesYES + B + 1;
                double expected = probYES * strokesYES + (1-probYES) * strokesNO;
                
                System.out.println("back "+back +" = "+expected);
                
                if (expected<result) result=expected;

                probYES*=pcorrect[left]; //prob for next iteration
            }

        }

        private void readInput() {
            try {
                String line = reader.readLine();
                StringTokenizer st = new StringTokenizer(line);
                A = Integer.parseInt(st.nextToken());
                B = Integer.parseInt(st.nextToken());

                line = reader.readLine();
                st = new StringTokenizer(line);
                pcorrect = new double[A+1]; //extra slot for the loop
                for (int i=0; i<A; i++) {
                    pcorrect[i] = Double.parseDouble(st.nextToken());
                }
                pcorrect[A]=1;  //extra slot for the loop

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void printOutput() {
            writer.println("Case #"+(testId+1)+": "+ result);
        }
    }
}
