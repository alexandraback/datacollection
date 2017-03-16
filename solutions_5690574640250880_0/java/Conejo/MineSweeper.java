import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;


public class MineSweeper {
	
	public int[][] currentMatrix;
	private int R,C,M, nPositions;
	public int[] cstart;
	private int currentMinePositions[];
	//BRUTE FORCE :(
	public MineSweeper(int r, int c, int m){
		R = r;
		C = c;
		nPositions = r*c;
		M = m;
		currentMinePositions = new int[m];
		cstart = null;
		currentMatrix = new int[r][c];
		for(int i = 0;i<r;i++)
			for(int j = 0;j<c;j++){
				if(m>0){
					currentMatrix[i][j] = 1;
					currentMinePositions[M-m] = i*C+j;
					m--;
				}else
					currentMatrix[i][j] = 0;
					
			}
	}
	public boolean checkForSolution(){
		int[][] checkMatrix = new int[R][C];
		cstart = this.findStartForSolution();
		if(cstart == null){
			int nSquare = R*C;
			if((nSquare-M)==1){
				//good, just one square free

				for(int i = 0;i<R;i++)
					for(int j = 0;j<C;j++)
						currentMatrix[i][j] = 1;
				currentMatrix[0][0] = 0;
				cstart = new int[]{0,0};
				return true;
			}
			return false;//not good
		}
		for(int i = 0;i<R;i++)
			for(int j = 0;j<C;j++)
				checkMatrix[i][j] = currentMatrix[i][j];
		
		this.expandStartRecursive(checkMatrix, cstart);
		
		for(int i = 0;i<R;i++)
			for(int j = 0;j<C;j++)
				if(checkMatrix[i][j] == 0)
					return false;
		return true;
 		
	}
	public boolean increment(){
		if(M == 0)
			return false;
		int espacios = 0;
		boolean foundAnother = false;
		for(int mina = M-1;mina>=0;mina--){
			currentMinePositions[mina]++;
			if(currentMinePositions[mina]<(nPositions-espacios)){
				for(int minaRec = mina+1;minaRec<M;minaRec++){
					currentMinePositions[minaRec] = currentMinePositions[minaRec-1]+1;
				}
				foundAnother = true;
				break;
			}
			espacios++;
			
		}
		if(!foundAnother)
			return false;
		for(int i = 0;i<R;i++)
			for(int j = 0;j<C;j++)
				currentMatrix[i][j] = 0;
		for(int minPos:currentMinePositions){
			int i = minPos / C;
			int j = minPos % C;
			currentMatrix[i][j] = 1;
		}
//		System.out.print("Minas: ");
//		for(int posicion : currentMinePositions)
//			System.out.print(posicion+" ");
//		System.out.println(" ");
		return foundAnother;
	}
	public void expandStartRecursive(int[][] matrix, int[] start){
		int i = start[0];
		int j = start[1];
		
		matrix[i][j] = 2;
		
		List<int[]> toExpandTo = new LinkedList<>();
		
		if(i>0){
			if(matrix[i-1][j] == 0)toExpandTo.add(new int[]{i-1,j});
			if(matrix[i-1][j] == 1)return;//no more expansion, mine arround
		}
		if(i>0 && j > 0){
			if(matrix[i-1][j-1] == 0)toExpandTo.add(new int[]{i-1,j-1});
			if(matrix[i-1][j-1] == 1)return;
		}
		if(i>0 && (j+1) < C){
			if(matrix[i-1][j+1] == 0)toExpandTo.add(new int[]{i-1,j+1});
			if(matrix[i-1][j+1] == 1)return;
		}
		if((i+1)<R){
			if(matrix[i+1][j] == 0)toExpandTo.add(new int[]{i+1,j});
			if(matrix[i+1][j] == 1)return;
			
		}
		if((i+1)<R && j > 0){
			if(matrix[i+1][j-1] == 0)toExpandTo.add(new int[]{i+1,j-1});
			if(matrix[i+1][j-1] == 1)return;
		}
		if((i+1)<R && (j+1) < C){
			if(matrix[i+1][j+1] == 0)toExpandTo.add(new int[]{i+1,j+1});
			if(matrix[i+1][j+1] == 1)return;
		}
		if(j>0){
			if(matrix[i][j-1] == 0)toExpandTo.add(new int[]{i,j-1});
			if(matrix[i][j-1] == 1)return;
		}
		if((j+1) < C){
			if(matrix[i][j+1] == 0)toExpandTo.add(new int[]{i,j+1});
			if(matrix[i][j+1] == 1)return;
		}
		for(int[] pointToExpand:toExpandTo)
			this.expandStartRecursive(matrix, pointToExpand);
	}
	public int[] findStartForSolution(){
		for(int i = 0;i<R;i++){
			for(int j = 0;j<C;j++){
				if(currentMatrix[i][j] == 0){
					if(i>0 && currentMatrix[i-1][j] == 1)continue;//no good for start
					if(i>0 && j > 0 && currentMatrix[i-1][j-1] == 1)continue;//no good for start
					if(i>0 && (j+1) < C && currentMatrix[i-1][j+1] == 1)continue;//no good for start
					if((i+1)<R && currentMatrix[i+1][j] == 1)continue;//no good for start
					if((i+1)<R && j > 0 && currentMatrix[i+1][j-1] == 1)continue;//no good for start
					if((i+1)<R && (j+1) < C && currentMatrix[i+1][j+1] == 1)continue;//no good for start
					if(j>0 && currentMatrix[i][j-1] == 1)continue;//no good for start
					if((j+1) < C && currentMatrix[i][j+1] == 1)continue;//no good for start
					return new int[]{i,j};
				}
			}
		}
		return null;
	}
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("input_minesweeper.txt"));
		int nTest = Integer.parseInt(bf.readLine());
		for(int t = 1;t<=nTest;t++){
			String[] line = bf.readLine().split(" ");
			int R = Integer.parseInt(line[0]); //ROW
			int C = Integer.parseInt(line[1]); //COL
			int M = Integer.parseInt(line[2]); //MINES
			MineSweeper mine = new MineSweeper(R, C, M);
			boolean solutionFound = true;
			while(!mine.checkForSolution()){
				if(!mine.increment()){
					solutionFound = false;
					break;
				}
			}
			System.out.println("Case #"+t+":");
			if(!solutionFound)
				System.out.println("Impossible");
			else{
				for(int i = 0;i<R;i++){
					for(int j = 0;j<C;j++){
						if(mine.cstart[0] == i && mine.cstart[1] == j)
							System.out.print("c");
						else if(mine.currentMatrix[i][j] == 1)
							System.out.print("*");
						else if(mine.currentMatrix[i][j] == 0)
							System.out.print(".");
					}
					System.out.println("");
				}
			}
		}
		bf.close();
	}
}
