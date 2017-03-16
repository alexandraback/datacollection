
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
public class Round1BA {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("test.txt"));
            PrintStream ps = new PrintStream(new File("output.txt"));

            int T = sc.nextInt();


            for ( int t = 1 ; t <= T ; t++ ){
                ps.println("Case #" + t + ":");
                Set<Long> s = new TreeSet<Long>();
                TreeMap<Long, Integer> m = new TreeMap<Long, Integer>();
                int n = sc.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < a.length; i++) {
                    a[i] = sc.nextInt();
                }
                boolean isOk = false;
                for ( int i = 1 ; i < (1<<20) + 1 && !isOk ; i++ ){
                    long sum = 0;
                    for ( int j = 0 ; j < 20 ; j++ ){
                        if ( (i & (1<<j)) != 0 ){
                            sum += a[j];
                            System.out.println(" Suma " + j +" " + a[j]);
                        }
                    }
                    System.out.println("Da " + sum + " " + i );
                    if ( !m.containsKey(sum) ){
                        m.put(sum, i);
                    }else{
                        isOk = true;
                        int f = m.get(sum);
                        List<Integer> l = new LinkedList<Integer>();
                        System.out.println("Conseguido " + f + " " + i + " " + sum );
                        for( int j = 0 ; j < 20 ; j++ ){
                            if ( (f & ( 1 << j) ) != 0 ){
                                l.add(a[j]);
                                System.out.print(a[j]);
                                System.out.println("");
                            }
                        }
                        for (int j = 0; j < l.size() - 1; j++) {
                            ps.print(l.get(j) + " ");
                        }
                        ps.println(l.get(l.size()-1));
                        l = new LinkedList<Integer>();
                        for( int j = 0 ; j < 20 ; j++ ){
                            if ( (i & ( 1 << j) ) != 0 ){
                                l.add(a[j]);
                                System.out.print(a[j]);
                            }
                        }
                        for (int j = 0; j < l.size() - 1; j++) {
                            ps.print(l.get(j) + " ");
                        }
                        ps.println(l.get(l.size()-1));
                    }

                }
                if ( !isOk ){
                    ps.println("Impossible");
                }
            }
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExerciseA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
