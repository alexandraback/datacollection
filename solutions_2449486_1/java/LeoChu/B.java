import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;


public class B {
	Scanner scanner = new Scanner(System.in);
		
	//row, column
	int[][] height;
	int tRow;
	int tCol;
	int line = 1;
	boolean debug = false;
	
	void read() {
		tRow = scanner.nextInt();
		tCol = scanner.nextInt();
		if(debug){
			System.out.println(tRow+","+tCol);
		}
		line+=1;	
		if(debug){
			System.out.println("line: "+line);
		}
		line+=tRow;
		height = new int[tRow][tCol];
		for(int row = 0; row < tRow ; row++){
			for(int col=0; col< tCol; col++){
				height[row][col] = scanner.nextInt();
				if(debug){
					int debugHeight = height[row][col];
					if(debugHeight > 1){
						System.out.print("# ");
					}else{
						System.out.print(". ");
					}
					//System.out.print(debugHeight+" ");
					
				}
			}
			if(debug){
				System.out.println();
			}
		}
		return;
	}
	
	void solve() {
		for(int row=0; row<tRow; row++){
			if(debug){
				System.out.println();
				System.out.println("row="+row);
			}
			if (!isRowValid(row)){
				System.out.print("NO");
				return;
			}
		}
		System.out.print("YES");
	}
	
	boolean isRowValid(int row){
		int maxHeight = 0;
		
		for(int col=0; col<tCol; col++){
			maxHeight = Math.max(height[row][col],maxHeight);
		}
		
		for(int col=0; col<tCol; col++){
			int colHeight = height[row][col];
			if(colHeight < maxHeight){
				if (!isColumnValid(col, colHeight)){
					return false;
				}
			}
		}
		
		return true;
	}
	
	boolean isColumnValid(int col, int minHeight){
		if(debug){
			System.out.println("check column "+col+" <= "+minHeight);
		}
		for(int row=0;row<tRow;row++){
			if(height[row][col] > minHeight){
				if(debug){
					System.out.println(row+","+col+" invalid");
				}
				return false;
			}
		}		
		return true;
	}
	
	void run() {
		int caseN = scanner.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {			
			System.out.printf("Case #%d: ", caseID);
			read();
			solve();
			System.out.println();
			if(debug){
				System.out.println("==================================");
			}
			System.out.flush();
		}
	}
	

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : ("B-large.in"))));
			//System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : ("B-sample.in"))));			
		} catch (Exception e) {
			e.printStackTrace();
		}
		new B().run();
	}
}
