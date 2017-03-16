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
				
				int n = sc.nextInt();
				
				String rez = solve(n);
				//System.out.println(n + " result: " + rez);
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


	private static String solve(int n) {
		
		if (n == 0) {
			return "INSOMNIA";
		}
		
		boolean used [] = new boolean[10];
		
		
		int i = 1;
		int m = n;
		while (true) {
			
			String a = "" + m;
			for (int j = 0; j < a.length(); j++) {
				int nn = a.charAt(j) - '0';
				used[nn] = true;
			}
			
			//System.out.println(m);
			//System.out.println(Arrays.toString(used));
			
			boolean all = true;
			for (int j = 0; j < used.length; j++) {
				if (!used[j]) {
					all = false;
				}
			}
			
			if (all) {
				break;
			}
			m = n*i;
			i++;
		}
		
		return "" + m;
	}











}
