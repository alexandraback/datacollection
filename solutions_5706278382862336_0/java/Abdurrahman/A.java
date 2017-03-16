import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-small.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int i = 1; i<=cases; i++){
			bw.write("Case #"+i+": ");
			
			String[] frac = br.readLine().split("/");
			int numerator = Integer.parseInt(frac[0]);
			int denominator = Integer.parseInt(frac[1]);
			
			int gcd = gcd(numerator, denominator);
			numerator/=gcd;
			denominator/=gcd;
			
			if((denominator & (denominator - 1)) != 0) {
				bw.write("impossible\r\n");
				continue;
			}
			
			int level;
			
			for(level = 0; numerator<denominator;level++){
				numerator*=2;
			}
			
			bw.write(level+"\r\n");
		}
		
		bw.close();
		
	}
	
	static int gcd(int a, int b){
		while(a!=b){
			if(a>b) a = a-b;
			else b = b-a;
		}
		return a;
	}
}
