import java.util.Scanner;


public class Pr3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		int L, j;
		long X, piU, temp, pointer1, pointer2;
		long[] U;
		String input;
		c: for(int t=1; t<=T; t++){
			L = s.nextInt();
			X = s.nextLong();
			input = s.next();
			U = new long[L];
			piU = 1;
			for(int i=0; i<L; i++){
				if(input.charAt(i)=='i') U[i]=2;
				if(input.charAt(i)=='j') U[i]=3;
				if(input.charAt(i)=='k') U[i]=4;
				piU = Mult(piU, U[i]);
			}
			
			if(piU==1 || (piU==-1 && X%2==0) || (piU*piU!=1 && X%4!=2)) {
				System.out.println("Case #"+t+": NO");
				continue c;
			}
			
			pointer1=-1;
			pointer2=-1;
			temp = 1;
			for(int i=0; i<4*L; i++){
				j = i%L;
				temp = Mult(temp, U[j]);
				if(temp == 2){
					pointer1 = i+1;
					break;
				}
			}
			if(pointer1 == -1){
				System.out.println("Case #"+t+": NO");
				continue c;
			}
			temp = 1;
			for(int i=1; i<4*L; i++){
				j = (4*L-i)%L;
				temp = Mult(U[j], temp);
				if(temp == 4){
					pointer2 = i;
					break;
				}
			}
			if(pointer2 == -1){
				System.out.println("Case #"+t+": NO");
				continue c;
			}
			
			X = X - pointer1/L - pointer2/L;
			if(X<=0){
				System.out.println("Case #"+t+": NO");
				continue c;
			}
			if(X==1){
				temp = 1;
				for(int i=(int) (pointer1%L); i<(L-(pointer2%L)); i++){
					temp = Mult(temp, U[i]);
				}
				if(temp == 3){
					System.out.println("Case #"+t+": YES");
					continue c;
				}
				else{
					System.out.println("Case #"+t+": NO");
					continue c;
				}
			}
			if(X>1){
				temp = 1;
				for(int i= (int) (pointer1%L); i<L; i++){
					temp = Mult(temp, U[i]);
				}
				temp = Mult(temp, Pow(piU, X-2));
				for(int i=0; i<L-(pointer2%L); i++){
					temp = Mult(temp, U[i]);
				}
				if(temp == 3){
					System.out.println("Case #"+t+": YES");
					continue c;
				}
				else{
					System.out.println("Case #"+t+": NO");
					continue c;
				}
			}
		}
	}
	
	public static int Mult(long a, long b){
		int c = 1;
		if(a<0){
			a*=-1;
			c*=-1;
		}
		if(b<0){
			b*=-1;
			c*=-1;
		}
		if(a==1 || b==1) c*=a*b;
		else{
			if(a==b) c*=-1;
			else {
				if(a==2	&& b==3) c*=4;
				if(a==2  && b==4) c*=-3;
				if(a==3  && b==2) c*=-4;
				if(a==3  && b==4) c*=2;
				if(a==4  && b==2) c*=3;
				if(a==4  && b==3) c*=-2;
			}
		}
		return c;
	}
	
	public static int Pow(long a, long b){
		int c = 1;
		b = b%4;
		for(int i=0; i<b; i++){
			c = Mult(c, a);
		}
		return c;
	}

}
