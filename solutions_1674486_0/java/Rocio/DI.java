import java.util.*;

public class  DI{
	
	static int isReachable(int start, int end, int[][] ch){
		Stack<Integer> st = new Stack<Integer>();
		st.push(start);
		int total = 0;
		while(!st.isEmpty()){
			int ver = st.pop();
			int[] mych = ch[ver];
			for(int i = 0; i<mych.length; i++){
				if(mych[i] == end)
					total++;
				else{
					st.push(mych[i]);
				}
			}
//			System.out.println("Current "+st);
		}
//		System.out.println(" start "+start+" end "+end+" total "+total);
		return total;
	}
	
	static boolean solve(int[][] ch, int N){
		for(int i = 0; i<N-1; i++){
			for(int j = i+1; j<N; j++){
					int reach = isReachable(i, j, ch);
					if(reach > 0){
						if(reach > 1)
							return true;
					}else if(isReachable(j,i, ch) >1){
						return true;
					}
				
			}
		}
		return false;
		
	}
	
	public static void main(String args[]){
	
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		
		for(int i = 1; i<=T; i++){
			int N = s.nextInt();
			int[][] children = new int[N][];				
			
			for(int j = 0; j<N; j++){
				int Mj = s.nextInt();
				children[j] = new int[Mj];
				for(int k = 0; k< Mj;k++){
					int child = s.nextInt() -1;
					children[j][k] = child;
				}
			}
			boolean y  = solve(children, N);
			if(y){
				System.out.println("Case #"+i+": Yes");
				
			}else{
				System.out.println("Case #"+i+": No");
			}
		}

	}
}