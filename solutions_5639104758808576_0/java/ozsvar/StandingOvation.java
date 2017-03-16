import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class StandingOvation {

	List<ArrayList<Integer>> cases = new ArrayList<ArrayList<Integer>>();
	List<Integer> results = new ArrayList<Integer>();
	
	/*
	 * Read file method
	 */
	public void readFile(String fileName)
	{
		Scanner scanner;
		try {
			scanner = new Scanner(new File(fileName));

			int testCases = scanner.nextInt();
 
			//System.out.println("testCases: "+ testCases);
			scanner.nextLine();
			for(int i=0; i<testCases; ++i)
			{
				String currentLine = scanner.nextLine();
				
				//System.out.println("currentLine:" +currentLine);
				
				int maxShy = Character.getNumericValue(currentLine.charAt(0));
				//System.out.println("maxShy: " + maxShy);
				cases.add(new ArrayList<Integer>());
				
				for(int j = 2; j <= maxShy+2; ++j){
					
					int number = Character.getNumericValue(currentLine.charAt(j));
					cases.get(i).add(number);
				}
				
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		
	}
	
	/*
	 * Write file method
	 */
	public void writeFile(String fileName)
	{
		PrintWriter writer;
		try {
			writer = new PrintWriter(fileName);
			
			int counter = 0;
			for(int res : results)
			{
				writer.print("Case #" + (++counter) + ": " + res);
				if(counter<results.size())
				{
					writer.println();
				}
			}
			
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		
	} 
	
	public void solve()
	{
		for(ArrayList<Integer> testCase : cases)
		{
			int sum = 0; 
			int friends = 0;
			for(int i = 0; i < testCase.size(); ++i)
			{
				
				if(testCase.get(i)>0 && i>sum)
				{
					friends +=  i - sum;
					sum += friends;
				}
				sum += testCase.get(i);
			}
			
			results.add(friends);
		}
	}
	
	public static void main(String[] args)
	{
		StandingOvation so = new StandingOvation();
		
		so.readFile("A-small-attempt2.in");
		
		so.solve();
		
		so.writeFile("A-small-attempt2.out");
	}
	
}
