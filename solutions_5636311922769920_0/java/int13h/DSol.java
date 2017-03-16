import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

import javax.swing.text.StyledEditorKit.BoldAction;


public class DSol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveD("d.in", "d.out");
		//solved("D-large.in", "D-large.out");		
		solveD("D-small-attempt0.in", "D-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));
		
		
		
		


	}


	private static void solveD(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			//System.out.println(t);
			for (long i2 = 0; i2 < t; i2++) {
				
				int k = sc.nextInt();
				int c = sc.nextInt();
				int s = sc.nextInt();
				
						
				
				
				
				
				String rez = solve(k, c, s);
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


	private static String solve(int k, int c, int s) {
		
		//System.out.println(k + " " + c + " " + s);
		String result = "";
		for (int i = 1; i <= s; i++) {
			
			long n = i; 
			for (int j = 1; j <= c-1; j++) {
				long kc = pow(k,j-1);
				n+= (i-1)*kc;
			}
			 
			 result += n;
			 if (i != s) {
			  result += " ";
			 }
		}
		return result;
	}


	private static long pow(int k, int c) {
		long r = k;
		for (int i = 0; i < c; i++) {
			r = r*k;
		}
		return r;
	}










}
