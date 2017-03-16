import java.io.*;
import java.util.*;

/**
 * @author Kazuki Nishiura
 */
public class TheGreatWallSmall {

    // debug flags
    private static final boolean debug = true;

    public static void main(String[] args) {
        PrintWriter writer = createWriter("c-small");
        Scanner scanner = createScanner("C-small-attempt0.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int testCaseNo = 1; testCaseNo <= numOfTestCase; testCaseNo++) {
            int numOfTribes = scanner.nextInt();
            Solver solver = new Solver(numOfTribes);
            for (int tribe = 0; tribe < numOfTribes; tribe++) {
                solver.addTribe(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
            }
            writer.print("Case #" + testCaseNo + ": " + solver.solve());
            writer.println();
        }
        writer.close();
    }

    static class Solver {
        private int[] firstDays;
        private int[] numOfAttacks;
        private int[] attackIndecies;
        private int[] startWest, startEast;
        private int[] initialStrength;
        private int[] deltaDay;
        private int[] deltaDistance;
        private int[] deltaStrength;
        private int tribeIndex = 0;
        private int numOfTribes = 0;
        private int[] wall = new int[10000];
        private int origin = wall.length / 2;

        public Solver(int numOfTribes) {
            this.numOfTribes = numOfTribes;
            firstDays = new int[numOfTribes];
            numOfAttacks = new int[numOfTribes];
            attackIndecies = new int[numOfTribes];
            Arrays.fill(attackIndecies, 0);
            Arrays.fill(wall, 0);
            startWest = new int[numOfTribes];
            startEast = new int[numOfTribes];
            initialStrength = new int[numOfTribes];
            deltaDay = new int[numOfTribes];
            deltaDistance = new int[numOfTribes];
            deltaStrength = new int[numOfTribes];
        }

        public void addTribe(int firstDay_, int numOfAttack_, int startWest_,
                             int startEast_, int initialStrength_, int deltaDay_,
                             int deltaDistance_, int deltaStrength_) {
            firstDays[tribeIndex] = firstDay_;
            numOfAttacks[tribeIndex] = numOfAttack_;
            startWest[tribeIndex]= startWest_;
            startEast[tribeIndex] = startEast_;
            initialStrength[tribeIndex] = initialStrength_;
            deltaDay[tribeIndex] = deltaDay_;
            deltaDistance[tribeIndex] = deltaDistance_;
            deltaStrength[tribeIndex] = deltaStrength_;
            tribeIndex++;
        }

        public int solve() {
            int numOfSucceedAttack = 0;
            SetMultiMap<Integer, Integer> attackers =
                    new SetMultiMap<Integer, Integer>();
            for (int i = 0; i < numOfTribes; i++) {
                attackers.add(firstDays[i], i);
            }

            while (attackers.size() != 0) {
                int attackDay = attackers.firstKey();
                Set<Integer> attackersOnTheDay
                        = attackers.get(attackDay);
                attackers.remove(attackDay);
                Set<SubWall> wallUpdates = new HashSet<SubWall>();
                for (Integer attacker: attackersOnTheDay) {
                    int attackIndex = attackIndecies[attacker];
                    int west = startWest[attacker] + attackIndex * deltaDistance[attacker];
                    int east = startEast[attacker] + attackIndex * deltaDistance[attacker];
                    int strength = initialStrength[attacker] + attackIndex * deltaStrength[attacker];
                    boolean attackSucceed = applyAttack(west, east, strength);
                   // System.out.println("day:" + attackDay + " [" + west + "," + east + "]" + " with " + strength + " -> " + attackSucceed);
                    if (applyAttack(west, east, strength)) {
                        SubWall subWall = new SubWall();
                        subWall.start = west; subWall.end = east; subWall.strength = strength;
                        wallUpdates.add(subWall);
                        numOfSucceedAttack++;
                    }

                    // prepare next attack
                    attackIndex++;
                    if (attackIndex < numOfAttacks[attacker]) {
                        int nextAttackDays = firstDays[attacker] + attackIndex * deltaDay[attacker];
                        attackers.add(nextAttackDays, attacker);
                        attackIndecies[attacker] = attackIndex;
                    }
                }

                for (SubWall update: wallUpdates) {
                    for (int x = update.start; x < update.end; x++) {
                        if (wall[x + origin] < update.strength) {
                            wall[x + origin] = update.strength;
                        }
                    }
                }
            }

            return numOfSucceedAttack;
        }

        private boolean applyAttack(int west, int east, int strength) {
            for (int i = west; i < east; i++) {
                if (wall[i + origin] < strength)
                    return true;
            }
            return false;
        }
    }

    private static  class SubWall implements Comparable {
        public int start;
        public int end;
        public int strength;

        @Override
        public int compareTo(Object o) {
            return start - ((SubWall) o).start;
        }


        @Override
        public int hashCode() {
            return start;
        }

        @Override
        public boolean equals(Object obj) {
            return start == ((SubWall) obj).start;
        }
    }

    // Collections utils
    static class SetMultiMap<K, V> extends TreeMap<K, Set<V>> {
        public void add(K key, V value) {
            if (containsKey(key)) {
                get(key).add(value);
            } else {
                Set<V> set = new HashSet<V>();
                set.add(value);
                put(key, set);
            }
        }
    }

    static class ListMultiMap<K, V> extends TreeMap<K, List<V>> {
        public void add(K key, V value) {
            if (containsKey(key)) {
                get(key).add(value);
            } else {
                List<V> list = new ArrayList<V>();
                list.add(value);
                put(key, list);
            }
        }
    }

    static class Counter<K> extends HashMap<K, Integer> {
        public void addCount(K key) {
            if (containsKey(key)) {
                int currentCount = get(key);
                put(key, currentCount + 1);
            } else {
                put(key, 1);
            }
        }
    }

    static private void debugOut(Object o) {
        if (debug) {
            System.out.println(o);
        }
    }

    // IO Utils
    static private PrintWriter createWriter() {
        return createWriter(null);
    }

    static private PrintWriter createWriter(String fileNameSuffix) {
        if (fileNameSuffix == null) {
            return new PrintWriter(System.out);
        } else {
            try {
                return new PrintWriter(new BufferedWriter((new FileWriter(
                        new File("output_" + fileNameSuffix + ".txt")))));
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
        }
    }

    static private Scanner createScanner() {
        return createScanner(null);
    }

    static private Scanner createScanner(String fileName) {
        if (fileName == null) {
            return new Scanner(System.in);
        } else {
            File inFile = new File(fileName);
            try {
                return new Scanner(inFile);
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
        }
    }
}
