import java.io.File;

import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

class Found extends Exception{
	
}

public class partilsum {
	
	static LinkedList<Integer> a,b;
	static int suma,sumb;
	
	public static boolean find(int[] tab, int index) throws Found{
		if(suma==sumb && !egaux(a,b)){
			//System.out.println("yooooo");
			throw new Found();
		}
		if(index >=tab.length){
			return false;
		}
		//System.out.println(index);
		a.add(tab[index]);
		suma+=tab[index];
		boolean sortie =find(tab, index+1);
		
		b.add(tab[index]);
		sumb+=tab[index];
		sortie = sortie ||find(tab, index+1);
		
		a.removeLast();
		suma-=tab[index];
		sortie = sortie ||find(tab, index+1);
		
		b.removeLast();
		sumb-=tab[index];
		sortie = sortie ||find(tab, index+1);
		
		return false;
	}

	private static boolean egaux(LinkedList<Integer> a2, LinkedList<Integer> b2) {
		return a2.equals(b2);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("C-small-attempt0.in"));
		int n = s.nextInt();
		for (int i = 0; i < n; i++) {
			int[] values = new int[20];
			int nbval = s.nextInt();
			for(int j=0; j<nbval; j++){
				values[j] = s.nextInt();
			}
			a = new LinkedList<Integer>();
			b = new LinkedList<Integer>();
			suma=0;
			sumb=0;
			System.out.println("Case #"+(i+1)+":");
			try{
				find(values, 0);
			}
			catch (Found e) {
				for(int v: a){
					System.out.print(v+" ");
				}
				System.out.println();
				for(int v: b){
					System.out.print(v+" ");
				}
				System.out.println("");
				continue;
			}
			System.out.println("Impossible");
		}

	}
}
