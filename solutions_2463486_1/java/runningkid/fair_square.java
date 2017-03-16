import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class fair_square{
	
	BigInteger A,B;
	
	BufferedReader br;
	PrintWriter out;
	 
	Boolean fair(BigInteger a){
		String str = a.toString();
		int len = str.length();
		int hlen = len/2;
		for(int i = 0; i < hlen; i++){
			if(str.charAt(i) != str.charAt(len-i-1)){
				return false;
			}
		}
		return true;
	}
	
	BigInteger increase(BigInteger m){
		String str = m.toString();
		int len = str.length();
		char a[] = str.toCharArray();
		int l = len/2 + len%2;
		for(int i = l-1; i >= 0; i--){
			if(a[i] < '9'){
				a[i] ++;
				if(l != len - i) a[len - i - 1]++;
				str = new String(a);
				return new BigInteger(str);
			}
			else{
				a[i] = '0';
				a[len - i - 1] = '0';
			}
		}
		a[len-1] = '1';
		str = "1" + new String(a);
		return new BigInteger(str);
	}
	
	void input() throws IOException{
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		Scanner sc = new Scanner(br);
		
		int case_n = sc.nextInt();
		for(int i_case = 1; i_case <= case_n; i_case++){
			A = sc.nextBigInteger();
			B = sc.nextBigInteger();
			BigInteger ans = BigInteger.valueOf(0);
			int len_a = A.toString().length()-1;
			int h_len_a = len_a/2;
			String str="1";
			for(int i = 0; i < h_len_a - 2; i++)
				str.concat("0");
			if(h_len_a >= 2) str.concat("1");
			
			BigInteger num = new BigInteger(str);
			while(num.multiply(num).compareTo(A) < 0)
				num = increase(num);
			BigInteger mul = num.multiply(num);
			while(mul.compareTo(B) <= 0){
				if(fair(mul)) ans = ans.add(BigInteger.valueOf(1));
				num = increase(num);
				mul = num.multiply(num);
			}
		
			out.println("Case #" + i_case + ": "+ ans);
		}
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new fair_square().input();
	}

}