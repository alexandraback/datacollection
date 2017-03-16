package test.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class Qual2012B {


	public static void main(String[] args) throws Exception {
		FileInputStream fos = new FileInputStream("c:/sanker/workspace/input2/B-large.in");
		BufferedReader buf = new BufferedReader(new InputStreamReader(fos));
		String str = "";
		int S, P, numT, N;

		str = buf.readLine();
		numT = Integer.parseInt(str);
		for(int i=0; i<numT ; i++) {
			str = buf.readLine();
			if(str == null) System.exit(0);
			String[] numbers = str.split(" ");
			N = Integer.parseInt(numbers[0]);
			S = Integer.parseInt(numbers[1]);
			P = Integer.parseInt(numbers[2]);

			int num, count=0, surpriseCnt=0;
			for(int j=3;j<numbers.length;j++) {
				num = Integer.parseInt(numbers[j]);
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
						if(d1 >= d3 && surpriseCnt+1 <= S) {
							count++; surpriseCnt++;
						}
				}
			}
			
			}
			System.out.println("Case #"+(i+1)+": "+count);
			
		}
		
	}
	
	

}
