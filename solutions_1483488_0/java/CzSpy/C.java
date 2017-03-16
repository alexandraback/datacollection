package codejam20120413;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class C {
	int digits(int in) {
		int count=0;
		for (;(in=in/10)>0; count++);
		return count;
	}
	int shift(int in, int mag) {	
		return  mag*(in%10) + in/10;
	}
	void run()throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("C.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C.out"));
		
		int cases = Integer.parseInt(bf.readLine());
		for (int i=0; i<cases; i++) {
			String[] s = bf.readLine().split(" ");
			int from = Integer.parseInt(s[0]);
			int to = Integer.parseInt(s[1]);
			int count=0;
			for (int j=from; j<to; j++) {
				int in = j;
				int digits = digits(in);
				int mag = 1;
				for (int k = 0; k < digits; k++) {
					mag = mag*10;
				}
				HashSet<Integer> set = new HashSet<Integer>();
				for (int k = 0; k < digits; k++) {
					int shift = shift(in, mag);
					if (shift>j && shift <= to) {
						if (!set.contains(shift)) {
							set.add(shift);
							count++;
						}
					}
					in=shift;
				}
			}
			pw.write("Case #"+ (i+1) + ": "+ count + "\n");
		}
		pw.close();
	}
		
	public static void main(String[] args)throws IOException {
		new C().run();
	}
	
	
}
