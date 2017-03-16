import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class LastWord {
static PrintWriter writer;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("in.txt"));
		writer = new PrintWriter("out.txt", "UTF-8");
		int n = sc.nextInt();
		sc.nextLine();
		for (int t = 0; t < n; t++) {
			String s=sc.nextLine();
			//System.out.println("--------------------------");
			//System.out.println(s);
			String g=sort(s,"",0);
			//System.out.println(g);
			out(t+1,g);
			
		}
		writer.close();
	}
	
	public static String sort(String full,String s,int l){
		if (l>=full.length())return s;
		String jj1=full.charAt(l)+s;
		String jj2=s+full.charAt(l);
		if (jj1.compareTo(jj2)>0)return sort(full,jj1,l+1);
		else return sort(full,jj2,l+1);
		
		
	}

	private static void out(int i, String j) {
		String s="Case #"+i+": "+j;
		writer.println(s);
		System.out.println(s);
		
	}
}
