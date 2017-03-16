import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static class Node{
		int id;
		int numvisited;
		ArrayList<Integer> path;
	}
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("Ain.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Aout.txt"));

		String in = fin.readLine();
		int tt = Integer.parseInt(in);

		int t = 1;

		while(t <= tt){
			in = fin.readLine();
			int n = Integer.parseInt(in);
			ArrayList<Node> nodes = new ArrayList<Node>();
			for(int i = 0; i < n; i++){
				in = fin.readLine();
				String[] sp = in.split(" ");
				Node node = new Node();
				node.id = i;
				ArrayList<Integer> path = new ArrayList<Integer>();
				for(int j = 1; j < sp.length; j++){
					path.add(Integer.parseInt(sp[j])-1);
				}
				node.path = path;
				nodes.add(node);
			}
			
			boolean diamond = false;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					nodes.get(j).numvisited = 0;
				}
				ArrayList<Node> tovisit = new ArrayList<Node>();
				tovisit.add(nodes.get(i));
				while(tovisit.size() > 0){
					Node node = tovisit.remove(0);
					node.numvisited++;
					for(int j = 0; j < node.path.size(); j++){
						tovisit.add(nodes.get(node.path.get(j)));
					}
				}
				for(int j = 0; j < n; j++){
					if(nodes.get(j).numvisited >= 2)
						diamond = true;
				}
			}
					

			String res = "No";
			if(diamond)
				res = "Yes";


			fout.println("Case #" + t + ": " + res);
			fout.flush();
			t++;
		}
	}
}