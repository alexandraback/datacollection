import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.Scanner;

public class EjercicioC {
	public static boolean prueba = false;

	public static void main(String args[]) throws Exception {
		OutputStream os = System.out;
		if (!prueba) {
			FileOutputStream fos = new FileOutputStream(
					new File("solucion.txt"));
			os = fos;
		}		
		Scanner s = new Scanner(new File("problema.txt"));
		int a = s.nextInt();
		for (int i = 0; i < a; i++) {
			int n = s.nextInt();
			int m = s.nextInt();
			Nodop boxes[] = new Nodop[n+1];
			Nodop toys[] = new Nodop[m+1];
			boxes[n] = new Nodop(0, 0);
			toys[m] = new Nodop(0, 0);
			for (int j=0; j<n;j++){
				boxes[j] = new Nodop(s.nextLong(), s.nextLong());
			}
			for (int j=0; j<m;j++){
				toys[j] = new Nodop(s.nextLong(), s.nextLong());
			}
			int mat[][] = new int[n+1][m+1];
			Nodop matBoxes[][][] = new Nodop[n+1][m+1][n];
			Nodop matToys[][][] = new Nodop[n+1][m+1][m];
			for (int j=0;j<n+1;j++){
				for (int k=0;k<m+1;k++){
					if (j==0 && k==0){
						mat[j][k] = 0;
						for (int p=0; p<n;p++){
							matBoxes[j][k][p] = new Nodop(boxes[p].cantidad, boxes[p].tipo);
						}
						for (int p=0; p<m;p++){
							matToys[j][k][p] = new Nodop(toys[p].cantidad, toys[p].tipo);
						}
						if (boxes[j].getTipo() == toys[k].getTipo()){
							mat[j][k] += Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matBoxes[j][k][j].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matToys[j][k][k].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
						}
					
					} else if (j==0){
						mat[j][k] = mat[j][k-1];						
						for (int p=0; p<n;p++){
							matBoxes[j][k][p] = new Nodop(matBoxes[j][k-1][p].cantidad, matBoxes[j][k-1][p].tipo);
						}
						for (int p=0; p<m;p++){
							matToys[j][k][p] = new Nodop(matToys[j][k-1][p].cantidad, matToys[j][k-1][p].tipo);
						}
						if (boxes[j].getTipo() == toys[k].getTipo()){
							mat[j][k] += Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matBoxes[j][k][j].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matToys[j][k][k].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
						}
						
					} else if (k==0){
						mat[j][k] = mat[j-1][k];						
						for (int p=0; p<n;p++){
							matBoxes[j][k][p] = new Nodop(matBoxes[j-1][k][p].cantidad, matBoxes[j-1][k][p].tipo);
						}
						for (int p=0; p<m;p++){
							matToys[j][k][p] = new Nodop(matToys[j-1][k][p].cantidad, matToys[j-1][k][p].tipo);
						}
						if (boxes[j].getTipo() == toys[k].getTipo()){
							mat[j][k] += Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matBoxes[j][k][j].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							matToys[j][k][k].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
						}
						
					} else{
						
						mat[j][k] = Math.max(mat[j-1][k], mat[j][k-1]);
						if (mat[j-1][k] > mat[j][k-1]){
							for (int p=0; p<n;p++){
								matBoxes[j][k][p] = new Nodop(matBoxes[j-1][k][p].cantidad, matBoxes[j-1][k][p].tipo);
							}
							for (int p=0; p<m;p++){
								matToys[j][k][p] = new Nodop(matToys[j-1][k][p].cantidad, matToys[j-1][k][p].tipo);
							}
							if (boxes[j].getTipo() == toys[k].getTipo() &&  j < n && k<m){
								mat[j][k] += Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
								matBoxes[j][k][j].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
								matToys[j][k][k].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							}
						}
						else{
							for (int p=0; p<n;p++){
								matBoxes[j][k][p] = new Nodop(matBoxes[j][k-1][p].cantidad, matBoxes[j][k-1][p].tipo);
							}
							for (int p=0; p<m;p++){
								matToys[j][k][p] = new Nodop(matToys[j][k-1][p].cantidad, matToys[j][k-1][p].tipo);
							}
							if (boxes[j].getTipo() == toys[k].getTipo() &&  j < n && k<m){
								mat[j][k] += Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
								matBoxes[j][k][j].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
								matToys[j][k][k].cantidad -= Math.min(matBoxes[j][k][j].getCantidad(), matToys[j][k][k].cantidad);
							}
						}
						
					}
					//System.out.print(mat[j][k] + " ");
				}
				//System.out.println();
			}
			os.write(("Case #" + (i + 1) + ": " + mat[n][m] + "\n").getBytes());
		}
	}

}

//boxes[j].cantidad -= Math.min(boxes[j].getCantidad(), toys[k].cantidad);
//toys[k].cantidad -=Math.min(boxes[j].getCantidad(), toys[k].cantidad);
class Nodop{
	long tipo;
	long cantidad;
	
	public long getTipo() {
		return tipo;
	}

	public void setTipo(long tipo) {
		this.tipo = tipo;
	}

	public long getCantidad() {
		return cantidad;
	}

	public void setCantidad(long cantidad) {
		this.cantidad = cantidad;
	}

	public Nodop(long cantidad, long tipo) {
		super();
		this.tipo = tipo;
		this.cantidad = cantidad;
	}
	
}