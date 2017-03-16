import java.util.Scanner;


public class Solution {
	static String yes="Yes";
	static String no="No";

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
	    int T = scan.nextInt();
	    String[] results = new String[T];
	    for(int k=0;k<T;k++){
	    	int N= scan.nextInt();
	    	int[][] nums= new int[N+1][N+1];
	    	for(int i=1;i<=N;i++){
	    		int M = scan.nextInt();	    
	    		int v =0;
	    		for(int j=1;j<=M;j++){
	    			v=scan.nextInt();
	    			nums[i][v]=1;
	    		}
	    			
	    	}
	    	results[k]=process(nums,N);    	
	    	
	    }
	    for(int k=0;k<T;k++){
	    	System.out.println("Case #"+(k+1)+": "+results[k]);
	    }
    }
	
	public static String process(int[][] nums,int N){
		//int[][] dup = new int[N+1][N+1];
	
		for(int i=1;i<=N;i++){
			boolean[] visited = new boolean[N+1];
			int[] connected = new int[N+1];
			boolean added=false;
			for(int j=1;j<=N;j++){
				if(nums[i][j]>0){
					connected[j] = nums[i][j];
					added = true;					
				}
				
			}
			
			
			
			while(added){
				added = false;
				for(int k=1;k<=N;k++){
					if(connected[k]>0 && !visited[k]){
						visited[k]=true;
						for(int j=1;j<=N;j++){
							if(nums[k][j]>0){
								 connected[j]++;
								 if(connected[j]==1){
									 added = true;
								 }else{
									 return yes;
								 }
							}
						}
					}
				}
			}
		}
		
		/*for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(nums[i][j]>1){
					return yes;
				}
			}
		}*/
		return no;
	}
	
}
