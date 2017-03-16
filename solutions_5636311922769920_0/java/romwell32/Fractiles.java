import java.util.Scanner;

public class Fractiles {

	public static String sequence(int K, int C, int S){
		if (C * S < K) {return " IMPOSSIBLE";}
		else
		{
			String ans = "";
			int cur_d = 0;
			while (cur_d < K)
			{
				long pos = 0;
				for (int i=0; i<C; i++){
					pos = pos * K + (cur_d < K ? cur_d : 0);
					cur_d ++;
				}
				ans += " " + (pos+1);
			}
			return ans;
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i < T; i++)
		{
			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();
			System.out.println("Case #" + (i+1) +":" + sequence(K,C,S));
		}
		sc.close();
		
	}
	
}
