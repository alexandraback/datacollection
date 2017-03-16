import java.util.*;
import java.io.*;

class Node implements Comparable{
	int x, y;
	public Node(){}
	public Node(int a, int b){
		x = a; y = b;
	}
	public boolean equals(Object key){
		Node tmp = (Node)key;
		if(x==tmp.x && y==tmp.y)  return  true;
		else  return  false;
	}
	public int compareTo(Object key){
		Node tmp = (Node)key;
		if(x == tmp.x)  return  y-tmp.y;
		else  return  x-tmp.x;
	}
}

public class C{
	Set hash = new TreeSet<Node>();
	void Cal(int A, int B, int n, PrintWriter cout){
		int ct = 0;
		String sn = Integer.valueOf(n).toString();
		for(int i = 1; i < sn.length(); i++){
			String sm = sn.substring(i) + sn.substring(0, i);
			int m = Integer.parseInt(sm);
			Node tmp = new Node(n, m);
			if(m>n && m<=B && !hash.contains(tmp))
				hash.add(tmp);
			//System.out.println(hash.size());
		}
	}
	void solve() throws FileNotFoundException{
		File fin = new File("data.in");
		File fout = new File("data.out");
		Scanner cin = new Scanner(fin);
		PrintWriter cout = new PrintWriter(fout);
		
		int T, A, B;
		T = cin.nextInt();
		for(int k = 1; k <= T; k++){
			A = cin.nextInt(); B = cin.nextInt();
			hash.clear();
			for(int i = A; i < B; i++)
				Cal(A, B, i, cout);
			cout.printf("Case #%d: %d\n", k, hash.size());
		}
		
		cout.flush();
	}
	public static void main(String [] args) throws Exception{
		C test = new C();
		test.solve();
	}
}












