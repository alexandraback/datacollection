package test.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class QualA {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		FileInputStream fos = new FileInputStream("c:/sanker/workspace/input/A-small-attempt0.in");
		BufferedReader buf = new BufferedReader(new InputStreamReader(fos));
		String str = "";
		int C, D, N;
		String Car[], Dar[];
		int Credit, Items;
		String eng = "abcdefghijklmnopqrstuvwxyz ";
		String goo = "ynficwlbkuomxsevzpdrjgthaq ";

		str = buf.readLine();
		N = Integer.parseInt(str);
		for(int cnti=0; cnti<N ; cnti++) {
			str = buf.readLine();
			if(str == null) System.exit(0);
			char[] chars = str.toCharArray();
			String msg = "";
				for(int j=0;j<chars.length;j++) {
					msg += eng.charAt(goo.indexOf(chars[j]));
				}
			
			System.out.println("Case #"+(cnti+1)+": "+msg);
			
		}
		
	}
	
	

}
