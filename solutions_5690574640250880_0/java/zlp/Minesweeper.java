import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Class: Minesweeper<br />
 * Date: 2014/04/12 21:46<br />
 * Description:<br />
 *
 * @author Laiping Zhou(sjtudesigner)
 */
public class Minesweeper {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int cases = sc.nextInt();
        for (int times = 1;times <= cases;times++)
        {
            out.printf("Case #%d:\n", times);
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int[] array = new int[R];
            int less = R * C - M;
            boolean found = false;

            if (R == 1)
            {
                array[0] = less;
                found = true;
            }
            else if (C == 1)
            {
                for (int i = 0;i < less;i++)
                    array[i] = 1;
                found = true;
            }
            else if (less == 1)
            {
                array[0] = 1;
                found = true;
            }
            else// if (less / R >= 2 && less % R != R - 1)
            {
                for (int i = 2;i <= R;i++)
                {
                    if (less / i >= 2 && less / i + ((less % i == 0) ? 0 : 1) <= C)
                    {
                        int j = 0;
                        for (j = 0;j < less % i;j++)
                        {
                            array[j] = less / i + 1;
                        }
                        for (;j < i;j++)
                            array[j] = less / i;

                        found = true;
                        if (less % i == 1)
                        {
                            if (less / i > 2 && i > 2)
                            {
                                array[1]++;
                                array[i - 1]--;
                            }
                            else { Arrays.fill(array, 0); found = false; continue; }
                        }
                        break;
                    }

                }

                if (!found)
                for (int i = 2;i <= C;i++)
                {
                    if (less / i >= 2 && less / i + ((less % i == 0) ? 0 : 1) <= R)
                    {
                        int j = 0;
                        for (j = 0;j < less / i;j++)
                        {
                            array[j] = C;
                        }
                        if (less % i != 0) array[j] = less % i;

                        found = true;
                        if (less % i == 1)
                        {
                            if (less / i > 2 && i > 2)
                            {
                                array[j]++;
                                array[j - 1]--;
                            }
                            else { Arrays.fill(array, 0); found = false; continue; }
                        }
                        break;
                    }
                }
            }

            if (found)
            {
                out.print('c');
                int j = 1;
                while (j < array[0]) { out.print('.'); j++; }
                while (j < C)
                {
                    out.print('*');
                    j++;
                }
                out.println();
                for (int i = 1;i < R;i++)
                {
                    j = 0;
                    while (j < array[i]) { out.print('.'); j++; }
                    while (j < C)
                    {
                        out.print('*');
                        j++;
                    }
                    out.println();
                }
            }
            else out.println("Impossible");
        }
        out.close();
    }

}
