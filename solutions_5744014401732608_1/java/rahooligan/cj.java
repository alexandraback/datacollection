import java.util.*;
import java.math.*;

/**
 *
 * @author rahuljaisingh
 */
public class cj {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i = 1; i <= T; i++)
        {
            System.out.print("Case #" + i + ": ");
            int B = sc.nextInt();
            BigInteger M = new BigInteger(sc.next());
            BigInteger two = new BigInteger("2");
            if(M.compareTo(two.pow(B-2)) == 1)
            {
                System.out.println("IMPOSSIBLE");
                continue;
            }
            System.out.println("POSSIBLE");
            solve(B, M.subtract(BigInteger.ONE));
        }
            
    }
    
    public static void solve(int B, BigInteger M)
    {
        int res[][] = new int[B][B];
        for(int i = 0; i < B; i++)
        {
            for(int j = 0; j < B; j++)
            {
                res[i][j] = (j > i) ? 1 : 0;
            }
        }
        for(int i = 1; i < B - 1; i++)
        {
            res[0][i] = 0;
        }
        BigInteger two = new BigInteger("2");
        for(int i = B - 2; i > 0; i--)
        {
            if(M.mod(two).equals(BigInteger.ONE))
            {
                res[0][i] = 1;
            }
            M = M.divide(two);
        }
        for(int i = 0; i < B; i++)
        {
            for(int j = 0; j < B; j++)
            {
                System.out.print(res[i][j]);
            }
            System.out.println();
        }
    }
}
