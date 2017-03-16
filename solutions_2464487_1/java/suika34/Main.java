import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			
			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] a = line.split(" ");
				long r = Long.parseLong(a[0]);
				long t = Long.parseLong(a[1]);
				long sol = solve(r, t);
				System.out.println("Case #"+i+": "+sol);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static long solve(long r, long t) {
		long max = t;
		long min = 0;
		
		while (max != min) {
			boolean last = false;
			//System.out.println(max + " "+ min);
			long mid = (max + min) / 2;
			if (max == min +1) {
				last = true;
				mid = max;
			}
			//System.out.println(mid);
			double a = Math.log(mid+1);
			double b = Math.log(2*r + 2*mid + 1);
			//long p = 2*r*(mid+1) + 2*mid*(mid+1) + mid+1;
//			p = (mid+1) * (2*r + 2*mid + 1);
//			if (p < 0) {
//				return -1;
//			}
			//System.out.println(p);
			if (a + b <= Math.log(t)) {
				min = mid;
				//System.out.println("OK");
			} else {
				max = mid;
				//System.out.println("NG");
			}
			//System.out.println(max + " "+ min);
			if (last) {
				return min+1;
			}
		}
		
		return min+1;
	}

}
