package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class Round1C_1 {
	public static int process(long p, long q) {
		if(p >= ((q/2) + (q%2))) return 1;
		
		for(int i=1; i<=40; i++) {
			p = 2*p;
			if( p>=q ) return i;
		}
		
		//여기까지 올 이유는 없다
		return -1;
		
	}
	public static void main(String args[]) {
		try {
			Scanner inputfile = new Scanner(new File("A-small-attempt0.in"));
			int t = inputfile.nextInt();
			String s = inputfile.nextLine();
			for(int i=0; i<t; i++) {
				s = inputfile.nextLine();
				String sa = s.split("/")[0];
				String sb = s.split("/")[1];
				
				long p = Long.parseLong(sa);
				long q = Long.parseLong(sb);
				
				
				System.out.printf("Case #%d: ", i+1);
				long k = p % q;
				for(int j=0; j<40; j++) {
					k = (k*2) % q;
				}
				
				if(k!=0) {
					System.out.println("impossible");
				}
				else {
					int ans = process(p,q);
					System.out.println(ans);
				}
				
			}
			
			inputfile.close();

				
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
