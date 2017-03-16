import java.util.*;

class QB{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kase = sc.nextInt();
		for(int k = 1; k<=kase; k++){
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();
			int[] tots = new int[N];
			for(int i = 0; i<N; i++)tots[i] = sc.nextInt();
			Arrays.sort(tots);
			int i = tots.length;//index of last reasonable score.
			while(i>0 && tots[i-1]>=(3*p-2)) i--;
			int j = 0;
			if(p!=1){
			 while(i>0 && tots[i-1]>= 3*p-4 && j<S){i--;j++;}
			}
			System.out.println("Case #"+k+": "+(N-i));
		}
	}
}
