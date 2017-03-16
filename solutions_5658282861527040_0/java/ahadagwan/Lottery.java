package googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lottery {
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("e:\\B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("e:\\1.out"));
		int t = sc.nextInt();
		//System.out.println(t);
		//out.println("hello");
		for (int i = 0; i < t; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int k=sc.nextInt();
			int val=0;
			for (int j = k; j < a; j++) {
				for (int j2 = k; j2 < b; j2++) {
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
