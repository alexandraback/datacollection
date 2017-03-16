import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;


public class ASol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveA("a.in", "a.out");
		solveA("A-large.in", "A-large.out");		
		//solveA("A-small-attempt0.in", "A-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));

	}


	private static void solveA(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			//System.out.println(t);
			for (long i2 = 0; i2 < t; i2++) {
				
				String  e = sc.nextLine();
				
				
				String rez = solve(e);
				//System.out.println(e + " result: " + rez);
				bw.write("Case #" + (i2+1) + ": " + rez + "\n");
			}
			
			

			
			bw.flush();
			bw.close();
			fw.close();
			sc.close();
		} catch (FileNotFoundException e) {
			
		} catch (IOException e) {
			
		} finally {
			
		}
	}


	private static String solve(String e) {
		//System.out.println("{" + e + "}");
		String words [] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		
		// 6 0 2 4 7 8
		// 
		
		// 3 5 1
		// r f o
		
		// 9
		// n
		
		ArrayList<Character> chars = new ArrayList<Character>();
		HashMap<Character,  Integer>  counts = new HashMap<Character, Integer>(); 
		
		
		for (int i = 0; i < e.length(); i++) {
			char c = e.charAt(i);
			if (!chars.contains(c)) {
				chars.add(c);
				counts.put(c,1);
			} else {
				counts.put(c, counts.get(c)+1);
			}
		}
		//System.out.println(chars);
		//System.out.println(counts);

		
		ArrayList<Character> result = new ArrayList<Character>();
		String a1 = "XZWUSG";
		String b1 = "602478";
		for (int i = 0; i < a1.length(); i++) {
			char c1 = a1.charAt(i);
			if (chars.contains(c1)) {
				int count = counts.get(c1);
				for (int j = 0; j < count; j++) {
					result.add(b1.charAt(i));
					
					String w = words[b1.charAt(i) - '0'];
					for (int k = 0; k < w.length(); k++) {
						char c2 = w.charAt(k);
						counts.put(c2, counts.get(c2) -1);	
					}
					// reduce counts
				}
			}
		}
		
		a1 = "RFO";
		b1 = "351";
		for (int i = 0; i < a1.length(); i++) {
			char c1 = a1.charAt(i);
			if (chars.contains(c1)) {
				int count = counts.get(c1);
				for (int j = 0; j < count; j++) {
					result.add(b1.charAt(i));
					
					String w = words[b1.charAt(i) - '0'];
					for (int k = 0; k < w.length(); k++) {
						char c2 = w.charAt(k);
						counts.put(c2, counts.get(c2) -1);	
					}
					// reduce counts
				}
			}
		}

		a1 = "I";
		b1 = "9";
		for (int i = 0; i < a1.length(); i++) {
			char c1 = a1.charAt(i);
			if (chars.contains(c1)) {
				int count = counts.get(c1);
				for (int j = 0; j < count; j++) {
					result.add(b1.charAt(i));
					
					String w = words[b1.charAt(i) - '0'];
					for (int k = 0; k < w.length(); k++) {
						char c2 = w.charAt(k);
						counts.put(c2, counts.get(c2) -1);	
					}
					// reduce counts
				}
			}
		}
		
		//System.out.println(result);
		
		Collections.sort(result);
		//System.out.println(result);
		
		String r = "";
		for (int i = 0; i < result.size(); i++) {
			r += result.get(i); 	
		}
		
		return r;

	}












}
