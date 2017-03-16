import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
	
	public static void main(String[] args){
		new C().run();
	}
	
	int n;
	BigInteger[] ma = new BigInteger[]{
		new BigInteger("2"),
		new BigInteger("3"),
		new BigInteger("5"),
		new BigInteger("7"),
		new BigInteger("11")
	};
	
	void run(){
		Scanner sc = new Scanner(System.in);
		
		int testNum = sc.nextInt();
		for(int t=1;t<=testNum;t++){
			int n = sc.nextInt();
			int j = sc.nextInt();
			String ans = fnc(n, j);
			System.out.print("Case #" + t + ":\n" + ans);
		}
	}
	
	String fnc(int n, int j){
		int cnt = 0;
		StringBuilder sb = new StringBuilder();
		long i = 0;
		while(true){
			String b = Long.toBinaryString(i);
			for(int k=b.length();k<n-2;k++){
				b = "0" + b;
			}
			b = "1" + b + "1";

			boolean f = true;
			for(int k=2;k<=10;k++){
				BigInteger bi = parse(b, k);
				boolean ff = false;
				for(BigInteger m : ma){
					BigInteger mod = bi.mod(m);
					if(mod.toString().equals("0")){
						ff = true;
						break;
					}
				}
				if(!ff){
					f = false;
					break;
				}
			}
			if(f){
				sb.append(b);
				sb.append(" ");
				for(int k=2;k<=10;k++){
					BigInteger bi = parse(b, k);
					for(BigInteger m : ma){
						BigInteger mod = bi.mod(m);
						if(mod.toString().equals("0")){
							sb.append(m.toString());
							break;
						}
					}
					if(k==10){
						sb.append("\n");
					}else{
						sb.append(" ");
					}
				}
				cnt++;	
			}
			if(cnt==j){
				break;
			}
			i++;
		}
		
		return sb.toString();
	}
	
	
	BigInteger parse(String b, int r){
		BigInteger bi = BigInteger.ZERO;
		
		for(int i=0;i<b.length();i++){
			if(b.charAt(b.length()-1-i)=='1'){
				BigInteger m1 = new BigInteger(Integer.toString(r));
				BigInteger m2 = m1.pow(i);
				bi = bi.add(m2);
			}
		}
		return bi;
	}
	
}
