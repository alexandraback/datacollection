import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Locale;
import java.util.regex.Pattern;

import com.google.common.collect.HashMultiset;
import com.google.common.math.BigIntegerMath;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).main();
	}
	
	public void main(){
		s=is;
		scanFile("A-large.in");	
		try {
			out=new PrintStream("out1AL.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
//		waitForInputSignal();
//		s.useDelimiter(Pattern.compile("\\D"));
		Locale.setDefault(Locale.US);
//		showln("This %s.","works");
		mainA();
	}
	
	
	public void mainA(){
//		HashMultiset<Integer> test=HashMultiset.create();
		int nr=s.nextInt();
		for (int i=0;i<nr;i++){
			BigInteger r=s.nextBigInteger();
			BigInteger t=s.nextBigInteger();
//			BigInteger br=new BigIn
			BigInteger zrm1=r.add(r).subtract(BigInteger.ONE);
			BigInteger vt=t.multiply(BigInteger.valueOf(8));
			BigInteger d=zrm1.multiply(zrm1).add(vt);
//			showln("%d %d %d",zrm1,vt,d);
			BigInteger M=BigIntegerMath.sqrt(d,RoundingMode.FLOOR).subtract(zrm1).divide(BigInteger.valueOf(4));
//			long M=(long) floor(Math.sqrt(r*r+t)-r);
			showln("Case #%d: %d",i+1,M);
		}
	}


}
