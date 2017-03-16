
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
public class Round1CC {

    private static long aK[];
    private static long aT[];
    private static long bK[];
    private static long bT[];

    private static long fun(int x , int y, long extraAK, long extraAT, long extraBK, long extraBT){
        System.out.println("Entro con " + x + " " + y + " " + extraAK + " " + extraAT);
        if ( x >= aK.length || y >= aK.length ){
            return 0;
        }
        if ( aT[x] == extraAT && extraAK > 0 ){
            System.out.println("aK" + aK[x]);
            return Math.min(extraAK, aK[x]) + fun(x,y, Math.max(extraAK, aK[x]) - Math.min(extraAK, aK[x]), -1, extraBK , extraBT);
        }
        if ( bT[y] == extraBT && extraBK > 0 ){
            return Math.min(extraBK, bK[y]) + fun(x,y,extraAK, extraAT,  Math.max(extraBK, bK[y]) - Math.min(extraBK, bK[y]) , -1);
        }
        long ans =0;
        if ( aT[x] == bT[y] ){
            if ( aK[x] < bK[y] ){
                ans = aK[x] + fun( x+1 , y+1 , 0, -1 ,bK[y] - aK[x] , bT[y]);
            }else{
                ans = bK[y] + fun( x+1 , y+1 , aK[x] - bK[y] , bT[y], 0 , -1);
            }
        }
        return Math.max(Math.max(fun(x+1, y, extraAK, extraAT, extraBK , extraBT),fun(x,y+1, extraAK, extraAT, extraBK , extraBT)),ans);
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("test3.txt"));
            PrintStream ps = new PrintStream(new File("output.txt"));


            int T = sc.nextInt();

            for ( int t = 1 ; t <= T ; t++ ){
                int nA = sc.nextInt() , nB = sc.nextInt();
                aK = new long[nA];
                aT = new long[nA];
                bK = new long[nB];
                bT = new long[nB];

                for( int i = 0 ; i < nA ; i++ ){
                    aK[i] = sc.nextLong();
                    long tt = sc.nextLong();
                    if ( i != 0 && aT[i-1] == tt ){
                        aK[i-1] += aK[i];
                        aT[i] = -1;
                    }else{
                        aT[i] = tt;
                    }
                }
                for( int i = 0 ; i < nB ; i++ ){
                    bK[i] = sc.nextLong();
                    long tt = sc.nextLong();
                    if ( i != 0 && bT[i-1] == tt ){
                        bK[i-1] += bK[i];
                        bT[i] = -1;
                    }else{
                        bT[i] = tt;
                    }
                }
                ps.println("Case #" + t + ": " + fun(0,0,0,-1,0,-1));
            }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExerciseA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
