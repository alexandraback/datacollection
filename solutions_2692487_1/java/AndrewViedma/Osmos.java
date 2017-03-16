package _2013.r1.a_osmos;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.LineNumberReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Osmos
{
	public static int numCambiosNecesarios (long tamMota, List<Integer> posiciones, int desde, int cambiosHechos)
	{
		// Fin
		if (desde >= posiciones.size()) {
			return cambiosHechos;
			
		} else {
			// Se intenta comer la siguiente
			int sig = posiciones.get (desde);
			if (tamMota > sig) {
				return numCambiosNecesarios (tamMota + sig, posiciones, desde+1, cambiosHechos);
				
			} else {
				int restantes = (posiciones.size() - desde);
				if (tamMota == 1) {
					return cambiosHechos + restantes;
					
				} else {
					// No se la puede comer, crea una nueva lo más grande posible que aumente el tamaño
					tamMota += (tamMota - 1);
					int posibleRes = numCambiosNecesarios (tamMota, posiciones, desde, cambiosHechos + 1);
					
					// Si acababa antes matando las que quedaban, lo hace en lugar de crear nuevas
					return Math.min (posibleRes, cambiosHechos + restantes);
				}
			}
		}
	}

	/**
	 * @param args
	 */
	public static void main( String[] args)
			throws Exception
	{
		long t0 = System.currentTimeMillis();
		String sIn = "src/_2013/r1/a_osmos/A-large.in";
		if (args.length > 0)  sIn = args[0];
		String sOut = sIn;
		if (sOut.endsWith (".in")) sOut = sOut.substring (0, sOut.length() - 3);
		sOut = sOut + ".out";
		
		LineNumberReader in = new LineNumberReader (new FileReader (sIn));
		PrintWriter out = new PrintWriter (new FileWriter (sOut));
	
		String linea0 = in.readLine();
		int numCasos = Integer.parseInt (linea0);
		
		for (int i=0; i<numCasos; i++) {
			System.out.println ("Case #" + (i+1));

			String s = in.readLine();
			String[] trozos = s.split (" ");
			int a = Integer.parseInt(trozos[0]);
			int n = Integer.parseInt(trozos[1]);
			
			List<Integer> l = new ArrayList<Integer>(n);
			
			s = in.readLine();
			trozos = s.split (" ");
			for (int k=0; k<n; k++) {
				l.add (Integer.parseInt (trozos[k]));
			}
			Collections.sort (l);
			int res = numCambiosNecesarios (a, l, 0, 0);
			
			out.println ("Case #" + (i+1) + ": " + res);
		}
		
		
		out.close();
		
		long t1 = System.currentTimeMillis();
		long seg = ((t1 - t0) / 1000);
		double mins = seg / 60d;
		
		System.out.println ("OK - " + mins + " minutos");
	}

}
