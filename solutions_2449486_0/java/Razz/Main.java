
public class Main {
	public static void main(String[] args) throws java.io.FileNotFoundException,java.io.IOException{
		java.io.BufferedReader bRead=new java.io.BufferedReader(new java.io.FileReader("F:\\B-small-attempt0.in"));
		java.io.BufferedWriter bWrite=new java.io.BufferedWriter(new java.io.FileWriter("F:\\B-small-attempt0.out"));
		StringBuffer output=new StringBuffer();
		int noCases=Integer.parseInt(bRead.readLine());
		
		int n,m;int[][] lawn=null;int[] rowMax=null,colMax=null;boolean possible;
		for(int i=0;i<noCases;i++){
			String[] curLine=bRead.readLine().split(" ");
			n=Integer.parseInt(curLine[0]);m=Integer.parseInt(curLine[1]);
			rowMax=new int[n];colMax=new int[m];lawn=new int[n][m];
			for(int row=0;row<n;row++){
				curLine=bRead.readLine().split(" ");
				for(int col=0;col<m;col++){
					lawn[row][col]=Integer.parseInt(curLine[col]);
					if(lawn[row][col] > rowMax[row])rowMax[row]=lawn[row][col];
					if(lawn[row][col] > colMax[col])colMax[col]=lawn[row][col];
				}
			}
			
			possible=true;
			Outer:
			for(int row=0;row<n;row++){
				for(int col=0;col<m;col++){
					if(lawn[row][col]!=rowMax[row] && lawn[row][col]!=colMax[col]){
						possible=false;break Outer;
					}
				}
			}//Outer
			
			if(possible)output.append("Case #"+(i+1)+": YES\n");
			else output.append("Case #"+(i+1)+": NO\n");
		}
		bWrite.write(output.toString());
		bWrite.close();bRead.close();
	}
}
