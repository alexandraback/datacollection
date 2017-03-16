import java.util.Scanner;


public class Surp {

	/**
	 * @param args
	 */
	public static void main(String[] args) { 
		int T,S,p,N=0;
		String L="";
		Scanner b = new Scanner(System.in);
		T=b.nextInt();
		L=b.nextLine();
		for(int i=0;i<T;i++){
			L=b.nextLine();
			String F[]=L.split(" ");
			N=0;
			S=Integer.parseInt(F[1]);
			p=Integer.parseInt(F[2]);
			int min=p+2*(p-2);
			if(min<=1){
				min=p;
			}
			for(int j=3;j<F.length;j++){
					int val=Integer.parseInt(F[j]);
					if(min<=val){
						if(min+1<val||min==0)
							N++;
						else
							if(S>0){
								S--;
								N++;
							}
						}
				}
			System.out.println("Case #"+(i+1)+": "+N);
			}
		}
	

}
