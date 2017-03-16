import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;


public class ProbB {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("C-small-attempt0.out"));
		String line;
		
		line = br.readLine();
		int T = Integer.parseInt(line);
		
		for(int i = 0; i < T; i++)
		{
			line = br.readLine();
			String[] tokens = line.split(" ");
			int N = Integer.parseInt(tokens[0]);
			int[] numbers = new int[N];
			for(int j = 0; j < N; j++)
			{
				numbers[j] = Integer.parseInt(tokens[j+1]);
			}
			
			int max = (int) Math.pow(2.0, N);
			//HashSet<Integer> hash = new HashSet<Integer>();
			HashMap<Integer, Integer[]> hash = new HashMap<Integer, Integer[]>();
			for(int j = 0; j < max; j++)
			{
				ArrayList<Integer> store = new ArrayList<Integer>();
				int tag = j;
				int sum = 0;
				for(int k = 0; k < N; k++)
				{
					if(tag % 2 == 1)
					{
						sum += numbers[k];
						store.add(numbers[k]);
					}
					
					tag = tag / 2;
				}
				
				if(hash.containsKey(sum))
				{
					String oline = "Case #" + (i + 1) + ":\n";
					String oneline = "";
					for(int k = 0; k < store.size(); k++)
					{
						oneline += " " + store.get(k);
					}
					oline += oneline.trim() + "\n";
					String twoline = "";
					Integer[] old = hash.get(sum);
					for(int k = 0; k < old.length; k++)
					{
						twoline += " " + old[k];
					}
					oline += twoline.trim() + "\n";
					System.out.println(oline);
					
					bw.write(oline);
					
					break;
				}
				else
					hash.put(sum, store.toArray(new Integer[store.size()]));
			}
		}
		br.close();
		bw.close();

	}

}
