package com.cbs.trials.cj13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.ArrayList;

public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//System.out.println("Test");
		
		//input
		String[] in=null;
		try{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Admin\\Downloads\\C-large-1.in"));
			//BufferedReader br = new BufferedReader(new FileReader("F:\\ECLIPSEWS\\codejam13\\small.in"));
			String line=null;
			ArrayList<String> ins 	= new ArrayList<>(); 
			while((line=br.readLine())!=null){
				ins.add(line);
			}
			in=ins.toArray(new String[]{});
		}catch(Exception e){
			System.out.println("Error finding/reading file.");
		}

		int numcases = Integer.parseInt(in[0]);
		
		for(int i=1;i<=numcases;i++){
			String[] nums = in[i].split(" ");
			debug("Trying ",nums[0],nums[1]);
			
			long res = getNumPoss(Long.parseLong(nums[0]), Long.parseLong(nums[1]));
			System.out.println(String.format("Case #%d: %s", i, ""+res));
		}
	}
	
	private static long getNumPoss(long low, long high){
		long res =  0;
		
		long lowrt = (long) Math.floor(Math.sqrt(low));
		long highrt = (long) Math.ceil(Math.sqrt(high));
		
		String strt = ""+lowrt;
		String end = ""+highrt;
		
		debug("Sqrt range ",strt, end);
		String curPal=null;
		if(strt.equals(strRev(strt))){
			curPal = strt;
		}else{
			curPal = getFirstHigherPalindrome(strt);
		}
		debug("First pal sqrt ", curPal);
		
		if(curPal == null || Long.parseLong(curPal)>Long.parseLong(end)) return 0; //not even one palindrome in range
		
		while(true){
			debug("Checking pal sqrt ", curPal);
			long cur = Long.parseLong(curPal);
			long cursq = cur*cur;
			debug("Sqr is ", cursq);
			
			if(cursq>=low && cursq<= high){
				String cursqstr = ""+cursq;
				if(cursqstr.equals(strRev(cursqstr))){
					debug("##########################", curPal, cursqstr);
					res++;
				}
			}
			
			if(cursq>high) return res; //no need to check further
			
			curPal=getNextPal(curPal);
			if(curPal == null || Long.parseLong(curPal)>Long.parseLong(end)) return res; //not even one palindrome in range
		}
		
	}
	private static String getNextPal(String curPal){
		String res=null;
		if(curPal.length()%2==0){
			String half = curPal.substring(0, curPal.length()/2 );
			long halfn = Long.parseLong(half);
			halfn++;
			String newhalf = halfn+"";
			if(half.length()==newhalf.length())
				res = newhalf + strRev(newhalf);
			else 
				res=getFirstHigherPalindrome((""+(long)(Math.pow(10.0, curPal.length()))));
			
			return res;
		}else if(curPal.length()%2==1){
			String half = curPal.substring(0, curPal.length()/2 +1);
			long halfn = Long.parseLong(half);
			halfn++;
			String newhalf = halfn+"";
			if(half.length()==newhalf.length())
				res = newhalf + strRev(newhalf).substring(1);
			else 
				res=getFirstHigherPalindrome((""+(long)(Math.pow(10.0, curPal.length()))));
			
			return res;
		}
		
		return res;
	}
	private static String getFirstHigherPalindrome(String curPal){
		String res=null;
		if(curPal.length()%2==0){
			String half = curPal.substring(0, curPal.length()/2 );
			long halfn = Long.parseLong(half);
			//halfn++;
			String newhalf = halfn+"";
			res = newhalf + strRev(newhalf);
			
		}else if(curPal.length()%2==1){
			String half = curPal.substring(0, curPal.length()/2 +1);
			long halfn = Long.parseLong(half);
			//halfn++;
			String newhalf = halfn+"";
			res = newhalf + strRev(newhalf).substring(1);
			
		}
		
		if(Long.parseLong(res)>Long.parseLong(curPal))
			return res;
		else
			return getNextPal(curPal);
	}
	private static String strRev(String in){
		int len = in.length();
		char[] out = new char[len];
		for(int i=0;i<len;i++){
			out[i]=in.charAt(len-i-1);
		}
		return new String(out);
	}
	
	private static boolean debug = false;
	private static void debug(Object o){
		if(debug)
			System.out.println("Debug: "+o);
	}
	private static void debug(Object o, Object o1){
		if(debug)
			System.out.println("Debug: "+o+ ": "+o1);
	}
	private static void debug(Object o, Object o1, Object o2){
		if(debug)
			System.out.println("Debug: "+o+ ": "+o1 + ", "+o2);
	}	
}
