
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
/**
 * @author Kate Henderson
 *
 */
public class Enclosure {

	private Scanner sc = null;
	private BufferedWriter bw = null;	
	private File inFile;
	private File outFile;
	private int cases;

	private boolean[][] game;
	private int rows;
	private int cols;
	private int K;
	private int min;



	public Enclosure(){
		inFile = new File("C-small-attempt0.in");
		outFile = new File("C-small-attempt0.out");
	}

	public static void main(String[] args) {
		Enclosure p = new Enclosure(); 
		p.solve();	
	}

	private void solve(){		
		try {
			sc = new Scanner(new FileReader(inFile));
			bw = new BufferedWriter(new FileWriter(outFile));

			cases = sc.nextInt();

			for (int c = 1; c <= cases; c++) {
				StringBuilder sb = new StringBuilder();
				rows = sc.nextInt();
				cols = sc.nextInt();
				K = sc.nextInt();
				game = new boolean[cols][rows];
				int space = rows*cols;
				/*for (int y = 0; y<rows; y++){
					for (int x = 0; x<cols; x++){
						game[x][y];
					}
				}*/
				if((space-4)==K)
					sb.append("Case #" + c + ": "+((rows*2)+(cols*2)-8)+"\n");
				else if (rows<=2||cols<=2){
					sb.append("Case #" + c + ": "+K+"\n");
				}else{
					int small = Math.min(rows, cols);
					if (K%2==0){
						min = K/2+2;
					}else{
						int cur = (int)K-((K+1)/3 *2);
						min = ((K+1)/3 *2)+cur;
					}				
					sb.append("Case #" + c + ": "+min+"\n");
				}
				try {
					bw.write(sb.toString());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			bw.flush();
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
