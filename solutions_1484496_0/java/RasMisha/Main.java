
import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class Main {

    static Scanner in;
    static PrintWriter out;
    static int[] a;
    static boolean[] u;
    static int n;
    static boolean wasFind;
    static HashMap<Integer,Integer> map;
    
    public static void R(int index, int sum) {
        //System.err.println(index);
        if (wasFind) return;
        if (index==n) {
            if (map.containsKey(sum)) {
                //System.err.println("Sum="+sum);
                wasFind = true;
                for (int i=0; i<n; i++) {
                    if (u[i])
                    {
                        out.printf("%d ",a[i]);
                    }
                }
                out.println();
                int prev = map.get(sum);
                //System.err.println("Prev="+prev);
                for (int i=0; i<=n; i++) {
                    if (prev%2==1) {
                        out.printf("%d ",a[i-1]);                       

                    }
                                            prev >>= 1;       
                       // System.err.println("Prev="+prev);
                }
            } else {
                int value = 0;
                for (int i=n-1; i>=0; i--) {
                    if (u[i]) value++;
                    value<<=1;
                }
                map.put(sum, value);
            }
        } else  {
            u[index]=true;
            R(index+1,sum+a[index]);
            u[index]=false;
            R(index+1,sum);
        }
    }
    
    public static void solve(int caseNumber) {
        map = new HashMap<Integer, Integer>();
        n = in.nextInt();
        wasFind = false;
        for (int i=0; i<n; i++) {
            a[i]=in.nextInt();
        }
        out.format(Locale.ENGLISH,"Case #%d:",caseNumber);
        out.println();
        R(0,0);
        if (!wasFind) out.print("Impossible");
        out.println();
        
        
    }
    
    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("file.txt"));
        out = new PrintWriter("out.txt");
        int T = in.nextInt();
        a = new int[21];
        u = new boolean[21];
        for (int i=0; i<T; i++) {
            solve(i+1);
        }
        
        out.close();
    }
}
