package facebook;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Qual {

	private static BufferedReader br = null;
	private static int readInt() {
		try {
			return Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static double readDouble() {
		try {
			return Double.parseDouble(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
	private static int[] readIntArr() {
		int[] ret = null;
		String[] tmp;
		try {
			String str = br.readLine();
			tmp = str.split(" ");
			ret = new int[tmp.length];
			for (int i = 0; i < tmp.length; i++)
				ret[i] = Integer.parseInt(tmp[i]);//Integer.parseInt(tmp[i]);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	
	public static int foundMax(String s) {
		int max = 10000;
		Map<Character, Integer> map = new HashMap<Character,Integer>();
		for (char c : s.toCharArray()) {
			int x = 0;
			if (map.containsKey(c)) {
				 x = map.get(c);
			}
			x++;
			map.put(c, x);
		}
		
		for (Entry<Character, Integer> e : map.entrySet()) {
			int x = e.getValue();
			char c = e.getKey();
			if (!mapChars.containsKey(c)) {
				return 0;
			}
			int t = mapChars.get(c);
			
			if (t / x < max)max = t / x;
		}
		return max;
	}
	
	public static void validate(String s, int count) {
		for (char c : s.toCharArray()) {
			int x = mapChars.get(c);
			x -= count;
			mapChars.put(c, x);
		}
	}
	
	public static Map<Character, Integer> mapChars;
	public static String[] str = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		br = new BufferedReader(new FileReader(new File("input.txt")));
		System.setOut(new PrintStream(new File("output.txt")));
		int T = readInt();
		
		for (int ind = 1; ind<=T; ind++) {
			System.out.print("Case #" + ind + ": ");
			
			String s = br.readLine();
			mapChars = new HashMap<Character, Integer>();
			for (char c : s.toCharArray()) {
				int x = 0;
				if (mapChars.containsKey(c)) {
					 x = mapChars.get(c);
				}
				x++;
				mapChars.put(c, x);
			}
			String ans = "";
			int[] ar = new int[] {0, 2, 6, 4, 5, 7, 1, 9, 3, 8};
			
			//0 2 6 4 5 7 1 9 3 8
			
			for (int i = 0; i < 10; i++) {
				int d = ar[i];
				int count = foundMax(str[d]);
				if (count > 0) {
				validate(str[d], count);
				}
				
				for (int j = 0; j < count; j++) {
					ans = ans + d;
				}
			}
			char[] ch = ans.toCharArray();
			Arrays.sort(ch);
			for (int i = 0; i < ch.length; i++)System.out.print(ch[i]);
			System.out.println();
			
		}
		

	}

}
