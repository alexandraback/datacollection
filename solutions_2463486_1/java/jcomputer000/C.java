import java.util.*;
import java.math.BigInteger;
public class C {
	String upper, lower;
	BigInteger sqrt(BigInteger val) {
		BigInteger min = BigInteger.ZERO;
		BigInteger max = BigInteger.TEN.pow(50);
		while(max.subtract(min).abs().compareTo(BigInteger.ONE) > 0) {
			BigInteger mid = max.add(min).shiftRight(1);
			int cmp = mid.multiply(mid).compareTo(val);
			if (cmp < 0)
				min = mid;
			else if (cmp > 0)
				max = mid.subtract(BigInteger.ONE);
			else
				return mid;
		}
		while(min.multiply(min).compareTo(val) > 0)
			min = min.subtract(BigInteger.ONE);
		for (BigInteger i = min;; i = i.add(BigInteger.ONE))
			if (i.multiply(i).compareTo(val) > 0)
				return i.subtract(BigInteger.ONE);
	}
	int bnd(int cur, int digit, int val) {
		if (cur != 1)
			return cur;
		if (digit > val)
			return 2;
		else if (digit < val)
			return 0;
		return 1;
	}
	long[][][][][] memo;
	long dp(int pos, int onesUsed, int twosUsed, int uloose, boolean lover, String test) {
		if (memo[pos][onesUsed][twosUsed][uloose][lover?1:0] != -1)
			return memo[pos][onesUsed][twosUsed][uloose][lover?1:0];
		long ret = 0;
		if (pos == lower.length()) {
			if (upper.length() != lower.length()) {
				ret++;
				int udigit = upper.charAt(pos)-'0';
				if (uloose==2) {
					//System.out.println(test + rev(test) + " " + ret);
					return ret;
				} else if (uloose==0)
					udigit = 2;
				boolean[] valid = new boolean[3];
				valid[0] = true;
				valid[1] = (twosUsed==0 && onesUsed<=4) || (twosUsed==1 && onesUsed==0);
				valid[2] = onesUsed<=2 && twosUsed==0;
				if (lover && uloose>=1)
					udigit--;
				for (int i=0; i<=udigit && i<3; i++)
					if (valid[i])
						ret++;
				//System.out.println(test + "_" + rev(test) + " " + ret + " .. " + Arrays.toString(valid) + " " + udigit);
			} else {
				ret = (lover && uloose>=1) || uloose==2 ? 0 : 1;
				//System.out.println(test + rev(test) + " " + ret);
			}
			return memo[pos][onesUsed][twosUsed][uloose][lover?1:0] = ret;
		}
		int udigit = upper.charAt(pos)-'0';
		int ldigit = lower.charAt(pos)-'0';
		ret += 2 + ((twosUsed==0 && onesUsed<=4) || (twosUsed==1 && onesUsed==0) ? 1 : 0) + (twosUsed==0 && onesUsed<=2 ? 1 : 0);
		//System.out.println(test + "?" + rev(test) + " " + ret);
		if (onesUsed+twosUsed>0)
			ret += dp(pos+1,onesUsed,twosUsed,bnd(uloose,0,udigit),lover,test+"0");
		if ((twosUsed==0 && onesUsed < 4))
			ret += dp(pos+1,onesUsed+1,twosUsed,bnd(uloose,1,udigit),lover||ldigit<1,test+"1");
		if (twosUsed < 1 && onesUsed == 0)
			ret += dp(pos+1,onesUsed,twosUsed+1,bnd(uloose,2,udigit),lover||ldigit<2,test+"2");
		return memo[pos][onesUsed][twosUsed][uloose][lover?1:0] = ret;
	}
	String rev(String s) {
		return new StringBuilder(s).reverse().toString();
	}
	long dp(BigInteger number) {
		number = sqrt(number);
		String num = number.toString();
		long ret = 0;
		if (num.length() == 1) {
			if (number.longValue() == 0)
				return 1;
			else if (number.longValue() == 1)
				return 2;
			else if (number.longValue() == 2)
				return 3;
			else
				return 4;
		}
		//System.out.println("sqrt = " + number.longValue());
		upper = num.substring(0,(num.length()+1)/2);
		lower = rev(num.substring((num.length()+1)/2));
		memo = new long[upper.length()+1][9][4][3][2];
		for (long[][][][] D: memo)
			for (long[][][] A: D)
				for (long[][] B: A)
					for (long[] C: B)
						Arrays.fill(C,-1);

		//System.out.println(upper + ".." + lower);
		//System.out.println(dp(0,0,0,1,false,""));
		return dp(0,0,0,1,false,"");
	}
	C(Scanner in) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			BigInteger A = in.nextBigInteger();
			BigInteger B = in.nextBigInteger();
			System.out.printf("Case #%d: %d\n",t+1,dp(B)-dp(A.subtract(BigInteger.ONE)));
		}
	}
	public static void main(String[] args) {
		new C(new Scanner(System.in));
	}
}
