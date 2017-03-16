import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Math.abs;
import static java.lang.Math.max;

public class DancingWithGooglers {

    public static void main(String[] args) throws IOException {
        new DancingWithGooglers().solveAll();
    }

    BufferedReader reader;

    int T;

    private void solveAll() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(reader.readLine());
        for (int i = 0; i < T; i++) {
            solve(i + 1);
        }
    }

    private void solve(int caseNumber) throws IOException {
        String line = reader.readLine();
        String[] strings = line.split(" ");
        int N = Integer.parseInt(strings[0]);
        int S = Integer.parseInt(strings[1]);
        int P = Integer.parseInt(strings[2]);
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            scores[i] = Integer.parseInt(strings[3 + i]);
        }

        Triplet[] bestTriplets = new Triplet[N];
        Triplet[] bestSurprisingTriplets = new Triplet[N];

        for (int i = 0; i < N; i++) {
            //System.out.println("Score: " + scores[i]);
            bestTriplets[i] = findBestTriplet(scores[i]);
            bestSurprisingTriplets[i] = findBestSurprisingTriplet(scores[i]);
            //System.out.println(bestTriplets[i] + " - " + "*" + bestSurprisingTriplets[i]);
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            if (bestTriplets[i].scores[0] >= P) {
                result++;
            }
        }
        int usedSurprising = 0;
        for (int i = 0; i < N; i++) {
            if (bestSurprisingTriplets[i].scores[0] >= P
                    && bestTriplets[i].scores[0] < P
                    && usedSurprising < S) {
                result++;
                usedSurprising++;
            }
        }

        System.out.println("Case #" + caseNumber + ": " + result);
    }

    private Triplet findBestTriplet(int score) {
        for (int i = 10; i >= 0; i--) {
            for (int j = i; j >= max(i - 1, 0); j--) {
                for (int k = j; k >= max(j - 1, 0); k--) {
                    if (i + j + k == score && i - k <= 1) {
                        return new Triplet(i, j, k);
                    }
                }
            }
        }
        return null;
    }

    private Triplet findBestSurprisingTriplet(int score) {
        for (int i = 10; i >= 0; i--) {
            for (int j = i; j >= max(i - 2, 0); j--) {
                for (int k = j; k >= max(j - 2, 0); k--) {
                    if (i + j + k == score && i - k <= 2) {
                        return new Triplet(i, j, k);
                    }
                }
            }
        }
        return null;
    }

    class Triplet {
        int[] scores;

        public Triplet(int s1, int s2, int s3) {
            scores = new int[] {s1, s2, s3};
        }

        @Override
        public String toString() {
            return scores[0] + " " + scores[1] + " " + scores[2];
        }
    }

}
