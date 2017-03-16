package test.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class Qual2012C {


	public static void main(String[] args) throws Exception {
		FileInputStream fos = new FileInputStream("c:/sanker/workspace/input2/C-small-attempt0.in");
		BufferedReader buf = new BufferedReader(new InputStreamReader(fos));
		String str = "";
		int N0;

		str = buf.readLine();
		N0 = Integer.parseInt(str);
		for(int cnti=0; cnti<N0 ; cnti++) {
			str = buf.readLine();
			if(str == null) System.exit(0);
			String[] chars = str.split(" ");
			int A, B;
			A = Integer.parseInt(chars[0]);
			B = Integer.parseInt(chars[1]);
			int num=0, count=0;
			for(int j=A;j<B;j++) {
				num = j;
				String num1 = String.valueOf(num);
				String orgnum1 = String.valueOf(num);
				int numlen = num1.length();
				for(int k=1;k<=numlen;k++) {
					num1 = orgnum1.substring(orgnum1.length()-k)+""+orgnum1.substring(0, orgnum1.length()-k);
					if(num1.equals(String.valueOf(num)))
						break;
					if(num < Integer.parseInt(num1) && Integer.parseInt(num1) <= B ) {
						count++;
					}
				}
			}
			
			System.out.println("Case #"+(cnti+1)+": "+count);
			
		}
		
	}
	
	

}
