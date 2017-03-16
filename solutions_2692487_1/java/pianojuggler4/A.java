import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();
		
		for(int X=1;X<=T;X++) {
			int A = in.nextInt();
			int N = in.nextInt();
			int m[] = new int[N];
			for(int n=0;n<N;n++) {
				m[n] = in.nextInt();
			}
			
			Arrays.sort(m);
			
			int count = 0;
			int temp = Integer.MAX_VALUE;
			
			for(int n=0;n<N;n++) {
				if(A>m[n]) {
					A += m[n];
					continue;
				}
				//remove the rest or
				if(count + (N-n) < temp) {
					temp = count + (N-n);
				}
				
				A += (A-1);
				count++;
				n--;
				if(count > temp) {
					count = temp;
					break;
				}
			}
			
			out.write("Case #" + X + ": " + count + "\n");
		}
		
		in.close();
		out.close();
	}
}