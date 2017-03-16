import java.util.Scanner;


public class Pr1B1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		//System.out.println(obrat(6));
		int T = s.nextInt();
		long n;
		long min, pom, suc;
		for(int t=1; t<=T; t++){
			n=s.nextLong();
			min = 1;
			suc = n;
			pom = 1;
			while(true){
				if(suc == 1){
					break;
				}
				if(obrat(suc)<suc && (suc%10)!=0){
					suc = obrat(suc);
					min++;
				}
				else{
					suc--;
					min++;
				}
				//System.out.println(suc);
			}
			System.out.println("Case #"+t+": "+min);
		}
	}




	public static long obrat (long a){
		long b = 0;
		int i;
		for(i=14; i>=0; i--){
			if(a >=  moc(10, i)){
				//System.out.println(i);
				break;
			}
		}
		i++;
		
		for(int j=1; j<=i; j++){
			b += moc(10,i-j) * (a%(moc(10,j))/moc(10,(j-1)));
			a = a - a%moc(10,j);
		}
		return b;
	}
	
	public static long moc (int a, int b){
		long r = 1;
		for(int i=0; i<b; i++)
			r = r*a;
		return r;
	}
}