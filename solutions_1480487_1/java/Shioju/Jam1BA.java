import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Jam1BA {

    static final String TASK_ID = "jam1ba";
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
        private int N, total, lower;
        private int[] scores;
        private double[] result;



        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            double average = total * 2.0 / N;
            double losertotal = 0;
            result = new double[N];
            lower =0;
            for (int j=0; j<N; j++) {
                if (scores[j]<average) {
                    lower++;
                    losertotal+=scores[j];
                }
            }

            double passing = (total + losertotal) / lower;

            for (int i=0; i<N; i++) {
                if (scores[i]>=passing) {
                    result[i]=0;
                } else {
                    result[i] = (passing - scores[i])/total*100;
                }
            }
        }

        private void readInput() {
            try {
                String line = reader.readLine();
                StringTokenizer st = new StringTokenizer(line);
                N = Integer.parseInt(st.nextToken());
                scores = new int[N];
                total =0;
                for (int i=0; i<N; i++) {
                    scores[i]=Integer.parseInt(st.nextToken());
                    total+=scores[i];
                }

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void printOutput() {
            writer.print("Case #"+(testId+1)+": ");
            for (int i=0; i<N; i++)
                if (i==N-1) {
                    writer.println(result[i]);
                } else {
                    writer.print(result[i]+" ");
                }
        }
    }
}
