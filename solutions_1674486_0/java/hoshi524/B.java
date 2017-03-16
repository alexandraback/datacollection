import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B {
	static FileWriter out;
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		out=new FileWriter("out.txt");
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			int n=sc.nextInt();
			int m[][]=new int[n][];
			for(int i=0;i<n;i++){
				int M=sc.nextInt();
				m[i]=new int[M];
				for(int j=0;j<M;j++){
					m[i][j]=sc.nextInt()-1;
				}
			}
			boolean ans=false;
			for(int i=0;i<n;i++){
				boolean use[]=new boolean[n];
				Queue<Integer> que=new LinkedList<Integer>();
				que.add(i);
				use[i]=true;
				while(!que.isEmpty()){
					int state=que.poll();
					for(int j=0;j<m[state].length;j++){
						if(use[m[state][j]]){
							ans=true;
						}else{
							que.add(m[state][j]);
							use[m[state][j]]=true;;
						}
					}
				}
			}
			output("Case #"+t+": "+(ans?"Yes":"No"));
		}
		out.close();
	}
	
	static void output(String str) throws IOException{
		out.write(str+"\n");
		System.out.println(str);
	}
}
