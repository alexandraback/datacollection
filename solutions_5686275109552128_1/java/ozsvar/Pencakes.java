import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Pencakes {

	
	List<Integer> results = new ArrayList<Integer>();
	List<ArrayList<Integer>> testCases = new ArrayList<ArrayList<Integer>>();
	
	/*
	 * Read file method
	 */
	public void readFile(String fileName) {
		Scanner scanner;
		try {
			scanner = new Scanner(new File(fileName));

			int testCaseNumber = scanner.nextInt();

			scanner.nextLine();
			for (int i = 0; i < testCaseNumber; ++i) {
				
				int plates = scanner.nextInt();
				testCases.add(new ArrayList<Integer>());
				for(int j=0; j < plates; ++j){
					testCases.get(i).add(scanner.nextInt());			
				}
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	/*
	 * Write file method
	 */
	public void writeFile(String fileName) {
		PrintWriter writer;
		try {
			writer = new PrintWriter(fileName);

			int counter = 0;
			for (int res : results) {
				
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

	public void solve() {
		for(ArrayList<Integer> testCase : testCases)
		{
			 Collections.sort(testCase);
			 
			 int max = testCase.get(testCase.size()-1);
			 int min = max;
			 int sum;
		        for(int i = 1 ; i <= max; i++) {
		            sum = i ;
		            for(int j = 0 ; j < testCase.size() ; j++) {
		                if( testCase.get(j) > i ) {
		                    if( testCase.get(j)%i == 0 )
		                        sum += (testCase.get(j)/i-1) ;
		                    else
		                        sum += (testCase.get(j)/i) ;
		                }
		            }
		            min = (min < sum) ? min : sum;
		        }
			 
		        //System.out.println("min1: "+ min);
		        results.add(min);
			// System.out.println(testCase);
			
		}
	}

	public static void main(String[] args) {
		Pencakes p = new Pencakes();

		p.readFile("B-large.in");

		p.solve();

		p.writeFile("B-large.out");
	}
}
