import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by BG2Air on 5/8/16.
 */
public class Round3_q3 {

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for(int t=1;t<=T;t++)
        {

            int J = scanner.nextInt();
            int P = scanner.nextInt();
            int S = scanner.nextInt();
            int K = scanner.nextInt();

            int[][] JP = new int[J][P];
            int[][] JS = new int[J][S];
            int[][] PS = new int[P][S];


            ArrayList<String> ans = new ArrayList<>();
            for(int i=0;i<J;i++)
            {
                for(int j=0;j<P;j++)
                {
                    for(int k=0;k<S;k++)
                    {
                        //
                        if(JP[i][j]+1 <= K && JS[i][k]+1 <=K && PS[j][k]+1 <= K)
                        {
                            JP[i][j]++;
                            JS[i][k]++;
                            PS[j][k]++;
                            ans.add(String.format("%d %d %d",i+1,j+1,k+1));
                        }
                    }
                }
            }

            System.out.printf("Case #%d: %d\n", t, ans.size());
            for(String s : ans)
                System.out.println(s);



        }
    }
}
