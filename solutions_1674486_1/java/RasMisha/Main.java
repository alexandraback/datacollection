
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class Main {

    static Scanner in;
    static PrintWriter out;
    static int[] a;
    static ArrayList<ArrayList<Integer>> g;
    static boolean[] u;
    static boolean isDiam=false;

    public static void explore(int v) {
        if (isDiam) return;
        u[v]=true;
        ArrayList<Integer> data = g.get(v);
        for (Integer cur : data) {
            if (u[cur]) {
                isDiam = true;
                break;
            } else {
                explore(cur);
            }
            
        }
    }
    
    public static void solve(int caseNumber) {
        int n = in.nextInt();
        isDiam = false;
        out.format(Locale.ENGLISH,"Case #%d:",caseNumber);
        g = new ArrayList<ArrayList<Integer>>();
        u = new boolean[n];
        int sum = 0;
        for (int i=0; i<n; i++) {
            ArrayList<Integer> data = new ArrayList<Integer>();
            int k = in.nextInt();
            sum+=k;
            for (int j=0; j<k; j++) {
                data.add(in.nextInt()-1);
            }
            g.add(data);
        }
        for (int i=0; i<n; i++) {
                u = new boolean[n];
                explore(i);
        }
        out.println(isDiam?" Yes":" No");
    }
    
        
    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("file.txt"));
        out = new PrintWriter("out.txt");
        int T = in.nextInt();
        for (int i=0; i<T; i++) {
            solve(i+1);
        }
        
        out.close();
    }
}
