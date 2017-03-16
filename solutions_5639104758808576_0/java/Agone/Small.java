import java.util.Scanner;


public class Ovation {

	public static void main(String[] args) {
		Scanner read= new Scanner(System.in);
		
		int T,Smax;
		String N;
		T=read.nextInt();
		for(int i=0;i<T;i++){
			Smax=read.nextInt();
			N=read.next();
			int inv=0,P=0;
			char[] R=N.toCharArray();
			
			
			for(int j=0;j<R.length;j++){
				N="0";
				
				if(R[j]=='0'){
					if(P<j+1){
						 int inv1 = j+1-P;
						 P+=inv1;
						 inv+=inv1;
					}
				}
				
				N+=R[j] ;
				
			P+=Integer.parseInt(N);
			}
			int x=i+1;
			System.out.println("Case #"+x+": "+inv);
			
		}
	}

}
