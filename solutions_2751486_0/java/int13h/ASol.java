import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Date;
import java.util.Locale;


public class ASol {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Date d1 = new Date();
		solveProblem("A-small-attempt4.in", "A-small-attempt4.out");
		//solveProblem("a.in", "a.out");		
		Date d2 = new Date();
		System.out.println("time: " + (d2.getTime() - d1.getTime()) + " ms");

	}

	private static void solveProblem(String in, String out) {
		try {
			FileReader fis = new FileReader(in);
			BufferedReader  dis = new BufferedReader (fis);
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);

			
			int t = Integer.parseInt(dis.readLine());
			
			for (int i = 0; i < t; i++) {
				
				String l1 = dis.readLine();
				String e1[] = l1.split(" ");

				String a = e1[0];
				int n = Integer.parseInt(e1[1]);
				
				
				String result = solve(a, n);
				System.out.println(a + " " + a.length() + " " + n);
				System.out.println("result: " + result);
				bw.write("Case #" + (i+1) + ": " + result + "\n");
				
			
			}
			
			
			bw.flush();
			bw.close();
			fw.close();
			dis.close();
			fis.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			
		}
		
	
	}

	private static String solve(String a, int n) {
		//System.out.println(a + " " + n);
		
		
		a = a.replaceAll("[aeiou]", "0");
		
		a = a.replaceAll("[^aeiou0]", "1");
		
		System.out.println(a);
		
		
		if (a.length() == 1)
			return (isCon(a, n) ? "1" : "0");
		
		
		
		int cnt = 0; 
		for (int i = 0; i < a.length(); i++) {
			for (int j = i+1; j < a.length()+1; j++) {
				String substring = a.substring(i, j);
				
				//System.out.println(substring);
				
				if (substring.length() >= n) {
					
					//System.out.println(substring + " " + isCon(substring, n));
					if (isCon(substring, n)) {
						
						cnt++;
					}
					
					
				}
			}
		}
		
		//if (isCon(a, n))
		// 	cnt++;
		
		return ""+cnt;
	}

	private static boolean isCon(String substring, int n) {
		// a, e, i, o, and u 
		
		//System.out.println(substring);
		
		int con = 0;
		for (int i = 0; i < substring.length(); i++) {
			if (substring.charAt(i) == '0') {
				con = 0;
			} else {
				con++;
				if (con >= n)
					return true;
			}
				
		}
		return false;
	}








}
