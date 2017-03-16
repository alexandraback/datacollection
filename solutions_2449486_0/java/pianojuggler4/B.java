import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();
		
		outer: for(int X=1;X<=T;X++) {
			int N = in.nextInt();
			int M = in.nextInt();
			
			int x[][] = new int[N][M];
			for(int n=0;n<N;n++) {
				for(int m=0;m<M;m++) {
					x[n][m] = in.nextInt();
				}
			}
			
			for(int n=0;n<N;n++) {
				for(int m=0;m<M;m++) {
					boolean t1 = false, t2 = false;
					int C = x[n][m];
					for(int a=0;a<N;a++) {
						if(x[a][m] > C) {
							t1 = true;
						}
					}
					for(int a=0;a<M;a++) {
						if(x[n][a] > C) {
							t2 = true;
						}
					}
					if(t1 && t2) {
						out.write("Case #" + X + ": NO\n");
						continue outer;
					}
				}
			}
			
			out.write("Case #" + X + ": YES\n");
		}
		
		in.close();
		out.close();
	}
}