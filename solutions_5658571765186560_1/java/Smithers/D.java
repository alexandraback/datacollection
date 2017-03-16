// Google Code Jam Qualification Round 2015
// Problem D. Ominous Omino
// Solution in Java
// By Smithers

import java.util.Scanner;

class D {
    
    private static String solveCase(int X, int R, int C) {
        if (R * C % X != 0) {
            return "RICHARD";
        }
        
        switch (X) {
            case 1:
            case 2:
                return "GABRIEL";
            
            case 3:
                if (R == 1 || C == 1) {
                    return "RICHARD";
                } else {
                    return "GABRIEL";
                }
            
            case 4:
                if (R <= 2 || C <= 2) {
                    return "RICHARD";
                } else {
                    return "GABRIEL";
                }
            
            case 5:
                if (R <= 2 || C <= 2 || R * C == 15) {
                    return "RICHARD";
                } else {
                    return "GABRIEL";
                }
            
            case 6:
                if (R <= 3 || C <= 3) {
                    return "RICHARD";
                } else {
                    return "GABRIEL";
                }
            
            default:
                return "RICHARD";
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int T = scanner.nextInt();
        for (int x = 1; x <= T; x++) {
            int X = scanner.nextInt();
            int R = scanner.nextInt();
            int C = scanner.nextInt();
            String res = solveCase(X, R, C);
            System.out.println("Case #" + x + ": " + res);
        }
    }
    
}