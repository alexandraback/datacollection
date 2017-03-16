import java.util.*;
import java.io.*;

// naomi, ken

public class D
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int numBlocks = input.nextInt();
            double[] ken = new double[numBlocks];
            double[] naomi = new double[numBlocks];
            for (int i = 0; i < numBlocks; i++)
                naomi[i] = input.nextDouble();
            for (int i = 0; i < numBlocks; i++)
                ken[i] = input.nextDouble();

            int ans1 = 0;
            TreeSet<Double> naomis = new TreeSet<Double>();
            for (double num : naomi)
                naomis.add(num);
            for (double num : ken)
            {
                Double other = naomis.higher(num);
                if (other != null)
                {
                    naomis.remove(other);
                    ans1++;
                }
            }

            int ans2 = 0;
            TreeSet<Double> kens = new TreeSet<Double>();
            for (double num : ken)
                kens.add(num);
            for (double num : naomi)
            {
                Double other = kens.higher(num);
                if (other != null)
                    kens.remove(other);
                else
                    ans2++;
            }

            System.out.printf("Case #%d: %d %d\n", n + 1, ans1, ans2);
        }
    }
}

