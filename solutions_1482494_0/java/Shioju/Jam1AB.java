import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Jam1AB {

    static final String TASK_ID = "jam1ab";
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
        private int N;
        private int[] a,b;
        private boolean[] star1, star2;
        String result;

        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            int star = 0;
            int play=0;
            boolean up = true;
            boolean progress = true;

            if (testId==4)
                System.out.println();
            
            while (progress) {
                progress = false;
                up=true;
                while (up) {   //keep beating 2 stars first
                    up = false;
                    for (int i=0;i<N; i++) {  //find 2-stars to beat
                        if (star2[i]) {  //try to beat 2 star
                            if (star>=b[i]) { //beat 2 star
                                if (star1[i]) {  //not beat level 1 before
                                    star+=2;
                                    star1[i]=false;
                                    star2[i]=false;
                                } else {
                                    star+=1;
                                    star2[i]=false;
                                }
                                play++;
                                up=true;
                                progress=true;
                            }
                        }
                    }
                }

                for (int i=0;i<N; i++) {  //find 1-stars to beat
                    if (star1[i]) {  //try to beat 1 star
                        if (star>=a[i]) { //beat 1 star
                            star+=1;
                            star1[i]=false;
                            play++;
                            progress=true;
                            break;
                        }
                    }
                }
            }

            if (star<2*N) {
                result = "Too Bad";
            } else {
                result = play+ "";
            }
        }

        private void readInput() {
            try {
                String line = reader.readLine();
                StringTokenizer st;
                N = Integer.parseInt(line);
                a = new int[N];
                b = new int[N];
                star1 = new boolean[N];
                star2 = new boolean[N];
                
                for (int i=0; i<N; i++) {
                    line = reader.readLine();
                    st = new StringTokenizer(line);
                    a[i] = Integer.parseInt(st.nextToken());
                    b[i] = Integer.parseInt(st.nextToken());
                    star1[i]=true;
                    star2[i]=true;
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
