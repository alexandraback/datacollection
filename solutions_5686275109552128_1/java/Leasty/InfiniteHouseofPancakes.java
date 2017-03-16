/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import java.util.Scanner;
import java.util.*;
/**
 *
 * @author Tom
 */
public class InfiniteHouseofPancakes {
    ArrayList<Integer> pancakes;
    
    public static InfiniteHouseofPancakes[] readFile(Scanner input) {
        InfiniteHouseofPancakes[] puzzles = new InfiniteHouseofPancakes[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {          
            int diners = input.nextInt();
            ArrayList<Integer> pancakes = new ArrayList<>();
            for(int j = 0; j < diners; ++j) {
                pancakes.add(input.nextInt());
            }
            
            puzzles[i] = new InfiniteHouseofPancakes(pancakes);
        }
        
        return puzzles;
    }
    
    public InfiniteHouseofPancakes(ArrayList<Integer> pancakes) {
        this.pancakes = pancakes;
    }

    public String solve() {       
        boolean done = false;
        
        Collections.sort(pancakes);
        int max = pancakes.get(pancakes.size() - 1);
        int result = max;
        
        for(int i = 1; i <= max; ++i) {
            int left = 1;
            int right = max;
            
            while(left < right) {
                int mid = (left + right)/2;
                if(possible(i, mid)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            result = Math.min(result, i + left);
        }        
        
        return "" + result;
    }
    
    private boolean possible(int splits, int goal) {
        int count = 0;
        for(int i = pancakes.size() - 1; 0 <= i && goal < pancakes.get(i); --i) {
            int current = pancakes.get(i);
            if(current%goal == 0) {
                count += current/goal - 1;
            } else {
                count += current/goal;
            }
        }
        
        return count <= splits;
    }
}
