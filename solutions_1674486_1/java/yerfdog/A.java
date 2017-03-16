import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(new File("A-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));
		int t = scan.nextInt();
		outer:
		for (int i = 1; i <= t; i++) {
			int N = scan.nextInt();
			HashSet<Integer> leaves = new HashSet<Integer>();
			HashSet<Integer> nextLeaves = new HashSet<Integer>();
			Node[] nodes = new Node[N+1];
			for(int j = 1; j <= N; j++){
				leaves.add(j);
				nodes[j] = new Node();
			}
			for(int j = 1; j <= N; j++){
				int M = scan.nextInt();
				for(int k = 0; k < M; k++){
					int L = scan.nextInt();
					nodes[j].parents.add(L);
					nodes[L].children++;
					leaves.remove(L);
				}
			}
			while(!leaves.isEmpty()){
				for(Iterator<Integer> leaf = leaves.iterator(); leaf.hasNext();){
					int leafVal = leaf.next();
					for(Iterator<Integer> parent = nodes[leafVal].parents.iterator(); parent.hasNext();){
						int parVal = parent.next();
						Node par = nodes[parVal];
						for(Iterator<Integer> below = nodes[leafVal].below.iterator(); below.hasNext();){
							int belowVal = below.next();
							if(par.below.contains(belowVal)){
								out.write("Case #" + i + ": "+ "Yes" + "\n");
								continue outer;
							}
							par.below.add(belowVal);
						}
						par.below.add(leafVal);
						if(--par.children == 0){
							nextLeaves.add(parVal);
						}
					}
				}
				leaves = nextLeaves;
				nextLeaves = new HashSet<Integer>();
			}
			out.write("Case #" + i + ": "+ "No" + "\n");
		}
		out.close();
	}
}
class Node{
	int children;
	HashSet<Integer> below;
	HashSet<Integer> parents;
	public Node(){
		children = 0;
		below = new HashSet<Integer>();
		parents = new HashSet<Integer>();
	}
}
