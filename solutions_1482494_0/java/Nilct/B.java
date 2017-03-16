import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * Apr 28, 2012 
 * @author parisel
 * GGJ - Qualification Round
 */
public class B {
    private final static boolean LOCAL= true;
    private static final boolean DEBUG= false;
    private static final int TEST= 0, SMALL= 1, LARGE= 2;
    private static final String[] infile= { "-test.in",  "-small1.in",  "-large.in"};
    private static final String[] outfile= {"-test.out", "-small1.out", "-large.out"};
    java.io.BufferedReader br;
    java.io.PrintWriter out;
    int N;
    String[] tok;

    private String[] getTok() throws IOException {return br.readLine().split(" ");}
    private int getInt() throws IOException {return Integer.valueOf(br.readLine());}
    private int[] getInt(int N) throws IOException {
        int[] data= new int[N]; tok= br.readLine().split(" ");
        for (int i=0; i<N; i++) data[i]= Integer.valueOf(tok[i]);
        return data;
    }
    private int toInt(String s) { return Integer.valueOf(s); }


    boolean[] oneStar;
    boolean[] twoStar;

    private int answer() {
        int i;

        int noOfPlay= 0;
        int noOfStar= 0;
        int loop= 2*N;
        oneStar= new boolean[N];
        twoStar= new boolean[N];
        boolean found, allIsPlayed;
        int highestxx;
        int select;
        while (loop>0) {
            found= false;
            // find best ** without *
            for (i=0; i<N; i++)
                if (!twoStar[i] && !oneStar[i] && b[i]<= noOfStar) {
                    noOfStar+= 2;
                    twoStar[i]= oneStar[i]= true;
                    ++noOfPlay;
                    found= true;
                    if (DEBUG) System.out.printf("%d **\n", i+1);
                    break;
//                    --loop;
                }
            // if not found, best ** with *
            if (!found) {
                for (i=0; i<N; i++)
                    if (!twoStar[i] && oneStar[i] && b[i]<= noOfStar) {
                        noOfStar+= 1;
                        twoStar[i]= true;
                        ++noOfPlay;
                        found= true;
                         if (DEBUG) System.out.printf("%d ** (*)\n", i+1);
                        break;
    //                    --loop;
                    }
            }
            // if not found, best * with highest **
            if (!found) {
                highestxx= 0; select= -1;
                for (i=0; i<N; i++)
                    if (!twoStar[i] && !oneStar[i] && a[i]<= noOfStar && b[i]> highestxx) {
                        highestxx= b[i];
                        select= i;
                    }

                if (select>-1) {
                    noOfStar+= 1;
                    oneStar[select]= true;
                    ++noOfPlay;
                    found= true;
                    if (DEBUG) System.out.printf("%d * \n", select+1);
//                    --loop;
                }

            }
            if (!found) return -1;
            // check all is played
            allIsPlayed= true;
            for (i=0; i<N; i++) if (!twoStar[i]) { allIsPlayed= false; break;}
            if (allIsPlayed) break;
        }




        return noOfPlay;
    }




    class Level implements Comparable<Level>{
        int id;
        int cost;
        int stars;
        
        public Level(int i, int c, int s) {
            id= i; cost= c; stars= s;
        }

        public int compareTo(Level o) {
            if (cost!=o.cost) return cost-o.cost;
            else return stars - o.stars;
        }
    }

    int[] a;
    int[] b;

    public void solve() throws IOException {
        int i,j,k;
        String s;

        int MODE= SMALL;
        br = new BufferedReader (new FileReader("B"+infile[MODE]));
        if (MODE== TEST) {
            out= new PrintWriter(System.out);
        } else {
        out = new PrintWriter(new BufferedWriter(new FileWriter("Bfull"+outfile[MODE])));
        }
        int C= Integer.valueOf(br.readLine());
        for (int c=1; c<=C; c++) {
            // read
            N= Integer.valueOf(br.readLine());
            a= new int[N]; b= new int[N];
            for (i=0; i<N; i++) {
                tok= getTok();
                a[i]= Integer.valueOf(tok[0]);
                b[i]= Integer.valueOf(tok[1]);

            }
            // output
            int u= answer();
            if (u==-1) out.printf("Case #%d: %s\n", c, "Too Bad");
            else out.printf("Case #%d: %d\n", c, u);
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().solve();
    }
}
