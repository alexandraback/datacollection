package test.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class QualB {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		FileInputStream fos = new FileInputStream("c:/sanker/workspace/input1/B-large.in");
		BufferedReader buf = new BufferedReader(new InputStreamReader(fos));
		String str = "";
		int S, P, N, N0;
		String Car[], Dar[];
		int ar[],k=0;

		str = buf.readLine();
		N0 = Integer.parseInt(str);
		for(int cnti=0; cnti<N0 ; cnti++) {
			str = buf.readLine();
//			System.out.println("str="+str);
			if(str == null) System.exit(0);
			String[] chars = str.split(" ");
			N = Integer.parseInt(chars[0]);
			S = Integer.parseInt(chars[1]);
			P = Integer.parseInt(chars[2]);

			int num, count=0, surCount=0;
			for(int j=3;j<chars.length;j++) {
				num = Integer.parseInt(chars[j]);
				if(num == 0) {
					if(num == P) count++;
					continue;
				}
				if(num/3 >= P) {
					count++;
				}else {
					int d1 = num - P;
					int d2 = (P * 2) - 2;
					if(d1 >= d2)
						count++;
					else {
						int d3 = (P * 2) - 4;
						if(d1 >= d3 && surCount+1 <= S) {
							count++; surCount++;
						}
				}
			}
			
			}
			System.out.println("Case #"+(cnti+1)+": "+count);
			
		}
		
	}
	
	

}
