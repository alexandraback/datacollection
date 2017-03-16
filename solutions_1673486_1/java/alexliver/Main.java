import java.util.*;
import java.io.*;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		sc.nextLine();
		
		for(int cs = 1; cs<=cases; cs++)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			double [] arr = new double[n];
			for(int i=0; i<n; i++)
				arr[i] = sc.nextDouble();
			double best = Double.MAX_VALUE;
			double total = 1;
			int i=0;
			for(double d:arr)
			{
				i++;
				double right = total*d;
				double wrong = 1 - right;
				int rightMoves = (n-i)+m-i+1;
				int wrongMoves = rightMoves+m+1;
				best = Math.min(best, right*rightMoves+wrong*wrongMoves);
				total = right;
			}
			best = Math.min(best, 2+m);
			out.println("Case #"+cs+": "+new java.text.DecimalFormat("#.000000").format(best)  );
		}
		out.close();
		fis.close();
	}



}
