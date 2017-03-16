package com.google.codejam.Qualification2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new BufferedReader(new FileReader(args[0] + ".in")));
		Writer writer = new BufferedWriter(new FileWriter(args[0] + ".out"));
		
		int T = scanner.nextInt();
		Set<Integer> set = new HashSet<Integer>();

		for (int x = 1; x <= T; ++x) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			
			int y = 0;
			if (B >= 21) {
				for (int n = A; n < B; ++n) {
					set.clear();
					int nDigits = getDigits(n);
					
					int k1 = 10;
					int k2 = 1;
					for (int i = 0; i < nDigits - 1; ++i)
						k2 *= 10;
					
					int n1 = n / k1;
					int n2 = n % k1;										
					for (int i = 0; i < nDigits - 1; ++i) {
						int m = n2 * k2 + n1;
						if (n2 != 0 && m > n && m <= B && !set.contains(m)) {
							//System.out.println(n + ": " + n2 + " " + n1);
							set.add(m);
							++y;
						}
						
						k1 *= 10;
						k2 /= 10;
						n1 = n / k1;
						n2 = n % k1;
					}
				}
			}
			
			System.out.println("Case #" + x + ": " + y);
			writer.write("Case #" + x + ": " + y + "\n");
		}
		
		writer.close();
		scanner.close();
	}
	
	static int getDigits(int n) {
		if (n == 0)
			return 1;
		
		int result = 0;
		
		while (n > 0) {
			n /= 10;
			++result;
		}		
		
		return result;
	}

}
