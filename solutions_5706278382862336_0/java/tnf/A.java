import java.util.*;

class A{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kases = sc.nextInt();
		sc.nextLine();
		for(int k = 1; k<=kases; k++){
			String[] s = sc.nextLine().split("/");
			long num = Long.parseLong(s[0]);
			long den = Long.parseLong(s[1]);
			long div = gcd(num,den);
			num = num/div;
			den = den/div;
			String ans = "";
			long test = den;
			while(test%2 ==0){
				test = test/2;
			}
			long near = 1;
			long pow = 1;
			while(2*num < den){
				num*=2;
				near++;
			}
			if(test!=1) ans = " impossible";
			else ans = " "+near;
			System.out.println("Case #"+k+":"+ans);
		}
	}


	public static long gcd(long a, long b){ return (b==0?a: gcd(b, a%b));}

}
