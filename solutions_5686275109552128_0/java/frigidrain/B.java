import java.io.*;

public class B
{

  public static int solve(int[] P, int max) {
    int res = Integer.MAX_VALUE;
    for(int h = 1; h <= max; h++) {
      int t = 0;
      for(int p : P) {
        if(p > h) {
          if(p % h == 0)
            t += p/h - 1;
          else
            t += p/h;
        }
      }
      res = Math.min(h + t, res);
    }
    return res;
  }


	public static void main(String[] args) throws IOException
	{  
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    for(int t = 1; t <= T; t++) {
      int D = Integer.parseInt(br.readLine());
      int[] P = new int[D];
      String[] tokens = br.readLine().split(" ");
      int max = 0;
      for(int i = 0; i < P.length; i++) {
        P[i] = Integer.parseInt(tokens[i]);
        max = Math.max(P[i], max);
      }
      System.out.format("Case #%d: %d\n", t, solve(P, max));
    }
    br.close();
	}
}
