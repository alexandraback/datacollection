import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-large.out"));
		
		long cases = Long.parseLong(br.readLine());
		
		for(long i = 1; i<=cases; i++){
			System.out.println(i);
			bw.write("Case #"+i+": ");
			
			String[] frac = br.readLine().split("/");
			long numerator = Long.parseLong(frac[0]);
			long denominator = Long.parseLong(frac[1]);
			
			long gcd = gcd(numerator, denominator);
			numerator/=gcd;
			denominator/=gcd;
			
			if((denominator & (denominator - 1)) != 0) {
				bw.write("impossible\r\n");
				continue;
			}
			
			long level;
			
			for(level = 0; numerator<denominator;level++){
				System.out.println(numerator+"/"+denominator);
				numerator*=2;
			}
			
			bw.write(level+"\r\n");
		}
		
		bw.close();
		
	}
	
	static long gcd(long a, long b){
		while (b != 0){
	       long t = b;
	       b = a % b;
	       a = t;
		}
	    return a;
	}
}
