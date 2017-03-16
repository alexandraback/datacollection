import java.util.Scanner;

public class pro1 {
	static int R,C,W;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T= scan.nextInt();

		for( int t=0; t<T; t++){
			R= scan.nextInt();
			C= scan.nextInt();
			W= scan.nextInt();
			
			println("Case #"+(t+1)+": "+run());
		}
	}
	
	static String run(){

		int find = (C/W)*(R-1);
		find += (C-1)/W;
		int ret = find+W;

		return ""+ret;
	}
	
	
	static void println(String a){
		System.out.println(a);
	}
	static void print(String a){
		System.out.print(a);
	}
	static int factorial(int f){
		if( f == 0 ) return 1;
		int ret = 1;
		for( int i=1; i<=f; i++	){
			ret *= i;
		}
		return ret;
	}	
	/*
	 *  a[0]:index of smallest, a[l-1]:index of largest
	 *  1 3 4 6 0 7  --> index[0]=4, index[1]=0, index[2]=1, ...
	 */
	static int[] indexedSort(int[] arr, int l){
		int[] index = new int[l];
		for( int i=0; i<l; i++){
			index[i] = i;
		}
		
		for( int i=0; i<l; i++){
			int min = i;
			for( int j=i; j<l; j++){
				if( arr[index[min]] > arr[index[j]] ){
					min = j;
				}
			}
			int temp = index[i];
			index[i] = index[min];
			index[min] = temp;
		}
		
		return index;
	}
	static String abbreviate(String str){
		char c = str.charAt(0);
		String ret = ""+c;
		for(int i=0; i<str.length();i++){
			if( c != str.charAt(i) ){
				c = str.charAt(i);
				ret += c;
			}
		}
		return ret;
	}
	static long gcd(long x, long y) {
		long temp;
		while (y != 0) {
			temp = x % y;
			x = y;
			y = temp;
		}
		return Math.abs(x);
	}
	static long lcm(long[] list) {
		long lcm = 1;
		for (int i = 0; i < list.length; i++){
			lcm = lcm*list[i]/gcd(lcm,list[i]);
		}
		return lcm;
	}
	static long pow(long a, long b){
		long ret=1;
		for( int i=0;i<b; i++){
			ret*=a;
		}
		return ret;
	}
}
