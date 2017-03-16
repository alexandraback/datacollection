import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class Problem2 {
	public static void main (String[] args) throws IOException {
		File file = new File("input1.txt");
		Scanner scan = null;
		try {
			scan = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		FileWriter fstream = null;
		try {
			fstream = new FileWriter("output.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
		BufferedWriter out = new BufferedWriter(fstream);
		
		int lineNumber;
		lineNumber = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < lineNumber; i++) {
			Scanner lineScan = new Scanner(scan.nextLine());
			out.write("Case #" + (i + 1) + ": ");
			int a = lineScan.nextInt();
			int b = lineScan.nextInt();
			int total = 0;
			
			ArrayList<Integer> prev = new ArrayList<Integer>();
			
			for (int j = a; j <= b; j++) {
				String curr = String.valueOf(j);
				
				for (int k = 1; k < curr.length(); k++) {
					String second = curr.substring(k);
					String first = curr.substring(0, k);
					String afterStr = second + "" + first;
					int after = Integer.parseInt(afterStr);
					if (after > j && after <= b) {
						if (!prev.contains(after)) {
							total++;
							prev.add(after);
						}
					}	
				}
				prev.clear();
			}
			out.write(total + " \n");
		}
		out.close();
		
	}

}
