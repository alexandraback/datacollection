
import java.util.ArrayList;
import java.util.Scanner;

public class A2 {
    public static boolean a[][];
    public static int n;
    public static boolean used[],found;
    public static void rec(int x) {
        if (found) return;
        used[x] = true;
        for (int ii=0;ii<n;ii++)
            
            if (a[x][ii] && !used[ii]) {
                rec(ii);
            } else 
                if (a[x][ii] && used[ii]) {
                    found = true;
                    return;
                }
    }
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int tt=0;tt<t;tt++) {
            n = in.nextInt();
            a = new boolean[n][n];
            ArrayList<Integer> b = new ArrayList<Integer>();
            for (int i=0;i<n;i++) {
                int m = in.nextInt();
                if (m==0) b.add(i);
                for (int j=0;j<m;j++) {
                    int x = in.nextInt() - 1;
                    a[x][i] = true;
                }
            }
            found = false;
            
            for (int i=0;i<b.size();i++) {
                used  = new boolean[n];
                if (!found)
                rec(b.get(i));
            }
            System.out.println("Case #"+(tt+1)+": "+(found?"Yes":"No"));
        }
    }
}
