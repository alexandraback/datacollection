import java.io.*;
import java.util.*;
public class B {
  public static void main (String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int[] best_no_surprise = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
	int[] best_surprise    = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};
	
	int T = Integer.parseInt(in.readLine());
	for (int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(in.readLine());
	  int N = Integer.parseInt(st.nextToken());
	  int S = Integer.parseInt(st.nextToken()); 
	  int p = Integer.parseInt(st.nextToken());
	  int[] a = new int[N];
	  for (int i = 0; i < N; i++)
	    a[i] = Integer.parseInt(st.nextToken());
	  /*System.out.print(N + " " + S + " " + p);
      for (int i = 0; i < N; i++)
	    System.out.print(" " + a[i]);
	  System.out.println();*/
	  
	  int n_over_p = 0;
	  int n_surp = 0;
	  for (int i = 0; i < N; i++) {
	    if (best_no_surprise[a[i]] >= p)
		  n_over_p++;
		if (best_no_surprise[a[i]] < p && best_surprise[a[i]] >= p)
		  n_surp++;
      }
	  int max_val = n_over_p + Math.min(S, n_surp);
	  System.out.println("Case #"+(t+1)+": " + max_val);
	}
	in.close();
  }
  
  static void init () {
  }
}