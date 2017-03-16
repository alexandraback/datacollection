package code_jam.ctsai;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Problem_A {
	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader(
				"/Users/SISQUAKE/workspace/code_jam/input/A-small-attempt0_1.in");

		BufferedReader br = new BufferedReader(fr);
		int n;

		n = Integer.parseInt(br.readLine());

		for (int i = 1; i <= n; i++) {
			String str = br.readLine();
			char c = str.charAt(0);
			String tmp = ""+c;
			for (int j = 1; j < str.length(); j++) {
				if(str.charAt(j)>=tmp.charAt(0)){
					tmp = str.charAt(j) + tmp;
				}else{
					tmp = tmp+str.charAt(j) ;
				}
			}
			System.out.println(tmp);

		}
		fr.close();

	}
}
