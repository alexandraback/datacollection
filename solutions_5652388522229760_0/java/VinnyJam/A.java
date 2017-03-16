import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small.in"));
		PrintWriter out = new PrintWriter(new File("A_small.txt"));
		int T = in.nextInt();
		for (int t =0; t<T; t++){
			int n = in.nextInt();
			if (n != 0){
			boolean[] d = new boolean[10];
			int step = 0;
			int count = 10;
			while (count>0){
				step++;
				int m = step*n;
				while (m>0){
					int di = m%10;
					if (!d[di]){
						d[di]=true;
						count--;
					}
					m = m/10;
				}
			}
			out.println("Case #"+(t+1)+": "+step*n);
			}
			else{
				out.println("Case #"+(t+1)+": INSOMNIA");
			}
		}
		out.close();

	}

}
