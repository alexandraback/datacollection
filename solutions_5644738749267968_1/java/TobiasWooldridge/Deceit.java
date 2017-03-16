import java.util.*;

public class Deceit {
    public static class Solution {
        int numBlocks;
        List<Double> naomi;
        List<Double> ken;

        Solution() {
            this.naomi = naomi;
            this.ken = ken;
        }

        static int playWar(LinkedList<Double> naomi, LinkedList<Double> ken) {
            Collections.reverse(naomi);
            Collections.reverse(ken);

            int score = 0;

            while (!naomi.isEmpty()) {
                double naomiChoice = naomi.removeFirst();

                // Ken can't win
                if (naomiChoice > ken.getFirst()) {
                    ken.removeLast();
                    score++;
                } else {
                    Double kenChoice = ken.getFirst();
                    for (Double t : ken) {
                        if (t > naomiChoice) {
                            kenChoice = t;
                        } else {
                            break;
                        }
                    }
                    ken.removeFirstOccurrence(kenChoice);
                }
            }

            return score;
        }

        static int playDeceit(LinkedList<Double> naomi, LinkedList<Double> ken) {
            int score = 0;

            while (!naomi.isEmpty()) {
                double d = naomi.removeFirst();
                if (d > ken.getFirst()) {
                    score++;
                    ken.removeFirst();
                }
            }

            return score;
        }
    }

    public static void main(String[] args) {
        final Scanner in = new Scanner(System.in);
        final int testCases = in.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            int inBlocks = in.nextInt();

            List<Double> naomi = new ArrayList<Double>(inBlocks);
            for (int i = 0; i < inBlocks; i++) {
                naomi.add(in.nextDouble());
            }
            Collections.sort(naomi);

            List<Double> ken = new ArrayList<Double>(inBlocks);
            for (int i = 0; i < inBlocks; i++) {
                ken.add(in.nextDouble());
            }
            Collections.sort(ken);

            int warScore = Solution.playWar(new LinkedList<Double>(naomi), new LinkedList<Double>(ken));
            int deceitScore = Solution.playDeceit(new LinkedList<Double>(naomi), new LinkedList<Double>(ken));

            System.out.println("Case #" + testCase + ": " + deceitScore + " " + warScore);
        }
    }
}
