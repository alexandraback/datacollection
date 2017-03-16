package cround;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Elves {
	static final String inFile = "A-large.in";
	static final String outFile = "A-largeOUT.txt";
	static Scanner scanner;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException{
		scanner = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numOfTests = scanner.nextInt();
		scanner.nextLine();
		for(int i = 0; i < numOfTests; i++){
			writer.print("Case #"+(i+1)+": ");
			solve(i+1);
		}
		writer.flush();
		scanner.close();
		writer.close();
		
	}
	public static void solve(int caseNum){
		
		String line = scanner.nextLine();
		System.out.println(line);
		String[] w = line.split("/");
		long nom = Long.parseLong(w[0]);
		long denom = Long.parseLong(w[1]);
		solve2(nom, denom, 40L, true, 0);
		/*long div = euclid(nom, denom);
		System.out.println("div: " + div);
		nom = nom / div;
		denom = denom /div;
		long denomcopy = denom;
		while (denomcopy % 2 == 0 && denomcopy != 1){
			denomcopy = denomcopy/2;
		}
		if (denomcopy != 1) {
			writer.println("impossible");
			return;
		}
		long gen = 0;
		
		while(nom < denom){
			denom = denom / 2;
			gen++;
		}
		if (gen == 40){
			if (nom!=denom) {
				writer.println("impossible");
				return;
			}
		}
		writer.println(gen);
		System.out.println(nom + " " + denom + " " + gen);
		*/
		
	}
	
	public static void solve2(long nom, long denom, long genLeft, boolean first, long firstGen){
		long div = euclid(nom, denom);
		System.out.println("div: " + div);
		nom = nom / div;
		denom = denom /div;
		long denomcopy = denom;
		while (denomcopy % 2 == 0 && denomcopy != 1){
			denomcopy = denomcopy/2;
		}
		if (denomcopy != 1) {
			writer.println("impossible");
			return;
		}
		long gen = 0;
		
		while(nom < denom){
			denom = denom / 2;
			gen++;
		}
		if (gen > genLeft){
			writer.println("impossible");
			return;
		}
		else if (nom == denom) {
			writer.println(first ? gen : firstGen);
			return;
		}
		else{
			long newNom = nom - denom;
			solve2(newNom, denom, genLeft - gen, false, first ? gen : firstGen);
		}
		
		//System.out.println(nom + " " + denom + " " + gen);
	}
	
	static long euclid(long x, long y){
		if (y == 0) return x;
		if (x == 1) return 1;
		else return euclid(y, x % y);
	}
}
