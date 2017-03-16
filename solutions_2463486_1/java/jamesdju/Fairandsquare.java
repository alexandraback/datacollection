import java.util.*;
import java.math.BigInteger;

class Fairandsquare{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] precomputed_str = new String[] {"1", "4", "9", "121", "484", 
		"10201", "12321", "14641", "40804", "44944", "1002001", "1234321", "4008004", 
		"100020001", "102030201", "104060401", "121242121", "123454321", "125686521", 
		"400080004", "404090404", "10000200001", "10221412201", "12102420121", "12345654321", 
		"40000800004", "1000002000001", "1002003002001", "1004006004001", "1020304030201", 
		"1022325232201", "1024348434201", "1210024200121", "1212225222121", "1214428244121", 
		"1232346432321", "1234567654321", "4000008000004", "4004009004004"};
		
		BigInteger[] precomputed = new BigInteger[precomputed_str.length];
		for(int i = 0; i < precomputed_str.length; i++){
			precomputed[i] = new BigInteger(precomputed_str[i]);
		}
		int tc = sc.nextInt();
		int counter = 1;

		while(tc-- > 0){
			BigInteger min = sc.nextBigInteger();
			BigInteger max = sc.nextBigInteger();
			int left = 0, right = 0;

			for(int i = 0; i < precomputed.length; i++){
				if(precomputed[i].compareTo(min) == 1 || precomputed[i].compareTo(min) == 0){
					left = i;
					break;
				}
			}
			for(int i = precomputed.length-1; i >= 0; i--){
				if(precomputed[i].compareTo(max) == -1 || precomputed[i].compareTo(max) == 0){
					right = i;
					break;
				}
			}
			System.out.println("Case #" + (counter++) + ": " + (right-left+1));
		}
	}
}