import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: rathinakumar
 * Date: 13/4/13
 * Time: 10:00 AM
 * To change this template use File | Settings | File Templates.
 */
public class Lawnmower {
    final static String PROBLEM_NAME = "Lawnmower";
    final static String WORK_DIR = "E:\\Rathinakumar\\CodeJam\\" + PROBLEM_NAME + "\\";
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR+"input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int T = sc.nextInt();
        for(int Case=1; Case<=T; Case++)
        {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int[][] lwn = new int[N][M];
            int[] row = new int[N];
            int[] col = new int[M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M;j++)
                {
                    lwn[i][j] = sc.nextInt();
                    if(lwn[i][j]>col[j])
                        col[j]=lwn[i][j];
                    if(lwn[i][j]>row[i])
                        row[i]=lwn[i][j];
                }

            boolean flag = true;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<M;j++)
                    if(lwn[i][j]<col[j] && lwn[i][j]<row[i])
                    {
                        flag=false;
                    }
                if(!flag)break;
            }

            if(flag)
                pw.println("Case #" + Case + ": YES");
            else
                pw.println("Case #" + Case + ": NO");

        }
        pw.close();
        sc.close();

    }

}
