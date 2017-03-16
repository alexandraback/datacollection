import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;


public class Main {
	public static String resolver(BufferedReader entrada) throws Exception {
		String linea = entrada.readLine();
		int num = Integer.parseInt(linea.trim());
		PriorityQueue<Tribe> queue = new PriorityQueue<Tribe>(1000);
		for(int i = 0; i < num; i++) {
			queue.add(new Tribe(entrada.readLine()));
		}
		
		int attacks = 0;
		Tribe next_tribe = null;
		
		
		ArrayList<Marked> wall = new ArrayList<Marked>();
		ArrayList<Marked> pending = new ArrayList<Marked>();
		
		System.out.println("iniciadop");
		long prev_day = -1;
		while((next_tribe = queue.poll()) != null) {
			long new_day = next_tribe.getDay();
			long str = next_tribe.getStrength();
			long ini_x = next_tribe.getIniX();
			long fin_x = next_tribe.getFinX();
			
			
			if(new_day > prev_day) {
				wall.addAll(pending);
				pending.clear();
			}
			
			PriorityQueue<Marked> observed = new PriorityQueue<Marked>();
			for(Marked m : wall) {
				if(m.str < str)
					continue;
				if(m.fin < ini_x)
					continue;
				if(m.ini > fin_x)
					continue;
				observed.add(m);
			}
			if(observed.isEmpty()) {
				attacks++;
			} else {
				Marked m = observed.poll();
				if(m.ini > ini_x) {
					attacks++;
				} else {
					long min = m.fin;
					while((m = observed.poll()) != null) {
						if(min >= fin_x) {
							break;
						}
						if(m.ini > min) {
							break;
						}
						if(m.fin > min)
							min = m.fin;
					}
					
					if(min < fin_x)
						attacks++;
				}
			}
			
			
			pending.add(new Marked(ini_x, fin_x, str));
			if(next_tribe.attack())
				queue.add(next_tribe);
			prev_day = new_day;
		}
		
		
		return Integer.toString(attacks);
	}
	
	public static void main(String[] args) throws Exception {
        System.out.println("?");
		BufferedReader lector = null;
		BufferedReader entrada = null;
		BufferedWriter salida = null;
		try {
			lector = new BufferedReader(new InputStreamReader(System.in));
			String tipo = lector.readLine().trim();
			entrada = new BufferedReader(new InputStreamReader(new FileInputStream(tipo + ".in")));
			salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(tipo + ".out")));
			int casos = Integer.parseInt(entrada.readLine());
			int contador = 1;
			while(casos > 0) {
				salida.write("Case #" + contador + ": " + resolver(entrada) + "\n");
				contador++;
				casos--;
			}
		} catch(Exception e) {
			e.printStackTrace();
		} finally {
			if(lector != null) {
				try {
					lector.close();
				} catch(Exception e) {}
			}
			if(entrada != null) {
				try {
					entrada.close();
				} catch(Exception e) {}
			}
			if(salida != null) {
				try {
					salida.close();
				} catch(Exception e) {}
			}
		}
        System.out.println("Fin");
    }
	
	
}
