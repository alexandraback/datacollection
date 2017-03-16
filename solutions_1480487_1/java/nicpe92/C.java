import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;

public class C {


	public static void main (String[] args)
	{


		try {
			//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/A-large.in"))));
			PrintWriter pw = new PrintWriter(System.out);
			int cases = Integer.parseInt(in.readLine());	
			for (int i = 0; i < cases; i++) {
				String[] l = in.readLine().split(" ");
				int N = Integer.parseInt(l[0]);
				int sum = 0;
				StringBuffer rta = new StringBuffer();
				int[] scores = new int[N];
				for (int j = 0; j < scores.length; j++) {
					scores[j] = Integer.parseInt(l[j+1]);
					sum+=scores[j];
				}
				double a = 2*sum;
				a/=(double)N;
				DecimalFormatSymbols dfs = new DecimalFormatSymbols();
				dfs.setDecimalSeparator('.');
				DecimalFormat df = new DecimalFormat("#0.000000", dfs);
				int sumB=0;
				int numB=0;
				for (int j = 0; j < scores.length; j++) {
					if(scores[j]>a)
					{
						sumB+=scores[j];
						numB++;
					}
				}
				a=2*sum-sumB;
				a/=(double)(N-numB);
				for (int j = 0; j < scores.length; j++) {
					double b = a-scores[j];
					b/=(double)sum;
					b*=100;
					if(b<0)
						b=0;
					rta.append(" "+df.format(b));
				}
				System.out.println("Case #"+(i+1)+":"+rta);
				}

				
			pw.flush();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
