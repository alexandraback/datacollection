import java.io.*;
import java.util.Scanner;


public class GCJCsmall {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(new File("C-small-practice.in"));
		GCJCsmall main = new GCJCsmall();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("C-small-attempt5.in"));
		//Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("C5.out", "UTF-8");
		for(int i=1; i<=cases; i++){
			//String[] size = scan.nextLine().split(" ");
			//Integer.parseInt(size[0]);
			//scan.nextInt();
			int R=scan.nextInt();
			int C=scan.nextInt();
			int M=scan.nextInt();
			
			int nRows = Math.min(R,C);
			int nCols = Math.max(R,C);				//
			String[][] minefield = new String[nRows][nCols];
			minefield=iterateField(minefield, M, nRows, nCols);
			
			writer.println("Case #"+i+": ");
			System.out.println("Rows: "+R+" Columns: "+C+" mines: "+M);
			System.out.println("Case #"+i+": ");
			if(minefield==null){
				writer.println("Impossible");
				System.out.println("Impossible");
			}else{
				if(R==nRows){
					printToFile(minefield, writer);
					print(minefield);
				}else{
					printToFile(transpose(minefield), writer);
					print(transpose(minefield));
				}
			}
			//writer.println("Case #"+i+": "+"YES");
			//System.out.println("Case #"+i+": "+"YES");		
		}
		writer.close();
	}
	
	public String[][] iterateField(String[][] minefield, int M, int nRows, int nCols){
		int emptySpaces=nRows*nCols-M;
		if(M==nRows*nCols){
			return fullMines(nRows, nCols);
		}
		
		if(M==0){
			minefield = defillRect(minefield, 0, 0, nRows, nCols);
			minefield[0][0]="c";
			return minefield;
		}
		
		if(nRows==1){
			minefield=fillRect(minefield,0,0,1,M);
			minefield[0][nCols-1]="c";
			return complete(minefield);
		}
		if(emptySpaces==1){
			minefield = fullMines(nRows, nCols);
			minefield[0][0]="c";
			return complete(minefield);
		}
		
		if(nRows==2){
			if(emptySpaces%2==1||emptySpaces==2){
				return null;
			}else{
				minefield=fillRect(minefield, 0, 0, 2, M/2);
			}
			minefield[0][nCols-1]="c";
			return complete(minefield);
		}
		if(nRows==3&&nCols==3&&M==2){
			return null;
		}
		if(M<nRows){
			if(M!=nRows-1){
				minefield=fillRect(minefield, 0, 0, M, 1);
				minefield[0][nCols-1]="c";
				return complete(minefield);
			}else{
				minefield=fillRect(minefield, 0, 0, M-1, 1);
				minefield[0][1]="*";
				minefield[0][nCols-1]="c";
				return complete(minefield);
			}
		}
		if(M < nRows*nCols-2*nRows-1){
			minefield=fillRect(minefield, 0, 0, nRows, M/nRows);
			if(M%nRows!=nRows-1){
				minefield=fillRect(minefield, 0, M/nRows, M%nRows, 1);
			}else{
				minefield=fillRect(minefield, 0, M/nRows, nRows-2, 1);
				minefield=fillRect(minefield, 0, M/nRows+1, 1, 1);
			}
			minefield[0][nCols-1]="c";
			return complete(minefield);
		}
		
		if(emptySpaces==2||emptySpaces==3||emptySpaces==5||emptySpaces==7){
			return null;
		}
		if(emptySpaces%2==0){
			minefield=defillRect(minefield, 0, 0, emptySpaces/2, 2);
			minefield[0][0]="c";
			return complete(minefield);
		}else{			
			//emptySpaces/2<nRows||emptySpaces == 2*nRows+1
			minefield = defillRect(minefield, 0, 0, emptySpaces/2-1, 2);
			minefield = defillRect(minefield, 0, 2, 3, 1);
			minefield[0][0]="c";
			return complete(minefield);
		}
		//System.out.println("missed a case");
		//return minefield;
		
	}
	
	public String[][] complete(String[][] minefield){
		for(int i=0; i<minefield.length; i++){
			for(int j=0; j<minefield[0].length; j++){
				if(minefield[i][j]!="*"&&minefield[i][j]!="c"){
					minefield[i][j]=".";
				}
			}
		}
		return minefield;
	}
	
	public String[][] defillRect(String[][] A, int starty, int startx, int height, int width){
		for(int i=starty; i<starty+height; i++){
			for(int j=startx; j<startx+width; j++){
				A[i][j]=".";
			}
		}
		for(int i=0; i<A.length; i++){
			for(int j=0; j<A[0].length; j++){
				if(A[i][j]!="."&&A[i][j]!="c"){
					A[i][j]="*";
				}
			}
		}
		return A;
	}
	
	
	public String[][] fillRect(String[][] A, int starty, int startx, int height, int width){		
		for(int i=starty; i<starty+height; i++){
			for(int j=startx; j<startx+width; j++){
				A[i][j]="*";
			}
		}
		return A;
	}
	public String[][] transpose(String[][] A){
		String[][] B = new String[A[0].length][A.length];
		for(int i=0; i<A[0].length; i++){
			for(int j=0; j<A.length; j++){
				B[i][j] = A[j][i];
			}
		}
		return B;
	}
	
	public void print(String[][] field){
		for(int i=0; i<field.length; i++){
			for(int j=0; j<field[0].length; j++){
				System.out.print(field[i][j]);
			}
			System.out.println();
		}
	}
	
	public void printToFile(String[][] field, PrintWriter writer){
		for(int i=0; i<field.length; i++){
			for(int j=0; j<field[0].length; j++){
				writer.print(field[i][j]);
			}
			writer.println();
		}
	}
	
	public String[][] fullMines(int R, int C){
		String[][] mines = new String[R][C];
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				mines[i][j]="*";
			}
		}
		return mines;
	}
	
}
