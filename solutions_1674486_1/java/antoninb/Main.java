package A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class Main {
	
	public static boolean rec(int c, Classe[] classes, boolean begin, int from){
		if(classes[c].visited)
			return true;
		
		classes[c].visited = true;
		
		for(int c1: classes[c].inherits){
			if(c1 != from && rec(c1, classes, false, c))
				return true;
		}
		
		return false;
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String fileName = args[0];
		String fileName = "A-large.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		int N;
		Classe[] classes;
		String res;
		
		for(int i = 0; i < T; i++){
			N = sC.nextInt();
			classes = new Classe[N];
			res = "No";
			
			for(int j = 0; j < N; j++){
				classes[j] = new Classe();
			}
			
			for(int j = 0; j < N; j++){
				int M = sC.nextInt();
				for(int k = 0; k < M; k++){
					int c = sC.nextInt();
					//System.out.println(c);
					classes[j].add(c - 1);
					//classes[c - 1].add(j);
				}
			}
			
			for(int j = 0; j < N; j++){
				for(int k = 0; k < N; k++){
					classes[k].visited = false;
				}
				if(rec(j, classes, true, j))
					res = "Yes";
			}
			
			System.out.println("Case #" + (i + 1) + ": " + res);
		}

	}

}

class Classe{
	HashSet<Integer> inherits;
	boolean visited;
	
	public Classe(){
		inherits = new HashSet<Integer>();
	}
	
	public void add(int n){
		inherits.add(n);
	}

}
