import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class q{
	int type;
	BigInteger number;
	public q(BigInteger n,int t){
		type=t;number=n;
	}
	public q copy(){
		return new q(number,type);
	}
}
public class B {
	public static void main(String ... args) throws Exception{
		
		Scanner in = new Scanner(new File("C-small-attempt1.in"));
		PrintStream out = new PrintStream(new File("C-small-attempt1.out"));
		//Scanner in = new Scanner(System.in);
		//PrintStream out = System.out;

		
		int T = in.nextInt();
		in.nextLine();
		
		for(int t=0;t<T;t++){

			int N = in.nextInt();
			int M = in.nextInt();
			
			Queue<q> qn = new LinkedList<q>();
			Queue<q> qm = new LinkedList<q>();
			for(int n=0;n<N;n++){
				qn.add(new q(in.nextBigInteger(),in.nextInt()));
			}
			for(int m=0;m<M;m++){
				qm.add(new q(in.nextBigInteger(),in.nextInt()));
			}
			
			BigInteger result = start(copyQueue(qn),copyQueue(qm));
			
			out.println("Case #" + (t+1) +": " + result);
			
		}
		
		
	}
	
	static BigInteger start(Queue<q> nq, Queue<q> mq){
		if(nq.size() == 0 || mq.size()==0) return new BigInteger("0");
		
		q n = nq.peek();
		q m=mq.peek();
		
		BigInteger count = new BigInteger("0");
		if(n.type == m.type){
			BigInteger min =n.number.min(m.number);
			n.number=n.number.subtract(min);
			m.number=m.number.subtract(min);
			count = count.add(min);
			
			if(m.number.compareTo(new BigInteger("0"))==0){
				mq.poll();
			}
			if(n.number.compareTo(new BigInteger("0"))==0){
				nq.poll();
			}
			count = count.add(start(nq,mq));
		}else{
			Queue<q> nq2=copyQueue(nq);
			Queue<q> mq2=copyQueue(mq);
			nq2.poll();mq2.poll();
			BigInteger cnt1 = start(copyQueue(nq),mq2);
			BigInteger cnt2 = start(nq2,copyQueue(mq));
			count = count.add(cnt1.max(cnt2));
			
		}
		
		
		return count;
	}
	
	static Queue<q> copyQueue(Queue<q> qu){
		q[] a = new q[qu.size()];
		qu.toArray(a);
		Queue<q> q2 = new LinkedList<q>();
		for(int i=0;i<a.length;i++) q2.add(a[i].copy());
		return q2;
	}
}
