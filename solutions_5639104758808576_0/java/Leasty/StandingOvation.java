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
public class StandingOvation {
    private int max;
    private String audience;
    
    public static StandingOvation[] readFile(Scanner input) {
        StandingOvation[] puzzles = new StandingOvation[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {          


            puzzles[i] = new StandingOvation(input.nextInt(), input.next());
        }
        
        return puzzles;
    }
    
    public StandingOvation(int max, String audience) {
        this.max = max;
        this.audience = audience;
    }

    public String solve() {
        int result = 0;
        int standing = 0;            
        
        for(int i = 0; i < audience.length(); ++i) {
            int amount = audience.charAt(i) - '0';

            if(i <= standing) {
                standing += amount;
            } else {
                int needed = i - standing;
                result += needed;
                standing += needed + amount;
            }
        }

        return "" + result;
    }
}
