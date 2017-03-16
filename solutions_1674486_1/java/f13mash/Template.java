import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class Template {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int cases=Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=cases;t++){
			String out="Case #"+t+":";
			int N=Integer.parseInt(br.readLine().trim());
			
			int[][] pars=new int[N][N];
			
			List<Integer> lst=new ArrayList<Integer>();
			
			for(int i=0;i<N;i++){
				String[] splts=br.readLine().trim().split(" ");
				pars[i][0]=Integer.parseInt(splts[0]);
				lst.add(i);
				
				for(int j=1;j<=pars[i][0];j++){
					pars[i][j]=Integer.parseInt(splts[j])-1;
				}
			}
			//lst.add(0);
			boolean ispos=false;
			for(Integer e : lst){
				boolean[] vis=new boolean[N];
				List<Integer> q=new LinkedList<Integer>();
				
				q.add(e);
				vis[e]=true;
				
				while(q.size()>0 && !ispos){
					
					int p=q.get(0);
					q.remove(0);
					vis[p]=true;
					//System.out.println("p is : "+p);
					for(int k=1;k<=pars[p][0];k++){
						int el=pars[p][k];
						if(vis[el]){
							ispos=true;
							break;
						}
						vis[el]=true;
						q.add(el);
					}
				}
				
				if(ispos)
					break;
				
			}
			out+=(ispos?" Yes":" No");
			System.out.println(out);
		}
	}
	
	static void solve(){
		
	}

}
