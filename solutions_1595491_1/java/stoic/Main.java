import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;


public class Main {

	private static String fileDirectory = "files/";
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Problem2(fileDirectory + "B-large.in",fileDirectory + "B-large.out");
	}
	
	public static void Problem2(String inFile, String outFile)
	{
		try {
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			

			
			
			int cases = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < cases; i++)
			{
				if (i > 0)
				{
					bw.newLine();
				}
				
				
				String line = br.readLine();
				String[] numbers = line.split(" ");
				int N = Integer.parseInt(numbers[0]);
				int S = Integer.parseInt(numbers[1]);
				int p = Integer.parseInt(numbers[2]);
				
				int count = 0;
				for (int j = 3; j < numbers.length; j++)
				{
					
					int t = Integer.parseInt(numbers[j]);
					if (t >= ((p - 1) + (p - 1) + p) && t >= p)
					{
						count++;
					}
					else if ((t >= ((p - 2) + (p - 2) + p)) && S > 0 && t >= p)
					{
						count++;
						S = S - 1;
					}
					System.out.println(S);
				}
				bw.write("Case #" + (i+1) + ": ");
				bw.write(Integer.toString(count));
			}
			

			bw.close();
			br.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
