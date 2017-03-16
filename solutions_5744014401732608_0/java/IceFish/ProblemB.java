import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args){
		String finput="/Users/yifangyin/Downloads/B-small-attempt5.in";
		File file = new File(finput);
		int numofcases=0;
		try{
			Scanner sc = new Scanner(file);
			numofcases=sc.nextInt();
			StringBuilder sb=new StringBuilder();
			for(int i=0;i<numofcases;i++){
				int B=sc.nextInt();
				long M=sc.nextLong();
				//B=4;
				//M=20;
				String output=solver(B,M);
				String s="Case #"+String.valueOf(i+1)+": "+output;
				System.out.println(B+" "+M);
				System.out.println(s);
				sb.append(s);
				sb.append("\n");
				
				//break;
			}
			sc.close();
			
			String foutput="/Users/yifangyin/Downloads/test.txt";
			PrintWriter writer = new PrintWriter(foutput);
			writer.println(sb.toString());
			writer.close();
			
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	
	public static String solver(int B, long M){
		String output="";
		StringBuilder sb=new StringBuilder();
		//System.out.println(B+" "+M);
		int[][] res=new int[B][B];
		for(int i=0;i<B;i++){
			res[i]=new int[B];
		}
		if(B==2){
			if(M==1){
				sb.append("POSSIBLE");
				sb.append("\n");
				sb.append("01\n");
				sb.append("00");
			}else{
				sb.append("IMPOSSIBLE");
			}
			output=sb.toString();
			return output;
		}

		int[] nodes=new int[B-2];
		int cnt=0;
		int sumval=0;
		while(M!=0){
			int tmp=(int) (M % 2);
			nodes[cnt]=tmp;
			//System.out.println(M+" "+cnt+" "+nodes[cnt]);
			cnt++;
			M=M/2;
			sumval+=tmp;
			if(cnt>=B-2){
				break;
			}
		}

		System.out.println(sumval+" "+M);
		if((sumval!=0 && M==1) || M>1){
			sb.append("IMPOSSIBLE");
			output=sb.toString();
			return output;
		}
		
		sb.append("POSSIBLE");
		sb.append("\n");
		if(M==1){
			res[0][B-1]=1;
		}
		for(int i=0;i<B-2;i++){
			if(nodes[i]==1){
				for(int j=0;j<i+1;j++){
					for(int k=j+1;k<=i+1;k++){
						res[j][k]=1;
					}
				}
				res[0][i+1]=1;
				res[i+1][B-1]=1;
			}
		}
		
		for(int i=0;i<B;i++){
			for(int j=0;j<B;j++){
				sb.append(String.valueOf(res[i][j]));
			}
			if(i<B-1){
				sb.append("\n");
			}
		}
		output=sb.toString();
		return output;
	}
		
}
