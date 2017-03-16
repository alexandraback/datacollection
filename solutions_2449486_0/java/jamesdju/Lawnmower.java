import java.util.*;

class Lawnmower{

	public static int[][] lawn;
	public static int[] maxRow;
	public static int row, col;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		int counter = 1;

		while(tc-- > 0){
			row = sc.nextInt();
			col = sc.nextInt();
			lawn = new int[row][col];
			maxRow = new int[row];

			int max = 0;
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					lawn[i][j] = sc.nextInt();
					if(lawn[i][j] > max){
						max = lawn[i][j];
					}
				}
				maxRow[i] = max;
				max = 0;
			}

			if(isPossible()){
				System.out.println("Case #" + (counter++) + ": YES");
			} else{
				System.out.println("Case #" + (counter++) + ": NO");
			}
		}
	}

	public static boolean isPossible(){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(lawn[i][j] < maxRow[i]){
					for(int k = 0; k < row; k++){
						if(lawn[k][j] > lawn[i][j]){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
}