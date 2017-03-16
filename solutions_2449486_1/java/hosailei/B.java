import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class B {
	
	static int [][] _grid;
	static int [][] _workingCopy;
	static boolean [][] _processed;
	static int N;
	static int M;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcases = Integer.parseInt(br.readLine());
		
		cases:
		for(int i =1; i<=testcases; i++){
			
			String[] size =  br.readLine().split(" ");
			N = Integer.parseInt(size[0]);
			M = Integer.parseInt(size[1]);
			
			if(N==1 || M==1) {
				System.out.format("Case #%d: YES\n", i);
				for(int z =0; z<N; z++)
					br.readLine();
				continue cases;
			}
			
			// Build the pattern
			_processed = new boolean[N][M];
			_grid = new int[N][M];
			for(int row = 0; row<N; row++){
				String[] rowVal = br.readLine().split(" ");
				for(int col = 0; col<M; col++){
					_grid[row][col] = Integer.parseInt(rowVal[col]);
				}
			}
			
			
			while(!done()){
				int[] min = findMin();
				boolean colValid = checkCol(_grid[min[1]][min[0]], min[0]);
				boolean rowValid = checkRow(_grid[min[1]][min[0]], min[1]);
				if(!colValid && !rowValid){ 
					System.out.format("Case #%d: NO\n", i);
					continue cases;
				} 
				if(colValid){
					for(int c = 0; c<N; c++)
						_processed[c][min[0]] = true;
				}
				if(rowValid){
					for(int r = 0; r<M; r++)
						_processed[min[1]][r] = true;
				}
			}
			System.out.format("Case #%d: YES\n", i);
			
		}

	}
	
	static boolean done() {
		for(boolean[] row:_processed){
			for(boolean e: row ){
				if(!e) return false;
			}
		}
		return true;
		
	}
	static boolean checkRow(int val, int row){
		for(int i=0; i<M; i++){
			if(_grid[row][i] <= val) continue;
			return false;
		}
		return true;
	}
	
	static boolean checkCol(int val, int col){
		for(int i=0; i<N; i++){
			//System.out.println(i);
			if(_grid[i][col] <= val) continue;
			return false;
		}
		return true;
	}
	

	static int[] findMin() {
		int[] minMN = new int[2];
		int min = Integer.MAX_VALUE;
		
		for(int n = 0; n<N; n++){
			for(int m=0; m<M; m++){
				if(!_processed[n][m]){
					if(_grid[n][m] < min){
						min = _grid[n][m];
						minMN[0] = m;
						minMN[1] = n;
					}
				}
			}
		}
		return minMN;
	}
	
}
