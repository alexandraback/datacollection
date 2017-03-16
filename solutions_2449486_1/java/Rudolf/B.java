import java.io.*;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: rudolf
 * Date: 13.04.13
 * Time: 19:59
 * To change this template use File | Settings | File Templates.
 */
public class B {

    public static void main(String ... args) throws FileNotFoundException {
        String name = "B-large";
        Scanner sc = new Scanner(new FileInputStream(name + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(name + ".out")));
        int t = sc.nextInt();
        for(int ti = 0; ti < t; ti++) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int minn[] = new int[n];
            int minm[] = new int[m];
            int maxn[] = new int[n];
            int maxm[] = new int[m];

            for(int i = 0; i < n; i++){
                minn[i] = Integer.MAX_VALUE;
                maxn[i] = Integer.MIN_VALUE;
            }
            for(int i = 0; i < m; i++){
                minm[i] = Integer.MAX_VALUE;
                maxm[i] = Integer.MIN_VALUE;
            }

            int mp[][] = new int[n][];
            for(int i = 0; i < n; i++) {
                mp[i] = new int[m];
                for(int j = 0; j < m; j++) {
                    int v = mp[i][j] = sc.nextInt();
                    minn[i] = minn[i]>v?v:minn[i];
                    minm[j] = minm[j]>v?v:minm[j];
                    maxn[i] = maxn[i]<v?v:maxn[i];
                    maxm[j] = maxm[j]<v?v:maxm[j];
                }
            }
            boolean yes = true;
            for(int i = 0; i < n && yes; i++) {
                for(int j = 0; j < m && yes; j++) {
                    if(mp[i][j] < maxn[i] && mp[i][j] < maxm[j])
                        yes = false;
                }
            }
            System.out.println("Case #" + (ti+1) + ": " + (yes?"YES":"NO"));
        }

    }
}
