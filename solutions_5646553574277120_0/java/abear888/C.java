import java.io.*;
import java.util.*;

public class C{
	public static int power(int base, int exponent){
		int output=1;
		for (int i=1; i<=exponent; i++){
			output*=base;
		}
		return output;
	}
	
	public static void main (String[]args)throws IOException{
		BufferedReader x=new BufferedReader(new FileReader("Csmall1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Csmall1.out")));
		int t=Integer.parseInt(x.readLine());
		for (int cases=1; cases<=t; cases++){
			StringTokenizer st=new StringTokenizer(x.readLine());
			st.nextToken();
			int d=Integer.parseInt(st.nextToken());
			int v=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(x.readLine());
			int[]nom=new int[d];
			for (int i=0; i<d; i++){
				nom[i]=Integer.parseInt(st.nextToken());
			}
			boolean[]visited=new boolean[5];
			for (int i=0; i<=4; i++){
				if (power(2,i)>v)visited[i]=true;
			}
			for (int i=0; i<d; i++){
				for (int j=0; j<=4; j++){
					if (nom[i]==power(2,j)){
						visited[j]=true;
						nom[i]=0;
					}
				}
			}
			for (int i=0; i<=power(2, d)-1; i++){
				ArrayList<Integer> temp=new ArrayList<Integer>();
				for (int j=0; j<d; j++){
					if ((i&(1L<<j))!=0){
						temp.add(nom[j]);
					}
				}
				int sum=0;
				for (int cur:temp){
					sum+=cur;
				}
				for (int j=0; j<=4; j++){
					if (power(2,j)==sum)visited[j]=true;
				}
			}
			int ans=0;
			for (int i=0; i<=4; i++){
				if (!visited[i])ans++;
			}
			out.println("Case #"+cases+": "+ans);
		}
		out.close();
		System.exit(0);
	}
}