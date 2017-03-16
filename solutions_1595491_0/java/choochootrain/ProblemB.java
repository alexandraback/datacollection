/*
choochootrain
Google Code Jam 2012
*/
import java.io.*;
import java.util.*;

class ProblemB
{
  public static void main (String [] args) throws IOException 
  {
    String filename = "B-small-attempt0";  
    BufferedReader f = new BufferedReader(new FileReader(filename + ".in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")));
    int numberOfTests = Integer.parseInt(f.readLine());
    for(int n = 1; n <= numberOfTests; n++)
    {
      StringTokenizer st = new StringTokenizer(f.readLine());
      int numPeople = Integer.parseInt(st.nextToken());
      int numSurprising = Integer.parseInt(st.nextToken());
      int threshold = Integer.parseInt(st.nextToken());
      ArrayList<Integer> points = new ArrayList<Integer>(numPeople);
      for(int i = 0; i < numPeople; i++) {
        points.add(Integer.parseInt(st.nextToken()));
      }

      int num = 0;
      for(int i = 0; i < points.size(); i++) {
        if(max(makeNormal(points.get(i))) >= threshold) {
          num++;
          points.remove(i);
          i--;
        }
      }

      for(int i = 0; i < points.size() && numSurprising > 0; i++) {
        if(max(makeSurprising(points.get(i))) >= threshold) {
          num++;
          numSurprising--;
          points.remove(i);
          i--;
        }
      }
      String solution = "" + num;
      out.println("Case #" + n + ": " + solution);
    }
    out.close();
    System.exit(0);
  }

  private static int max(int[] nums) {
    if (Math.min(Math.min(nums[0], nums[1]), nums[2]) >= 0)
      return Math.max(Math.max(nums[0], nums[1]), nums[2]);
    else
      return -1;
  }

  private static int[] make (int a, int b, int c) {
    int[] arr = new int[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    return arr;
  }

  private static int[] makeNormal(int total) {
    if (total % 3 == 0)
      return make(total/3, total/3, total/3);
    else if (total % 3 == 1)
      return make(total/3, total/3, total/3 + 1);
    else
      return make(total/3, total/3 + 1, total/3 + 1);
  }
  
  private static int[] makeSurprising(int total) {
    if (total % 3 == 0)
      return make(total/3 - 1, total/3, total/3 + 1);
    else if (total % 3 == 1)
      return make(total/3 - 1, total/3 + 1, total/3 + 1);
    else
      return make(total/3, total/3, total/3 + 2);
  }
}
