import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class EjercicioB {
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
				int x = s.nextInt();
				int y = s.nextInt();				
				Set<Posicion> posiciones = new HashSet<Posicion>();
				String sol = null;
				int val = 1;
				posiciones.add(new Posicion("",0,0));				
				while (sol == null){
					Set<Posicion> posiciones2 = new HashSet<Posicion>();
					for (Posicion p : posiciones){
						Posicion h = new Posicion(p.sol + "N",p.x,p.y + val);
						if (h.x == x && h.y == y){
							sol = h.sol;
							break;
						}
						posiciones2.add(h);
						h = new Posicion(p.sol + "S",p.x,p.y - val);
						if (h.x == x && h.y == y){
							sol = h.sol;
							break;
						}
						posiciones2.add(h);
						h = new Posicion(p.sol + "E",p.x + val,p.y);
						if (h.x == x && h.y == y){
							sol = h.sol;
							break;
						}
						posiciones2.add(h);
						h = new Posicion(p.sol + "W",p.x - val,p.y);
						if (h.x == x && h.y == y){
							sol = h.sol;
							break;
						}
						posiciones2.add(h);
					}
					posiciones = posiciones2;
					val++;
				}
				os.write(("Case #" + (i + 1) + ": " + sol + "\n").getBytes());

			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	
	}

 class Posicion {
	public String sol = "";
	public int x;
	public int y;
	
	
	

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Posicion other = (Posicion) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

	public Posicion(String sol, int x, int y) {
		super();
		this.sol = sol;
		this.x = x;
		this.y = y;
	}

	public boolean equals(Posicion p ){
		return (p.x == this.x) && p.y == this.y; 
	}

	
}
