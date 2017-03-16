/*
choochootrain
Google Code Jam 2012
*/
import java.io.*;
import java.util.*;

class ProblemC 
{
  public static Set<String> seen;
  public static int a;
  public static int b;

  public static void main (String [] args) throws IOException 
  {
    String filename = "C-small-attempt0";  
    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    seen = new HashSet<String>();
    for(int n = 1; n <= numberOfTests; n++)
    {
      StringTokenizer st = new StringTokenizer(f.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());

      for(int i = a; i <= b; i++) {
        findNumRotations(i);
      }
      
      int solution = seen.size();
      out.println("Case #" + n + ": " + solution);

      seen = new HashSet<String>();
    }
    out.close();

    System.exit(0);
  }

  public static void findNumRotations(int num) {
    int numRots = getRotationCount(num);

    for(int i = 1; i <= numRots; i++) {
      int rotated = rotate(num, i, numRots + 1);
      if (rotated > num && rotated <= b) {
        seen.add(num + " " + rotated);
        System.out.println(num + " " + rotated);
      }
    }
  }

  private static int rotate(int num, int amt, int digits) {
    int bottom = (int)(num / Math.pow(10, amt));
    int top = (int)(num % Math.pow(10, amt));

    return (int)(top * Math.pow(10, digits - amt) + bottom);
  }

  private static int getRotationCount(int num) {
    if (num < 10)
      return 0;

    int c = 0;
    while(num > 0) {  
      num = num / 10;
      c++;
    }

    return c - 1;
  }
}
