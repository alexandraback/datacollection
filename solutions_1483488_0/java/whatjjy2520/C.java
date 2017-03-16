import java.io.*;
import java.util.*;
public class C {
  static int N = 2000001;
  static int[][] pair = new int[N][6];
  static int[] np = new int[N];

  public static void main (String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	for (int i = 1; i <= 6; i++)
	  gen(i);
	gen(1000000, 2000000, 7);
	/*for (int i = 1; i < 1000; i++)
	  for (int j = 0; j < np[i]; j++)
	    System.out.println(i + " " + pair[i][j]);*/
	int T = Integer.parseInt(in.readLine());
	for (int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(in.readLine());
	  int A = Integer.parseInt(st.nextToken());
	  int B = Integer.parseInt(st.nextToken());
	  int count = 0;
	  for (int i = A; i <= B; i++)
	    for (int j = 0; j < np[i]; j++)
		  if (pair[i][j] <= B)
		    count++;
	  System.out.println("Case #"+(t+1)+": " + count);
	}
	in.close();
  }
  
  static void gen (int d) {
    gen(pow10(d-1), pow10(d)-1, d);
  }
  
  static void gen (int lb, int ub, int d) {
    for (int i = lb; i <= ub; i++) {
	  int n = i;
      for (int j = 0; j < d-1; j++) {
		n = (n%10)*lb+(n/10);
		if (n > i) {
		  boolean found = false;
		  for (int k = 0; k < np[i]; k++)
		  if (pair[i][k] == n)
		    found = true;
		  if (!found) {
		    pair[i][np[i]] = n;
		   np[i]++;
		  }
		}
      }
	}
  }
  
  static int pow10 (int n) {
    int res = 1;
	for (int i = 0; i < n; i++)
	  res *= 10;
	return res;
  }
}