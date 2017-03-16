package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class QualC {	
	private String inFileName = "F:\\codejam\\C-small-attempt2.in";
	private String outFileNeme = "F:\\codejam\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;
		int m,n,k;
		int[][] mat;
		boolean gotResult=false;
		public TestCase(){
			m = getInt();
			n = getInt();
			k = getInt();
			int comb = m*n;
			mat = new int [m][n];		
		}
		
		public void run() {
			int count = m*n;
			Integer[] arr = new Integer[count];
			for(int i = 0;i<count;i++){
				arr[i]=i;
			}
			goComb(arr, k, 0, new Integer[k]);
			if(!gotResult)
			result ='\n'+"Impossible";
			
		}
		void analyze(Set<Integer> set){
			Integer iC=0;
			mat = new int[m][n];
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(set.contains(iC)){
						mat[i][j]=9;
					}
					iC++;
				}
			}
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(mat[i][j]!=9){
						int count=0;
						try {if(mat[i-1][j-1]==9)count++;} catch (Exception e) {}
						try {if(mat[i-1][j]==9)count++;} catch (Exception e) {}
						try {if(mat[i-1][j+1]==9)count++;} catch (Exception e) {}
						try {if(mat[i][j-1]==9)count++;} catch (Exception e) {}
						try {if(mat[i][j+1]==9)count++;} catch (Exception e) {}
						try {if(mat[i+1][j-1]==9)count++;} catch (Exception e) {}
						try {if(mat[i+1][j]==9)count++;} catch (Exception e) {}
						try {if(mat[i+1][j+1]==9)count++;} catch (Exception e) {}
						mat[i][j]=count;
					}
				}
			}
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(mat[i][j]!=9){
						int[][] t = getcopy();
						openCells(t, i, j);
						if(checkMatrix(t)){
							result = printresult(i,j);
							gotResult=true;
							return;
						}
					}
				}
			}
		}
		void goComb(Integer[] arr, int len, int startPosition, Integer[] r){
			if (len == 0 && !gotResult){
				Set<Integer> set = new HashSet<Integer>(Arrays.asList(r));
				analyze(set);
	            return;
	        }       
	        for (int i = startPosition; i <= arr.length-len; i++){
	            r[r.length - len] = arr[i];
	            if(!gotResult)
	            goComb(arr, len-1, i+1, r);
	        }
			
		}
		
		void openCells(int[][] t, int i, int j){
			if(t[i][j]==0){
				t[i][j]=-1;
				try {if(t[i-1][j-1]==0)openCells(t, i-1, j-1);  t[i-1][j-1]=-1;} catch (Exception e) {}
				try {if(t[i-1][j]==0)openCells(t, i-1, j); t[i-1][j]=-1; } catch (Exception e) {}
				try {if(t[i-1][j+1]==0)openCells(t, i-1, j+1); t[i-1][j+1]=-1; } catch (Exception e) {}
				try {if(t[i][j-1]==0)openCells(t, i, j-1); t[i][j-1]=-1;} catch (Exception e) {}
				try {if(t[i][j+1]==0)openCells(t, i, j+1); t[i][j+1]=-1;} catch (Exception e) {}
				try {if(t[i+1][j-1]==0)openCells(t, i+1, j-1);t[i+1][j-1]=-1;} catch (Exception e) {}
				try {if(t[i+1][j]==0)openCells(t, i+1, j);t[i+1][j]=-1;} catch (Exception e) {}
				try {if(t[i+1][j+1]==0)openCells(t, i+1, j+1);t[i+1][j+1]=-1;} catch (Exception e) {}
			}else{
				t[i][j]=-1;
			}
		}
		int[][] getcopy(){
			int[][] t = new int [m][n];
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(mat[i][j]==9){
						t[i][j]=-1;
					}else{
						t[i][j]=mat[i][j];
					}
				}
			}
			return t;
		}
		boolean checkMatrix(int[][] t){
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(t[i][j]!=-1){
						return false;
					}
				}
			}
			return true;
		}
		String printresult(int a, int b){
			StringBuffer sb = new StringBuffer();
			sb.append('\n');
			for(int i=0;i<m;i++){
				for(int j=0; j<n;j++){
					if(i==a && j==b) {
						sb.append('c');
					}else{
						if(mat[i][j]==9){
							sb.append('*');
						}else{
							sb.append('.');
						}
					}						
				}
				if(i<m-1)sb.append('\n');
			}
			return sb.toString();
		}
		
	}	
		
	public void execute(){
		testCaseCount = getInt();
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		}
		for(int i =0; i<testCaseCount; i++){
			cases.get(i).run();
		}
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
			writeLine(op);
		}
	}	
	public TestCase getCase(){
		return new TestCase();
	}	
	public void writeLine(String line){outSc.format(line+'\n');}
	public String nextLine(){return inSc.nextLine();}
	public String getWord(){return inSc.next();}	
	public Integer getInt(){return inSc.nextInt();}	
	public Double getDouble(){return inSc.nextDouble();}	
	public Long getLong(){return inSc.nextLong();}	
	public BigInteger getBigInt(){return  new BigInteger(getWord());}	
	public BigDecimal getBigDecimal(){return  new BigDecimal(getWord());}
	public void closeOutputFile(){outSc.flush();outSc.close();}	
	Scanner inSc;
	Formatter outSc;	
	public QualC() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		QualC st = new QualC();
		st.execute();
		st.complete();
	}
}
