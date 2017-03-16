package codejam20120413;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class B {
	
	void run()throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("B.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B.out"));
		
		int cases = Integer.parseInt(bf.readLine());
		for (int i=0; i<cases; i++) {
			String[] s = bf.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int S = Integer.parseInt(s[1]);
			int p = Integer.parseInt(s[2]);
			int count = 0;
			for (int j=0; j<N; j++) {
				int score = Integer.parseInt(s[j+3]);
				if (score>p*3-3) 
					count++;
				else 
					if ((p*3-3 > 0) && (score==p*3-3 || score==p*3-4) && S-->0) 
						count++;
						
			}
				
			pw.write("Case #"+ (i+1) + ": "+ count + "\n");
		}
		pw.close();
	}
		
	public static void main(String[] args)throws IOException {
		new B().run();
	}
	
	
}
