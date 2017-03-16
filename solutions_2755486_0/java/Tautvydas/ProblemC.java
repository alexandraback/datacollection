import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * User: Tautvydas
 * Date: 5/12/13
 */
public class ProblemC {
    private BufferedWriter bw;

    public static void main(String args[]) throws IOException {
        System.out.println("Program start - Google code jam 2013 - round 1B");

        ProblemC round = new ProblemC();
        round.openToWrite("Round1C/C-small-attempt0.out");
        round.readFile("Round1C/C-small-attempt0.in");
        round.bw.close();

    }

    public void readFile(String filename) throws IOException{

        BufferedReader br = new BufferedReader(new FileReader(filename));
        try {
            String line = br.readLine();
            int caseCount = Integer.parseInt(line);
            System.out.println("case count: " + caseCount);
            int caseNo = 0;

            while (line != null) {
                caseNo++;
                //each case
                line = br.readLine();
                if (line == null){
                    break;
                }
                int minW = Integer.MAX_VALUE;
                int maxE = Integer.MIN_VALUE;
                int attackCount = Integer.parseInt(line);
                List<Attack> attacks = new ArrayList<Attack>();
                for (int i = 0; i < attackCount; i++) {
                    line = br.readLine();
                    final String[] numbers = line.split(" ");
                    Tribe tribe = new Tribe(numbers);
                    attacks.addAll(tribe.getAttacks());
                    minW = Math.min(minW, tribe.getMinW());
                    maxE = Math.max(maxE, tribe.getMaxE());
                }

                int ans = solve(attacks, minW, maxE);

                System.out.println("case #" + caseNo + ", breaches: " + ans + " <---------------");
                write(caseNo, ans);

            }
        } finally {
            br.close();
        }
    }

    private int solve(List<Attack> attacks, int minW, int maxE) {
        Collections.sort(attacks);

        int breaches = 0;

        Wall wall = new Wall(minW, maxE);

        int i = 0;
        while (i < attacks.size()) {
            List<Attack> onDayAttacks = new ArrayList<Attack>();
            int day = attacks.get(i).day;

            while (i < attacks.size() && attacks.get(i).day == day) {
                onDayAttacks.add(attacks.get(i));
                i++;
            }
//            System.out.println("attack with " + onDayAttacks.size());
            breaches += wall.attack(onDayAttacks);
//            System.out.println("attack breached: "+breaches);
        }
//        System.out.println("i value:" + i);
        return breaches;
    }




    private void openToWrite(String filename) {

        try {
            File file = new File(filename);

            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            bw = new BufferedWriter(fw);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void write(int caseNr, int result){
        try {
            bw.write("Case #" + caseNr + ": " + result);
            bw.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private class Wall  {

        int [] wall;
        int offset;

        public Wall(int minW, int maxE) {
            int size = maxE - minW + 2;
            size *= 2;
            wall = new int[size];
            offset = -minW;

            for (int i = 0; i < wall.length; i++) {
                wall[i] = 0;
            }
        }

        public int attack(List<Attack> attacks) {
            int breaches = 0;
            for (Attack attack : attacks) {
                breaches += attack(attack);
            }
            for (Attack attack : attacks) {
                reinforce(attack);
            }
            return breaches;
        }

        private int attack(Attack attack) {
            int start = attack.w + offset;
            start *= 2;
            int end = attack.e + offset;
            end *= 2;
            int s = attack.strength;
//            System.out.println(attack);
            for (int i = start; i <= end; i++) {
//                System.out.println("Wall: [" + i+ "] -> " + wall[i]);
                if (wall[i] < s)
                    return 1;
            }
            return 0;
        }

        private void reinforce(Attack attack) {
            int start = attack.w + offset;
            start *= 2;
            int end = attack.e + offset;
            end *= 2;
            int s = attack.strength;
            for (int i = start; i <= end; i++) {
                if (wall[i] < s)
                    wall[i] = s;
            }
//            System.out.print("reinforce wall: ");
//            for (int i : wall) {
//                System.out.print(i + ", ");
//            }
//            System.out.println();
        }
    }

    private class Tribe {

        int firstAttack, numberOfAttacks;
        int w, e; //coordinates of first attack
        int s;
        int attackInterval;
        int move;
        int deltaS;

        private Tribe(int firstAttack, int numberOfAttacks, int w, int e, int s, int attackInterval, int move, int deltaS) {
            this.firstAttack = firstAttack;
            this.numberOfAttacks = numberOfAttacks;
            this.w = w;
            this.e = e;
            this.s = s;
            this.attackInterval = attackInterval;
            this.move = move;
            this.deltaS = deltaS;
        }

        private Tribe(String[] numbers) {
            this(Integer.parseInt(numbers[0]),
                    Integer.parseInt(numbers[1]),
                    Integer.parseInt(numbers[2]),
                    Integer.parseInt(numbers[3]),
                    Integer.parseInt(numbers[4]),
                    Integer.parseInt(numbers[5]),
                    Integer.parseInt(numbers[6]),
                    Integer.parseInt(numbers[7]));
        }

        public List<Attack> getAttacks() {
            List<Attack> list = new ArrayList<Attack>(numberOfAttacks);
            for (int i = 0; i < numberOfAttacks; i++) {
                int day = firstAttack + i*attackInterval;
                int strength = s + i*deltaS;
                int east = e + i*move;
                int west = w + i*move;
                Attack attack = new Attack(day, strength, west, east);
                list.add(attack);
            }
            return list;
        }

        public int getMinW() {
            return Math.min(w, w+numberOfAttacks*move);
        }
        public int getMaxE() {
            return Math.max(e, e+numberOfAttacks*move);
        }

    }

    private class Attack implements Comparable<Attack>{
        int day, strength, w, e;

        private Attack(int day, int strength, int w, int e) {
            this.day = day;
            this.strength = strength;
            this.w = w;
            this.e = e;
        }

        @Override
        public int compareTo(Attack o) {
            return new Integer(day).compareTo(o.day);
        }

        @Override
        public String toString() {
            return "Attack{" +
                    "day=" + day +
                    ", strength=" + strength +
                    ", w=" + w +
                    ", e=" + e +
                    '}';
        }
    }
}
