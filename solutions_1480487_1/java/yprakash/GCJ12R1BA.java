import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;

public class GCJ12R1BA
{
	private static String output, newline = System.getProperty("line.separator");

	private static void fun() throws IOException
	{
		int n, ntc, i, j, count;
		double d, sum, ex;
		Scanner sc = new Scanner(new File("A-large.in"));
		ntc = sc.nextInt();
		int[] arr;
		boolean[] b;
		double[] ans;
		for(i=1; i<=ntc; i++) {
			output += "Case #" + i + ":";
			ex = sum = count = 0;
			n = sc.nextInt();
			b = new boolean[n];
			ans = new double[n];
			arr = new int[n];

			for(j=0; j<n; j++) {
				sum += (arr[j] = sc.nextInt());
			}
			for(j=0; j<n; j++) {
				d = 200.0 / n - (100*arr[j]) / sum;
				//ans[j] = d;
				if(d >= 0) {
					ans[j] = d;
				}
				else {
					b[j] = true;
					count++;
					ex -= d;
				}
			}
			if(count > 0) {
				ex /= (n - count);
				for(j=0; j<n; j++)
					if(!b[j])
						ans[j] -= ex;
			}
			for(j=0; j<n; j++) {
				output += " " + ans[j];
			}
			output += newline;
		}
		sc.close();
	}

	public static void main(String[] args) throws IOException
	{
		output = "";
		fun();
		OutputStream fo = new FileOutputStream("A-large.out");
		fo.write(output.getBytes());
		fo.close();
	}
}
