import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;


public class First {
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new First().go();
	}
	
	public void go() {
		
		try {
			Scanner sc = new Scanner(new FileReader("A-large.in"));
			
			int T = sc.nextInt();
			
			String[] ans = new String[T];
			sc.nextLine();
			for (int i =0 ; i < T; i++) {
				
				int count = 0;
				String[] str = sc.nextLine().split("/");
				long P = Long.parseLong(str[0]);
				long Q = Long.parseLong(str[1]);
				long R = GCF(Q, P);
				if(R != 1) {
					P = P/R;
					Q = Q/R;
				}
				if(!((Q & (Q - 1)) == 0)) {
					ans[i] = "impossible";
					continue;
				}
				double d = (double)P/Q;
				while(d < 1) {
					d = d * 2;
					count++;
				}
				ans[i] = ""+count;
			}
			
			output(ans);	
			
		}catch(IOException e) {}
		
		
	}
	
	public long GCF(long a, long b) {
	    if (b == 0) return a;
	    else return (GCF (b, a % b));
	}
	
	public int[] strToInt(String line) {
		String[] str = line.split(" ");
		int[] a = new int[str.length];
		for(int i = 0; i < str.length; i++) {
			a[i] = Integer.parseInt(str[i]);
		}
		return a;
	}
	
	public void output(String[] n) {
		for(int i = 0 ; i < n.length; i++) {
			System.out.println("Case #" + (i+1) + ": " + n[i]);
		}
	}

}
