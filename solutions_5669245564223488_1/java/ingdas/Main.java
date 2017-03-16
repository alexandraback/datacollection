

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	final static long modn = 1000000007;
	
	public static void main(String[] args) {
		int c = sc.nextInt();
		for (int i = 0 ; i < c ; i++){
			System.out.print("Case #"+(i+1)+": ");
			solve();
		}
		
	}

	private static void solve() {
		boolean abort = false;
		
		int c = sc.nextInt();
		
		HashMap<Character,Integer> pure = new HashMap<>();
		HashMap<Character,Character> impure = new HashMap<>();
		HashMap<Character,Character> impurer = new HashMap<>();
		HashSet<Character> contained = new HashSet<>();
		
		for(int i = 0 ; i < c ; i++){
			String n = sc.next();
			
			if(abort){
				continue;
			}
			
			boolean st = true;
			char curChar = n.charAt(0);
			for(int j = 1 ;  j < n.length() ; j ++){
				if(n.charAt(j) == curChar){
					continue;
				}
				if(!st){
					contained.add(curChar);
				}
				
				curChar = n.charAt(j);
				st = false;
			}
			if(st){
				if(pure.containsKey(curChar)){
					pure.put(curChar, pure.get(curChar)+ 1);
				}else{
					pure.put(curChar,1);
				}
			}else{
				if(impure.containsKey(n.charAt(0)) || impurer.containsKey(curChar)){
					System.out.println("0");
					abort = true;
					continue;
				}
				impure.put(n.charAt(0), curChar);
				impurer.put(curChar,n.charAt(0));
			}
		}
		if(abort){
			return;
		}
		
		for(char con : contained){
			if(impurer.containsKey(con) || impure.containsKey(con) || pure.containsKey(con)){
				System.out.println("0");
				return;
			}
		}
		BigInteger factor = BigInteger.ONE;
		long pureUnique = 0;
		for(char a : pure.keySet()){
			factor.multiply(facul(pure.get(a)));
			if(! impure.containsKey(a) && ! impurer.containsKey(a)){
				pureUnique++;
			}
		}
		HashMap<Character, Character> purged = purge(impure);
		if(purged != null){
			BigInteger out = factor.multiply(facul(purged.size()+pureUnique));
			out.mod(new BigInteger("1000000007"));
			
			System.out.println(out);			
		}
		
	}
	
	private static HashMap<Character, Character> purge(HashMap<Character, Character> impure){
		for(Character a : impure.keySet()){
			Character b = impure.get(a);
			if(impure.containsKey(b)){
				if(a == impure.get(b)){
					System.out.println("0");
					return null;
				}
				HashMap<Character,Character> out = (HashMap<Character, Character>) impure.clone();
				out.remove(a);
				out.remove(b);
				out.put(a, impure.get(b));
				
				return purge(out);
			}
		}
		return impure;
	}

	static BigInteger facul(long n){
		BigInteger r = BigInteger.ONE;
		for(long i = 2 ; i <= n ; i++){
			r = r.multiply(BigInteger.valueOf(i));		
		}
		return r;
	}
	
	

}
