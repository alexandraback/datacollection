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
		solveA("A-small-attempt0.in", "A-small-attempt0.out");
		//solveA("A-large.in", "A-large.out");		
		//solveA("A-large-practice.in", "A-large-practice.out");
		
		Date d2 = new Date();
		System.out.println("time: " + (d2.getTime() - d1.getTime()));
		
		
		
		


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
				
				int r = sc.nextInt();
				int c = sc.nextInt();
				int w = sc.nextInt();
				

				
				
				
				
				String rez = solve(r, c, w);
				//System.out.println("result: " + rez);
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


	private static String solve(int r, int c, int w) {
		//System.out.println(r + " " + c + " " + w);
		int result = w;
		if (w == 1) {
			result = c;
		} else {
			result = c/w+(w-1);
			if (c % w != 0) {
				result++;
			}
		}
		
		
		return ""+result*r;
	}


	












}
