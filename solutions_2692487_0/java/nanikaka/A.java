package gcj2013.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2013/r1b";
	final String PROBLEM = "A";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int A = sc.nextInt(), N = sc.nextInt();
			int[] m = new int[N];
			for(int i=0;i<N;i++)m[i]=sc.nextInt();
			Arrays.sort(m);
			int res = N, num = 0;
			if(A>1){
				for(int i=0;i<N;i++){
					res = Math.min(res, num+N-i);
					while(A <= m[i]){
						A = 2*A-1;
						num++;
					}
					A+=m[i];
				}
				res = Math.min(res, num);
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
