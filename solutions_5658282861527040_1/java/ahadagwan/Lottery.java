package googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lottery {
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("e:\\B-large.in"));
		PrintWriter out = new PrintWriter(new File("e:\\1.out"));
		int t = sc.nextInt();
		//System.out.println(t);
		//out.println("hello");
		for (int i = 0; i < t; i++) {
			Long a = sc.nextLong();
			Long b = sc.nextLong();
			Long k=sc.nextLong();
			int val=0;
			for (Long j = k; j < a; j++) {
				for (Long j2 = k; j2 < b; j2++) {
					if((j&j2)>k-1){
						val++;
						
					}
				}
			}
			
			out.println("Case #"+(i+1)+": "+((a*b)-val));
		}
		out.close();
	}
}
