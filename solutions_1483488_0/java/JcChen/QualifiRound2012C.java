import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;


public class QualifiRound2012C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			PrintWriter pw = new PrintWriter(args[1]);
			String line = br.readLine();
			System.out.println(line);
			int T = Integer.valueOf(line.trim());
			for (int i=0; i<T; i++)
			{
				line = br.readLine();
				System.out.println(line);
				String[] input = line.trim().split(" ");
				int A = Integer.valueOf(input[0]);
				int B = Integer.valueOf(input[1]);
				int result = 0;
				
				for(int j=A; j<=B; j++)
				{
					int bit = (int)Math.floor(Math.log10(A));
					HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
					map.put(j, true);
					
					int pair = (j%10)*(int)Math.pow(10, bit)+ j/10;
					while(!map.containsKey(pair))
					{
						if(j>pair)
						{
							map.put(pair, true);
							pair = (pair%10)*(int)Math.pow(10, bit)+ pair/10;
							continue;
						}

						if(A<=pair && pair<=B)
							result++;
						pair = (pair%10)*(int)Math.pow(10, bit)+ pair/10;
						continue;
					}
				}
				
				pw.println("Case #"+(i+1)+": "+result);
				System.out.println("Case #"+(i+1)+": "+result);
			}
			pw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
