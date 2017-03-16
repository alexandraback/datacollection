import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

/*
6
1 4
10 120
100 1000
1 1
1 10000000000000000000000000000000000000000
1 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

*/
public class FairAndSquare {
	public FairAndSquare() throws Exception{
		System.setOut(new PrintStream(new File("C-large-1.out")));
		System.setIn(new FileInputStream(new File("C-large-1.in")));
		for(BigInteger i: choose){
			if(i.equals(BigInteger.ZERO))
				continue;
			if(isPal(i.multiply(i))) pos.put(i.multiply(i), 0);
			BigInteger doub = i.multiply(n10).add(i);
			if(isPal(doub.multiply(doub))) pos.put(doub.multiply(doub), 0);
			//perm(i, i, n10, 10, 4);
			perm(i, i, n10, 24, 4);
		}
		pos.put(BigInteger.valueOf(9), 0);
		pos.put(BigInteger.ZERO, 0);
		Entry<BigInteger, Integer> prev = null;
		for(Entry<BigInteger, Integer> i: pos.entrySet()){
			if(prev == null) prev = i;
			else{
				i.setValue(prev.getValue()+1);
				prev = i;
			}
		}
		
		//for(Entry<BigInteger, Integer> i: pos.entrySet())
		//	System.out.println(i.getKey() + ": " + i.getValue());
		
		
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			BigInteger A, B;
			A = new BigInteger(in.next());
			B = new BigInteger(in.next());
			int ans = 0;
			if(pos.containsKey(B))
				ans += pos.get(B);
			else ans += pos.lowerEntry(B).getValue();
			ans -= pos.lowerEntry(A).getValue();
			System.out.printf("Case #%d: %d\n", t, ans);
		}
		in.close();
	}
	BigInteger n100 = BigInteger.valueOf(100);
	BigInteger n10 = BigInteger.TEN;
	BigInteger[] choose = {BigInteger.ZERO, BigInteger.ONE, BigInteger.valueOf(2)};
	TreeMap<BigInteger, Integer> pos = new TreeMap<>();
	void perm(BigInteger left, BigInteger right, BigInteger p10, int i, int oneCt){
		if(i == 0) return;
		for(BigInteger x: choose){
			BigInteger single = left.multiply(p10).multiply(n10).add(x.multiply(p10)).add(right);
			//System.out.println(single);
			//if(isPal(single.multiply(single))) System.out.printf("%d: %d\n", single, single.multiply(single));
			//if(isPal(single.multiply(single))) System.out.printf("%d\n", single);
			if(isPal(single.multiply(single))) pos.put(single.multiply(single), 0);
			BigInteger doub = left.multiply(p10).multiply(n100).add(x.multiply(p10).multiply(n10)).add(x.multiply(p10)).add(right);
			//System.out.println(doub);
			//if(isPal(doub.multiply(doub))) System.out.printf("%d: %d\n", doub, doub.multiply(doub));
			//if(isPal(doub.multiply(doub))) System.out.printf("%d\n", doub);
			if(isPal(doub.multiply(doub))) pos.put(doub.multiply(doub), 0);
			if(oneCt == 0)
				continue;
			if(!x.equals(choose[2]))
				perm(left.multiply(n10).add(x), right.add(p10.multiply(x)), p10.multiply(n10), i-1, x.equals(choose[1]) ? oneCt-1 : oneCt);
		}
	}
	boolean isPal(BigInteger v){
		String n = v+"";
		for(int l = 0, r = n.length()-1; l<=r; l++, r--)
			if(n.charAt(l) != n.charAt(r))
				return false;
		return true;
	}
	public static void main(String[] args) throws Exception{
		new FairAndSquare();
	}
}
