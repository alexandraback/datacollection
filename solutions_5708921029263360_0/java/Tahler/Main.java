import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nTests = scanner.nextInt();
        for (int i = 0; i < nTests; i++) {
            int nJackets = scanner.nextInt();
            int nPants = scanner.nextInt();
            int nShirts = scanner.nextInt();
            int comboLimit = scanner.nextInt();

            OutfitSolver solver = new OutfitSolver(nJackets, nPants, nShirts, comboLimit);
            List<OutfitSolver.Outfit> outfits = solver.outfits();
            int days = outfits.size();
            System.out.println("Case #" + (i + 1) + ": " + days);
            for (OutfitSolver.Outfit outfit : outfits) {
                System.out.println(outfit);
            }
        }
    }

    private static class OutfitSolver {
        private Map<Combination, Integer> combos = new HashMap<>();
        private int nJackets;
        private int nPants;
        private int nShirts;
        private int comboLimit;

        public OutfitSolver(int nJackets, int nPants, int nShirts, int comboLimit) {
            this.nJackets = nJackets;
            this.nPants = nPants;
            this.nShirts = nShirts;
            this.comboLimit = comboLimit;
        }

        public int numberOfCombos() {
            return nJackets * nPants;
        }

        public int daysUntilJail() {
            return comboLimit * numberOfCombos();
        }

        public List<Outfit> outfits() {
            List<Outfit> allOutfits = new ArrayList<>();
            for (int j = 1; j <= nJackets; j++) {
                for (int k = 1; k <= nPants; k++) {
                    for (int l = 1; l <= nShirts; l++) {
                        allOutfits.add(new Outfit(j, k, l));
                    }
                }
            }
            List<Outfit> outfits = new ArrayList<>();
            for (Outfit outfit : allOutfits) {
                Combination jp = new Combination(outfit.jacket, outfit.pant, 0);
                Combination js = new Combination(outfit.jacket, 0, outfit.shirt);
                Combination ps = new Combination(0, outfit.pant, outfit.shirt);
                if (!combos.containsKey(jp)) {
                    combos.put(jp, 0);
                }
                if (!combos.containsKey(js)) {
                    combos.put(js, 0);
                }
                if (!combos.containsKey(ps)) {
                    combos.put(ps, 0);
                }
                int timesUsed = combos.get(jp) + combos.get(js) + combos.get(ps);

                if (timesUsed + 1 <= comboLimit) {
                    combos.put(jp, combos.get(jp) + 1);
                    combos.put(js, combos.get(js) + 1);
                    combos.put(ps, combos.get(ps) + 1);
                    outfits.add(outfit);
                }
            }
            return outfits;
        }

        private class Outfit {
            int jacket;
            int pant;
            int shirt;

            public Outfit(int jacket, int pant, int shirt) {
                this.jacket = jacket;
                this.pant = pant;
                this.shirt = shirt;
            }

            @Override
            public String toString() {
                return jacket + " " + pant + " " + shirt;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || this.getClass() != o.getClass()) return false;

                Outfit outfit = (Outfit) o;

                if (this.jacket != outfit.jacket) return false;
                if (this.pant != outfit.pant) return false;
                return this.shirt == outfit.shirt;
            }

            @Override
            public int hashCode() {
                int result = this.jacket;
                result = 31 * result + this.pant;
                result = 31 * result + this.shirt;
                return result;
            }
        }

        private class Combination {
            int jacket;
            int pant;
            int shirt;

            public Combination(int jacket, int pant, int shirt) {
                this.jacket = jacket;
                this.pant = pant;
                this.shirt = shirt;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || this.getClass() != o.getClass()) return false;

                Combination that = (Combination) o;

                if (this.jacket != that.jacket) return false;
                if (this.pant != that.pant) return false;
                return this.shirt == that.shirt;

            }

            @Override
            public int hashCode() {
                int result = this.jacket;
                result = 31 * result + this.pant;
                result = 31 * result + this.shirt;
                return result;
            }
        }
    }
}
