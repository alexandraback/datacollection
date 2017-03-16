import java.io.*;

class graph{
	
	public static void main(String[] args) throws IOException{
		BufferedReader inp = new BufferedReader(new FileReader("inp.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		
		int test = Integer.parseInt(inp.readLine());
		int p =1;
		while(test>0){
			int n = Integer.parseInt(inp.readLine());
			int val[][] = new int[n+1][n+1];
			int gra[][] = new int[n+1][n+1];
			int i = 1;
			while(i<=n){
				String data[] = inp.readLine().split(" ");
				int j = 1;
				int k = 1;
				while(j<data.length){
					int e = Integer.parseInt(data[j]);
					gra[i][e]=1;
					j++;
				}
				i++;
			}
			int val1 = dfs(gra,val,n);
			if(val1==1){
				System.out.println("yes");
				out.write("Case #"+p+": "+"Yes\n");
			}
			else {
				System.out.println("no");
				out.write("Case #"+p+": "+"No\n");
			}
			test--;
			p++;
		}
		out.close();
	}
	
	public static int dfs(int[][] gra, int[][] val, int n){
		int i = 1;
		while(i<=n){
			int j = 1;
			while(j<=n){
				if(val[j][i]==1){
					val[i][j]=0;
					j++;
					continue;
				}
				else {
				int res = isPath(gra,i,j,n);
				val[i][j] = res;
				if(res>1){
				System.out.println("Multiple paths: "+ i+ " "+j);
				return 1;
			}
				}
				j++;
			}
			i++;
		}
		return 0;
	}
	
	public static int isPath(int[][] gra,int i , int j, int n){
			if(i==j) return 1;
			int k = 1;
			int count = 0;
			while(k<=n){
				if(gra[i][k]==1)
					if (isPath(gra,k,j,n)==1){
					count++;
				}
				k++;
			}
			return count;
				
	}
	
}