import java.util.*;
import java.lang.*;
import java.math.*;

public class coinJam
{
	//Integer.parseLong(str, base)

	static BigInteger isPrime(BigInteger n){
		BigInteger b0 = new BigInteger("0");
		BigInteger b2 = new BigInteger("2");
		BigInteger b3 = new BigInteger("3");
		BigInteger b6 = new BigInteger("6");
		BigInteger limit = new BigInteger("10000");
		if (n.compareTo(b2) == 0 || n.compareTo(b3) == 0)
			return new BigInteger("-1");
		else if ((n.mod(b2)).compareTo(b0) == 0)
			return b2;
		else if ((n.mod(b3)).compareTo(b0) == 0)
			return b3;
		else {
			BigInteger i = new BigInteger("5");
			BigInteger w = new BigInteger("2");

			while((i.multiply(i)).compareTo(n) == -1){
				if ((n.mod(i).compareTo(b0)) == 0)
					return i;
				i = i.add(w);
				w = b6.subtract(w);
				if (i.compareTo(limit) == 1){
					return new BigInteger("-1");
				}
			}
			return new BigInteger("-1");
		}
	}

	static String isJam(String s){
		String ret = "";
		if (s.charAt(0) == '0' || s.charAt(s.length() - 1) == '0'){
			return "";
		}

		for (int i = 2; i <= 10; i++){
			BigInteger primality = isPrime(new BigInteger(s, i));
			BigInteger neg = new BigInteger("-1");
			if (primality.compareTo(neg) == 0){
				return "";
			}
			ret = ret + " " + primality.toString();
		}
		return ret;
	} 

	static String nextBinaryString(String s){
		String ret = "";
		for (int i = s.length() - 1; i >= 0; i--){
			if(s.charAt(i) == '0'){
				ret = s.substring(0, i) + "1" + ret;
				return ret;
			}
			else {
				ret = "0" + ret;
			}
		}

		return "false";
	}

	// static String prevBinaryString(String s){
	// 	String ret = "";
	// 	for (int i = s.length() - 1; i >= 0; i--){
	// 		if(s.charAt(i) == '1'){
	// 			ret = s.substring(0, i) + "0" + ret;
	// 			return ret;
	// 		}
	// 		else {
	// 			ret = "1" + ret;
	// 		}
	// 	}
	// 			ret = "";
	// 	for(int i = 0; i < s.length(); i++){
	// 		ret += "0";
	// 	}
	// 	return "false";
	// }

	// static String randomBinaryString(String s){
	// 	String ret = "";
	// 	Random rnd = new Random();
	// 	for (int i = 0; i < s.length(); i++){
	// 		ret += rnd.nextInt(2);
	// 	}
	// 	return ret;
	// }

	static void produceJam(int n, int j){
		HashSet<String> hs = new HashSet<String>();

		int count = 0;
		String currStr = "";
		for(int i = 1; i <= n - 2; i++){
			currStr += "0";
		}

		while (j > 0){
			String res = isJam("1" + currStr + "1");
			hs.add(currStr);
			if (res.length() != 0){
				System.out.println("1" + currStr + "1" + res);
				count++;
				System.err.println(count);
				j--;
			}
			
			while (hs.contains(currStr)){
				currStr = nextBinaryString(currStr);
			}
		}
	}

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        in.nextInt();
        int n = in.nextInt();
        int j = in.nextInt();
        System.out.println("Case #1:");
        produceJam(n,j);
    }
}