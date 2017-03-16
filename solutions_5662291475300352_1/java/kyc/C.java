import java.util.*;
import java.io.*;

public class C
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            List<Hiker> hikers = new ArrayList<Hiker>();
            for (int i = 0; i < N; i++)
            {
                int D = input.nextInt();
                int H = input.nextInt();
                int M = input.nextInt();
                for (int j = 0; j < H; j++)
                    hikers.add(new Hiker(D, M + j));
            }

            long minEncounters = Long.MAX_VALUE;
            for (Hiker follow : hikers)
            {
                long numEncounters = 0;
                for (Hiker hiker : hikers)
                {
                    if (hiker.cross > follow.cross)
                        numEncounters++;
                    else
                        numEncounters += (follow.cross - hiker.cross) / (360L * hiker.M);
                }
                if (numEncounters < minEncounters)
                    minEncounters = numEncounters;
            }

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(minEncounters);
        }
    }

    static class Hiker
    {
        int D;
        int M;
        long cross;
        boolean passed;

        Hiker(int D, int M)
        {
            this.D = D;
            this.M = M;
            this.cross = (360L - D) * M;
            this.passed = false;
        }
    }
}
