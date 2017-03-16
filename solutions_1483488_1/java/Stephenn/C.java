package info.stephenn.codejam2012.qualify;

import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Scanner;

public class C {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseX=1; caseX <= cases; caseX+=1){
			int A = sc.nextInt();
			int B = sc.nextInt();
			System.out.println("Case #"+caseX+": "+doitSweep(A,B));
		}
	}
	
	public static int doitRecycled(int A, int B){
		int[] mCounts = new int[B+1];
		
		int count=0;
		for (int m = A+1; m<= B; m++){
			int mCount = 0;
			int nStart = A;
			for (int mrIndex = m; mrIndex >=0; mrIndex-=1){
				if (C.isRecycled(mrIndex, m)){
					mCount = mCounts[mrIndex];
					nStart = mrIndex;
					break;
				}
			}
			
			
			for (int n = nStart; n< m; n++){
				if (C.isRecycled(n, m))
					mCount+=1;
			}
			count += mCount;
			
			mCounts[m] = mCount;
		}
		return count;
	}
	
	public static int doit(int A, int B){
		int count=0;
		for (int m = A+1; m <= B; m++){
			for (int n = A; n < m; n++){
				if (isRecycled(n,m)){
					count+=1;
					System.out.println("("+n+","+m+")");
				}
					
			}
		}
		
		return count;
	}
	
	public static int isRecycledString(String n, String m){
		
		
		if (isRecycled(Integer.parseInt(n), Integer.parseInt(m)))
			return 1;
		else return 0;
		
//		for (int split =1; split < n.length(); split++){
//			String t = n.substring(split) + n.substring(0, split);
//			if (t.equals(m))
//				return 1;
//		}
//		return 0;
	}
	
	public static boolean isRecycled(int n, int m){
		int length = Integer.toString(n).length();
		
		int pow = 1;
		for (int i =1 ; i < length; i++)
			pow *= 10;
		
		int t = n;
		for (int split =1; split < length; split++){
			int back = t%10;
			int front = t/10;
			int backInFront = back * pow;
			t = backInFront + front;
			if (t==m)
				return true;
		}
		
		return false;
	}
	
	public static int doit3(int A, int B){
		table.clear();
		int count=0;
		for (int m = A+1 ; m <= B; m++){
			count += permutationsOf(m, A, B);
		}
		return count;
	}
	
	public static int permutationsOf(int n, int fromA, int toB){
		int length = Integer.toString(n).length();
		
		int pow = 1;
		for (int i =1 ; i < length; i++)
			pow *= 10;
		
		int t = n;
		int count =0;
		for (int split =1; split < length; split++){
			int back = t%10;
			int front = t/10;
			int backInFront = back * pow;
			t = backInFront + front;
			if (fromA <= t && t <= toB && t != n && doIHave(n,t)==false && doIHave(t,n)==false){
				have(n,t);
				have(t,n);
				System.out.println("is perm"+t);
				count +=1;
			}
				
		}
		return count;
	}
	
	static Hashtable<String,String> table = new Hashtable<String,String>();
	static String EMPTY_STRING = "";
	
	public static void have(int x, int y){
		//mark that this perm has been counted.
		table.put(Integer.toString(x)+","+Integer.toString(y), EMPTY_STRING);
	}
	public static boolean doIHave(int x,int y){
		return table.contains(Integer.toString(x)+","+Integer.toString(y));
	}
	
	public static int doitSweep(int A, int B){
		boolean[] done = new boolean[B+1];
		HashMap<String,String> distinctPairs = new HashMap<String,String>();
		
		int count=0;
		for (int x = A; x <= B; x++){
			if (done[x] == false){
				int[] perms = permutationsOfBetween(x, A, B);
				for (int p : perms) done[p] =true;
				
				for (int n : perms){
					for (int m : perms){
						if (n != m && distinctPairs.containsKey(indexPair(n,m))==false){
							count+=1;
							distinctPairs.put(indexPair(n,m), EMPTY_STRING);
						}
					}
				}
			}
		}
		return count;
	}
	
	public static String indexPair(int n, int m){
		if (n < m) return ""+n+","+m;
		else return ""+m+","+n;
	}
	
	public static int[] permutationsOfBetween(int x, int A, int B){
		int length = Integer.toString(x).length();
		
		int[] permutations = new int[length];
		int permCount=0;
		
		int pow = 1;
		for (int i =1 ; i < length; i++)
			pow *= 10;
		
		int t = x;
		for (int split =0; split < length; split++){
			int back = t%10;
			int front = t/10;
			int backInFront = back * pow;
			t = backInFront + front;
			
			if (A <= t && t <= B){
				permutations[permCount++] = t;
			}	
		}
		return Arrays.copyOfRange(permutations, 0, permCount);		
	}
}