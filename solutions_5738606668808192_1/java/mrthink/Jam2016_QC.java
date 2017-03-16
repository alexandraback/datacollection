import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Jam2016_QC {
	public int[] primes;
	
	public int[] getPrimeNumbers(int n) {
		List<Integer> ret = new ArrayList<Integer>();
		
		for(int i=2; i<n; ++i) {
			boolean check = false;
			for(int j: ret) {
				if(i%j == 0) {
					check = true;
					break;
				}
			}
			
			if(!check)
				ret.add(i);
		}
		
		int[] ret2 = new int[ret.size()];
		int idx = 0;
		for(int d: ret) {
			ret2[idx] = d;
			idx++;
		}
		
		return ret2;
	}
	
	public BigInteger convert(byte[] str, int d) {
		BigInteger idx = new BigInteger("0");
		for(byte b: str) {
			idx = idx.multiply(new BigInteger(Integer.toString(d))).add(new BigInteger(Integer.toString(b - '0')));
		}
		
		return idx;
	}
	
	public void solve(int n, int j) {
		System.out.println("Case #" + 1 + ":");
		
		//	make start int
		long val = (1<<(n-1)) - 1;
		for(int i=0; i<j;) {
			//	generate next int
			val += 2;
//			System.out.println(val);
			
			int count = 0;
			byte[] str = Long.toBinaryString(val).getBytes();
			int[] ret = new int[11];
			
			for(int k=2; k<=10; ++k) {
				BigInteger big = convert(str, k);
				
				for(int p: primes) {
					if(p > val)
						break;
					
					if(big.divideAndRemainder(BigInteger.valueOf(p))[1].intValue() == 0) {
						ret[k] = p;
						count++;
						break;
					}
				}
			}
			
			if(count < 9)
				continue;
			
			System.out.print(Long.toBinaryString(val));
			for(int k=2; k<=10; ++k)
				System.out.print(" " + ret[k]);
			System.out.println();
			
			i++;
		}
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);

		Jam2016_QC	inst	= new Jam2016_QC();
		
//		byte[] r = {'1', '0', '0', '1'};
//		for(int i=2; i<=10; ++i) {
//			System.out.println(inst.convert(r, i).toString());
//		}
		
//		String d = Integer.toBinaryString(7);
//		System.out.println(d);
//		System.out.println(inst.convert(d.getBytes(), 2));
		
		inst.primes = inst.getPrimeNumbers(20000);
//		for(int i: inst.primes) {
//			System.out.println(i);
//		}
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			int		n		= scanIn.nextInt();
			int		j		= scanIn.nextInt();
			
			inst.solve(n, j);
		}
		
		scanIn.close();
	}
}
