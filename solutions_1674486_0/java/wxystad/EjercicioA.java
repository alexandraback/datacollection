import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class EjercicioA {
	public static boolean prueba = false;


	public static void main(String args[]) {

		try {
			FileOutputStream fos = new FileOutputStream(
					new File("solucion.txt"));

			OutputStream os = System.out;
			if (!prueba)
				os = fos;
			Scanner s = new Scanner(new File("problema.txt"));
			int a = s.nextInt();
			
			for (int i = 0; i < a; i++) {
				int cant = s.nextInt();				
				Nodo nodo[] = new Nodo[cant+1];
				
				for (int j = 0; j < cant; j++) {
					if (nodo[j+1] == null)
						nodo[j+1] = new Nodo(j+1);
					int c = s.nextInt();
					for (int k=0; k<c;k++){
						int b = s.nextInt();
						if (nodo[b] == null)
							nodo[b] = new Nodo(b);
						nodo[j+1].getPadres().add(nodo[b]);
					}					
				}
				boolean opa = false;
				for (int j = 1; j < cant+1; j++) {
					
					System.out.println(nodo[j].calcularAdyacentes());
				}
				for (int j = 1; j < cant+1; j++) {
					if (nodo[j].isEs()){
						opa = true;
						break;
					}
					
				}
				if (opa)
					os.write(("Case #" + (i + 1) + ": Yes\n").getBytes());
				else
				os.write(("Case #" + (i + 1) + ": No\n").getBytes());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}


}

class Nodo{
	private int valor;
	private List<Nodo> padres;
	private List<Nodo> adyacentes;
	private boolean es = false;
	
	public Nodo(int valor) {
		super();
		this.valor = valor;
		padres = new ArrayList<Nodo>();
		adyacentes = null;
	}
	public List<Nodo> calcularAdyacentes() {
		if (adyacentes == null){
			adyacentes = new ArrayList<Nodo>();
			for (Nodo n : padres){
				if (adyacentes.contains(n)){
					es =true;
					return adyacentes;
				}
				adyacentes.add(n);
				for (Nodo ady: n.calcularAdyacentes()){
					if (adyacentes.contains(ady)){
						es =true;
						return adyacentes;
					}
					adyacentes.add(ady);
				}
			}
		}
		return adyacentes;
		
	}
	public boolean isEs() {
		return es;
	}
	public void setEs(boolean es) {
		this.es = es;
	}
	public int getValor() {
		return valor;
	}
	public void setValor(int valor) {
		this.valor = valor;
	}
	public List<Nodo> getPadres() {
		return padres;
	}
	public void setPadres(List<Nodo> padres) {
		this.padres = padres;
	}
	
}