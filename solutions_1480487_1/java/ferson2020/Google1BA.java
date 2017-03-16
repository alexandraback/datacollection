import java.io.*;
import java.util.*;

public class Google1BA
{   public static void main(String[] args) throws Throwable
    {   new Google1BA();
    }
    
    public Google1BA() throws Throwable
    {   Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   int numContestants = in.nextInt();
            int[] scores = new int[numContestants];
            int totalScore = 0;
            for (int j = 0; j < numContestants; j++)
            {   scores[j] = in.nextInt();
                totalScore += scores[j];
            }
            out.print("Case #" + (i + 1) + ":");
            for (int j = 0; j < numContestants; j++)
            {   double voteLeft = 100;
                int numEqual = 1;
                boolean[] checked = new boolean[numContestants];
                checked[j] = true;
                for (int k = 0; k < numContestants; k++)
                {   if (scores[k] < scores[j])
                    {   voteLeft -= ((double)scores[j] - scores[k]) * 100 / totalScore;
                        numEqual++;
                        checked[k] = true;
                    }
                }
                if (voteLeft <= 0)
                {   out.print(" " + 0.0);
                }
                else
                {   double score = voteLeft * totalScore / (100 * numEqual) + scores[j];
                    int behind = getBehind(scores, checked, score);
                    while (behind != -1)
                    {   score = (score * numEqual + scores[behind]) / (numEqual + 1);
                        numEqual++;
                        checked[behind] = true;
                        behind = getBehind(scores, checked, score);
                    }
                    double answer = (score - scores[j]) * 100 / totalScore;
                    out.print(" " + answer);
                }
            }
            out.println();
        }
        out.close();
    }
    
    private int getBehind(int[] scores, boolean[] checked, double score)
    {   int toRet = -1;
        for (int i = 0; i < scores.length; i++)
        {   if (!checked[i] && scores[i] < score && (toRet == -1 || scores[i] < scores[toRet]))
            {   toRet = i;
            }
        }
        return toRet;
    }
}