import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;


public class CSol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveC("c.in", "c.out");
		//solveA("A-large.in", "A-large.out");		
		solveC("C-small-attempt0.in", "C-small-attempt0.out");
		
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()));

	}


	private static void solveC(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			

			
				
			//System.out.println(t);
			for (long i2 = 0; i2 < t; i2++) {
				int c = sc.nextInt();
				int d = sc.nextInt();
				int v = sc.nextInt();
				sc.nextLine();
				
				int den [] = new int[d];
				for (int i = 0; i < d; i++) {
					den[i] = sc.nextInt();
				}
				
				String rez = solve(c, d, v, den);
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


	private static String solve(int c, int d, int v, int[] den) {
		//System.out.println("C: "  + c + " " + d + " V: " + v);
		
		ArrayList<Integer> dd = new ArrayList<Integer>();
		for (int i = 0; i < den.length; i++) {
			dd.add(den[i]);
		}
		
		
		//print(dd);
		
		// generate possible sums
		boolean values[] = new boolean[v+1];
		if (c == 1) {
			
			int cnt= 1;
			for (int i = 0; i < dd.size(); i++) {
				cnt= 2*cnt;
			}
			
			//System.out.println("2^" +dd.size() + "=" + cnt);
			for (int i = 0; i < cnt; i++) {
				
				int sum = 0;
				for (int j = 0; j < dd.size(); j++) {
					if ((i & 1<<j) != 0) {
						sum += den[j];
					}
				}
				
				//System.out.println(i + " " + Integer.toBinaryString(i) + " " + sum);
				if (sum < v+1) {
					values[sum] = true;
				}
			}
			
			
			
			
			int not = notPossible(v, values);
			//System.out.println(not);
			
			while (not != 0) {
				
				int newV = -1;
				for (int i = 1; i <= v; i++) {
					if (!values[i]) {
						//System.out.println("adding: " + i);
						newV = i;
						dd.add(i);
						break;
					}
				}
				
				
				if (newV != -1) {
					for (int i = v; i >= 1; i--) {
						if (values[i]) {
							if (i+newV<v+1) {
								values[i + newV] = true;
							}
						}
					}
					values[newV] = true;
				}
				
				
				not = notPossible(v, values);
			}
			
			//System.out.println("with new denominations: ");
			//print(dd);
			
			return ""+(dd.size()-d);
		}
		
		
		return null;
	}


	private static void print(ArrayList<Integer> dd) {
		for (int i = 0; i < dd.size(); i++) {
			System.out.print(dd.get(i)+" " );
		}
		System.out.println();
	}


	private static int notPossible(int v, boolean[] values) {
		int not = 0;
		for (int i = 1; i <= v; i++) {
			if (!values[i]) {
				not++;
			}
		}
		return not;
	}
















}
