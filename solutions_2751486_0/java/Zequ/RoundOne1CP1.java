package codeJam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Hubert
 */
public class RoundOne1CP1 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// Scanner sc = new Scanner (System.in);
		Scanner sc = new Scanner (new FileReader("A-small-attempt0 (1).in"));
		// PrintWriter pw = new PrintWriter (System.out);
		PrintWriter pw = new PrintWriter (new FileWriter("out1.txt"));
		int numCases = sc.nextInt();
		for (int z = 0; z < numCases; z++) {
			String name = sc.next();
			int n = sc.nextInt();
			int result = 0;
			for (int i = 0; i <= name.length()-n;i++) {
				for (int j = i+n; j <= name.length(); j++) {
					String p = name.substring(i,j);
					int con = 0;
					boolean works = false;
					// System.out.println(p);
					for (int k = 0; k <= p.length(); k++) {
						if(k<p.length() && (p.charAt(k) != 'a' && p.charAt(k) != 'e' && p.charAt(k) != 'i' && p.charAt(k) != 'o' && p.charAt(k) != 'u')) {
							con++;
						}
						else {
							if (con >= n) {
								works = true;
							}
							con = 0;
						}
					}
					if(works) {
						result++;
					}
				}
			}
			pw.println("Case #" + (z+1) + ": " + result);
		}
		pw.flush();
		pw.close();
	}
}
