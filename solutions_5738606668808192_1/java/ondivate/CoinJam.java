import java.math.BigInteger;
import java.util.*;

public class CoinJam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int lim1=1000;
		TreeSet<Long> primes=new TreeSet<Long>();
		boolean isPrime[]=new boolean[lim1];
		Arrays.fill(isPrime, true);
		isPrime[0]=false;
		isPrime[1]=false;
		for(int i=2;i<lim1;i++){
			if(isPrime[i]){
				primes.add((long) i);
				int j=i+i;
				while(j<lim1){
					if(isPrime[j])
						isPrime[j]=false;
					j+=i;
				}
			}
		}
		
		Scanner sc=new Scanner(System.in);
//		int T=sc.nextInt();
		int T=1;
		for(int cn=1; cn<=T;cn++){
//			int N=sc.nextInt();
//			int J=sc.nextInt();
			int N=32;
			int J=500;
			int tot=0;
			
			System.out.println("Case #"+cn+": "); 
			long cur=0;
			while(tot<J){
				String S=Long.toBinaryString(cur);
				while(S.length()+2<N)
					S="0"+S;
				S="1"+S+"1";
				boolean okay=true;
				long f[]=new long[11];
				for(int i=2;i<=10;i++){
					BigInteger bi=new BigInteger(S, i);
					for(long div:primes){
						if(bi.mod(BigInteger.valueOf(div)).equals(BigInteger.ZERO)){
							f[i]=div;
							break;
						}
					}
					if(f[i]==0)
						okay=false;
				}
				if(okay){
					tot++;
					System.out.print(S);
					for(int i=2;i<=10;i++){
						System.out.print(" "+f[i]);
					}
					System.out.println();
				}
				cur++;
			}
			
		}
	}

}
