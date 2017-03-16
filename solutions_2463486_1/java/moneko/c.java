import java.util.*;

public class c {
	static ArrayList<Long> list;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		list = new ArrayList<Long>();

		for(long i = 1; i < 1e7+1; i++)
			if(isPalin(i) && isPalin(i*i))
				list.add(i*i);

		int T = in.nextInt();
		for(int t = 1; t <= T; t++) {
			long A = in.nextLong();
			long B = in.nextLong();

			int ans = 0;
			for(long i : list)
				if(i >= A && i <= B)
					ans++;
			System.out.printf("Case #%d: %d\n", t, ans);
		}
	}
	
	static boolean isPalin(long num) {
		String tmp = num + "";
		for(int i = 0; i <= tmp.length()/2; i++)
			if(tmp.charAt(i) != tmp.charAt(tmp.length()-i-1))
				return false;
		
		return true;
	}
}
