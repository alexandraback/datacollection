import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class Main {
	public static int big = 0;
	public static int regain = 0;
	public static int energy = 0;
	public static int nowenergy = 0;
	static boolean isvalid(long a, long base){
		if(a > base)
			return false;
		long b = 1;
		while(b < a){
			b <<= 1;
		}
		return b == a;
	}
	public static void main(String[] args) throws FileNotFoundException{
		int num;
		PrintStream pso = null;
		FileInputStream psi = null;
		psi = new FileInputStream("D:\\Users\\Rophyll\\Downloads\\A\\A-small-attempt0 (2).in");
		pso = new PrintStream(new FileOutputStream("D:\\Users\\Rophyll\\Downloads\\A\\out1.out"));
		System.setIn(psi);
		System.setOut(pso);
		Scanner sc = new Scanner(System.in);
		
		num = sc.nextInt();
		for(int i = 0; i < num; i++){//each case
			long base = 1l << 40;
			
			long a, b, g;
			a = sc.nextLong();
			b = sc.nextLong();
			long A = a;
			long B = b;
			if(b > a){
				long t = 0;
				t = a;
				a = b;
				b = t;
			}
			while(b != 0){
				long t = a % b;
				a = b;
				b = t;
			}
			g = a;
			a = A/g;
			b = B/g;
			
			if(!isvalid(b, base)){
				System.out.println("Case #"+(i+1)+": impossible");
				continue;
			}
			a *= base/b;
			int result = 0;
			int j = 0;
			while(a != 0){
				if((a&1l) != 0){
					result = j;
				}
				j++;
				a >>= 1;
			}
			
			System.out.println("Case #"+(i+1)+": "+(40-result));
		}
	}
}