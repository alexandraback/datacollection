import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;


public class CSol {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Date d1 = new Date();
		//solveC("c.in", "c.out");
		solveC("C-small-attempt0.in", "C-small-attempt0.out");
		//solveC("C-large.in", "C-large.out1");
		Date d2 = new Date();
		//System.out.println("time: " + (d2.getTime() - d1.getTime()) + " ms");

	}

	private static void solveC(String in, String out) {
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
				
				Arrays.sort(ss);
				String result = solve(n, ss);
				//System.out.println(result);
				
				bw.write("Case #" + (i+1) + ":\n" + result + "\n");
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

	private static String solve(int n, int[] ss) {
		/*
		System.out.println(n);
		for (int i = 0; i < ss.length; i++) {
			System.out.print(ss[i] + " ");
		}
		System.out.println();
		*/
		
		
		int max = (int)Math.pow(2, ss.length);
		HashMap<Long, Integer> map = new HashMap<Long, Integer>();

		for (int i = 0; i <= max; i++) {
			String s = Integer.toBinaryString(i);
			s = pad(s, ss.length);
			//System.out.println(s+ " " + s.length());
			long sum = 0;
			for (int j = 0; j < ss.length; j++) {
				if (s.charAt(j) == '1')
					sum += ss[j];
			}
			
			if (map.containsKey(sum)) {
				//System.out.println(i + " "  + map.get(sum) + " " + sum);
				return print(i, ss) + "\n" + print(map.get(sum), ss);
			} else {
				map.put(sum, i);
			}

		}
		return "Impossible";
	}

	private static String print(int i, int[] ss) {
		String rez = "";
		String s = Integer.toBinaryString(i);
		s = pad(s, ss.length);
		for (int j = 0; j < ss.length; j++) {
			if (s.charAt(j) == '1')
				rez += ss[j] + " ";
		}
		return rez.trim();
	}

	private static String pad(String s, int length) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < length-s.length(); i++) {
			sb.append("0");
		}
		sb.append(s);
		return sb.toString();
	}



}
