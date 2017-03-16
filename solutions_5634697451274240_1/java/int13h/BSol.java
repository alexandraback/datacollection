import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;


public class BSol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveB("b.in", "b.out");
		solveB("B-large.in", "B-large.out");		
		//solveB("B-small-attempt0.in", "B-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));
		
		
		
		


	}


	private static void solveB(String in, String out) {
		
		

		
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			//System.out.println(t);
			for (long i2 = 0; i2 < t; i2++) {
				
			
				String line = sc.nextLine();
				
				
				int rez =  solve(line);
				
				//System.out.println(line + " result: " + rez);
				
				bw.write("Case #" + (i2+1) + ": " +  rez + "\n");
				
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





	private static int solve(String line) {
		
		int cnt = 0;
		for (int i = 0; i < line.length()-1; i++) {
			if (line.charAt(i) != line.charAt(i+1)) {
				cnt++;
			}
		}
		
		if (line.endsWith("+"))
			return cnt;
		else 
			return cnt+1;
		
		
	}


	








}
