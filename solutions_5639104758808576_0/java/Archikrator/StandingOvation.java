package google.codejam_2015;

import java.util.Scanner;

public class StandingOvation {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            int maxShyness = s.nextInt();
            String shynesses = s.next();
            
            System.out.printf("Case #%d: %d%n", i+1, solve(maxShyness, shynesses));
        }
    }
    
    private static int solve(int maxShynessLevel, String shynessesString) {
        int[] peopleByShynessLevel = new int[maxShynessLevel + 1];
        char[] shynessesCharA = shynessesString.toCharArray();
        for (int i = 0; i < shynessesCharA.length; i++) {
            char c = shynessesCharA[i];
            peopleByShynessLevel[i] = Integer.parseInt(""+c);
        }
        
        int standingPeople = 0;
        int neededFriends = 0;
        for(int shynessLevel = 0; shynessLevel <= maxShynessLevel; shynessLevel++) {
            int peopleDebt = shynessLevel - standingPeople;
            if (peopleDebt > 0) {
                neededFriends += peopleDebt;
                standingPeople += peopleDebt;
            }
            standingPeople += peopleByShynessLevel[shynessLevel];
        }
        return neededFriends;
    }
}
