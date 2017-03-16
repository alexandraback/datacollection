import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Dance {
	private File file = new File("D:\\Sources\\GoogleCodeJam\\files\\B-small-attempt0.in");
	private File outFile = new File("D:\\Sources\\GoogleCodeJam\\files\\result.out");
	
	private Integer[] results;
	private Integer solved = 0;
	
	public void readData() {
		boolean first = true;
		Scanner scanner;
		try {
			scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				Scanner scan = new Scanner(line);
				if (first) {
					results = new Integer[scan.nextInt()];
					first = false;
				} else {
					int[] googlers = new int[scan.nextInt()];
					int sup = scan.nextInt();
					int above = scan.nextInt();
					for (int i = 0; i < googlers.length; i++) {
						googlers[i] = scan.nextInt();
					}
					results[solved] = solveProblem(googlers, sup, above);
					solved++;
				}
			}
			printResult();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private Integer solveProblem(int[] googlers, int sup, int above) {
		if(above == 0)
			return googlers.length;
		int notSup = 0;
		int suprising = 0;
		for (int i = 0; i < googlers.length; i++) {
			if(above * 3 - 2 <= googlers[i]) {
				notSup++;
			} else if(above > 1 && above * 3 - 4 <= googlers[i]) {
				suprising++;
			}
		}
		
		return suprising > sup ? notSup + sup : notSup + suprising;
	}

	private void printResult() {
		try {
			FileWriter fstream = new FileWriter(outFile);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < results.length; i++) {
				out.write("Case #" + (i + 1) + ": " + results[i]);
				out.newLine();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
