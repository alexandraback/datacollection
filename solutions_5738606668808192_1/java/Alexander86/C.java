import java.util.*;
import java.math.*;

public class C{
	public static Random rand;
	public static Scanner scan;
	public static void main(String[] args){
		rand = new Random(378146823);
		scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; t++){
			System.out.println("Case #" + t + ":");
			calc();
		}
	}

	public static void calc(){
		int len = scan.nextInt();
		int N = scan.nextInt();
		BigInteger c_divisors[] = new BigInteger[11];
		int i_divisors[] = {3,5,7,11,13,17,19,23,29,31,37};
		BigInteger divisors[] = new BigInteger[11];
		divisors[0] = BigInteger.valueOf(3);
		divisors[1] = BigInteger.valueOf(5);
		divisors[2] = BigInteger.valueOf(7);
		divisors[3] = BigInteger.valueOf(11);
		divisors[4] = BigInteger.valueOf(13);
		divisors[5] = BigInteger.valueOf(17);
		divisors[6] = BigInteger.valueOf(19);
		divisors[7] = BigInteger.valueOf(23);
		divisors[8] = BigInteger.valueOf(29);
		divisors[9] = BigInteger.valueOf(31);
		divisors[10] = BigInteger.valueOf(37);
		TreeSet<String> used = new TreeSet<String>();
		while(used.size() < N){
			char dig[] = new char[len];
			dig[0] = dig[len-1] = '1';
			for(int i = 1; i < len - 1; i++)dig[i] = (rand.nextBoolean()?'0':'1');
			String cur = new String(dig);
			if(used.contains(cur))continue;
			for(int b = 2; b <= 10; b++){
				BigInteger base = BigInteger.valueOf(b);
				BigInteger num = BigInteger.ZERO;
				for(int i = 0; i < len; i++){
					num = num.multiply(base);
					if(dig[i] == '1')num = num.add(BigInteger.ONE);
				}
				c_divisors[b] = null;
				for(int i = 0; i < divisors.length; i++){
//					System.out.println(num + " " + divisors[i]);
//					System.out.println("JH");
					if(num.compareTo(divisors[i]) <= 0)continue;
//					System.out.println(divisors[i] + " " + num.mod(divisors[i]));
					if(num.mod(divisors[i]).equals(BigInteger.ZERO)){
						c_divisors[b] = divisors[i];
						break;
					}
				}
				if(c_divisors[b] == null){
//					System.out.println(cur + " " + b + " " + num);
					cur = "";
					break;
				}
			}
//			System.out.println("H");
			if(cur.equals(""))continue;
			System.out.print(cur);
			for(int b = 2; b <= 10; b++)System.out.print(" " + c_divisors[b]);
			System.out.println();
			used.add(cur);
		}
	}
}
