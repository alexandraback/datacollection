
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author DeViL JiN
 */
public class battleship {

    public static void main(String[] args) throws IOException {
        int t = input();
        int a[] = new int[3], n, r, c;
        for (int i = 1; i <= t; i++) {

            input(a, 3);
            r = a[0];
            c = a[1];
            n = a[2];
            int ans=0;
           ans+=(r)*(c/n);
           int m=c%n; 
           ans+=n;
           if(m==0){
           ans-=1;
           }
           
           
            
            System.out.println("Case #" + i + ": " + ans);

        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(
            System.in));
    private static String s[], w, q;

    public static void input(int a[], int p) throws IOException {
        s = br.readLine().trim().split(" ");
        int i;
        for (i = 0; i < p; i++) {
            a[i] = Integer.parseInt(s[i]);
        }

    }

    public static void input(long a[], int p) throws IOException {
        s = br.readLine().split(" ");
        int i;
        for (i = 0; i < p; i++) {
            a[i] = Long.parseLong(s[i]);
        }
    }

    public static int input() throws IOException {
        int ab;
        ab = Integer.parseInt(br.readLine().trim());
        return ab;
    }
}
