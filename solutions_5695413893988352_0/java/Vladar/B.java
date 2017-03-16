import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/*
UTILS :

ArrayList<Long>[] sol = (ArrayList<Long>[]) new ArrayList[size];
Collections.sort();
System.out.println("");
(String).toCharArray();

sc.nextLong();
sc.nextBigInteger();
sc.nextLine();
sc.nextDouble();
sc.nextInt();
sc.nextInt(int radix);
sc.nextBoolean();
 */


public class B {
	public static void main(String [] args) throws Exception
	{		
		Scanner sc = new Scanner(new File("B/small.txt"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(new File("src/B.txt"))));
		int size = sc.nextInt();
		sc.nextLine();


		for (int i=0; i<size; i++) {
			// Case #
			writer.print("Case #" + (i+1) + ": ");
			System.out.print("Case #" + (i+1) + ": ");

			// Solve
			String line = sc.nextLine();
			String[] parts = line.split(" ");
			String part1 = parts[0];
			String part2 = parts[1];


			int range = (int) Math.pow(10, part1.length());

			int bestDiff = 100000;
			int bestP1 = 0;
			int bestP2 = 0;

			for(int j = 0; j<range; j++) {
				for(int k = 0; k<range; k++) {
					if(match(j,part1) && match(k,part2)) {
						int diff = Math.abs(j-k);
						if(diff<bestDiff) {
							bestDiff = diff;
							bestP1 = j;
							bestP2 = k;
						}
						if(diff==bestDiff) {
							if(j<bestP1) {
								bestDiff = diff;
								bestP1 = j;
								bestP2 = k;
							}
							if(j==bestP1) {
								if(k<bestP2) {
									bestDiff = diff;
									bestP1 = j;
									bestP2 = k;
								}
							}
						}
					}
				}
			}				
			// Print result
			writer.println(String.format("%0"+ part2.length() +"d", bestP1) + " " + String.format("%0"+ part2.length() +"d", bestP2));
			System.out.println(String.format("%0"+ part2.length() +"d", bestP1) + " " + String.format("%0"+ part2.length() +"d", bestP2));


		}

		writer.close();
		sc.close();
	}

	public static boolean match(int a, String num) {
		String n = String.format("%0"+ num.length() +"d", a);
		for(int i=0; i<num.length(); i++) {
			if(num.charAt(i)!='?') {
				if(num.charAt(i)!=n.charAt(i)) return false;
			}
		}

		return true;

	}
}







