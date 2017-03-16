import java.awt.geom.Arc2D.Double;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Password {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pass.out")));
		
		int numberCases = Integer.parseInt(f.readLine());
		String log;
		StringTokenizer st;
		int typed;
		int total;
		double[] prob;
		
		for (int i = 1; i <= numberCases; i++)
		{
			log = "Case #" + i + ": ";
			st = new StringTokenizer(f.readLine());
			typed = Integer.parseInt(st.nextToken());
			total = Integer.parseInt(st.nextToken());
			prob = new double[typed];
			
			st = new StringTokenizer(f.readLine());
			for (int j = 0; j < typed; j++)
			{
				prob[j] = java.lang.Double.parseDouble(st.nextToken());
			}
			
			log += java.lang.Double.toString(calculateExpected(typed, total, prob));
			out.println(log);
		}
		
		out.close();
		System.exit(0);
	}

	private static double calculateExpected(int typed, int total, double[] p) 
	{
		//keep typing, delete some, restart
		double keepTyping;
		double[] deleteSome = new double[typed];
		double restart;
		
		double allCorrect = 1;
		
		for (int i = 0; i < typed; i++)
		{
			allCorrect *= p[i];
		}
		
		keepTyping = (total + 1 - typed)*allCorrect + (2*total + 2 - typed)*(1 - allCorrect);
		
		for (int i = 1; i <= typed; i++)
		{
			allCorrect = 1;
			
			for (int j = 0; j < typed - i; j++)
			{
				allCorrect *= p[j];
			}
			
			deleteSome[i-1] = (total - typed + 2*i + 1)*allCorrect 
								+ (2*total - typed + 2*i + 2)*(1 - allCorrect);
		}
		
		restart = total + 2.0;
		
		double temp = Math.min(keepTyping, restart);
		
		return Math.min(temp, min(deleteSome));
	}
	
	
	public static double min(double[] a)
	{
		double best = a[0];
		
		for (int i = 1; i < a.length; i++)
		{
			if (a[i] < best)
				best = a[i];
		}
		
		return best;
	}
}
