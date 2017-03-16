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
		Problem3(fileDirectory + "C-large.in",fileDirectory + "C-large.out");
	}
	
	public static void Problem3(String inFile, String outFile)
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
				int A = Integer.parseInt(numbers[0]);
				int B = Integer.parseInt(numbers[1]);
				int length = String.valueOf(A).length();
				int count = 0;
				
				
				
				for (int j = A; j <= B; j++)
				{
					String sNum = Integer.toString(j);
					HashMap<Integer, Integer> map = new HashMap<Integer,Integer>();
					//System.out.print(sNum + ": ");
					for (int k = 1; k < length; k++)
					{
						
						String newNum = sNum.substring(k, sNum.length());
						newNum += sNum.substring(0, k);
						//System.out.print(" " + newNum);
						int number = Integer.parseInt(newNum);
						if (number > j && number <= B)
						{
							if (!map.containsKey(number))
							{
								map.put(number, null);
								count++;
							}
						}
						
					}
					//System.out.println();
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
