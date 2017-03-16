import java.io.*;
import java.util.*;

public class password
{
	
	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
			PrintWriter pw = new PrintWriter(new FileWriter("output.out"));
			
			int T = Integer.parseInt(br.readLine());
			
			for (int t = 1; t <= T; t++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine(), " ", false);
				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				
				double[] ps = new double[A];
				st = new StringTokenizer(br.readLine(), " ", false);
				
				double E = A+B+1; // backspace all and redo
				double probPass = 1;
				for (int i = 0; i < A; i++)
				{
					ps[i] = Double.parseDouble(st.nextToken());
					probPass *= ps[i];
					
					double E2 = probPass*(A+B-2*(i+1)+1) + (1-probPass)*(A+B-2*(i+1)+1+B+1);
					if (E2 < E) E = E2;

					// System.out.println(t+": "+probPass+", "+i+", "+E2);
				}
				double E3 = 1+B+1; // enter right away
				if (E3 < E) E = E3;
				
				java.text.DecimalFormat fmt = new java.text.DecimalFormat("#.000000");
				pw.println("Case #"+t+": "+fmt.format(E));
			}
			
			pw.flush(); pw.close();
			br.close();
		}
		catch (IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
}