/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import java.util.Scanner;

/**
 *
 * @author Tom
 */
public class OminousOmino {
    private int X;
    private int R;
    private int C;
    
    public static OminousOmino[] readFile(Scanner input) {
        OminousOmino[] puzzles = new OminousOmino[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {                      
            puzzles[i] = new OminousOmino(input.nextInt(), input.nextInt(), input.nextInt());
        }
        
        return puzzles;
    }
    
    public OminousOmino(int X, int R, int C) {
        this.X = X;
        this.R = R;
        this.C = C;
    }

    public String solve() {
        System.out.println(X + " " + R + " " + C);
        if(7 <= X) {
            return "RICHARD";
        }
        
        if((R * C)%X != 0) {
            return "RICHARD";
        }
        
        if(R < C) {
            int temp = R;
            R = C;
            C = temp;
        }
        
        if(R < X) {
            return "RICHARD";
        }
        
        for(int a = 0, b = X; a < b; ++a, --b) {
            if(C < (a + 1)) {
                return "RICHARD";
            }
        }
        
        if(X == 4 && C == 2) {
            return "RICHARD";
        }
        
        if(X == 5 && C == 3) {
            for(int a = 0, b = R - 3; 0 <= b; ++a, --b) {
                if((1 + a * 3)%5 == 0 && (3 + b * 3)%5 == 0) {
                    return "GABRIEL";
                }
            }
            
            return "RICHARD";
        }
        
        return "GABRIEL";
    }
}
