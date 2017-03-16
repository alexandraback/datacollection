import java.util.*;
import java.lang.*;

public class coinJam
{
	//Integer.parseLong(str, base)

	static long isPrime(long n){
		if (n == 2 || n == 3)
			return -1;
		else if (n % 2 == 0)
			return 2;
		else if (n % 3 == 0)
			return 3;
		else {
			long i = 5;
			long w = 2;

			while((i*i) <= n){
				if ((n % i) == 0)
					return i;
				i += w;
				w = 6 - w;
			}
			return -1;
		}
	}

	static String isJam(String s){
		String ret = "";
		if (s.charAt(0) == '0' || s.charAt(s.length() - 1) == '0'){
			return "";
		}

		for (int i = 2; i <= 10; i++){
			int primality = (int)isPrime(Long.parseLong(s, i));
			if (primality == -1){
				return "";
			}
			ret = ret + " " + Integer.toString(primality);
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
	static void produceJam(int n, int j){
		String currStr = "";
		for(int i = 1; i <= n - 2; i++){
			currStr += "0";
		}

		while (j > 0){
			String res = isJam("1" + currStr + "1");
			if (res.length() != 0){
				System.out.println("1" + currStr + "1" + res);
				j--;
			}
			currStr = nextBinaryString(currStr);
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