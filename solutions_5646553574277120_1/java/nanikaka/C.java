package gcj2015.r1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	final boolean DEBUG = false;
	final boolean isSmall = false;
	final String PACKAGE = "gcj2015/r1c";
	final String PROBLEM = "C";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt0.in")));
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
			int C = sc.nextInt(), D = sc.nextInt(), V = sc.nextInt();
			int[] d = new int[D];
			for(int i=0;i<D;i++)d[i]=sc.nextInt();
			int pos = 0, res = 0;
			long v = 0;
			while(v < V){
				while(pos < D && d[pos] <= v+1){
					v += 1L * C * d[pos++];
					if (V <= v)break;
				}
				if (V <= v)break;
				res++;
				v += (v+1L)*C;
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
