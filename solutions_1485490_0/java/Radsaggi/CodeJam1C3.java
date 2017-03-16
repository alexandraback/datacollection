import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CodeJam1C3 {
	
	static BufferedReader br;
	static PrintWriter pw;
	
	static int ntoy,nbox;
	static long box[][],toy[][];
	static long count=0;
	
	public static void main(String[] args)throws Exception{
		br=new BufferedReader (new FileReader ("in.txt"));
		pw=new PrintWriter (new FileWriter("out.txt"));
		
		int t=Integer.parseInt( br.readLine() );
		for (int i=1;i<=t;i++){
			input();
			work(0,0,0);
			
			pw.printf ("Case #%d: %d",i,count);
			
			pw.println();
		}
		
		pw.close();
	}
	
	public static void input()throws Exception{
		StringTokenizer data=new StringTokenizer(br.readLine());
		nbox=Integer.parseInt(data.nextToken());
		ntoy=Integer.parseInt(data.nextToken());
		
		data=new StringTokenizer(br.readLine());
		box=new long[nbox][2];
		for (int i=0;i<nbox;i++){
			box[i][0]=Long.parseLong(data.nextToken());
			box[i][1]=Long.parseLong(data.nextToken());
		}
		
		data=new StringTokenizer(br.readLine());
		toy=new long[ntoy][2];
		for (int i=0;i<ntoy;i++){
			toy[i][0]=Long.parseLong(data.nextToken());
			toy[i][1]=Long.parseLong(data.nextToken());
		}
		
		count=0;
	}
	
	public static void work(int i,int j,long calc){
		long x=0;
		if (box[i][1]==toy[j][1]){
			
			x=Math.min(box[i][0],toy[j][0]);
			box[i][0]-=x;
			toy[j][0]-=x;
			calc+=x;
		}
		
		if (i+1==nbox && j+1==ntoy){
			if (calc>count){
				count=calc;
			}
			if (box[i][1]==toy[j][1]){
				box[i][0]+=x;
				toy[j][0]+=x;
			}
			return;
		} else if (i+1==nbox){
			work(i,j+1,calc);
		} else if (j+1==ntoy){
			work(i+1,j,calc);
		} else if (box[i][0]==0){
			work(i+1,j,calc);
		} else if (toy[j][0]==0){
			work(i,j+1,calc);
		} else {
			work(i,j+1,calc);
			work(i+1,j,calc);
			
		}
		if (box[i][1]==toy[j][1]){
			box[i][0]+=x;
			toy[j][0]+=x;
		}
	}
	
}