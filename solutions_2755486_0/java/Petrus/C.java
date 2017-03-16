package net.axisk.codejam.round1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class C {
    public static class Tribe {
        public int firstAttackDay;
        public int attacks;
        public int westPoint;
        public int eastPoint;
        public int strength;
        public int deltaDays;
        public int deltaMovement;
        public int deltraStrength;
    }

    public static class Attack implements Comparable<Attack>{
        public int day;
        public int west;
        public int east;
        public int strength;

        public Attack clone() {
            Attack copy = new Attack();
            copy.day = day;
            copy.west = west;
            copy.east = east;
            copy.strength = strength;
            return copy;
        }

        @Override
        public int compareTo(Attack o) {
            return new Integer(day).compareTo(o.day);
        }
    }

    private int solve(Tribe[] tribes) {
        int result = 0;
        int attackCount = 0;
        for (Tribe tribe : tribes)
            attackCount += tribe.attacks;

        int minWest = tribes[0].westPoint;
        int maxEast = tribes[0].eastPoint;
        Attack[] attacks = new Attack[attackCount];
        int index = 0;
        Attack lastAttack = null;
        for (Tribe tribe : tribes) {
            for (int i = 0; i < tribe.attacks; i++) {
                if (lastAttack == null) {
                    lastAttack = new Attack();
                    lastAttack.day = tribe.firstAttackDay;
                    lastAttack.west = tribe.westPoint;
                    lastAttack.east = tribe.eastPoint;
                    lastAttack.strength = tribe.strength;
                } else {
                    lastAttack.day += tribe.deltaDays;
                    lastAttack.west += tribe.deltaMovement;
                    lastAttack.east += tribe.deltaMovement;
                    lastAttack.strength += tribe.deltraStrength;
                }
                attacks[index++] = lastAttack.clone();
                minWest = Math.min(minWest, lastAttack.west);
                maxEast = Math.max(maxEast, lastAttack.east);
            }
            lastAttack = null;
        }
        Arrays.sort(attacks);
        int wallLength = Math.abs(maxEast - minWest);
        int wallDelta = 0 - minWest;
        int[] heights = new int[wallLength];
        for (int i = 0; i < wallLength; i++) {
            heights[i] = 0;
        }

        List<Attack> penetratedAttacks = new ArrayList<Attack>();
        int currentDay = 0;
        for (Attack a : attacks) {
            if (currentDay != a.day) {
                for(Attack prevAttack : penetratedAttacks) {
                    int normalizedWest = prevAttack.west + wallDelta;
                    int normalizedEast = prevAttack.east + wallDelta;
                    for (int i = normalizedWest; i < normalizedEast; i++) {
                        heights[i] = Math.max(heights[i], prevAttack.strength);
                    }
                }
                penetratedAttacks.clear();
            }
            currentDay = a.day;
            boolean success = false;
            int normalizedWest = a.west + wallDelta;
            int normalizedEast = a.east + wallDelta;

            for (int i = normalizedWest; i < normalizedEast; i++) {
                if (heights[i] < a.strength) {
                    success = true;
                    penetratedAttacks.add(a);
                    break;
                }
            }
            if (success)
                result++;
        }

        return result;
    }

    public void solve(Scanner sc, PrintWriter pw) {
        int tests = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < tests; i++) {
            Tribe[] tribes = new Tribe[sc.nextInt()];
            sc.nextLine();
            for (int j = 0; j < tribes.length; j++) {
                tribes[j] = new Tribe();
                tribes[j].firstAttackDay = sc.nextInt();
                tribes[j].attacks = sc.nextInt();
                tribes[j].westPoint = sc.nextInt();
                tribes[j].eastPoint = sc.nextInt();
                tribes[j].strength = sc.nextInt();
                tribes[j].deltaDays = sc.nextInt();
                tribes[j].deltaMovement = sc.nextInt();
                tribes[j].deltraStrength = sc.nextInt();
            }

            int result = solve(tribes);
            pw.println("Case #" + (i + 1) + ": " + result);
            pw.flush();
            if (sc.hasNext())
                sc.nextLine();
        }
    }

    public static void main(String[] args) throws Exception {
        String fileName = "C:\\Users\\axisK\\Downloads\\C-small-attempt0.in";
        Scanner sc = new Scanner(new FileReader(fileName));
        PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
        new C().solve(sc, pw);
        pw.close();
        sc.close();
    }
}