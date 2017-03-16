package jam.tools;

import java.math.*;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class File {

	public static ArrayList<String> getLines(String fp) {

		BufferedReader br = null;
		ArrayList<String> lines = new ArrayList<String>();
		try {

			String sCurrentLine;

			br = new BufferedReader(new FileReader(fp));

			while ((sCurrentLine = br.readLine()) != null) {
				lines.add(sCurrentLine);
			}

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		return lines;
	}

	public static ArrayList<Integer> decodeInts(String line) {
		ArrayList<Integer> t = new ArrayList<Integer>();
		StringTokenizer st = new StringTokenizer(line);
		while (st.hasMoreTokens()) {
			t.add(Integer.parseInt(st.nextToken()));
		}
		return t;
	}

	public static ArrayList<Long> decodeLongs(String line) {
		ArrayList<Long> t = new ArrayList<Long>();
		StringTokenizer st = new StringTokenizer(line);
		while (st.hasMoreTokens()) {
			t.add(Long.parseLong(st.nextToken()));
		}
		return t;
	}

	public static ArrayList<Double> decodeDoubles(String line) {
		ArrayList<Double> t = new ArrayList<Double>();
		StringTokenizer st = new StringTokenizer(line);
		while (st.hasMoreTokens()) {
			t.add(Double.parseDouble(st.nextToken()));
		}
		return t;
	}

	public static ArrayList<String> decodeStrings(String line) {
		ArrayList<String> t = new ArrayList<String>();
		StringTokenizer st = new StringTokenizer(line);
		while (st.hasMoreTokens()) {
			t.add((st.nextToken()));
		}
		return t;
	}

	public static boolean gogo(int x, int y, int gox, int goy, int level) {
		System.out.println(x + " " + y);
		if (level >= 500)
			return false;
		if (x == gox && y == goy)
			return true;
		boolean result = false;

		result = gogo(x + level, y, gox, goy, level + 1);
		if (result) {
			System.out.print('E');
			return true;
		}
		result = gogo(x - level, y, gox, goy, level + 1);

		if (result) {
			System.out.print('W');
			return true;
		}
		result = gogo(x, y + level, gox, goy, level + 1);

		if (result) {
			System.out.print('N');
			return true;
		}
		result = gogo(x, y - level, gox, goy, level + 1);

		if (result) {
			System.out.print('S');
			return true;
		}
		return result;
	}

	public static int factorial(int n) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		return result;
	}

	public static double calcProb(int i, int n) {
		return factorial(n) / factorial(i) / factorial(n - i) / Math.pow(2, n);
	}

	public static double calculate(int x, int n) {
		double sum = 0;
		for (int i = x; i <= n; i++) {
			sum += calcProb(i, n);
		}
		return sum;
	}

	public static boolean scan(int start,int end,String name,int n){
		name=name.substring(start,end);
		int consec=0;
		String vowels="aeiou";
		for (int i =0;i<name.length();i++){
			if (!vowels.contains(""+name.charAt(i))) {consec++;if (consec==n) return true;}
			else consec=0;
		}
		return false;
	}
	private static int level;
	private static String result = "";

	public static void main(String[] args) {
		PrintWriter writer = null;
		try {
			writer = new PrintWriter("D:\\Jam\\output.txt", "UTF-8");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		ArrayList<String> t = File.getLines("D:\\Jam\\input.in");
		int testcases = File.decodeInts(t.get(0)).get(0);
		int line = 1;

		System.out.println(testcases);
		for (int i = 0; i < testcases; i++) {
			result="";
			ArrayList<String> temp = File.decodeStrings((t.get(line)));
			line++;
			String name = temp.get(0);
			int n = Integer.parseInt(temp.get(1));
			boolean[][] cont=new boolean[name.length()+1][name.length()+1];
			int answer=0;
			for (int a=0;a<=name.length();a++)
				for (int b=a;b<=name.length();b++) if (scan(a,b,name,n)) {cont[a][b]=true;answer++;}
			
			writer.println("Case #" + (i + 1) + ": " +answer);
			// gogo(0,0,x,y,1);

		}

		// writer.println("Case #" + (i + 1) + ": " +result1);
		// writer.println("Case #" + (i + 1) + ": " +result.substring(1));

		// for (int i=0;i<testcases;i++) writer.println("Case #" + (i + 1) +
		// ": " + getFromCh(results[i]));
		writer.close();

	}
}
