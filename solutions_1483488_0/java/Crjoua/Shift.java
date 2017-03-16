import java.util.Scanner;


public class Shift {
	public static void main(String[] args) {
		int a,b,c,d=10,e=0,x,T,j;
		int inf,sup,res=0;
		Scanner l = new Scanner(System.in);
		T=l.nextInt();
		for(j=0;j<T;j++){
			inf=l.nextInt();
			sup=l.nextInt();	
			res=0;
			for(int k=inf;k<=sup;k++){
				x=k;
				int vixi=k;
				c=0;
				e=0;
				while(vixi>0){
					vixi=vixi/10;
					e++;		
				}
				for(int i=0;i<e&&c!=k;i++){
					a=x%d;
					b=x/d;
					c= (a*(int)Math.pow(10, e-1)+b);
					if((c>k)&&(c<=sup)&&(c>=inf))
						res++;
					//System.out.println(c);
					x=c;
				}
			}
			System.out.println("Case #"+(j+1)+": "+res);
		}
	
	}
}
