
package zad1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.in"));
        Formatter out = new Formatter(new File("output.txt"));
        
        HashSet<Character> volews = new HashSet<Character>();
        volews.add('a');
        volews.add('e');
        volews.add('i');
        volews.add('o');
        volews.add('u');
        
        int tests = in.nextInt();
        for(int test = 0 ; test < tests; test++){
            char[] name = in.next().toCharArray();
            int n = in.nextInt();
            int accum = 0;
            int start = 0;
            long count = 0;
            for(int i = 0 ; i < name.length; i++){
                if(!volews.contains(name[i])){
                    accum++;
                }else{
                    accum = 0;
                }
                
                if(accum >=n){
                    count +=(name.length-i)*(i-n+2 - start);
                    start = (i-n+2);
                }
            }
            out.format("Case #%d: %d\n", test+1, count);
        }
        out.close();
    }
}
