package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {
	public static ArrayList<String> pailie(String keys, int S) {
		ArrayList<String> temp = new ArrayList<String>();
		ArrayList<String> result = temp;
		temp.add("");
		for(int i = 0; i < S; i++)
		{
			result = new ArrayList<String>();
			for (String s:temp)
				for (int j = 0; j < keys.length(); j++)
					result.add(s + keys.charAt(j));
			temp = result;
		}
		return result;
	}
	public static double banana(String keys, String target, int S) {
		ArrayList<String> result = pailie(keys, S);
		int max = 0;
		int sum = 0;
		System.out.println(result.size());
		for (String s: result) {
			int start = 0;
			int count = 0;
			while ((start = s.indexOf(target, start)) >= 0) {
				count++;
				start++;
			}
			sum += count;
			max = Math.max(count, max);
			//System.out.println(s + "\t" + count);
		}
		return max - sum * 1.0 / result.size();
	}
	public static void main(String[] args) {
		File fin = new File("src/Round1C/B-small-attempt0.in");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/Round1C/B_test.out.txt");
			int T = scan.nextInt();
			for(int i = 0; i < T; i++)
			{
				int K = scan.nextInt();
				int L = scan.nextInt();
				int S = scan.nextInt();
				String keys = scan.next();
				String target = scan.next();
				output.println("Case #" + (i + 1) + ": " + banana(keys, target, S));
				System.out.println("Case #" + (i + 1) + ": " + banana(keys, target, S));
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
