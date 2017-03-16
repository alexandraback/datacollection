import java.util.*;
import java.text.DecimalFormat;

class A
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    DecimalFormat df = new DecimalFormat("0.000000");
    int numCase, n, sum, counter,counter2;
    double [] scores;
    double [] result;
    double target;
    
    numCase = sc.nextInt();
    
    for(int i = 0; i < numCase; i++)
    {
      sum = 0;
      counter = 0;
      counter2 = 0;
      n = sc.nextInt();
      scores = new double[n];
      result = new double[n];
      for(int j = 0; j < n; j++)
      {
        scores[j] = (double)sc.nextInt();
        sum += scores[j];
      }
      target = (2*sum)/(double)n;
      
      for(int j = 0; j < n; j++)
        result[j] = (double)(target - scores[j])/(double)sum * 100;

      for(int j = 0; j < n; j++)
      {
        if(result[j] < 0)
          counter++;
      }
      for(int j = 0; j < n; j++)
      {
        if(result[j] < 0)
        {
          for(int k = 0; k < n; k++)
          {
            if(result[k] > 0)
              result[k] += result[j]/ (double)(n-counter);
          }
          result[j] = 0;
        }
      }
      System.out.print("Case #" + (i+1) + ": ");
      for(int j = 0; j < n; j++)
      {
        System.out.print(df.format(result[j]));
        if(j != n-1)
          System.out.print(" ");
      }
      System.out.println();
    }
  }
}