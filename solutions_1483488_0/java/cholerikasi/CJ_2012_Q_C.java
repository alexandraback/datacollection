import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;


public class CJ_2012_Q_C {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("cj_files/in"));
		FileWriter w = new FileWriter(new File("cj_files/out"));
		
		int cases = in.nextInt();
		int a, b, numDigits, count, newNum;
		String oStr, nStr;
		TreeSet<Integer> numbers = new TreeSet<Integer>();
		
		for(int i = 1; i <= cases; i++) {
			a = in.nextInt();
			b = in.nextInt();
			numDigits = (a + "").length();
			count = 0;
			for(int j = a; j < b; j++) {
				oStr = j + "";
				numbers.clear();
				for(int k = 1; k < numDigits; k++) {
					nStr = oStr.substring(numDigits - k) + oStr.substring(0, numDigits - k);
					newNum = Integer.parseInt(nStr);
					if(newNum > j && newNum <= b) {
						numbers.add(newNum);
					}
				}
				count += numbers.size();
			}
			
			w.write(String.format("Case #%d: %d\n", i, count));
		}
		
		w.close();
	}
}
