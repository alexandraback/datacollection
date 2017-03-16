import java.util.*;

public class C{

	static String arr[];
	static String dp[][];
	static boolean e[][];

	static String f(int index, int bit){
		if(((1<<index)&bit) == 0) return "z";
		if((1<<index) == bit) return "";
		if(dp[index][bit] != null)
			return dp[index][bit];

		String ret = "z";
		bit -= (1<<index);
		for(int i = 0; i < arr.length; i++){
			if(((1<<i)&bit)==0) continue;
			if(!e[index][i]) continue;
			for(int j = 0; j <= bit; j++){
				if((j&bit) != j) continue;
				if(((1<<i)&j)==0) continue;

				String temp = arr[i] + f(i,j) + f(index,bit-j+(1<<index));
				if(temp.indexOf('z') == -1 && ret.compareTo(temp) > 0)
					ret = temp;
			}
		}

		return dp[index][bit] = ret;
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int N = sc.nextInt();
			int M = sc.nextInt();
			arr = new String[N];
			for(int i = 0; i < N; i++)
				arr[i] = sc.next();

			dp = new String[N][1<<N];
			e = new boolean[N][N];
			for(int i = 0; i < M; i++){
				int a = sc.nextInt()-1;
				int b = sc.nextInt()-1;
				e[a][b] = e[b][a] = true;
			}

			String ans = "z";
			for(int i = 0; i < N; i++){
				String temp = arr[i] + f(i,(1<<N)-1);
				if(temp.indexOf('z') == -1 && ans.compareTo(temp) > 0)
					ans = temp;
			}
			System.out.printf("Case #%d: %s\n",ca,ans);
		}
	}
}