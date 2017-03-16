import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {
	static FileWriter out;
	static Long box[][],toy[][],ans;
	static void dfs(int n,Long useN,int m,Long useM,Long num){
		if(n==box.length || m==toy.length){
			ans=Math.max(ans, num);
			return;
		}
		while(box[n][1].equals(toy[m][1])){
			Long tmp=Math.min(box[n][0]-useN, toy[m][0]-useM);
			num+=tmp;
			useN+=tmp;
			if(useN.equals(box[n][0])){
				n++;
				if(n==box.length){
					ans=Math.max(ans, num);
					return;
				}
				useN=0L;
			}
			useM+=tmp;
			if(useM.equals(toy[m][0])){
				m++;
				if(m==toy.length){
					ans=Math.max(ans, num);
					return;
				}
				useM=0L;
			}
		}
		dfs(n+1,0L,m,useM,num);
		dfs(n,useN,m+1,0L,num);
	}
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		out=new FileWriter("out.txt");
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			int n=sc.nextInt(),m=sc.nextInt();
			box=new Long[n][2];toy=new Long[m][2];
			for(int i=0;i<n;i++){
				box[i][0]=sc.nextLong();
				box[i][1]=sc.nextLong();
			}
			for(int i=0;i<m;i++){
				toy[i][0]=sc.nextLong();
				toy[i][1]=sc.nextLong();
			}
			ans=0L;
			dfs(0,0L,0,0L,0L);
			output("Case #"+t+": "+ans);
		}
		out.close();
	}
	
	static void output(String str) throws IOException{
		out.write(str+"\n");
		System.out.println(str);
	}
}
