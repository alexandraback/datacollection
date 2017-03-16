import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Cell {
	int num;
	HashSet<Integer> predecesseurs;
	LinkedList<Integer> parents;
	
	Cell(int i) {
		num = i;
		predecesseurs = new HashSet<Integer>();
		parents = new LinkedList<Integer>();
	}
}

public class Main {
	public static boolean addNoIntersect(HashSet<Integer> a, HashSet<Integer> b) {
		for(Iterator<Integer> i = a.iterator(); i.hasNext();) {
			int e = (int) i.next();
			if(b.contains(e))
				return true;
			else
				b.add(e);
		}
		return false;
	}
	
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		Case : for(int x=0; x<T; x++) {
			int N = in.nextInt();
			Cell[] tab = new Cell[N];
			Queue<Integer> racines = new LinkedList<Integer>();
			in.nextLine();
			for(int i=0; i<N; i++) {
				tab[i] = new Cell(i+1);
			}
			for(int i=0; i<N; i++) {
				int M = in.nextInt();
				if(M==0)
					racines.add(i+1);
				else {
					for(int j=0; j<M; j++) {
						int v = in.nextInt();
						tab[i].parents.add(v);
					}
				}
			}
			
			System.out.print("Case #" + String.valueOf(x+1) + ": ");
			
			boolean[] viewed = new boolean[N];
			for(int i=0; i<N; i++) {
				Arrays.fill(viewed, false);
				Queue<Integer> todo = new LinkedList<Integer>();
				todo.add(i);
				while(!todo.isEmpty()) {
					int p = todo.poll();
					if(viewed[p]) {
						System.out.println("Yes");
						continue Case;
					}
					viewed[p] = true;
					for(Iterator<Integer> k = tab[p].parents.iterator(); k.hasNext();)
						todo.add(((int) k.next()) -1);
				}
			}
			/*
			while(! racines.isEmpty()) {
				int r = racines.poll();
				//System.out.println("Evaling " + String.valueOf(r));
				//HashSet<Integer> agregate = new HashSet<Integer>();
				if(tab[r-1].enfants != null) {
					for(Iterator<Integer> i = tab[r-1].enfants.iterator(); i.hasNext();) {
						int e = (int) i.next();
						if(addNoIntersect(tab[r-1].predecesseurs, tab[e-1].predecesseurs)) {
							System.out.println("Yes");
							continue Case;
						}
						else {
							tab[e-1].predecesseurs.add(r);
							racines.offer(e);
							//System.out.println("Added " + String.valueOf(e));
						}
					}
				}
			}*/
			System.out.println("No");
			
		}
	}
}