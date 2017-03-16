package gcj2015.r1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final boolean isSmall = false;
	final String PACKAGE = "gcj2015/r1c";
	final String PROBLEM = "A";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt0.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out-deg.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int R = sc.nextInt(), C = sc.nextInt(), W = sc.nextInt();
			int w = 0, res = 0;
			res += R*(C/W);
			if (C%W==0)res+=W-1;
			else res+=W;
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
