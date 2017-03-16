import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			long n=sc.nextLong();
			if (n<=10){
				System.out.println("Case #"+t+": "+n);
				continue;
			}
			long temp=10;
			long number=10;
			while(wei(number)<wei(n)){
				int oldWei=wei(number);
				int tempWei=oldWei/2;
				long newnumber=toLong(tempWei);
				while(wei(newnumber)<oldWei){
					newnumber=newnumber*10;
				}
				newnumber++;				
				number=number*10;
				temp+=toLong(tempWei);
				temp++;
				temp+=number-newnumber;
			}
			long ans=temp+(n-number);
			long reverse=getReverse(n);
			if (number!=n){
				for (int i=0;i<2;i++){
					long leftPart=n/myPow10((wei(n)/2));
					long rightPart=n%myPow10((wei(n)/2));
					if (rightPart!=0){
						long newnumber=number+getReverse(leftPart);
						newnumber=getReverse(newnumber);
						if (temp+getReverse(leftPart)+1+n-newnumber<ans){
							ans=temp+getReverse(leftPart)+1+n-newnumber;
						}
					}else{
						long newnumber=number+getReverse(leftPart-1);
						newnumber=getReverse(newnumber);
						if (temp+getReverse(leftPart-1)+1+n-newnumber<ans){
							ans=temp+getReverse(leftPart-1)+1+n-newnumber;
						}
					}
					temp++;
					if (wei(getReverse(n))==wei(n)){
						n=getReverse(n);					
					}else{
						break;
					}
				}	
			}
			System.out.println("Case #"+t+": "+ans);
		}
	}
	private static long myPow10(int x) {
		long ans=1;
		for (int i=1;i<=x;i++){
			ans=ans*10;
		}
		return ans;
		
	}
	private static long getReverse(long n) {
		String ans="";
		while(n>0){
			ans+=n%10;
			n=n/10;
		}
		return Long.parseLong(ans);
	}
	public static long toLong(int x){
		String ans="";
		for (int i=1;i<=x;i++){
			ans=ans+"9";
		}
		return Long.parseLong(ans);
	}
	public static int wei(long x){
		int ans=0;
		while(x>0){
			x=x/10;
			ans++;
		}
		return ans;
	}
}
