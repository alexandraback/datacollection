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

      long count = Math.min((long) Math.sqrt(t / 2), t / (2 * r - 1));

      while(2 * count * count + (2 * r - 1) * count > t)
      {
        count--;
      }

      out.println("Case #" + test + ": " + count);
    }

  }

}
