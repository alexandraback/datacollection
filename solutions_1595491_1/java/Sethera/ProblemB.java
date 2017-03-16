
import java.io.*;
import java.util.*;

/**
 *
 * @author Hilos
 */
public class ProblemB {

    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {
            String filename = "B-large";
            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));

            int caseCount = Integer.parseInt(br.readLine());

            for (int c = 0; c < caseCount; c++) {
                String[] lineParts = br.readLine().split(" ");

                int N = Integer.parseInt(lineParts[0]);
                int S = Integer.parseInt(lineParts[1]);
                int p = Integer.parseInt(lineParts[2]);

                int[] scores = new int[N];

                for (int s = 0; s < N; s++) {
                    scores[s] = Integer.parseInt(lineParts[3 + s]);
                }

                SolveCase(c + 1, N, S, p, scores);
            }


        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }

    public static void SolveCase(int caseNumber, int N, int S, int p, int[] scores) throws Exception {

        int aboveOrEqual = 0;
        int surprisingLeft = S;

        int scoreCount = scores.length;
        for (int s = 0; s < scoreCount; s++) {
            int score = scores[s];

            if(score == 0){
                if(p == 0){
                    aboveOrEqual++;   
                }
            }else  if (score % 3 == 1) {
                if ((score + 2) / 3 >= p) {
                    aboveOrEqual++;
                }
            } else if (score % 3 == 0) {
                if ((score / 3) >= p) {
                    aboveOrEqual++;
                } else if (surprisingLeft > 0 && (score / 3) + 1 >= p) {
                    aboveOrEqual++;
                    surprisingLeft--;
                }
            } else if (score % 3 == 2) {
                if (((score + 1) / 3) >= p) {
                    aboveOrEqual++;
                } else if (surprisingLeft > 0 && ((score + 1) / 3) + 1 >= p) {
                    aboveOrEqual++;
                    surprisingLeft--;
                }
            }
        }

        bw.write("Case #" + caseNumber + ": " + aboveOrEqual + "\n");
        bw.flush();
    }
}
