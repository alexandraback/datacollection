package qr2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MinesweeperMaster {

	/**
	 * @param args
	 */
	public static int caseCount;
	public static BufferedReader inbuf;
	public static BufferedWriter outbuf;
	public static String fileIn="data/qr2014/C-small-attempt3.in";
	public static String fileOut="data/qr2014/C-small-attempt3.out";
	
	public static int isCan(int R,int C,int M){
		int reM=R*C-M;
		if(reM==1) return 11;//忘记了。。。
		if(reM==R*C) return 12;//忘记了...
		if(R==1||C==1) return 1;	
		else{
			if(reM==2||reM==3||reM==5||reM==7) return 0;
			else if(reM==4||reM==6||reM==8) return 2;
			else{
				if(R>=3&&C>=3&&reM>=9) return 3;
				else return 0;
			}
		}		
	}

	public static void print0() throws IOException{
		outbuf.write("Impossible\r\n");
	}
	
	public static void print1(int R,int C,int M) throws IOException{
		int rem=R*C-M;
		if(R==1){
			outbuf.write("c");
			for(int i=1;i<=rem-1;i++)
				outbuf.write(".");
			for(int i=1;i<=M;i++)
				outbuf.write("*");
			outbuf.write("\r\n");
		}
		else{
			outbuf.write("c\r\n");
			for(int i=1;i<=rem-1;i++)
				outbuf.write(".\r\n");
			for(int i=1;i<=M;i++)
				outbuf.write("*\r\n");
		}
		
	}
	
	public static int[][] getJishuResult(int R,int C,int M)throws IOException{
		int rem=R*C-M;
		int[][] result=new int[R][C]; 
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				result[i][j]=1;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				result[i][j]=0;
		rem-=9;
		if(rem==0) return result;
		
		int col=3;
		while(rem>0&&col<C){
			result[0][col]=0;
			result[1][col]=0;
			col++;
			rem-=2;
		}
		if(rem==0) return result;
		
		int row=3;
		while(rem>0&& row<R){
			result[row][0]=0;
			result[row][1]=0;
			row++;
			rem-=2;
		}
		if(rem==0) return result;
		
		int col2=3;
		while(rem>0&& col2<C){
			result[2][col2]=0;
			col2++;
			rem--;
		}
		if(rem==0) return result;
		
		//最终结果到来啦
		
		int arow=rem/(C-2);
		int arem=rem-arow*(C-2);
		 for(int i=3;i<3+arow;i++){
			 for(int j=2;j<C;j++)
				 result[i][j]=0;
		 }
		 for(int j=2;j<arem+2;j++)
			 result[3+arow][j]=0;
		 return result;

	}

	public static int[][] getOushuResult(int R,int C,int M)throws IOException{
		int rem=R*C-M;
		int[][] result=new int[R][C];
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				result[i][j]=1;
		int col=0;
		while(rem>0&&col<C){
			result[0][col]=0;
			result[1][col]=0;
			col++;
			rem-=2;
		}
		if(rem==0) return result;
	
		int row=2;
		while(rem>0&&row<R){
			result[row][0]=0;
			result[row][1]=0;
			row++;
			rem-=2;
		}
		if(rem==0) return result;
		
		 int arow=rem/(C-2);
		 int arem=rem-arow*(C-2);
		 for(int i=2;i<2+arow;i++){
			 for(int j=2;j<C;j++)
				 result[i][j]=0;
		 }
		 for(int i=2;i<arem+2;i++)
			 result[2+arow][i]=0;
		 return result;
				
	}
	public static void printResult(int[][]result) throws IOException{
		int R=result.length;
		int C=result[0].length;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(i==0&&j==0)
					outbuf.write("c");
				else {
					if(result[i][j]==0)
						outbuf.write(".");
					else outbuf.write("*");
				}
				if(j==C-1)
					outbuf.write("\r\n");				
			}
		}
	}
	public static void print(int R,int C,int M)throws IOException{
		int judge=isCan(R,C,M);
		if(judge==0) print0();
		else if(judge==11 ){
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(i==0&&j==0)
						outbuf.write("c");
					else 
						outbuf.write("*");
					if(j==C-1) 
						outbuf.write("\r\n");
				}
			}
		}
		else if(judge==12){
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(i==0&&j==0)
						outbuf.write("c");
					else 
						outbuf.write(".");
					if(j==C-1) 
						outbuf.write("\r\n");
				}
			}
		}
		else if(judge==1) print1(R,C,M);
		else {
			int[][] result=new int[R][C];
			if(judge==2) result=getOushuResult(R,C,M);
			else{
				if((R*C-M)%2==0) result=getOushuResult(R,C,M);
				else result=getJishuResult(R,C,M);
			}
			printResult(result);
		}
	}
		

	

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//打开文件句柄
		long sTime=System.currentTimeMillis();
		inbuf=new BufferedReader(new FileReader(fileIn));
		outbuf=new BufferedWriter(new FileWriter(fileOut));	
		caseCount=Integer.valueOf(inbuf.readLine());
		String line="";	
		for(int i=1;i<=caseCount;i++){
			outbuf.append("Case #"+i+":\r\n");//注意这里的空格
			line=inbuf.readLine();
			String[] numstr=line.split(" ");
			int R=Integer.valueOf(numstr[0]);
			int C=Integer.valueOf(numstr[1]);
			int M=Integer.valueOf(numstr[2]);
			print(R,C,M);
		}
		
		
		
		
		//关闭文件句柄	
		inbuf.close();
		outbuf.close();
		System.out.println("time:"+(System.currentTimeMillis()-sTime)/1000.0+"s");
	}

}
