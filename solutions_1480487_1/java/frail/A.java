import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A
{

    public static void main(String[] args) throws Exception
    {

        Scanner sc = new Scanner(new FileReader("large-input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("large-output.txt"));

        final int CASE_COUNT = sc.nextInt();

        DecimalFormat sixDec = new DecimalFormat("0.000000");

        for(int caseNum = 1; caseNum <= CASE_COUNT; caseNum++)
        {
            pw.print("Case #" + caseNum + ": ");
            // HERE WE SOLVE STUFF

            int contestantCount = sc.nextInt();
            int[] values = new int[contestantCount];

            int sum = 0;

            for(int k = 0; k < contestantCount; k++)
            {
                int tmp = sc.nextInt();
                values[k] = tmp;
                sum += tmp;
            }

            double totalpoints = (double)(2 * sum);
            double avg = totalpoints / contestantCount;
            
            
            int realConst = contestantCount;
            
            if(contestantCount > 2)
            {
                for(int k = 0; k < contestantCount; k++)
                {
                    int tmp = values[k];
                    if(tmp > avg){
                        totalpoints -= tmp;
                        realConst--;
                    }
                }
            }

            double realAvg = totalpoints / realConst;
            
            for(int k = 0; k < contestantCount; k++)
            {
                int tmp = values[k];
                if(tmp > avg){
                    pw.print("0.0 ");
                } else {
                    double req = (realAvg - tmp) / sum;
                    
                    pw.print(sixDec.format(req * 100) + " ");
                }
            }

            // PUT ANSWER HERE
            pw.println();
        }

        pw.flush();
        pw.close();
        sc.close();
    }

}
