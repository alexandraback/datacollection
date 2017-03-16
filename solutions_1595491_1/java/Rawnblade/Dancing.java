import java.util.*;

public class Dancing {
	static int[] topS;
	static int[] topN;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		fill();
		int times = reader.nextInt();
		for(int k = 1; k <= times; k++){
			int n = reader.nextInt();
			int s = reader.nextInt();
			int p = reader.nextInt();
			
			int[] t = new int[n];
			for(int i = 0; i < n; i++)
				t[i] = reader.nextInt();
			
			int cnt = 0;
			for(int i = 0; i < n; i++){
				if(topN[t[i]] >= p){
					cnt++;
				}else if(topS[t[i]] >= p && s > 0){
					cnt++;
					s--;
				}
			}
			
			System.out.println("Case #"+k+": "+cnt);
		}
	}
	
	public static void fill(){
		topS = new int[31];
		topN = new int[31];
		Arrays.fill(topS, -1);
		for(int n = 0; n <= 30; n++)
			for(int i = 0; i <= 10; i++)
				for(int j = i; j <= Math.min(i+2,10) && i+j <= n && n-i-j <= 10; j++){
					if((Math.abs(i-(n-i-j)) <= 2 && Math.abs(j-(n-i-j)) <= 2) && (Math.abs(i-(n-i-j)) == 2 || Math.abs(j-(n-i-j)) == 2 || j-i==2)){
						topS[n] = Math.max(topS[n], Math.max(i,Math.max(j,n-i-j)));
					}else if(Math.abs(i-(n-i-j)) <= 2 && Math.abs(j-(n-i-j)) <= 2){
						topN[n] = Math.max(topN[n], Math.max(i,Math.max(j,n-i-j)));
					}
				}
	}
}
