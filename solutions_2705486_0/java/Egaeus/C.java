import java.io.*;

import static java.lang.Integer.*;
import static java.lang.Math.*;
import java.util.*;
public class C {
	static ArrayList<char[]> set=new ArrayList<char[]>();
	static char[] str;
	static int[][] mem;
	static int solve(int a,int b) {
		if(a==b)return 0;
		if(mem[a][b]>-1)return mem[a][b];
		int min=memP[a][b];
		for(int i=a+1;i<b;i++)
			if(solve(a,i)!=MAX_VALUE&&solve(i,b)!=MAX_VALUE)
				min=min(solve(a,i)+solve(i,b),min);
		return mem[a][b]=min;
	}
	
	static int f(int a,int b) {
		int min=MAX_VALUE;
		for(char[] s:set) {
			if(b-a==s.length) {
				int cont=0;
				for(int i=0;i<s.length&&cont!=MAX_VALUE;i++) {
					if(s[i]!=str[a+i]){
						boolean ws=true;
						for(int j=0,h=i+1;j<4&&h<s.length&&ws;j++,h++)
							if(str[a+h]!=s[h])ws=false;
						if(!ws)
							cont=MAX_VALUE;
						else cont++;
					}
				}
				min=min(min,cont);
			}
		}
		return min;
	}
	
	static int[][] memP;
	
	public static void main(String[] args) throws Throwable{
		System.setOut(new PrintStream("A.out"));
		BufferedReader in=new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
		for(String ln;(ln=in.readLine())!=null;) {
			set.add(ln.toCharArray());
		}
		
		in=new BufferedReader(new InputStreamReader(System.in));
		for(int t=0,T=parseInt(in.readLine().trim());t++<T;) {
			str=in.readLine().toCharArray();
			mem=new int[str.length+1][str.length+1];
			for(int[] m:mem)Arrays.fill(m, -1);
			memP=new int[str.length+1][str.length+1];
			for(int[] m:memP)Arrays.fill(m, MAX_VALUE);
			for(int i=0;i<=str.length;i++)
				for(int j=i+1;j<=str.length;j++)
					if(j-i<=10)
						memP[i][j]=f(i,j);
			System.out.println("Case #"+t+": "+solve(0,str.length));
		}
	}
}
