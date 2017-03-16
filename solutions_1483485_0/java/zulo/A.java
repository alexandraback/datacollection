import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class A {
	static void map(char[] tgt, String a, String b) {
		for (int p=0; p<a.length(); p++) {
			char ca=a.charAt(p), cb=b.charAt(p);
			if (ca>='a' && ca<='z') 
				tgt[ca-'a']=cb;
		}
	}

	public static void main(String[] args) throws Exception {
		char[] tgt=new char[33];
		map(tgt, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		map(tgt, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		map(tgt, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
		map(tgt, "qz", "zq");
	
		Scanner sc=new Scanner(System.in);
		String ln=sc.nextLine();
		int rc=Integer.parseInt(ln);
		for (int r=0; r<rc; r++) {
			ln=sc.nextLine();
			String re="";
			for (int p=0; p<ln.length(); p++) {
				char x=ln.charAt(p);
				if (x>='a' && x<='z')
					re += tgt[x-'a'];
				else
					re +=x;
			}
			System.out.printf("Case #%d: %s\n", r+1, re);
		}
	}
}