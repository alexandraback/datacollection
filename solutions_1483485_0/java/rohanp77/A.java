import java.io.*;
import java.util.*;

public class A {
	
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static String[] input = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	
	public static String[] output = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up",		
	};
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		
		char[] map = new char[26];
		for (int i=0; i<map.length; i++) map[i]=0;
		for (int i=0; i<input.length; i++){
			for (int j=0; j<input[i].length(); j++){
				if (input[i].charAt(j)==' ') continue;
				map[input[i].charAt(j)-'a'] = output[i].charAt(j);
			}
		}
		map['q'-'a'] = 'z';
		
		int sum = 0;
		for (int i=0; i<map.length; i++){
			sum += i - map[i] + 'a';
		}
		map['z'-'a'] = (char)sum;
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			String trans = readLine();
			for (int i=0; i<trans.length(); i++)
				out.print((trans.charAt(i)==' ')?' ':map[trans.charAt(i)-'a']);
			out.println();
		}
		
		in.close();
		out.close();
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		if (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
}
