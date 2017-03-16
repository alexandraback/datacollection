import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		String fileName = "B-small-attempt0";
		BufferedReader br = new BufferedReader(new FileReader(fileName + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));
		int t = Integer.valueOf(br.readLine());
		for (int i=1; i<=t; i++){
			String dim = br.readLine();
			Scanner scanner = new Scanner(dim);
			int n,m;
			n = scanner.nextInt();
			m = scanner.nextInt();
			int grid[][]= new int [n][m];
			boolean posible[][] = new boolean[n][m];
			String row;
			for (int j=0; j<n;j++){
				row = br.readLine();
				scanner = new Scanner(row);
				for (int k=0; k<m; k++){
					grid[j][k] = scanner.nextInt();
					posible[j][k] = true;
				}
			}
			//podado horizontal
			for (int j=0; j<n; j++){
				for (int k=0; k<m; k++){
					//atras
					for (int l=k-1; l>=0; l--){
						if (grid[j][k]<grid[j][l]){
							posible[j][k] = false;
						}
					}
					//adelante
					if(posible[j][k]){
						for (int l=k+1; l<m; l++){
							if (grid[j][k]<grid[j][l]){
								posible[j][k] = false;
							}
						}
					}
				}
			}
			// podado vertical
			for (int j=0; j<m; j++){
				for (int k=0; k<n; k++){
					if (!posible[k][j]){
						//arriba
						boolean cambio = true;
						for (int l=k-1; l>=0; l--){
							if (grid[k][j]<grid[l][j]){
								cambio = false;
								break;
							}
						}
						if (cambio){
							for (int l=k+1; l<n; l++){
								if (grid[k][j]<grid[l][j]){
									cambio = false;
									break;
								}
							}
						}
						if(cambio){
							posible[k][j] = true;
						}
					}
				}
			}
			//comprobacion final
			boolean respuesta = true;
			for (int j=0; j<n;j++){
				for (int k=0; k<m; k++){
					if (!posible[j][k]){
						respuesta = false;
						break;
					}
				}
			}
			if (respuesta){
				bw.write("Case #"+i+": YES\n");
			}else{
				bw.write("Case #"+i+": NO\n");
			}
		}
		br.close();
		bw.close();
	}
}
