import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class Polindrome {

	static String filePath = "files/C-large-1.in"; 
	static long START = 1l;
	static long END = 
			//1000l; 
			1000000000000000l;
	static List<Long> fair = new ArrayList<Long>(); 
	public static void main(String[] args) throws IOException {
		
		for (long i = START; i < END; i++) {
			if (!checkPolindrome(i)) {
				continue;
			}
			long square = i * i;
			if (!checkPolindrome(square)) {
				continue;
			}
			if (square <= END) {
				fair.add(square);
			} else {
				break;
			}
		}
		
		FileReader fileReader = new FileReader(filePath);
		BufferedReader bufferedReader = new BufferedReader(fileReader);

		String line;
		line = bufferedReader.readLine();
		
		int noTestCases = Integer.parseInt(line);
		for (int i = 0; i < noTestCases; i++) {
			line = bufferedReader.readLine();
			String[] temp = line.split(" ");
			long start = Long.parseLong(temp[0]);
			long end = Long.parseLong(temp[1]);
			int numberOfFairs = 0;
			for (long fairNumber: fair) {
				if (fairNumber > end) {
					break;
				}
				if (fairNumber >= start && fairNumber <= end) {
					numberOfFairs++;
				}
			}
			System.out.println("Case #" + (i + 1) + ": " + numberOfFairs);
		}
		
		//System.out.println(fair);
	}
	static boolean checkPolindrome(long number) {
		String temp1 = Long.toString(number);
		String temp2 = new StringBuffer(temp1).reverse().toString();
		if (temp1.equals(temp2)) {
			return true;
		}
		return false;
	}

}
