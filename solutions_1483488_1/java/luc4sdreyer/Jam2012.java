package gcj;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

import java.util.Iterator;

public class Jam2012 {
	//-10^9 < Integer.MAX_VALUE (2^31) < 10^10
	//-10^18 < Long.MAX_VALUE (2^63) < 10^20


	public static void main(String[] args) throws NumberFormatException, IOException {		
		Scanner sc = new Scanner(new FileReader(filename+".in"));
		String output;
		String outputfile = filename + ".out";

		FileOutputStream Output = new FileOutputStream(outputfile);
		PrintStream file2 = new PrintStream(Output);

		boolean after25 = false;
		boolean after50 = false;
		boolean after75 = false;

		int T = sc.nextInt();
		//int T = Integer.parseInt(sc.nextLine());
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);


		//getPrimesH();
		for (int i = 0; i < T; i++) {

			//ArrayList<Integer> orders = new ArrayList<Integer>();
			//ArrayList<Long> v2 = new ArrayList<Long>();
			//ArrayList<String> queryList = new ArrayList<String>();

			//StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int a = sc.nextInt();
			int b = sc.nextInt();

			output = solve(a,b);

			file2.println("Case #" + (i+1) + ": "+output);
			if ((100*(i+1)/T >= 25) && (!after25)) {
				System.out.println(Calendar.getInstance().getTime()+" - 25% done");				after25 = true;
			} else if ((100*(i+1)/T >= 50) && (!after50)) {
				System.out.println(Calendar.getInstance().getTime()+" - 50% done");				after50 = true;
			} else if ((100*(i+1)/T >= 75) && (!after75)) {
				System.out.println(Calendar.getInstance().getTime()+" - 75% done");				after75 = true;
			}
		}
		sc.close();		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
	}
	/*
	private static String solve(String nextLine) {
		char[] a = {'f','g','d','e','b','c','a','n','o','l','m','j','k','h','i','w','v','u','t','s','r','q','p','z','y','x'};
		char[] b = {'c','v','s','o','h','e','y','b','k','g','l','u','i','x','d','f','p','j','w','n','t','z','r','q','a','m'};
		HashMap<Character,Character> lib = new HashMap<Character,Character>();
		for (int i = 0; i< a.length; i++) {
			if(!lib.containsKey(a[i])) {
				lib.put(a[i], b[i]);
			}
		}
		
		StringBuilder out = new StringBuilder();
		for (int i = 0; i< nextLine.length(); i++) {
			if (nextLine.charAt(i) == ' ') {out.append(' ');} else {
			out.append(lib.get(nextLine.charAt(i)));}
		}
		return out.toString();
	}*/

	private static String solve(int a, int b) {
		int length = String.valueOf(b).length();
		if (length == 1) {
			return "0";
		}
		HashSet<Integer> found = null;
		long total = 0;
		for (int i = a; i < b; i++) {
			found = null;
			String s = String.valueOf(i);
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < s.length(); j++) {
				sb.append(s.charAt((j+s.length()-1)%s.length()));
			}
			int shift = Integer.parseInt(sb.toString());
			for (int j = 1; j < length; j++) {
				
				if (shift > i && shift <= b) {
					if (found == null) {
						found = new HashSet<Integer>();
					}
					if (!found.contains(shift)) {
						found.add(shift);
						//System.out.println(i+","+shift);
						total++;
					}
				}
				
				//s = String.valueOf(shift);
				sb = new StringBuilder();
				for (int k = 0; k < s.length(); k++) {
					sb.append(s.charAt((k+s.length()-(1+j))%s.length()));
				}
				shift = Integer.parseInt(sb.toString());
			}
		}
		return String.valueOf(total);
	}

	//static String size = "sample";
	//static String size = "small";
	//static String size = "large"=
	static String filename = "D:\\gcj\\2012\\Q\\C-large";
}