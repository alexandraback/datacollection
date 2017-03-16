import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class A
{
  public static void main(String[] args) throws Exception
  {
    Scanner in = new Scanner(new File("problem.in"));
    PrintStream out = new PrintStream("problem.out");

    int T = in.nextInt();

    for(int test = 1; test <= T; test++)
    {
      long r = in.nextLong();
      long t = in.nextLong();

      int count = 0;
      while(t >= 2 * r + 1)
      {
        count++;
        t -= 2 * r + 1;
        r += 2;
      }

      out.println("Case #" + test + ": " + count);
    }

  }

}
