import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;

public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
//		Scanner sc = new Scanner(new File("A-large.in"));
//		Scanner sc = new Scanner(new File("A.in"));
		int n = sc.nextInt();
		int count = 1;
		
		while(n --> 0) {
			String name = sc.next();
			int value = sc.nextInt();
			
			int result = 0;
			
			result = solve2(name, value);
			
			System.out.println("Case #" + count + ": " + result);
			count++;
		}
	}
	
	public static void solve(String name, int value) {
		LinkedList<Integer> substring = new LinkedList<Integer>();
		
		for(int i = 0; i < name.length()-value; i++) {
			String temp = name.substring(i, i+value);
			if(allConsonants(temp))
				substring.add(i);
		}
		
	}
	
	public static boolean allConsonants(String piece) {
		boolean allConsonants = true;
		
		for(int i = 0; i< piece.length() && allConsonants; i++) {
			String temp = piece.substring(i, i);
			if(temp.equalsIgnoreCase("a") || temp.equalsIgnoreCase("e")|| temp.equalsIgnoreCase("i")|| temp.equalsIgnoreCase("o")|| temp.equalsIgnoreCase("u"))
				allConsonants = false;
		}
		
		return allConsonants;
	}
	
	public static int solve2(String name, int value) {
		int result = 0;
		
		for(int i = 0; i <= name.length()-value; i++) {
			for(int j = i+value; j <= name.length(); j++) {
//				System.out.println(name.substring(i, j));
				if(numConsonants(name.substring(i, j), value)) {
					result += 1;
				}
			}
		}
		
		return result;
	}
	
	public static boolean numConsonants(String piece, int n) {
		int numConsonants = 0;
		boolean found = false;
		
		for(int i = 0; i< piece.length() && !found; i++) {
			String temp = piece.substring(i, i+1);
			if(!temp.equalsIgnoreCase("a") && !temp.equalsIgnoreCase("e") && !temp.equalsIgnoreCase("i") && !temp.equalsIgnoreCase("o") && !temp.equalsIgnoreCase("u"))
				numConsonants += 1;
			else
				numConsonants = 0;
			if(numConsonants >= n)
				found = true;
		}
		
		return found;
	}
}
