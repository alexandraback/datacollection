import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QC {

    static final String TASK_ID = "qc";
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
        private int result;

        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            int digit = (int) Math.log10(A) + 1;
            int div=1;
            int pow = (int) Math.pow(10,digit);

            //System.out.println("=============== A="+A+"  B="+B+"  ====================");
            for (int n=A; n<=B; n++) {
                int div2 = div;
                int pow2 = pow;
                int[] matches = new int[digit-1];
                int count = 0;
                for (int j=1; j<digit; j++) {
                    div2*=10;
                    pow2/=10;
                    int m = (n % div2) * pow2 + n / div2; //shift last digit to front
                    if (n<m && m<=B) {
                        boolean exists = false;
                        for (int k=0; k<count; k++) {
                            if (matches[k]==m) {
                                exists=true;
                                break;
                            }
                        }
                        if (!exists) {
                            result++;
                            //System.out.println("("+n+" , "+m+")");
                            matches[count++]=m;
                        }
                    }
                }
            }
            System.out.println(result);
        }

        private void readInput() {
            try {
                String line = reader.readLine();
                StringTokenizer st = new StringTokenizer(line);
                A = Integer.parseInt(st.nextToken());
                B = Integer.parseInt(st.nextToken());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void printOutput() {
            writer.println("Case #"+(testId+1)+": "+ result);
        }
    }
}
