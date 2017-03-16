
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Li9htmare
 */
public class ProblemC {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("C-small-1-attempt0.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int caseCount = Integer.parseInt(in.readLine());

        resultBuilder.append("Case #1:\n");
        for (int caseI = 1; caseI <= caseCount; caseI++) {
            String[] tokens = in.readLine().split(" ");
            int R = Integer.parseInt(tokens[0]);
            int N = Integer.parseInt(tokens[1]);
            int M = Integer.parseInt(tokens[2]);
            int K = Integer.parseInt(tokens[3]);

            for (int i = 0; i < R; i++) {
                int[] count = new int[6];
                tokens = in.readLine().split(" ");
                for (int j = 0; j < K; j++) {
                    int n = Integer.parseInt(tokens[j]);
                    int[] tempCount = count.clone();
                    while (n % 2 == 0) {
                        n = n / 2;
                        if (tempCount[2] > 0) {
                            tempCount[2]--;
                        } else {
                            count[2]++;
                        }
                    }
                    while (n % 3 == 0) {
                        n = n / 3;
                        if (tempCount[3] > 0) {
                            tempCount[3]--;
                        } else {
                            count[3]++;
                        }
                    }
                    while (n % 5 == 0) {
                        n = n / 5;
                        if (tempCount[5] > 0) {
                            tempCount[5]--;
                        } else {
                            count[5]++;
                        }
                    }
                }

                int total = count[2] + count[3] + count[5];

                for (int k = 0; k <= total - N; k++) {
                    if (count[2] >= 2) {
                        count[4]++;
                        count[2] -= 2;
                    }
                }
                
                total = count[2] + count[3] + count[4] +count[5];
                
                for (int k = 0; k < N - total; k++) {
                    count[((int) (Math.random() * 4)) + 2]++;
                }

                for (int k = 2; k <= 5; k++) {
                    for (int j = 0; j < count[k]; j++) {
                        resultBuilder.append(k);
                    }
                }
                resultBuilder.append("\n");
            }

        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }

    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("result.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
