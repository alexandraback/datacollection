import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Vector;


public class Problem3 {

	private static String fileDirectory = "files/";
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Solve(fileDirectory + "sample.in",fileDirectory + "sample.out");
		Solve(fileDirectory + "C-small-attempt0.in",fileDirectory + "C-small-attempt0.out");
		//Solve(fileDirectory + "C-large.in",fileDirectory + "C-large.out");
	}
	
	public static void Solve(String inFile, String outFile)
	{
		
		try {
			//Initialize IO
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			
			//Read the number of cases
			int cases = Integer.parseInt(br.readLine());
			
			//Loop through test cases
			for (int i = 0; i < cases; i++)
			{
				HashMap<Integer, Vector<Integer>> map = new HashMap<Integer, Vector<Integer>>();
				//Most likely we only want to newline after the first test case
				if (i > 0)
				{
					bw.newLine();
				}
				
				//Almost always want to read the line this way
				String line = br.readLine();
				
				//If multiple values per line, use this to split and store them.
				String[] numbers = line.split(" ");
				int N = Integer.parseInt(numbers[0]);
				
				int[] s = new int[N];
				for (int j = 1; j <= N; j++)
				{
					s[j-1] = Integer.parseInt(numbers[j]);
				}
				Vector<Integer> A = null, B = null;
				boolean impossible = true;
				for (int j = 0; j < (1<<N); j++)
				{
					Vector<Integer> subset = new Vector<Integer>();
					for (int k=0; k < N; k++)
					{
						if ((j&(1<<k)) > 0)
							subset.add(s[k]);
					}
					
					int sum = 0;
					for (int k=0; k<subset.size(); k++)
					{
						sum += subset.get(k);
					}
					if (map.containsKey(sum))
					{
						A = subset;
						B = map.get(sum);
						impossible = false;
						break;
					}
					else
					{
						map.put(sum, subset);
					}
				}

				String results = "";
				
				if (impossible)
				{
					results = "Impossible";
				}
				else
				{
					
					for (int k=0; k<A.size(); k++)
					{
						if (k > 0)
						{
							results += " ";
						}
						results += A.get(k);
					}
					results += "\n";
					
					for (int k=0; k<B.size(); k++)
					{
						if (k > 0)
						{
							results += " ";
						}
						results += B.get(k);
					}
				}
				
				//Often times we will want to count the number of something for the results
				//int count = 0;
				
				
				//START LOGIC HERE
				
				
				
				
				
				
				//END LOGIC HERE
				
				//Print out test case number
				bw.write("Case #" + (i+1) + ": ");
				bw.newLine();
				//Write the result
				bw.write(results);
			}
			
			
			
			
			//Clean up IO
			bw.close();
			br.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
