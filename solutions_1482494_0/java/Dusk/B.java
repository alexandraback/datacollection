import java.io.*;
import java.util.*;

public class B implements Runnable{
	public void run(){
		try{
			Scanner in = new Scanner(new File("B-small.in"));
			PrintWriter out = new PrintWriter("B-small.out");
			int t = in.nextInt(), n, k, ans = 0, stars, i, j, buf;
			int[] a = new int[1000], b = new int[1000], c = new int [1000];
			boolean h1, h2;
			for (k = 1; k <= t; k++){
				n = in.nextInt();
				h1 = false;
				h2 = true;
				for (i = 0; i < n; i++){
					a[i] = in.nextInt();
					if (a[i] == 0) h1 = true;
					if (a[i] > 2 * n - 2) h2 = false;
					b[i] = in.nextInt();
					if (b[i] > 2 * n - 1) h2 = false;
				}
				stars = 0;
				if (h1 && h2){
					for (i = 0; i < n - 1; i++){
						for (j = i + 1; j < n; j++)
							if (a[i] > a[j]){
								buf = a[i];
								a[i] = a[j];
								a[j] = buf;
								buf = b[i];
								b[i] = b[j];
								b[j] = buf;
							} else
							if ((a[i] == a[j]) && (b[i] < b[j])){
								buf = b[i];
								b[i] = b[j];
								b[j] = buf;
							}
						c[i] = 0;
					}
					c[n-1] = 0;
					ans = 0;
					h1 = true;
					while (h1 && (stars < n * 2)){
						h1 = false;
						h2 = true;
						while (h2){
							h2 = false;
							for (i = 0; i < n; i++)
								if ((c[i] < 2) && (b[i] <= stars)){
									stars += (2 - c[i]);
									c[i] = 2;
									h1 = h2 = true;
									ans++;
								}
						}
						for (i = 0; i < n; i++)
							if ((c[i] == 0) && (a[i] <= stars)){
								c[i] = 1;
								stars++;
								ans++;
								h1 = true;
								break;
							}
					}
				}
				out.print("Case #" + k + ": ");
				if (stars >= n * 2) out.println(ans); else out.println("Too Bad");
			}
			out.close();
		}
		catch(Exception e){
//			System.out.println(e.toString());
		}
	}

	public static void main(String args[]){
		(new Thread(new B())).start();
	}
}