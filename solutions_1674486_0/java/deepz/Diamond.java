import java.util.Scanner;


public class Diamond {
	
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int count = in.nextInt(); 
		
		for(int i=0;i<count;i++){
			
			Diamond d= new Diamond();
			String r=d.readCase(in);
			System.out.println("Case #"+(i+1)+": "+r);
			}
			
		}	
	 
	   public String readCase(Scanner in){
		   int N=in.nextInt();
		   int graph[][]=new int[N][N];
		   int nostart[]=new int[N];
		   visited=new int[N];
		   for(int i=0;i<N;i++){
			   int m=in.nextInt();
			   for(int j=0;j<m;j++){
				   int mi=in.nextInt();
				   graph[i][mi-1]=1;
				   nostart[mi-1]=1;
				   
			   }
			   }
		   
		   String o;
		   int results=processOneCase(N,graph,nostart);
		   if(results==1)
			   	o="Yes";
		   else
			   o="No";
		   
		   return o;
			   
		   
	   }
		
		public int processOneCase(int N,int[][] graph,int nostart[]){
			
			for(int i=0;i<N;i++){
				if(nostart[i]==0){
					for(int j=0;j<N;j++)
						visited[j]=0;
					//System.out.print(i);
					if(doDFS(N,graph,i)==1)
						return 1;
				}
			}
			return 0;
		}
		
		public int visited[];
		public  int doDFS(int N,int[][] graph, int start){		
			
			//System.out.print(start);
			int cycle=0;	
			visited[start]=1;
			for(int j=0;j<N;j++){
				if(graph[start][j]==1){
					if (visited[j]==1)
						return 1;					
					if(doDFS(N,graph,j)==1)
						return 1;
					
				}
			}
			
			return cycle;
			
		}

}
