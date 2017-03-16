import java.util.*;

public class Energy2
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      int E = in.nextInt();
      int R = in.nextInt();
      int N = in.nextInt();
      int []v = new int[N];
      for(int j = 0; j < v.length; j++) v[j] = in.nextInt();
      
      System.out.println("Case #" + i + ": " + AB(E, R, v, 0, v.length, E, R));
    }
  }
  
  public static long AB(long E, long R, int []v, int lo, int hi, long A, long B)
  {
    if(hi - lo == 0) { return 0; }
    if(hi - lo == 1) { return (A + R - B) * v[lo]; }
    int maxInd = lo;
    for(int i = lo + 1; i < hi; i++) if(v[i] > v[maxInd]) maxInd = i;
    long micro = 0;
    
    long peak = A + (maxInd - lo) * R;
    if(peak > E) { micro += AB(E, R, v, lo, maxInd, A, E); peak = E; }
    
    long trough = B - (hi - maxInd) * R;
    if(trough < 0) { micro += AB(E, R, v, maxInd + 1, hi, Math.min(R, E), B); trough = 0; }
    
    return micro + (peak - trough) * v[maxInd];
  }
}