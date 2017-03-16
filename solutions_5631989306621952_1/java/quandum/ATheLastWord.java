import java.io.*;
import java.util.*;
import java.math.*;

public class ATheLastWord {
	static Scanner reader;
	static PrintWriter outWrite;
	static String s,res;
	static void add(char x){
		String p=Character.toString(x)+res,
			   q=res+Character.toString(x);
		
		if (p.compareTo(q)>=0) res=p;
		else res=q;
	}
	public static void main(String[] args) throws Exception {
		reader=new Scanner(new File("A-large.in"));
		outWrite=new PrintWriter(new File("A-output.txt"));
		int nTest=Integer.parseInt(reader.nextLine());
		for (int test=1;test<=nTest;test++){
			s=reader.nextLine();
			res="";
			for (int i=0;i<s.length();i++) add(s.charAt(i));
			if (test>1) outWrite.println();
			outWrite.print("Case #" + test+": "+res);
		}
		outWrite.close();

	}

}
