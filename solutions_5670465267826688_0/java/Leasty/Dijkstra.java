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
public class Dijkstra {
    private long repeat;
    private String str;
    
    public static Dijkstra[] readFile(Scanner input) {                
        Dijkstra[] puzzles = new Dijkstra[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {          
            int strLength = input.nextInt();
            long repeat = input.nextLong();
            String str = input.next();
            
            puzzles[i] = new Dijkstra(repeat, str);
        }
        
        return puzzles;
    }
    
    public Dijkstra(long repeat, String str) {
        this.repeat = repeat;
        this.str = str;
    }

    public String solve() {
        int[][] system = new int[5][5];
        //1 = 1, i = 2, j = 3, k = 4
        system[1][1] = 1;
        system[1][2] = 2;
        system[1][3] = 3;
        system[1][4] = 4;
        
        system[2][1] = 2;
        system[2][2] = -1;
        system[2][3] = 4;
        system[2][4] = -3;
        
        system[3][1] = 3;
        system[3][2] = -4;
        system[3][3] = -1;
        system[3][4] = 2;
        
        system[4][1] = 4;
        system[4][2] = 3;
        system[4][3] = -2;
        system[4][4] = -1;
        
        int[] asNum = new int[str.length()];
        int oneResult = 1;
        for(int i = 0; i < asNum.length; ++i) {
            int number;            
            
            if(str.charAt(i) == 'i') {
                number = 2;
            } else if(str.charAt(i) == 'j') {
                number = 3;
            } else {
                number = 4;
            }
            
            if(oneResult < 1) {
                oneResult = -1 * system[-1 * oneResult][number];
            } else {
                oneResult = system[oneResult][number];
            }
            
            asNum[i] = number;
        }
        
        int result = 1;
        for(int i = 0; i < repeat; ++i) {
            if(result < 1) {
                if(oneResult < 1) {
                    result = system[result * -1][oneResult * -1];
                } else {
                    result = -1 * system[result * -1][oneResult];
                }
            } else {
                if(oneResult < 1) {
                    result = -1 * system[result][-1 * oneResult];
                } else {
                    result = system[result][oneResult];
                }
            }
        }
        
        if(result != -1) {
            return "NO";
        }
        
        boolean[][][] seen = new boolean[asNum.length][5][2];
        int currentNum = 0;
        int currentResult = 1;
        int neg = 0;
        int repeats = 0;        
        int goal = 2;
        
        boolean done = false;
        while(!done) {
            if(seen[currentNum][currentResult][neg]) {
                return "NO";
            }
            seen[currentNum][currentResult][neg] = true;
            
            if(neg == 0) {
                currentResult = system[currentResult][asNum[currentNum]];
                
                if(currentResult < 1) {
                    currentResult *= -1;
                    neg = 1;
                }
            } else {
                currentResult = -1 * system[currentResult][asNum[currentNum]];
                
                if(currentResult < 1) {
                    currentResult *= -1;
                    neg = 1;
                }
            }
            
            currentNum++;
            if(currentNum == asNum.length) {
                currentNum = 0;
                repeats++;
                if(repeats == repeat) {
                    return "NO";
                }
            }
            
            if(currentResult == goal) {
                done = true;
            }
        }
        
        seen = new boolean[asNum.length][5][2];
        currentResult = 1;
        neg = 0;
        goal = 3;
        
        done = false;
        while(!done) {
            if(seen[currentNum][currentResult][neg]) {
                return "NO";
            }
            seen[currentNum][currentResult][neg] = true;
            
            if(neg == 0) {
                currentResult = system[currentResult][asNum[currentNum]];
                
                if(currentResult < 1) {
                    currentResult *= -1;
                    neg = 1;
                }
            } else {
                currentResult = -1 * system[currentResult][asNum[currentNum]];
                
                if(currentResult < 1) {
                    currentResult *= -1;
                    neg = 1;
                }
            }
            
            currentNum++;
            if(currentNum == asNum.length) {
                currentNum = 0;
                repeats++;
                if(repeats == repeat) {
                    return "NO";
                }
            }
            
            if(currentResult == goal) {
                done = true;
            }
        }
        
        return "YES";
    }    
}
