package qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class FairAndSquare {
	static boolean[] fair=new boolean[1001];
	static boolean[] fairAndSquare=new boolean[1001];
	public static void process() {
		//Find palindromes
		for(int i=1;i<=1000;i++) {
			if(isPalindrome(i)) {
				fair[i]=true;
			}
		}
		int sq;
		for(int i=1;i<32;i++) {
			if(fair[i]) {
				sq=i*i;
				if(fair[sq]) {
					fairAndSquare[sq]=true;
				}
			}
		}
	}
	public static boolean isPalindrome(int x) {
		String s=x+"";
		int length=s.length();
		for(int i=0;i<length/2;i++) {
			if(s.charAt(i)!=s.charAt(length-1-i)) {
				return false;
			}
		}
		return true;
	}
	public static void main(String args[]) throws IOException {
		FileInputStream fis=new FileInputStream("C:/users/baqiral/Desktop/baqir.txt");
		BufferedReader br=new BufferedReader(new InputStreamReader(fis));
		process();
		int test=Integer.valueOf(br.readLine());
		int tester=1,i=0,a=0,b=0,pos;
		while(tester<=test) {
			String s=br.readLine();
			pos=s.indexOf(" ");
			a=Integer.valueOf(s.substring(0,pos));
			b=Integer.valueOf(s.substring(pos+1));
			int count=0;
			for(i=a;i<=b;i++) {
				if(fairAndSquare[i]) {
					count++;
				}
			}
			System.out.println("Case #"+tester+": "+count);
			tester++;
		}
	}
}
