import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Lawnmower {

	private static int[][] matrix = new int[100][100];
	
	public static void main(String[] args) {
		
		int i, j, n, m, T;
		String line;
		String[] tokens;
		
		try {
			
			File fileOut = new File("C:/Users/Robi/Desktop/CodeJam/lawno.txt");
			File fileIn = new File("C:/Users/Robi/Desktop/CodeJam/lawni.txt");
			
			
			BufferedReader br = new BufferedReader(new FileReader(fileIn.getAbsoluteFile()));
			BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut.getAbsoluteFile()));
 
			// if file doesn't exists, then create it
			if (!fileOut.exists()) {
				fileOut.createNewFile();
		}
			
			
			
		T = Integer.parseInt(br.readLine());
			
		for(i = 0; i < T; i++){
			line = br.readLine();
			tokens = line.split(" ");
			
			n = Integer.parseInt(tokens[0]);
			m = Integer.parseInt(tokens[1]);
			
			getMatrix(matrix, br, n,m);
			
			if(checkMatrix(matrix,n,m)) {
				bw.write("Case #"+Integer.toString(i+1)+": YES");
				bw.newLine();
			}else {
				bw.write("Case #"+Integer.toString(i+1)+": NO");
				bw.newLine();
			}
		}
			
			
		bw.close();
		br.close();
 
		System.out.println("Done");
 
		} catch (IOException e){ 
			e.printStackTrace();
		}
		
	}
	
	private static void getMatrix(int[][] matrix, BufferedReader in, int n, int m) throws IOException{
		int i,j;
		String s;
		String[] tokens;
		
		for(i = 0; i < n; i++){
			
			s = in.readLine();
			tokens = s.split(" ");
			
			for(j = 0; j < m; j++){
				matrix[i][j] = Integer.parseInt(tokens[j]);	
			}
			
		}
	}
	
	private static boolean checkMatrix(int[][] matrix, int n, int m){
		boolean ok = true;
		int i,j,k;
		
		//for every point
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				boolean top=false,left=false,right=false,bot=false;
				
				for(k = 0; k < n; k++)
					if(matrix[k][j] > matrix[i][j]){
						if(k > i)
							bot = true;
						else
							top = true;
					}
					
				for(k = 0; k < m; k++)
					if(matrix[i][k] > matrix[i][j]){
						if(k > j)
							right = true;
						else
							left = true;
					}
				if((bot&&right) || (bot&&left) || (top&&right) || (top&&left))
					return false;
			}
		}
		return ok;
	}
}
