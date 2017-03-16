import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;

public class A {
    static String in = "src/in";
    static String out = "src/out";
    
    static int armin;
    static int numMotes;
    static int[] motes;
    //static ArrayList<Long> added;
    static int numAdded;
    static int[] addNeeded;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File(in));
        BufferedWriter writer = new BufferedWriter(new FileWriter(out));
        int numLines = sc.nextInt();        
        for(int x = 1; x <= numLines; x++){
            
            armin = sc.nextInt();
            numMotes = sc.nextInt();
            motes = new int[numMotes];
            for(int y = 0; y < numMotes; y++){
                motes[y] = sc.nextInt();
            }
            
            if(armin == 1){
                writer.write("Case #" + x + ": " + numMotes);
                writer.newLine();
                continue;
            }
            
            Arrays.sort(motes);
            //added = new ArrayList<Long>();
            numAdded = 0;
            addNeeded = new int[numMotes];
            // first add them all
            // then remove one at a time
            int current = 0;
            while(current < numMotes){
                if(armin > motes[current]){
                    armin += motes[current];
                    addNeeded[current] = numAdded;
                    current++;
                } else {
                    //added.add(armin-1);
                    //System.out.println(numAdded);
                    numAdded++;
                    armin += armin - 1;
                    addNeeded[current] = numAdded;
                }
            }
            
            // keep array of how many needed to be added to get to current
            
            // answer is number removed (numMotes - current) + addNeeded
            
            //System.out.println(Arrays.toString(addNeeded));
            
            int answer = numMotes;
            for(int y = 0; y < numMotes; y ++){
                //System.out.println("y: " + y);
                int temp = numMotes - y - 1 + addNeeded[y];
                if(temp < answer) answer = temp;
            }
            
            
            // all added
            // removing last means:
            // armin -= last
            // if armin > 
            
            writer.write("Case #" + x + ": " + answer);
            writer.newLine();
        }
        sc.close();
        writer.close();
    }
    
    static String generate(){
        String answer = "";
        return answer;
    }
    
    static int removeLast(int prev, int last){
        armin -= motes[last];
        prev++; // adds to count fact of last removal
        if(last == 0){
            return prev - numAdded; // removes from count all the things added
        }
        long newArmin = armin;
        while(newArmin <= motes[last]){
            newArmin += newArmin-1; // remove the last added one
            prev--;
            numAdded--;
        }
        return prev;
        
        
        
        
        
    }
    
    // armin is everything including everything up to the last thing added
    // to remove last mote
    // first remove last entry
    // add one to ops
    // then see if armin had extra things added to it
    // that is, if armin > last thing
    // if not, subtract half of armin (remove last "added")
    // decrement answer
}