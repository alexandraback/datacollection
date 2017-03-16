import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B {

    public static void main(String[] args) throws Throwable {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            System.out.println("Case #" + c + ": " + solveCase(reader.readLine()));
        }
    }

    private static int solveCase(String line) {
        String[] tokens = line.split(" ");
        int numGooglers = Integer.parseInt(tokens[0]);
        int surprisingTriplets = Integer.parseInt(tokens[1]);
        int p = Integer.parseInt(tokens[2]);
        int[] results = new int[numGooglers];
        for (int i = 0; i < numGooglers; i++) {
            results[i] = Integer.parseInt(tokens[i + 3]);
        }

        int num = 0;

        for (int i = 0; i < numGooglers; i++) {
            int res = results[i];
            int lowestScore = res / 3;
            int highestScore = lowestScore;
            int remainder = res - lowestScore * 3;
            if (remainder > 0) {
                highestScore++;
            }
            if (highestScore >= p) {
                num++;
            } else if (surprisingTriplets > 0) {
                switch (remainder) {
                case 0: // 222 -> 123
                    if (lowestScore > 0 && highestScore + 1 >= p) {
                        num++;
                        surprisingTriplets--;
                    }
                    break;
                case 1: // 223 -> 133
                    if (lowestScore > 0 && highestScore >= p) {
                        num++;
                        surprisingTriplets--;
                    }
                    break;
                case 2: // 233 -> 224
                    if (highestScore + 1 >= p) {
                        num++;
                        surprisingTriplets--;
                    }
                    break;
                }
            }
        }
        return num;
    }
}
