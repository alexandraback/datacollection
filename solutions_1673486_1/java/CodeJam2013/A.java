package com.google.code.codejam2012.Round1A;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new BufferedReader(new FileReader(args[0] + ".in")));
		Writer writer = new BufferedWriter(new FileWriter(args[0] + ".out"));
		
		int T = scanner.nextInt();

		for (int x = 1; x <= T; ++x) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			
			double[] p = new double[A];
			for (int i = 0; i < A; ++i)
				p[i] = scanner.nextDouble();
			
			double[] pCorrect = new double[A];
			pCorrect[0] = p[0];
			for (int i = 1; i < A; ++i)
				pCorrect[i] = pCorrect[i-1] * p[i];
			
			double eKeepTyping = pCorrect[A-1] * (B - A + 1) +
								 (1 - pCorrect[A-1]) * (B - A + 1 + B + 1);			
			double ePressEnter = 1 + B + 1;
			
			List<Double> e = new ArrayList<Double>();
			e.add(eKeepTyping);
			e.add(ePressEnter);
			
			for (int i = 1; i < A; ++i) {
				double eBackspace = pCorrect[A-i-1] * (i + B - A + i + 1) +
									(1 - pCorrect[A-i-1]) * (i + B - A + i + 1 + B + 1);
				e.add(eBackspace);
			}
			e.add((double) (A + B + 1));
			
			System.out.println("Case #" + x + ": " + Collections.min(e));
			writer.write("Case #" + x + ": " + Collections.min(e) + "\n");
		}
		
		writer.close();
		scanner.close();
	}
	
}
