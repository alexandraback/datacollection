import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class Main
{
    public static void main(String[] args)
            throws Exception
    {
        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        FileWriter out = new FileWriter(args[1]);
        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++)
        {
            String data[] = in.readLine().split("\\ ");
            int N = Integer.parseInt(data[0]);
            int S = Integer.parseInt(data[1]);
            int p = Integer.parseInt(data[2]);
            int[] totalPoints = new int[N];
            for (int i = 0; i < N; i++)
                totalPoints[i] = Integer.parseInt(data[i + 3]);

            int unconditionalSucc = 0;
            int failed = 0;

            int upperLimit;
            int lowerLimit;

            if (p >= 2)
            {
                upperLimit = 3 * p - 3;
                lowerLimit = 3 * p - 4;
            }
            else if (p == 1)
            {
                upperLimit = 0;
                lowerLimit = 1;
            }
            else
            {
                upperLimit = -1;
                lowerLimit = -1;
            }

            for (int i = 0; i < totalPoints.length; i++)
            {
                if (totalPoints[i] > upperLimit)
                    unconditionalSucc++;
                else if (totalPoints[i] < lowerLimit)
                    failed++;
            }

            int uncertain = N - failed - unconditionalSucc;

            out.write("Case #" + t + ": " + (Math.min(uncertain, S) + unconditionalSucc) + "\n");
        }

        in.close();
        out.close();
    }
}
