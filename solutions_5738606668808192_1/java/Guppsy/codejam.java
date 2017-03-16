import java.io.*;
import java.util.*;
import java.math.*;

public class codejam{
	
	static String i0 = "dummy.in";
	static String o0 = "dummy.out";
	
	static String i1 = "small.in";
	static String o1 = "small.out";
	
	static String i2 = "large.in";
	static String o2 = "large.out";
	
	public static void main(String[] args) throws Exception{
		
		Scanner r = null;
		BufferedWriter w = null;
		
		r = new Scanner(new FileReader(i0));
		w = new BufferedWriter(new FileWriter(new File(o0)));

		
		int t = r.nextInt();
		for (int i=0;i<t;i++){
			System.out.println("Case #"+(i+1)+"--------------");
			
			long result = 0;
			
			w.write("Case #"+(i+1)+": ");
			int cntr = 4;
			int[] primes = new int[100000];
			primes[0] = 2;
			primes[1] = 3;
			primes[2] = 5;
			primes[3] = 7;
			boolean b = true;
			for (int j=8;j<100000;j++){
				int sqrt = (int)(Math.sqrt(j)) + 1;
				b = true;
				for (int k=0;k < cntr && primes[k] < sqrt;k++){
					if (j%primes[k]==0){
						b = false;
						break;
					}
				}
				if (b){
					primes[cntr] = j;
					cntr++;
					System.out.println(j);
				}				
			}
			
			int n = r.nextInt();
			int c = r.nextInt();
			//long _n;
			BigInteger _n;
			int[] div = new int[10];
			boolean found = false;
			boolean ext = false;
			int counter = 0;
			for (int j=0;j<Math.pow(2, n-2);j++){
				String _s = Integer.toString(j,2);
				// System.out.println(n-2-_s.length());
				for (int k=0;_s.length()<n-2;k++){
					_s = "0"+_s;
				}
				String s = "1"+_s+"1";
				//System.out.println(j+" "+_s+" "+s);
				ext = false;
				for (int k = 2;k<11;k++){
					//_n = Long.parseLong(s, k);
					_n = new BigInteger(s, k);
					//System.out.println(k+" "+_n);
					found = false;
					for (int l = 0;l<cntr;l++){
						//if (_n%primes[l]==0 && _n!=primes[l]) {
						BigInteger _b = new BigInteger(Integer.toString(primes[l], 2), 2);
						if (_n.mod(_b).equals(BigInteger.ZERO) && !_n.equals(_b)) {
							div[k-2] = primes[l];
							found = true;
							break;
						}
					}
					if (!found){
						ext = true;
						break;
					}
				}
				
				if (ext)
					continue;
				else{
					w.write("\n");
					w.write(s);
					for (int k=2;k<11;k++)
						w.write(" "+div[k-2]);
					counter++;
				}
				if (counter == c)
					break;
			}
			//w.write(String.valueOf(tmp));
			w.write("\n");
		}
		w.close();
	}
}


