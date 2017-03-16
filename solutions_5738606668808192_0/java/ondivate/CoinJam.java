import java.util.*;

public class CoinJam {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int lim1=33333333;
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
			int N=16;
			int J=50;
			int tot=0;
			
			System.out.println("Case #"+cn+": "); 
			int cur=0;
			int lim=1<<(N-2);
			while(tot<J&&cur<lim){
				String S="1"+Long.toBinaryString(cur)+"1";
				if(S.length()!=N){
					cur++;
					continue;
				}
				boolean okay=true;
				long f[]=new long[11];
				for(int i=2;i<=10;i++){
					long nn=Long.valueOf(S, i);
					if(primes.contains(nn))
						okay=false;
					else{
						for(long div:primes){
							if(nn%div==0){
								f[i]=div;
								break;
							}
						}
						if(f[i]==0)
							okay=false;
					}
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
