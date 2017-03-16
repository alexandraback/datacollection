import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.Scanner;


public class ASol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveA("a.in", "a.out");
		//solveA("A-large.in", "A-large.out");		
		solveA("A-small-attempt0.in", "A-small-attempt0.out");
		
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
		
		String result = "";
		char last = e.charAt(0);
		result += last;
		for (int i = 1; i < e.length(); i++) {
			char c= e.charAt(i);
			if (c >= last) {
				result = c + result;
			} else {
				result = result + c;
			}
			last = result.charAt(0);
			//System.out.println(result);
		}
		
		return result;
	}












}
