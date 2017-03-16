package Round1C;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem1 {
	
	public static void main(String[] args) throws Exception {
		long inicio = System.currentTimeMillis();
		File f = new File("C:\\Users\\Reik Val\\Desktop\\A-small-attempt0.in");
		Scanner sc = new Scanner(f);
		FileWriter salida =  new FileWriter("C:\\Users\\Reik Val\\Desktop\\salida.txt");
        PrintWriter pw = new PrintWriter(salida);
		int registros = sc.nextInt();
		for(int k = 1; k <= registros; k++) {
			String nom = sc.next();
			int n = sc.nextInt();
			Pattern p = Pattern.compile("[a-z&&[^aeiou]]{"+n+"}");
			Matcher m = p.matcher(nom);
			long total = 0;
			int start = 0;
			while(m.find(start)) {
				int st = start;
				start =  m.start()+1;
				int end = m.end();
				int x = nom.substring(st,start).length();
				int y = nom.substring(end).length()+1;
				total += x*y;
			}
			System.out.println("Case #"+k+": " + total);
		}
		System.out.println("Fin del programa: " + ((float)(System.currentTimeMillis() - inicio)/1000f) + " secs.");
	}

}
