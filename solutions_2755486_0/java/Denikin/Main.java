import com.sun.xml.internal.fastinfoset.util.FixedEntryStringIntMap;

import java.io.FileInputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static final String EXAMPLE_INPUT = "example.txt";
    static final String SMALL_INPUT = "C-small-attempt0.in";
    static final String LARGE_INPUT = "A-large.in";
    static final String OUTPUT = "output.txt";

    public static void main(String[] args) throws Exception {
        startProcessing();
    }

    static void startProcessing() throws Exception {
        try(FileInputStream stream = new FileInputStream(SMALL_INPUT);
            Scanner scanner = new Scanner(stream);
            PrintWriter writer = new PrintWriter(OUTPUT))
        {
            int T = Integer.valueOf(scanner.nextLine());
            for (int caseNum = 1; caseNum <= T; ++caseNum) {
                long caseRes = solveCase(scanner);
                writer.println("Case #" + caseNum + ": " + caseRes);
            }
        }
    }

    static long solveCase(Scanner scanner) {
        SortedMap<Integer, List<Attack>> attacks = new TreeMap<>();
        int N = scanner.nextInt();
        for (int tribeIndex = 0; tribeIndex < N; ++tribeIndex) {
            int firstDay = scanner.nextInt();
            int attacksNum = scanner.nextInt();
            int westFirst = scanner.nextInt();
            int eastFirst = scanner.nextInt();
            int strengthFirst = scanner.nextInt();
            int deltaDays = scanner.nextInt();
            int deltaDist = scanner.nextInt();
            int deltaStrength = scanner.nextInt();
            Tribe aTribe = new Tribe(firstDay,attacksNum,westFirst,eastFirst,strengthFirst,deltaDays,deltaDist,deltaStrength);
            aTribe.addAttacks(attacks);
        }
        return simulateAttacks(attacks);
    }

    static long simulateAttacks(SortedMap<Integer, List<Attack>> attacks) {
        int[] wall = new int[401*2];
        for (int ind = 0; ind < wall.length; ++ind) {
            wall[ind] = 0;
        }

        long attacksPassed = 0;

        Set<Integer> days = attacks.keySet();
        for (Integer day : days) {
            List<Attack> list = attacks.get(day);
            // Check passed:
            for (Attack attack : list) {
                int west = (attack.westEnd + 200)*2;
                int east = (attack.eastEnd + 200)*2;
                for (int ind = west; ind <= east; ++ind) {
                    if (wall[ind] < attack.stren) {
                        ++attacksPassed;
                        break;
                    }
                }
            }

            // Build wall:
            for (Attack attack : list) {
                int west = (attack.westEnd + 200)*2;
                int east = (attack.eastEnd + 200)*2;
                for (int ind = west; ind <= east; ++ind) {
                    if (wall[ind] < attack.stren) {
                        wall[ind] = attack.stren;
                    }
                }
            }
        }

        return attacksPassed;
    }


    private static class Attack {
        int day;
        int westEnd;
        int eastEnd;
        int stren;

        private Attack(int day, int westEnd, int eastEnd, int stren) {
            this.day = day;
            this.westEnd = westEnd;
            this.eastEnd = eastEnd;
            this.stren = stren;
        }
    }


    private static class Tribe {
        int firstDay;
        int attacksNum;
        int westFirst;
        int eastFirst;
        int strengthFirst;
        int deltaDays;
        int deltaDist;
        int deltaStrength;

        private Tribe(int firstDay, int attacksNum, int westFirst, int eastFirst, int strengthFirst, int deltaDays, int deltaDist, int deltaStrength) {
            this.firstDay = firstDay;
            this.attacksNum = attacksNum;
            this.westFirst = westFirst;
            this.eastFirst = eastFirst;
            this.strengthFirst = strengthFirst;
            this.deltaDays = deltaDays;
            this.deltaDist = deltaDist;
            this.deltaStrength = deltaStrength;
        }

        public void addAttacks(SortedMap<Integer, List<Attack>> attacks) {
            int day = firstDay;
            int westEnd = westFirst;
            int eastEnd = eastFirst;
            int strength = strengthFirst;
            for (int attInd = 0; attInd < attacksNum; ++attInd) {
                Attack nextAttack = new Attack(day, westEnd, eastEnd, strength);
                if (attacks.containsKey(day)) {
                    List<Attack> list = attacks.get(day);
                    list.add(nextAttack);
                } else {
                    List<Attack> list = new ArrayList<>();
                    list.add(nextAttack);
                    attacks.put(day, list);
                }

                day += deltaDays;
                westEnd += deltaDist;
                eastEnd += deltaDist;
                strength += deltaStrength;
            }
        }
    }
}

