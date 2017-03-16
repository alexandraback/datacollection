import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Queue;
import java.util.regex.Pattern;

import com.google.common.collect.HashMultiset;
import com.google.common.math.BigIntegerMath;
import com.google.common.math.IntMath;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).main();
	}
	
	public void main(){
		s=is;
//		scanFile("test.in");
		scanFile("C-small-1-attempt0.in");	
		try {
			out=new PrintStream("out1C.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
//		waitForInputSignal();
//		s.useDelimiter(Pattern.compile("\\D"));
		Locale.setDefault(Locale.US);
//		showln("This %s.","works");
//		Thread.
		mainC();
//		showln("1\n10 10 10000");
//		for (int i=0;i<10000;i++){
//			show("%d ",i+1);
//		}
//		showln("");
	}
	
	public void mainC(){
		s.nextInt();
		int R=s.nextInt();
		int N=s.nextInt();
		int M=s.nextInt();
		int K=s.nextInt();
		List<Integer> val=new ArrayList<Integer>();
		showln("Case #1:");
		for (int i=0;i<R;i++){
			int kgv=1;
			val.clear();
			for (int j=0;j<K;j++){
				int v=s.nextInt();
				val.add(v);
				kgv=v*kgv/IntMath.gcd(v,kgv);
			}
			int c3=0;
			int c5=0;
			int c2=0;
			while(kgv%3==0){
				kgv=kgv/3;
				c3++;
			}
			while(kgv%5==0){
				kgv=kgv/5;
				c5++;
			}
			while(kgv%2==0){
				kgv=kgv/2;
				c2++;
			}
			int k=N-c3-c5;
			int c4=Math.max(0,c2-k);
			c2=c2-2*c4;
			int missing=N-c2-c4-c3-c5;
//			assert(c2+c4+c3+c5==N);
			for (int j=0;j<c2;j++){
				show("2");
			}
			for (int j=0;j<c3;j++){
				show("3");
			}
			for (int j=0;j<c4;j++){
				show("4");
			}
			for (int j=0;j<c5;j++){
				show("5");
			}
			for (int j=0;j<missing;j++){
				show("2");
			}
			showln("");
		}
	}
	
	public class para{
		long EStart, EEnd;
		int start, end;
		public para(long eStart, long eEnd, int start, int end) {
			EStart = eStart;
			EEnd = eEnd;
			this.start = start;
			this.end = end;
		}
		
		
	}
	
	long E,R;
	List<Long> val;
	Queue<para> queue;
	public void mainB(){
		int nr=s.nextInt();
		for (int i=0;i<nr;i++){
			E=s.nextLong();
			R=s.nextLong();
			int N=s.nextInt();
			val=new ArrayList<Long>();
			for (int j=0;j<N;j++){
				val.add(s.nextLong());
			}
			queue=new LinkedList<Main.para>();
			queue.add(new para(E, 0, 0, N));
			long res=0;
			while(queue.size()>0){
				res+=MaxUtily(queue.remove());
			}
			showln("Case #%d: %d",i+1,res);
		}
	}
	
	public long MaxUtily(para p){
		long EStart=p.EStart;
		long EEnd=p.EEnd;
		int start=p.start;
		int end=p.end;
		if (end-start==1){
			long Euse=Math.min(EStart,EStart+R-EEnd);
			return Euse*val.get(start);
		}
		int maxId=start;
		long maxVal=0;
		for (int i=start;i<end;i++){
			if (val.get(i)>maxVal){
				maxVal=val.get(i);
				maxId=i;
			}
		}
		long Epos=Math.min(E,EStart+(maxId-start)*R);
		long Euseable=Epos-Math.max(EEnd-(end-maxId)*R,0);
		long before=0;
		if (start<maxId){
			queue.add(new para(EStart,Epos,start,maxId));
//			before=MaxUtily(EStart,Epos,start,maxId);
		}
		long after=0;
		if (maxId+1<end){
			queue.add(new para(Math.min(Epos-Euseable+R,E), EEnd, maxId+1, end));
//			after=MaxUtily(Math.min(Epos-Euseable+R,E), EEnd, maxId+1, end);
		}
		return Euseable*maxVal;
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
