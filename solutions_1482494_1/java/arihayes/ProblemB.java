import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ari
 */
public class ProblemB {
    static String in = "src/b.in";
    static String out = "src/b.out";
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        int numLevels;
        int numStars;
        int count;
        int minTwo = Integer.MAX_VALUE;
        LinkedList<Level> levels;
        Level l;
        for(int x = 0; x < numlines; x++) {
            numStars = 0;
            count = 0;
            numLevels = scan.nextInt();
            levels = new LinkedList<Level>();
            for(int y = 0; y < numLevels; y++) {
                l = new Level(scan.nextInt(),scan.nextInt());
                if(l.two <= numStars) {
                    count++;
                    numStars += 2;
                }
                else {
                    levels.add(l);
                }
            }
            Collections.sort(levels);
            
            boolean done;
            while(true) {
                done = false;
                minTwo = -1;
                for(int y = levels.size() - 1; y >= 0; y--) {
                    if(levels.get(y).two <= numStars) {
                        if(levels.get(y).half) {
                            numStars++;
                        }
                        else {
                            numStars += 2;
                        }
                        count++;
                        levels.remove(y);
                    }
                    else {
                        minTwo = levels.get(y).two;
                        break;
                    }
                }
                
                if(minTwo < 0) {
                    break;
                }
                
                while(numStars < minTwo) {
                    boolean found = false;
                    for(int y = 0; y < levels.size(); y++) {
                        if((!levels.get(y).half) && levels.get(y).one <= numStars) {
                            levels.get(y).half = true;
                            count++;
                            numStars++;
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        minTwo = -1;
                    }
                }
                
                if(minTwo < 0) {
                    break;
                }
            }
            
            write.write("Case #" + (x+1) + ": ");
            if(levels.size() > 0) {
                write.write("Too Bad\n");
            }
            else {
                write.write(count + "\n");
            }
        }
        scan.close();
        write.close();
    }
    
    static class Level implements Comparable {
        public int one;
        public int two;

        boolean half = false;
        
        public Level(int o, int t) {
            one = o;
            two = t;
        }
        
        @Override
        public int compareTo(Object o) {
            Level l = (Level) o;
            if(two > l.two) {
                return -1;
            }
            else if(two < l.two) {
                return 1;
            }
            else {
                return l.one - one;
            }
        }
        
    }
}
