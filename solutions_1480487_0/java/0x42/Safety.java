import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.text.DecimalFormat;


public class Safety {

	public static void main(String[] args) throws Exception {
		Safety object = new Safety();
			object.solve(object.getClass().getSimpleName().toLowerCase());
		}
		
		private void solve(String filePrefix) throws Exception {
			
			StreamTokenizer st = new StreamTokenizer(new BufferedReader(new FileReader(filePrefix + ".in")));
			PrintWriter pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
			
			st.nextToken();
			int testsCount = (int) st.nval;
			
			for (int tc=0; tc<testsCount; tc++)
			{
				st.nextToken();
				int n = (int) st.nval;
				
				int values[] = new int[n];
				
				double sum = 0;
				
				for (int i=0; i<n; i++)
				{
					st.nextToken();
					values[i] = (int) st.nval;
					
					sum += values[i];
				}
				
				double result[] = new double[n];
				
				for (int i=0; i<n; i++)
				{
					double left = 0.0, right = 1.0;
					
					for (int tt=0; tt<100; tt++)
					{									
						double current = (left+right)/2.0;
						
						double sumYi = current;
						boolean okLarge = true;
												
						for (int j=0; j<n; j++)
							if (i != j)
							{
								double c = values[i];
								double o = values[j];
								
								double req = (c+sum*current-o)/sum;
								
								if (req > 1.0)
									okLarge = false;
								
								if (req >= 0)									
									sumYi += req;
							}
						
						if (sumYi > 1 || !okLarge)
							right = current;
						else
							left = current;
					}
					
					result[i] = 100 * ((left+right)/2.0);
				}
				
				DecimalFormat formatter = new DecimalFormat("0.00000000000");
				
				pw.write("Case #" + (tc+1) + ": " + formatter.format(result[0]));
				
				for (int z=1; z<n; z++)
					pw.write(" " + formatter.format(result[z]));
					
				pw.write("\n");
			}
			
			pw.flush();
			pw.close();
			
		}
}
