import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class B {


	public static void main(String[] args) {
		try{
			Scanner in = new Scanner(new File("B.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("B.out"));
			
			int T = in.nextInt();
			for (int nCase = 1; nCase <=T; nCase++) {
				
				int N = in.nextInt();
				int M = in.nextInt();
				int[][] lawn = new int[N+1][M+1];
				for (int i =0; i < N; i++){					
					for(int j=0; j<M; j++){
						lawn[i][j] = in.nextInt();
						if (lawn[i][j]>lawn[i][M])
							lawn[i][M]=lawn[i][j];
						if (lawn[i][j]>lawn[N][j])
							lawn[N][j]=lawn[i][j];						
					}					
				}
				boolean result = true;
				search:					
				for (int i = 0; i <N; i++){
					for(int j =0; j<M; j++){
						if ((lawn[i][j]<lawn[i][M]) && (lawn[i][j]<lawn[N][j])){
							result = false;
							break search;
						}								
					}
				}
				
				if(result)
					out.write("Case #"+nCase+": YES");				
				else
					out.write("Case #"+nCase+": NO");
				out.newLine();
			}
			
			
			
			in.close();
			out.close();
		}
		catch(Exception e){
			System.out.println(e.toString());			
		}

	}

}
