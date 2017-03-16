package googleCodeJam2014r1c;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	static long P,Q;
	static double EPS=0.000000000000001;
	static B[] bs=new B[41];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		for(int i=1;i<bs.length;i++){
			bs[i] = new B(1,1L<<i);
		}
		int T=sc.nextInt(); 
		L:for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			String[] s = sc.next().split("/");
			P=Long.parseLong(s[0]);
			Q=Long.parseLong(s[1]);
			double val = (double)P/(double)Q;
			B b = new B(P,Q);
			long a = 1L << 40;
			long mid=0,left=0,right=0;
			right=a;
			int cnt=0;
			while(left<right-1){
				cnt++;
				mid=(left+right)/2;
				B d = new B(mid,a);
				if(b.compareTo(d)==0){
					for(int i=1;i<bs.length;i++){
						if(bs[i].compareTo(d)<=0){
							System.out.println(i);
							continue L;
						}
					}
					System.out.println(d.p+" "+d.q);

				}
				else if(b.compareTo(d)>0){
					left = mid;
				}
				else{
					right=mid;
				}
			}


			System.out.println("impossible");
		}
	}
	static long gcd(long a,long b){
		if(b==0){
			return a;
		}
		if(a<b){
			long tmp=a;
			a=b;
			b=tmp;
		}
		return gcd(b,a%b);
	}
	static class B implements Comparable<B>{
		long p,q;
		B(long _a,long _b){
			long gcd=gcd(_a,_b);
			p=_a/gcd;
			q=_b/gcd;
		}
		long gcd(long a,long b){
			if(b==0){
				return a;
			}
			if(a<b){
				long tmp=a;
				a=b;
				b=tmp;
			}
			return gcd(b,a%b);
		}
		@Override
		public int compareTo(B arg0) {
			BigInteger b1 = BigInteger.ONE;
			BigInteger b2 = BigInteger.ONE;
			b1 = b1.multiply(new BigInteger(String.valueOf(this.p)));
			b1 = b1.multiply(new BigInteger(String.valueOf(arg0.q)));
			b2 = b2.multiply(new BigInteger(String.valueOf(arg0.p)));
			b2 = b2.multiply(new BigInteger(String.valueOf(this.q)));
			return b1.compareTo(b2);
		}
	}
}