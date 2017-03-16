import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;
import java.util.logging.Formatter;

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
            String[] AB = in.readLine().split("\\ ");
            int A = Integer.valueOf(AB[0]);
            int B = Integer.valueOf(AB[1]);
            String[] Ps = in.readLine().split("\\ ");
            double[] p = new double[Ps.length];
            for (int i = 0; i < Ps.length; i++)
                p[i] = Double.valueOf(Ps[i]);

            double Emin = B + 2;
            // System.out.println(Emin);
            double[] succ = new double[A];
            succ[0] = p[0];
            for (int i = 1; i < A; i++)
            {
                succ[i] = succ[i - 1] * p[i];
            }

            double EKeepTyping = (2.0 - succ[A - 1]) * ((double) B + 1.0) - (double) A;
            // System.out.println(EKeepTyping);

            if (Emin > EKeepTyping)
                Emin = EKeepTyping;

            for (int i = 1; i < A; i++)
            {
                double succN = 2.0 * (double) i + (double) B - (double) A + 1.0;
                double failedN = 2.0 * (double) i + 2.0 * (double) B - (double) A + 2.0;
                double Ei =   succN *  succ[A - i - 1] + failedN * (1.0 -  succ[A - i - 1]);
                // ystem.out.println("Ei " + i + " " + Ei);
                if (Ei < Emin)
                    Emin = Ei;
            }


            String result = String.format(Locale.US, "%.6f", Emin);
            out.write("Case #" + t + ": " + result + "\n");
        }
        in.close();
        out.close();
    }
}
