import java.util.*;
import java.io.*;
import java.math.*;
public class C {
	
	public static void main(String[] args) throws IOException {
		
		boolean[] isprime = new boolean[100001];
		Arrays.fill(isprime, true);
		isprime[0] = false;
		isprime[1] = false;
		
		
		for(int i = 2; i*i < isprime.length; i++){
			if(isprime[i])
			for(int j = i*i; j < isprime.length; j+=i){
				isprime[j] = false;
			}
		}
		
		ArrayList<BigInteger> sprimes = new ArrayList<BigInteger>();
		
		for (int i = 0; i < isprime.length; i++) {
			if(isprime[i]) sprimes.add(new BigInteger(i+""));
		}
		
		
		
		Scanner qwe = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter("C.out");
				
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			
			out.println("Case #"+cse+": ");
			int N = qwe.nextInt();
			int J = qwe.nextInt();
			HashSet<String> hs = new HashSet<String>();
			while(J-->0){
				
				
				while(true){
					
					int[] jam = new int[N];
					jam[0] = 1;
					jam[jam.length-1] = 1;
					
					for (int i = 1; i < jam.length-1; i++) {
						jam[i] = (int)(Math.random()*2);
					}
					
					if(hs.contains(Arrays.toString(jam))) continue;
					hs.add(Arrays.toString(jam));
					
					
					int[] divs = new int[11];
					BigInteger[] nums = new BigInteger[11];
					
					boolean good = true;
					
					for(int base = 2; base <= 10; base++){
						BigInteger num = BigInteger.ZERO;
						BigInteger b = new BigInteger(base+"");
						
						for (int i = 0; i <jam.length; i++) {
							num = num.multiply(b);
							if(jam[i] == 1) num = num.add(BigInteger.ONE);
						}
						
						if(num.isProbablePrime(100)){
							good = false;
							break;
						}
						
						nums[base] = num;
						
					}
					
					if(!good) continue;
					
					for(int base = 10; base >= 2; base--){
						//System.out.println("base: " + base);
						BigInteger c = nums[base];
						boolean found = false;
						for(BigInteger cont : sprimes){
							if(c.compareTo(cont) != 0 && c.mod(cont).equals(BigInteger.ZERO)){
								found = true;
								divs[base] = cont.intValue();
								break;
							}
						}
						if(!found){
							good = false;
							break;
						}
						
					}
					
					if(!good) continue;
					else{
						StringBuilder jprint = new StringBuilder("");
						for (int i = 0; i < jam.length; i++) {
							jprint.append(jam[i]);
						}
						
						//System.out.println("j: " + jprint);
						
						out.print(jprint.toString());
						for (int i = 2; i < divs.length; i++) {
							out.print(" " + divs[i]);
						}
						out.println();
						break;
					}
					
				}
				
			}
			
			
			
			
		}
		
		
		out.close();
		qwe.close();
	}

}
