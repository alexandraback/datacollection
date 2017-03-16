import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class prob1 {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String hm="", line[];
		int n =Integer.valueOf(in.readLine()), m=1,N,i,j, level[][];
		while(m<=n){
			N=Integer.valueOf(in.readLine());
			level=new int[N][N+1];
			for(i=0;i<N;i++){
				line=in.readLine().split(" ");
				level[i][0]=Integer.valueOf(line[0]);
				for(j=1;j<=level[i][0];j++)
					level[i][j]=Integer.valueOf(line[j]);
			}
			String paths,sep="";
			for(i=0;i<N;i++){
				sep="";
				paths=findPaths(level,N,i).replaceAll(",,", ",")+",";
				if(paths.contains("Yes")){
					sep="Yes";
							break;
				}
					
				//System.out.println(paths+" ");
				while(paths.length()>1){
					sep=paths.substring(0, paths.indexOf(',',1));
					paths=","+paths.substring(paths.indexOf(',',1)+1, paths.length());
					//System.out.println("#"+sep+" "+paths);
					if(paths.contains(sep+",") && !sep.equals("") && !sep.equals(",")){
						sep="Yes";
						break;
					}
				}
				if(sep=="Yes") break;
				
			}
			if(sep=="Yes")
				System.out.println("Case #"+m+": Yes");
			else
				System.out.println("Case #"+m+": No");
			m++;
		}
	}

	private static String findPaths(int[][] level,int N, int start) {
		String paths="",temp;
		if(level[start][0]==0){
			return String.valueOf(start);
		}else
			for(int j=1;j<=level[start][0];j++){
				temp=findPaths(level,N,level[start][j]-1);
				if(paths.contains(temp))
					return "Yes";
				else
					paths+=","+temp;
				if(paths.contains("Yes"))
					return "Yes";
			}
		return paths;
	}

}
