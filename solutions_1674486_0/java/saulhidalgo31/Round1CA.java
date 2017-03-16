
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Saul Hidalgo
 */
public class Round1CA {

    private static LinkedList<LinkedList<Integer>> l ;
    private static boolean[] ready;

    private static boolean isTree(int node){
        if ( ready[node] ) return false;
        ready[node] = true;
        boolean ans = true;
        for (int i = 0; i < l.get(node).size() && ans ; i++) {
            ans = isTree(l.get(node).get(i));
        }
        return ans;
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("A-small-attempt0.in"));
            PrintStream ps = new PrintStream(new File("output.txt"));

            int T = sc.nextInt();
            
            for ( int t = 1 ; t <= T ; t++ ){
                int n = sc.nextInt();
                l = new LinkedList<LinkedList<Integer> >();

                for( int i = 0 ; i < n ; i++ ){
                    int m = sc.nextInt();
                    l.add( new LinkedList<Integer>());
                    for ( int j = 0 ; j < m ; j++ ){
                        l.get(i).add(sc.nextInt()-1);
                    }
                }

                boolean isOk = true;
                for ( int i = 0 ; i < n && isOk; i++ ){
                    ready = new boolean[n];
                    isOk = isTree(i);
                }

                ps.print("Case #" + t + ": " + (!isOk?"Yes\n":"No\n"));
                

            }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExerciseA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
