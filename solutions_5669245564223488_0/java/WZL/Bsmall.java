package R1C;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Bsmall {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("B-small-attempt1.in"));
		int numCases = scanner.nextInt();	
		ArrayList<Long> res = new ArrayList<Long>();
		
		// Each case variables
		int numCars;
		ArrayList<String> cars;
		boolean failed;
		int[] free;
		ArrayList<Character> nos;
		ArrayList<Character> nof;
		char c1;
		char c2;
		char c3;
		long ways;
		int unique;
		
		// Each case loop		
		for (int i = 0; i < numCases; i++) {
			numCars = scanner.nextInt();
			cars = new ArrayList<String>();
			failed = false;
			free = new int[27];
			nos = new ArrayList<Character>();
			nof = new ArrayList<Character>();
			ways = 1;
			unique = 0;
			
			for (int j = 0; j < numCars; j++) {
				cars.add(scanner.next());
			}
			
			for (String car:cars) {
				if (invalid(car)) {
					failed = true;
					break;
				}
			}
			
			if (failed) {
				res.add(0l);
				continue;
			}
			
			for (String car:cars) {
				c1 = car.charAt(0);
				c2 = car.charAt(car.length() - 1);
				if (see(car)) {
					free[change(c1)]++;
				} else {
					if (nos.contains(c1)) {
						failed = true;
						System.out.println(i + " failed1");
						break;
					} else {
						nos.add(c1);
					}
					if (nof.contains(c2)) {
						failed = true;
						System.out.println(i + " failed2");
						break;
					} else {
						nof.add(c2);
					}
//					for (int j = 1; j < car.length() - 1; j++) {
//						c3 = car.charAt(j);
//						if ((nos.contains(c3) || nof.contains(c3)) && c3 != car.charAt(j - 1)) {
//							failed = true;
//							System.out.println(i + " failed3");
//							break;
//						} else {
//							if (!(nos.contains(c3))) 
//								nos.add(c3);
//							if (!(nof.contains(c3))) 
//								nof.add(c3);
//						}
//					}
				}
			}
			
			if (failed) {
				res.add(0l);
				continue;
			}
			for (int fre:free) {
				if (fre == 0)
					continue;
				ways = ways * factorial(fre);
				ways = ways % 1000000007;
				if (!(nos.contains(c2(fre))) && !(nof.contains(c2(fre)))) {
					ways = ways * 2;
				}
			}
			for (String car:cars) {
				c1 = car.charAt(0);
				c2 = car.charAt(car.length() - 1);
				if (see(car))
					continue;
				if (!(nof.contains(c1)) && !(nos.contains(c2))) {
					unique++;
				}
			}
			ways = ways * factorial(unique);
			ways = ways % 1000000007;
			res.add(ways);
		}
		
		PrintWriter result = new PrintWriter(new FileWriter("1CB.txt"));
		for (int i = 0; i < numCases; i++) {
			result.printf("Case #" + (i + 1) + ": " + (res.get(i) == -1 ? "NOT POSSIBLE" : res.get(i)) +"%n");
		}
		result.close();
	}
	
	public static long factorial(int n) {
		if (n == 0 || n == 1) {
			return 1;
		} else {
			return n * factorial(n - 1);
		}
	}
	
	public static char c2(int l) {
		if (l == 1) 
			return 'a';
		else if (l == 2) 
			return 'b';
		else if (l == 3) 
			return 'c';
		else if (l == 4) 
			return 'd';
		else if (l == 5) 
			return 'e';
		else if (l == 6) 
			return 'f';
		else if (l == 7) 
			return 'g';
		else if (l == 8) 
			return 'h';
		else if (l == 9) 
			return 'i';
		else if (l == 10) 
			return 'j';
		else if (l == 11) 
			return 'k';
		else if (l == 12) 
			return 'l';
		else if (l == 13) 
			return 'm';
		else if (l == 14) 
			return 'n';
		else if (l == 15) 
			return 'o';
		else if (l == 16) 
			return 'p';
		else if (l == 17) 
			return 'q';
		else if (l == 18) 
			return 'r';
		else if (l == 19) 
			return 's';
		else if (l == 20) 
			return 't';
		else if (l == 21) 
			return 'u';
		else if (l == 22) 
			return 'v';
		else if (l == 23) 
			return 'w';
		else if (l == 24) 
			return 'x';
		else if (l == 25) 
			return 'y';
		else 
			return 'z';
	}
	
	public static int change(char l) {
		if (l == 'a') 
			return 1;
		else if (l == 'b') 
			return 2;
		else if (l == 'c') 
			return 3;
		else if (l == 'd') 
			return 4;
		else if (l == 'e') 
			return 5;
		else if (l == 'f') 
			return 6;
		else if (l == 'g') 
			return 7;
		else if (l == 'h') 
			return 8;
		else if (l == 'i') 
			return 9;
		else if (l == 'j') 
			return 10;
		else if (l == 'k') 
			return 11;
		else if (l == 'l') 
			return 12;
		else if (l == 'm') 
			return 13;
		else if (l == 'n') 
			return 14;
		else if (l == 'o') 
			return 15;
		else if (l == 'p') 
			return 16;
		else if (l == 'q') 
			return 17;
		else if (l == 'r') 
			return 18;
		else if (l == 's') 
			return 19;
		else if (l == 't') 
			return 20;
		else if (l == 'u') 
			return 21;
		else if (l == 'v') 
			return 22;
		else if (l == 'w') 
			return 23;
		else if (l == 'x') 
			return 24;
		else if (l == 'y') 
			return 25;
		else 
			return 26;
	}
	
	public static boolean see(String car) {
		return car.charAt(0) == car.charAt(car.length() - 1);
	}
	
	public static boolean invalid(String car) {
		ArrayList<Character> no = new ArrayList<Character>();
		no.add(car.charAt(0));
		int ind = 0;
		int len = car.length();
		char temp;
		for (int i = 1; i < len; i++) {
			temp = car.charAt(i);
			if (no.contains(temp)) {
				if (temp != car.charAt(i - 1)) {
					return true;
				}
			} else {
				no.add(temp);
			}
		}
		return false;
		
	}

}
