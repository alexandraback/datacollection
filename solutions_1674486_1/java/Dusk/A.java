import java.io.*;
import java.util.*;

public class A implements Runnable{
	public void run(){
		try{
			Locale.setDefault(Locale.US);
			Scanner in = new Scanner(new File("A-large.in"));
			PrintWriter out = new PrintWriter("A-large.out");
			boolean[][] h = new boolean[1010][1010];
			boolean hh;
			int tt = in.nextInt(), k, i, j, m, n, t;
			for (k = 1; k <= tt; k++){
				out.print("Case #" + k + ": ");
				n = in.nextInt();
				for (i = 1; i <= n; i++){
					for (j = 1; j <= n; j++) h[i][j] = false;
					m = in.nextInt();
					for (j = 1; j <= m; j++)
						h[i][in.nextInt()] = true;
				}
				hh = false;
				for (t = 1; t <= n; t++){
					for (i = 1; i <=n; i++){
						if (t != i)
							for (j = 1; j <= n; j++)
								if ((t != j) && (i != j))
									if (h[i][t] && h[t][j])
										if (h[i][j]){
											out.println("Yes");
											hh = true;
											break;
										} else h[i][j] = true;
						if (hh) break;
					}
					if (hh) break;
				}
				if (!hh) out.println("No");
				
			}
			out.close();
		}
		catch(Exception e){
//			System.out.println(e.toString());
		}
	}

	public static void main(String[] args){
		(new Thread(new A())).start();
	}
}