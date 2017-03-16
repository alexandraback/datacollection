// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Problem2 {

    public static void main(String[] args) throws FileNotFoundException {

        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("B-small-attempt0.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);

        //open output file
        File f2 = new File("p2small.txt");
        PrintWriter p = new PrintWriter(f2);

        int maxPan = 9; //Maximum number of pancakes
        for (int j = 1; j <= T; j++) {
            int[] freqs = new int[maxPan];
            s.nextLine(); //don't care about number of people
            
            //Get frequencies of each pancake stack size
            String[] pcakes = s.nextLine().split(" ");
            int temp;
            for (int i = 0; i < pcakes.length; i++) {
                temp = Integer.parseInt(pcakes[i])-1;
                freqs[temp]++;
            }
            
            //For the small input, we can use recursion
            int optimal = getTime(freqs, maxPan, 0);
            
            //store the result in the output file
            p.println("Case #" + j + ": " + optimal);
        }

        p.close();
        s.close();
    }
    
    /**
     * Recursively determine the best strategy
     * @param freqs
     * @param maxtime
     * @param currtime
     * @return 
     */
    public static int getTime(int[] freqs, int maxtime, int currtime) {
        if (currtime == maxtime) {
            //we cannot beat the maximum time
            return maxtime;
        }
        boolean test = true;
        for (int i = 0; i < freqs.length; i++) {
            if (freqs[i] != 0) {
                test = false;
                break;
            }
        }
        if (test) {
            return currtime;
        }
        
        //try waiting 1 minute
        int[] nfreqs = Arrays.copyOfRange(freqs, 1, freqs.length);
        int best = getTime(nfreqs, maxtime, currtime + 1);
        
        //try splitting the largest entry
        
        //get the highest nonzero frequency
        int index = freqs.length;
        for (int i = freqs.length-1; i >= 0; i--) {
            if (freqs[i] != 0) {
                index = i;
                break;
            }
        }
        
        if (index == 0) { //nobody has more than 1 pancake
            return currtime + 1;
        }
        
        //index is now one less than the largest pancake stack size
        int limit = index / 2;
        for (int i = 0; i <= limit; i++) {
            nfreqs = Arrays.copyOf(freqs, freqs.length);
            nfreqs[i]++;
            nfreqs[index-i-1]++;
            nfreqs[index]--;
            int result = getTime(nfreqs, best, currtime + 1);
            
            if (result < best) {
                best = result; //replace best
            }
        }
        
        return best;
    }
}
