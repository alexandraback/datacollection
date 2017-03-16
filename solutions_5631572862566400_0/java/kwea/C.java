package round12016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class C {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("C-small.out"));
//        BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
//        PrintWriter pw = new PrintWriter(new File("C-large.out"));
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++){
        	int N = Integer.parseInt(br.readLine());
        	int[] BFF = new int[N+1];
        	int[] full = new int[N+1];
        	String[] ss = br.readLine().split(" ");
        	for(int j=1;j<=N;j++)
        		BFF[j] = Integer.parseInt(ss[j-1]);
        	int res =1;
        	int max = Integer.MIN_VALUE;
        	for(int k=1;k<=N;k++){
        		int kid = k;
        		if(full[kid]>=2){
        			max = Math.max(res,max);
        			continue;
        		}
        		while(full[kid]<2){
        			int bff = BFF[kid];
        			if(full[bff]>=2){
        				max = Math.max(res,max);
        				res=1;
        				break;
        			}
        			else{
        				full[bff]++;
        				full[kid]++;
        				if(full[bff]==2){
        					if(full[kid]==1){
        						max++;
        					}
        					break;
        				}
        				res++;
        				kid = bff;
        			}
        		}
        	}
        	pw.println("Case #"+i+": "+max);
        }
        pw.close();
        br.close();
	}
}
