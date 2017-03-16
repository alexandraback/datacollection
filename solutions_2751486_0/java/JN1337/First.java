import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class First {



	public static void main(String[] args) throws IOException {

		Scanner sc;
		FileWriter writer = new FileWriter("output.txt");
		sc = new Scanner(new File("A-small-attempt0.in"));

//		String test = sc.next();
		int cases = sc.nextInt();
		
		for (int c = 1; c <= cases; c++) {
			String name = sc.next();
			int n = sc.nextInt();
			int nvalue = 0;
			for (int begin = 0; begin <= name.length()-n; begin++) {
				for (int end = begin + n; end <= name.length(); end++ ) {
				String subString = name.substring(begin, end).toLowerCase();
				String matcher = ".*(?=([^euioa]{"+n+"})).*";
				boolean b = subString.matches(matcher);
					if(b) {
						nvalue++;
//						System.out.println(subString);
					}
				}
			}
			System.out.println(nvalue);
			writer.write("Case #" + c + ": " + nvalue + "\r\n");
		}
		sc.close();
		writer.close();

	}

}
