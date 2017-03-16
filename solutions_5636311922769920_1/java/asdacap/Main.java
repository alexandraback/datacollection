import java.util.*;
import java.math.*;
import java.security.*;
import java.util.concurrent.*;

public class Main{
	static Scanner in = new Scanner(System.in);

	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE  = new BigInteger("1");
	private final static BigInteger TWO  = new BigInteger("2");

	void run(){
		BigInteger K = in.nextBigInteger(),C = in.nextBigInteger(),S = in.nextBigInteger();

		BigInteger can = C.multiply(S);
		if(can.compareTo(K) < 0){
			System.out.print(" IMPOSSIBLE");
			return;
		}


		BigInteger lcount = ONE;
		for(int i=1;i<C.longValue();i++) lcount = lcount.multiply(K);

		TreeSet<BigInteger> checkings = new TreeSet<BigInteger>();

		BigInteger clcount = lcount;
		BigInteger base_place = ZERO;
		BigInteger cplace = base_place;
		for(int i=1;i<=K.longValue();i++){
			BigInteger ib = BigInteger.valueOf(i);
			cplace = cplace.add(clcount.multiply(ib.subtract(ONE)));
			//cerr << "CLCOUNT " << clcount << endl;
			////cerr << "CPLACE " << cplace << endl;
			if(clcount.compareTo(ONE) == 0){
				checkings.add(cplace.add(ONE));
				clcount = lcount;
				cplace = base_place;
			}else{
				clcount = clcount.divide(K);
			}
		}

		if(checkings.size() < S.longValue()){
			checkings.add(cplace.add(ONE));
		}

		boolean first = false;
		for(BigInteger d: checkings){
			if(!first){
				System.out.print(" ");
			}
			System.out.print(d.toString());
		}

	}

	public static void main(String[] args){
		int t = in.nextInt();
		for(int i=0;i<t;i++){
			System.out.print("Case #"+(i+1)+":");
			new Main().run();
			System.out.println();
		}
	}

}
