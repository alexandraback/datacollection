package oneb;

import java.util.*;

public class QuestionC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        for (int numTest = 0; numTest < numTests; numTest++) {
            int numJackets = sc.nextInt();
            int numPants = sc.nextInt();
            int numShirts = sc.nextInt();
            int maxRepeat = sc.nextInt();
            String answer = solve(numJackets, numPants, numShirts, maxRepeat);
            System.out.format("Case #%d: %s", numTest + 1, answer);
        }
    }

    private static String solve(int numJackets, int numPants, int numShirts, int maxRepeat) {
        int numOutfits = 0;
        StringBuilder answer = new StringBuilder();
        Map<Pair, Integer> jacketPantsCounts = new HashMap<>();
        Map<Pair, Integer> jacketShirtsCounts = new HashMap<>();
        Map<Pair, Integer> pantShirtsCounts = new HashMap<>();
        Set<Pair> pantShirtPairs = new HashSet<>();
        for (int numPant = 1; numPant <= numPants; numPant++) {
            for (int numShirt = 1; numShirt <= numShirts; numShirt++) {
                Pair pantShirt = new Pair(numPant, numShirt);
                pantShirtPairs.add(pantShirt);
            }
        }
        for (Pair pantShirtPair : pantShirtPairs) {
            int numPant = pantShirtPair.first;
            int numShirt = pantShirtPair.second;
            for (int numJacket = 1; numJacket <= numJackets; numJacket++) {
                Pair jacketPant = new Pair(numJacket, numPant);
                Pair jacketShirt = new Pair(numJacket, numShirt);
                Pair pantShirt = new Pair(numPant, numShirt);
                if (jacketPantsCounts.containsKey(jacketPant) && jacketPantsCounts.get(jacketPant) == maxRepeat) {
                    continue;
                }
                if (jacketShirtsCounts.containsKey(jacketShirt) && jacketShirtsCounts.get(jacketShirt) == maxRepeat) {
                    continue;
                }
                if (pantShirtsCounts.containsKey(pantShirt) && pantShirtsCounts.get(pantShirt) == maxRepeat) {
                    continue;
                }

                numOutfits++;
                answer.append(numJacket);
                answer.append(" ");
                answer.append(numPant);
                answer.append(" ");
                answer.append(numShirt);
                answer.append("\n");
                if (!jacketPantsCounts.containsKey(jacketPant)) {
                    jacketPantsCounts.put(jacketPant, 1);
                } else {
                    jacketPantsCounts.put(jacketPant, jacketPantsCounts.get(jacketPant) + 1);
                }
                if (!jacketShirtsCounts.containsKey(jacketShirt)) {
                    jacketShirtsCounts.put(jacketShirt, 1);
                } else {
                    jacketShirtsCounts.put(jacketShirt, jacketShirtsCounts.get(jacketShirt) + 1);
                }
                if (!pantShirtsCounts.containsKey(pantShirt)) {
                    pantShirtsCounts.put(pantShirt, 1);
                } else {
                    pantShirtsCounts.put(pantShirt, pantShirtsCounts.get(pantShirt) + 1);
                }
            }
        }
        return String.format("%d%n%s", numOutfits, answer.toString());
    }

    private static class Pair {
        final int first;
        final int second;

        private Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            if (first != pair.first) {
                return false;
            }
            return second == pair.second;

        }

        @Override
        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }
    }
}
