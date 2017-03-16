import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class A {
	public static void main(String[] args) {
		A obj = new A();
		String filame = "input.txt";
		if (args.length > 0) {
			filame = args[0];
		}
		obj.redFile(filame);

	}

	public void redFile(String filename) {
		File file = new File(filename);
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			Integer testCasesCount = Integer.parseInt(br.readLine());
			readTestCases(br, testCasesCount);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void readTestCases(BufferedReader br, int testCasesCount)
			throws IOException {
		int testCaseNumber = 1;
		for (String line; (line = br.readLine()) != null;) {
			String[] testCase = line.split("\\s+");
			processCase(testCase, testCaseNumber++);
		}
	}

	private void processCase(String[] visitorsLine, int testCasesCount) {
		int row = Integer.parseInt(visitorsLine[0]);
		int cells = Integer.parseInt(visitorsLine[1]);
		int width = Integer.parseInt(visitorsLine[2]);
//		char[] visitors = visitorsLine.toCharArray();
//		int total = 0;
//		int friends = 0;
//
//		System.out.print("Case #" + testCasesCount + ": ");
//		for (int i = 0; i < visitors.length; i++) {
//			int shameCount = Character.getNumericValue(visitors[i]);
//
//			if (total < i) {
//
//				int frindsToAdd = i - total;
//				total += frindsToAdd;
//				friends += frindsToAdd;
//			}
//			total += shameCount;
//		}
		//System.out.print(row);
		//System.out.print(cells);
		//System.out.println(width);

		int limit =  cells / width;
		int res = limit + width-1;
		
		int fin = res * row;
		int left = cells % width;
		//System.out.println(left);
		if(left != 0 && width != 1){
			fin++;
		}
		
		System.out.println("Case #"+ testCasesCount +": "+ fin);
		//System.out.println();
		
		
	}
}
