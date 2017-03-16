import java.util.*;

public class a {
  private static void print  (String p) { System.out.print(p);   }
  private static void println(String p) { System.out.println(p); }
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    
    int P = in.nextInt();
    in.nextLine();
    
    for (int p = 1; p <= P; p++) {
      int A = in.nextInt();
	  int N = in.nextInt();
	  int[] m = new int[N];
	  for (int i = 0; i < N; i++) m[i] = in.nextInt();
	  Arrays.sort(m);

	  int ops = 0;
	  if (A == 1) {
		  ops = N;
	  } else for (int i = 0; i < N; i++) {
		  int o = 0;
		  while(A <= m[i]) {
			 A += A-1;
			 o++;
		  }
		  if (o >= N-i) {
			  ops += N-i;
			  break;
		  } else {
			  ops += o;
			  A += m[i];
		  }
	  }
      
      System.out.printf("Case #%d: %d\n", p, ops);
    }
    
  }
}
