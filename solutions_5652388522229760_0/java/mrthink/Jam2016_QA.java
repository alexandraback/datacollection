import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Jam2016_QA {
	public int solve(int n) {
		Set<Byte> set = new HashSet<Byte>();
		
		for(int i=0; i<100; ++i){
			int num = n*(i+1);
			String str = Integer.toString(num);
			
			byte[] bbb = str.getBytes();
			for(byte c : bbb){
				set.add(c);
			}
			
			if(set.size() >= 10)
				return num;
		}
		
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2016_QA	inst	= new Jam2016_QA();
			int		n		= scanIn.nextInt();
			
			int ret = inst.solve(n);
			
			if(ret < 0) {
				System.out.println("Case #" + (i+1) + ": " + "INSOMNIA");
			} else {
				System.out.println("Case #" + (i+1) + ": " + ret);
			}
		}
		
		scanIn.close();
	}
}
