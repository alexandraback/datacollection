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
            int J = sc.nextInt();
            int P = sc.nextInt();
            int S = sc.nextInt();
            int K = sc.nextInt();
            int max = K > S ? S : K;
            int n = K > P ? P : K;
            System.out.println(J * n * max);
            int one = 1;
            int two = 1;
            int three = 1;
            for(int j = 0; j < J * n * max; j++)
            {
                System.out.println(one + " " + two + " " + three);
                if(two == P && three == S)
                {
                    one++;
                    two = 1;
                    three = 1;
                }
                if(three == S || (two == 1 && three == S-1))
                {
                    two++;
                    three = (two == S) ? 2 : 1;
                }
                else
                {
                    three++;
                    if(three == S - two + 1)
                    {
                        three++;
                    }
                }
            }
        }
    }
}
