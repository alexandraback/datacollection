import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.TreeSet;


class Pair implements Comparable<Pair>{
    int a , b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Pair other = (Pair) obj;
        if (this.a != other.a) {
            return false;
        }
        if (this.b != other.b) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = a*3;
        return hash;
    }

    public int compareTo(Pair o) {
        if ( o.a != this.a ){
            return this.a - o.a;
        }else{
            return this.b - o.b;
        }
    }


}

/**
 *
 * @author Saul Hidalgo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("test2.txt"));
            PrintStream ps = new PrintStream(new File("output2.txt"));

            int T = sc.nextInt();
            for ( int t = 1 ; t <= T ; t++ ){
                int n = sc.nextInt() , m = sc.nextInt();
                int ans = 0;
                TreeSet<Pair> tree = new TreeSet<Pair>();

                for ( int i = n ; i <= m ; i++ ){
                    String num = i + "";
                    for ( int j = 1 ; j < num.length() ; j++ ){
                        String conv = num.substring(j) + num.substring(0, j);
                        int tt = Integer.parseInt(conv);
                        Pair p = new Pair(i, tt);
                        if ( tt > i && tt <= m && !tree.contains(p)){
                            ++ans;
                            tree.add(p);
                        }
                    }
                }
                System.out.println("Caso = " + t);
                ps.println("Case #" + t + ": " + ans);
            }

        }
        catch (FileNotFoundException ex) {
            // =(
        }
    }
}
