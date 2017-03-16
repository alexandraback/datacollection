package codejam4;

import java.util.Scanner;

public class Codejam4 {

    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        int testCases = s.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            int X = s.nextInt();
            int R = s.nextInt();
            int C = s.nextInt();

            boolean richardWins;
            if (R*C % X != 0) {
                richardWins = true;
            } else {
                switch(X) {
                    case 1:
                    case 2:
                        richardWins = false;
                        break;
                    case 3: 
                        richardWins = (R == 1 || C == 1);
                        break;
                    case 4: 
                    case 5: 
                        richardWins = (R <= 2 || C <= 2);
                        break;
                    case 6: 
                        richardWins = (R <= 3 || C <= 3);
                        break;
                    default:
                        richardWins = true;
                        break;
                }
            }

            if (richardWins)
                System.out.println("Case #" + testCase + ": RICHARD");
            else
                System.out.println("Case #" + testCase + ": GABRIEL");
        }
    }
    
}
