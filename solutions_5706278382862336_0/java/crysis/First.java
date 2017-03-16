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
			Scanner sc = new Scanner(new FileReader("A-small-attempt1.in"));
			
			int T = sc.nextInt();
			
			String[] ans = new String[T];
			sc.nextLine();
			for (int i =0 ; i < T; i++) {
				
				int count = 0;
				String[] str = sc.nextLine().split("/");
				int P = Integer.parseInt(str[0]);
				int Q = Integer.parseInt(str[1]);
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
