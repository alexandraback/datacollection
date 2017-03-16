package gcj2012.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final String PACKAGE = "gcj2012/qual";
	final String PROBLEM = "A";
	
	void run(){
		if(!DEBUG){
			try {
				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
//				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"_large.in")));
				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
//				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"_large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		char[] c = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
		for(int CASE=1;CASE<=T;CASE++){
			char[] t = sc.nextLine().toCharArray();
			for(int i=0;i<t.length;i++)if(t[i]!=' ')t[i]=c[t[i]-'a'];
			System.out.println("Case #"+CASE+": "+new String(t));
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
