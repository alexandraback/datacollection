import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) throws IOException {
		
		
//		PrintWriter test = new PrintWriter("A.in");
//		int x = 1000000;
//		test.println(x+1);
//		for(int i =0; i <=x; i++)
//			test.println(i);
//		test.close();
		
		Scanner qwe = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter("A.out");
				
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			long n = qwe.nextInt();
			
			if(n == 0){
				out.println("Case #"+cse+": INSOMNIA");
				continue;
			}
			
			long mult = 1;
			boolean[] seen = new boolean[10];
			int count = 0;
			while(true){
				long next = n*mult;
								
				
				while(next > 0){
					int dig = (int)(next%10);
					if(!seen[dig]) count++;
					seen[dig] = true;
					next /= 10;
				}
				
				if(count == 10) break;
				
				mult++;
			}
			
			out.println("Case #"+cse+": " + (n*mult));
			
		}
		
		
		out.close();
		qwe.close();
	}

}
