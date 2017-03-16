import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
public class RecycledNumbers {
	
	public static void main(String[] args) throws IOException {
		File file = new File("c:\\java\\results.txt");
		file.createNewFile();
		PrintStream out = new PrintStream(file);
		Scanner scanIn = new Scanner(System.in);
		int T = 0;
		int a = 0;
		int b = 0;
		int n = 0;
		int digits = 0;
		HashSet<Pair> set = new HashSet<Pair>();//store results
		T=scanIn.nextInt();
		
		for(int i = 0; i < T; i++){
			a = scanIn.nextInt();
			b = scanIn.nextInt();
			digits = numDigits(a);
			n = a;
			if(a>b){
				//Zero
				out.println("Case #"+(i+1)+": 0");
				continue;
			}
			if(digits == 1){
				//Zero
				out.println("Case #"+(i+1)+": 0");
				continue;
			}
			
			while(n < b){
				int divisor = 10;
				int multiply = (int)Math.pow(10, (digits-1));
				int remain = 0;
				int part = 0;
				int temp = 0;
				for(int j = 0; j < digits-1; j++, divisor*=10, multiply/=10){
					remain = n%divisor;
					part = n/divisor;
					
					temp = (remain*multiply)+part;
					if(temp <= b && temp > n){
						set.add(new Pair(n, temp));
					}
					
					
				}
				
				n++;
			}
			
			out.println("Case #"+(i+1)+": "+set.size());
			
			set.clear();
		}//End of main loop
		
		out.close();
	}
	
	public static int numDigits(int number){
		int divisor = 10;
		int digits = 1;
		while(true){
			if(number%divisor == number){
				return digits;
			}
			else{
				digits++;
				divisor*=10;
			}
		}
	}

}

class Pair{
	int n;
	int m;
	
	public Pair(){
		n = 0;
		m = 0;
	}
	
	public Pair(int n, int m){
		this.n = n;
		this.m = m;
	}
	
	public void printPair(){
		System.out.printf("n: "+n);
		System.out.printf(" m: "+m+"\n");
	}
	
	public boolean equals(Object arg){
		if(this==arg)return true;
        if(arg==null)return false;
        if(arg instanceof Pair){
        	Pair other = (Pair)arg;
            if(this.n == other.n && this.m == other.m){
            	return true;
            }
            else return false;
        }
        return false;
	}
	
	public int hashCode(){
	      int code = 3;
	      code = (code >> 2) + n;
	      code = (code << 2) + m;

	      return code;
	    }
}
