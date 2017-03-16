import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	String s;
	HashMap<Character, Character> map;

	void run(){
		solveLocal();
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			s=sc.nextLine();
			solve();
		}
	}

	void solve(){
		String t="";
		for(char c : s.toCharArray()){
			t+=map.get(c);
		}
		answer(t);
	}

	void solveLocal(){
		String s="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String t="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		int n=s.length();
		map=new HashMap<Character, Character>();
		map.put('a', 'y');
		map.put('o', 'e');
		map.put('z', 'q');
		map.put(' ', ' ');
		for(int i=0; i<n; i++){
			map.put(s.charAt(i), t.charAt(i));
		}
		char key=0, value=0;
		for(char c='a'; c<='z'; c++){
			if(!map.containsKey(c)){
				key=c;
			}
			if(!map.containsValue(c)){
				value=c;
			}
		}
		map.put(key, value);
		debug(map.size());
	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		try{
			System.setIn(new FileInputStream("dat/A-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("dat/A-small.out")));
		}catch(Exception e){}
		new A().run();
		System.out.flush();
		System.out.close();
	}
}
