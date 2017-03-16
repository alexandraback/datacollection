import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class C
{
  public static void main(String[] args) throws Exception
  {
    Scanner in = new Scanner(new File("problem.in"));
    PrintStream out = new PrintStream("problem.out");

    int T = in.nextInt();

    for(int test = 1; test <= T; test++)
    {
      int r = in.nextInt();
      int n = in.nextInt();
      int m = in.nextInt();
      int k = in.nextInt();

      out.println("Case #" + test + ":");

      for(int i = 0; i < r; i++)
      {
        int n2 = 0, n3 = 0, n5 = 0;

        for(int j = 0; j < k; j++)
        {
          int number = in.nextInt();
          int x2 = 0, x3 = 0, x5 = 0;
          //2
          while(number % 2 == 0)
          {
            x2++;
            number /= 2;
          }
          //3
          while(number % 3 == 0)
          {
            x3++;
            number /= 3;
          }
          //5
          while(number % 5 == 0)
          {
            x5++;
            number /= 5;
          }
          if(x2 > n2)
            n2 = x2;
          if(x3 > n3)
            n3 = x3;
          if(x5 > n5)
            n5 = x5;

        }

        for(int c = 0; c < n3; c++)
        {
          out.print(3);
        }
        for(int c = 0; c < n5; c++)
        {
          out.print(5);
        }
        int left = 3 - n3 - n5;
        while(left > 0)
        {
          if(n2 > left)
          {
            out.print(4);
            n2 -= 2;
          }
          else
          {
            out.print(2);
            n2--;
          }
          left--;
        }
        out.println();

      }

    }
  }

}
