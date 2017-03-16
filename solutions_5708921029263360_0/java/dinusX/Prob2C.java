import java.io.*;
import java.util.Scanner;

/**
 * Created by dinus on 4/30/2016.
 */
public class Prob2C {
    public static void main(String[] args) throws FileNotFoundException {
        if(args.length == 1 && args[0].equals("test"))
        {
            String path = "C:\\codejam\\";
            String filename = "input.txt";
//            String filename = "C-large.in";
            System.setIn(new FileInputStream(new File(path + filename)));

            String outputName= filename.split("\\.")[0] + ".out";
            System.setOut(new PrintStream(new File(path + outputName)));
        }


        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int tests = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int test = 1; test <= tests; ++test) {
            StringBuilder result = new StringBuilder();
            int j = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            int k = in.nextInt();

            int[] jp = new int[101];
            int[] js = new int[101];
            int[] ps = new int[101];

            int total = 0;
            for(int i1=0; i1<j; i1++)
            {
                for(int i2=0; i2<p; i2++ )
                {
                    for(int i3=0; i3<s; i3++)
                    {
                        if(jp[i1*10+i2] < k && js[i1*10+i3] < k && ps[i2*10+i3] < k)
                        {
                            total++;
                            result.append((i1+1) + " " + (i2+1) + " " + (i3+1) + "\n");
                            jp[i1*10+i2]++;
                            js[i1*10+i3]++;
                            ps[i2*10+i3]++;
                        }
                    }
                }
            }
            System.out.println("Case #" + test + ": " + total);
            System.out.print(result);
        }


    }
}
