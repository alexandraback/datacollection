import java.util.Scanner;


public class Omino_Small {
	
	public static void main(String[] args) {
		Scanner read= new Scanner(System.in);
		int T,D,max=0,j,A=0,Min=0;
		int[] P = new int [1200];
		T=read.nextInt();
		for(int b=0;b<T;b++){
			D=read.nextInt();			
			
			for(j=0;j<D;j++){
				P[j]=read.nextInt();
				max=Math.max(max, P[j]);
			}
				
			
	
			 Min=max;
			for(j=1;j<=max;j++){
				A=j;
				for(int l=0;l<D;l++){
					if(P[l]>j){
						if(P[l]%j==0) A+=P[l]/j-1;
						else A+=P[l]/j;
					}		
				}
				Min=Math.min(Min, A);
			}
			int x=b+1;
			System.out.println("Case #"+x+": "+Min);
			}
		}		
	}

	


