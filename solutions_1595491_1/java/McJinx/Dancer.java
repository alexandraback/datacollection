import java.util.*;
import java.io.*;
public class Dancer 
{
  public static void main(String[] args) 
  {
    Scanner in = new Scanner(new BufferedInputStream(System.in));
    int T = in.nextInt();
    for(int i = 0; i < T; i++) 
    {
      int N = in.nextInt();
      int S = in.nextInt();
      int p = in.nextInt();
      int minTotal = p*3-4;
      int minTotalnoS = p*3-2;
      if(p <= 1)
      {
        minTotal = p;
        minTotalnoS = p;
      }
      int surprises = 0;
      int dancers = 0;
      //int[] scores = new int[N];
      for(int j = 0; j < N; j++)
      {
       // scores[j] = in.nextInt();
        int score = in.nextInt();
        if(score >= minTotal) {
          dancers++;
          if(score < minTotalnoS) 
            surprises++;
        }
      }
      if(S < surprises)
        dancers -= (surprises - S);
      System.out.printf("Case #%d: %d\n",i+1,dancers);
    }
  }
}