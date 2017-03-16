package cround;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Trains {
	static final String inFile = "B-small-attempt0.in";
	static final String outFile = "B-small-attempt0Out.txt";
	static Scanner scanner;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException{
		scanner = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numOfTests = scanner.nextInt();
		for(int i = 0; i < numOfTests; i++){
			writer.print("Case #"+(i+1)+": ");
			solve(i+1);
		}
		writer.flush();
		scanner.close();
		writer.close();
		
	}
	public static void solve(int caseNum){
		System.out.println();
		long sets = scanner.nextLong();scanner.nextLine();
		String[] cars = scanner.nextLine().split(" ");
		for (String w : cars) System.out.println(w);
		int[][] counts = new int[26][26];
		if (!initializeCounts(cars, counts)){
			writer.println("0");
			return;
		}
		for (int w : counts[0]) System.out.println(w);
		long pos = 1L;
		for (int i = 0; i < 26; i++){
			pos = (pos * fact(counts[i][i])) % 1000000007;
		}
			
		
		long disjoint = 0;
		
		for (int i = 0; i < 26; i++){
			boolean hasSuc = false;
			boolean endsWith = false;
			for (int j = 0; j < 26; j++){
				if (i!=j) {
					if (counts[i][j] != 0) hasSuc = true;
				}
			}
			for (int j = 0; j < 26; j++){
				
					if (counts[j][i] != 0) endsWith = true;
				
			}
			
			if (!hasSuc && endsWith) disjoint++;
				
		}
		
		System.out.println("dis: " + disjoint);
		pos = (pos * fact(disjoint)) % 1000000007;
		
		writer.println(pos);
	}
	
	public static boolean initializeCounts(String[] words, int[][] counts){
		Set<Character> mustNotFind = new HashSet<Character>();
		
		for (String w :  words) {
			char[] letters = w.toCharArray();
			ArrayList<Character> list = new ArrayList<Character>();
			char prev = '1';
			for (int i = 0; i < letters.length; i++){
				if (letters[i] != prev) {
					prev = letters[i];
					list.add(letters[i]);
				}
			}
			if (list.size() == 1) {
				int i = list.get(0) - 97;
				counts[i][i]++;
			}
			else if (list.size() == 2) {
				int i = list.get(0) - 97;
				int j = list.get(1) - 97;
				counts[i][j]++;
			}
			else {
				for (int i = 1; i < list.size() - 1; i++){
					if (mustNotFind.contains(list.get(i))) return false;
					else mustNotFind.add(list.get(i));
				}
				int i = list.get(0) - 97;
				int j = list.get(list.size() - 1) - 97;
				counts[i][j]++;
			}
			
		}
		
		for(char c : mustNotFind){
			int index = c - 97;
			for (int i = 0; i < 26; i++){
				if (counts[index][i] != 0) return false;
				if (counts[i][index] != 0) return false;
			}
		}
		
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++){
				if (counts[i][j] != 0 && counts[j][i] != 0 && i != j) return false;
				if (i != j && counts[i][j] > 1) return false;
				
			}
		
		for (int i = 0; i < 26; i++){
			int max = counts[i][i] + 1;
			long sum = 0;
			for (int j = 0; j < 26; j++){
				sum += counts[i][j];
			}
			if (sum > max) return false;
		}
		
		for (int i = 0; i < 26; i++){
			int max = counts[i][i] + 1;
			long sum = 0;
			for (int j = 0; j < 26; j++){
				sum += counts[j][i];
			}
			if (sum > max) return false;
		}
			
			
			
			
		
		return true;
	}
	
	static long fact(long n) {
		
		if (n == 1 || n == 0) return 1;
		long acc = 1;
		while (n > 1){
			acc = acc * n;
			n--;
		}
		return acc;
	}
}
