import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.HashMap;


public class EqualSums {

	public static void main(String[] args) throws Exception {
		EqualSums object = new EqualSums();
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
				
				HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();
				
				int values[] = new int[n];
				
				for (int i=0; i<n; i++)
				{
					st.nextToken();
					values[i] = (int) st.nval;
				}
				
				int sol1=-1, sol2=-1;
				
				for (int i=1; i<(1 << n) && (sol1==-1 && sol2==-1); i++)
				{
					int sum = 0;
					
					for (int j=0; j<n; j++)
						if (((1 << j) & i) != 0)
							sum += values[j];
					
					if (seen.containsKey(sum))
					{
						sol1 = seen.get(sum);
						sol2 = i;
						break;
					}
					
					seen.put(sum, i);												
				}
				
				if (sol1==-1 || sol2==-1)								
					pw.write("Case #" + (tc+1) + ": " + "Impossible" + "\n");
				else
				{
					ArrayList<Integer> first = new ArrayList<Integer>();
					for (int t=0; t<n; t++)
						if (((1 << t) & sol1) != 0)
							first.add(values[t]);
					
					ArrayList<Integer> second = new ArrayList<Integer>();
					for (int t=0; t<n; t++)
						if (((1 << t) & sol2) != 0)
							second.add(values[t]);
					
					pw.write("Case #" + (tc+1) + ":\n");
					
					if (first.size() > 0)
					{
						pw.write(""+first.get(0));
						for (int zz=1; zz<first.size(); zz++)
							pw.write(" " + first.get(zz));						
					}
					
					pw.write("\n");
					
					if (second.size() > 0)
					{
						pw.write(""+second.get(0));
						for (int zz=1; zz<second.size(); zz++)
							pw.write(" " + second.get(zz));						
					}
					
					pw.write("\n");
				}					
			}
			
			pw.flush();
			pw.close();
			
		}
}
