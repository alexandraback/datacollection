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
		//solveA("a.in", "a.out");
		//solveA("A-small-attempt0.in", "A-small-attempt0.out");		
		solveA("A-small-attempt4.in", "A-small-attempt4.out");
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()) + " ms");

	}

	private static void solveA(String in, String out) {
		try {
			FileReader fis = new FileReader(in);
			BufferedReader  dis = new BufferedReader (fis);
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);

			
			int t = Integer.parseInt(dis.readLine());
			for (int i = 0; i < t; i++) {
				String e = dis.readLine();
				String ee[] = e.split(" ");
				int n = Integer.parseInt(ee[0]);
				int ss [] = new int[n];
				for (int j = 0; j < n; j++) {
					int b = Integer.parseInt(ee[j+1]);
					ss[j] = b;
				}
				
				
				
				String original = solve(ss);
				//System.out.println(original);
				bw.write("Case #" + (i+1) + ": " + original + "\n");
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

	private static String solve(int[] ss) {
		
		for (int i = 0; i < ss.length; i++) {
			System.out.print(ss[i] + " " );
		}
		System.out.println();
		
		
		int n = ss.length;
		int sum = 0;
		for (int i = 0; i < ss.length; i++) {
			sum += ss[i];
		}
		System.out.println("sum: " + sum);
		
		
		int zero = 0;
		int min = -1;

		for (int i = 0; i < ss.length; i++) {
			min = Math.max(min, ss[i]);
		}
		for (int i = 0; i < ss.length; i++) {
			if (ss[i] == min)
				zero++;
		}
		
		Locale en = new Locale("en");
		String rez = "";
		/*
		if (zero == 1) {
			System.out.println("***" + sum + " " + min);
			double zp =  1.0*(sum-min)/sum;
			if (sum == min)
				zp = 1;
			System.out.println(zp);
			
			for (int i = 0; i < ss.length; i++) {
				if (ss[i] == 0)
					rez += String.format(en, "%.6f", zp*100) + " ";
				else
					rez += String.format(en, "%.6f", 0.0) + " ";
			}
			
		} else
			*/
		if (zero > 1) {
			System.out.println("xxxx");
			for (int i = 0; i < ss.length; i++) {
					rez += String.format(en, "%.6f", 0.0) + " ";
			}
		}
		else {
			
		
		double aaa[] = new double[ss.length];
		double psum = 0;
		for (int i = 0; i < ss.length; i++) {
			aaa[i] = 1.0*(ss[0]-ss[i])/sum;
			if (i >0) {
				//System.out.println("a0" + i + " " +  aaa[i]);
				psum += aaa[i];
			}
		}
		//System.out.println("psum: " + psum);
		double xx[] = new double[ss.length];
		xx[0] = 1.0*(1-psum)/ss.length;
		//System.out.println("x: " + xx[0]);
		for (int i = 1; i < ss.length; i++) {
			xx[i] = xx[0]+aaa[i];
		}
		for (int i = 0; i < ss.length; i++) {
			if (xx[i] < 0)
				System.out.println("zzzzz");
			//xx[i] = Math.max(0, xx[i]);
		}
		
		
		
		
		
		for (int i = 0; i < ss.length; i++) {
			rez += String.format(en, "%.6f", xx[i]*100) + " ";
		
		
		}
		
		}
		
		System.out.println(rez);
		return rez.trim();
	}



}
