import java.io.*;
import java.util.*;
import java.math.*;

public class A {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=0; i<t; i++){
			char[] s = in.next().toCharArray();
			System.out.println("Case #"+(i+1)+": "+solve(s, 0, s.length-1));
		}
	}
	
	public static  String solve(char[] s, int from, int to){
		if(from == to)
			return String.valueOf(s[from]);
		if(from > to)
			return "";
		char max = '@';
		int loc = 0;
		for(int j = to; j>=from; j--){
			if(s[j] > max){
				max = s[j];
				loc = j;
			}
		}
		
		String rest = "";
		if(loc != to){
			rest = new String(s, loc+1, (to-loc));
		}
		
		return (String.valueOf(s[loc]))+solve(s, from, loc-1) + rest;
		
	}
}