import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class A {
	public static void main (String [] args) throws IOException {new A().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		int times = file.nextInt();
		for(int asdf = 0; asdf<times; asdf++){
			int n = file.nextInt();
			int[] ar = new int[n];
			int[] count = new int[101];
			int[] tot = new int[101];
			int sum = 0;
			int max = 0;
			for(int i = 0; i<n; i++){
				sum += ar[i] = file.nextInt();
				max = Math.max(max,ar[i]);
				count[ar[i]] ++;
			}
			out.print("Case #" + ( asdf+1)+": ");
			double goal = Math.max(max,sum*2/n);
			for(int i = 0; i<n; i++)
				if( count[ar[i]] == 1 || count[ar[i]] == n)
					out.printf("%.6f%s", (goal-ar[i])*100/sum, i==n-1?"":" ");
				else
					out.printf("%.6f%s", ((goal-ar[i])/(count[ar[i]])+ar[i])*100/sum, i==n-1?"":" ");
			out.println();
		}
		out.close();
		System.exit(0);
	}
}