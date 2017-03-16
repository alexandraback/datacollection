import java.util.*;
import java.io.*;
//code by cl3488
public class culture {
	private static long[] tenToThe = new long[16];
	public static long getTo(int length){
		if(length == 1) return 0;
		if(length == 2) return 10;
		length--;
		long ans = getTo(length) + tenToThe[length/2] - 1;//1000...099...99
		ans++;//reverse
		ans += tenToThe[length - length/2] - 1;
		return ans;
	}
	public static void main(String[] args) throws IOException{
		
		tenToThe[0] = 1;
		for(int i=1;i<=15;i++){
			tenToThe[i] = tenToThe[i-1] * 10;
		}
		
//		System.out.println(getTo(4));
//		System.out.println(getTo(6));
//		System.out.println(tenToThe[14]);
		BufferedReader f = new BufferedReader(new FileReader("culture.in"));
		PrintWriter out = new PrintWriter(new FileWriter("culture.out"));
		int T = Integer.parseInt(f.readLine());
		for(int tc=1;tc<=T;tc++){
			out.print("Case #" + tc + ": ");
			String s = f.readLine(); long N = Long.parseLong(s);
			if(s.length() == 1){
				out.println(s);
				continue;
			}
//			if(tc==18) System.out.println(s);
			boolean done = false;
			for(int i=0;i<15;i++){
				if(N == tenToThe[i]){
					out.println(getTo(i+1));
					done = true;
//					System.out.println(tc);
				}
			}
			if(done){
				continue;
			}
			
			long ans = getTo(s.length());
			if(s.endsWith("0")){
				N--;
				s = Long.toString(N);
				ans++;
			}
			
//			if(tc==17) System.out.println(s);
			int mid = s.length() / 2;
			String firstHalf = s.substring(0, mid);
			String secondHalf = s.substring(mid);
			String realFirstHalf = "";
			for(int i=firstHalf.length()-1;i>=0;i--){
				realFirstHalf += firstHalf.substring(i, i+1);
			}
			long first = Long.parseLong(realFirstHalf);
			if(first != 1) ans ++;// then you need a reverse
			ans += first + Long.parseLong(secondHalf) - 1;
			
			out.println(ans);
		}
		out.close();
	}
}
