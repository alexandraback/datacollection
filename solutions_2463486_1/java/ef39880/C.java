package qualificationRound2013;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.TreeSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import static java.lang.Math.*;

public class C {

	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);
	static TreeSet<BigInteger> rpset = new TreeSet<BigInteger>();

	public static void main(String[] args) {
		try{
			scan = new Scanner(new File("C-large-1.in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter(new File("Clarge1.txt"))));
		}catch(IOException e){
			System.out.println(e);
		}
		
		rpset.add(new BigInteger("9"));
		String[] seed = new String[]{"0","1","2","00","11","22"};
		Queue<String> que = new LinkedList<String>();
		for (int i = 0; i < seed.length; i++) {
			que.offer(seed[i]);
		}
		while(!que.isEmpty()){
			String num = que.poll();
			if(num.length()>50 || isOverFlow(num)) continue;
			if(num.charAt(0)!='0'){
				rpset.add(new BigInteger(num).pow(2));
			}
			for (int i = 0; i < 3; i++) {
				que.offer(i+num+i);
			}
		}

//		for(String e : rpset){
//			out.println(e);
//		}
//		out.println(rpset.size());

		int n = si();
		for (int i = 0; i < n; i++) {
			BigInteger s = new BigInteger(scan.next());
			BigInteger e = new BigInteger(scan.next());
			int cnt=0;
			for (BigInteger rn : rpset) {
				if(e.compareTo(rn)<0) break;
				if(s.compareTo(rn)<=0) cnt++;
			}
			out.println("Case #"+(i+1)+": "+cnt);
		}

		out.flush();
	}

	static boolean isPal(BigInteger n){
		String str = ""+n;
		for (int i = 0; i < str.length()/2 ; i++) {
			if(str.charAt(i)!=str.charAt(str.length()-1-i)) return false;
		}
		return true;
	}

	static boolean isOverFlow(String n){
		int sum=0;
		for (int i = 0; i < n.length(); i++) {
			sum+=(int)pow((int)(n.charAt(i)-'0'),2);
			if(sum>=10) return true;
		}
		return false;
	}

	static int si() {
		return Integer.parseInt(scan.next());
	}
}
