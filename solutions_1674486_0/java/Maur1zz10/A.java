import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class A {
	static final String filename = "A";

	public static void main(String[] args) throws IOException {
		String finput = filename+".in";
		String foutput = filename+".out";
		Scanner s = new Scanner(new FileInputStream(finput));
		Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
		A solver = new A();
		solver.solve(s, w);
		w.close();
	}

	void solve(Scanner s, Writer w) throws IOException {
		int T = s.nextInt();
		for (int t = 0; t < T; t++) {
			int N=s.nextInt();
			Map<Integer, List<Integer>>map=new HashMap<Integer, List<Integer>>();
			for(int i=1;i<=N;i++){
				List<Integer>list=new ArrayList();
				int M=s.nextInt();
				for(int m=0;m<M;m++){
					list.add(s.nextInt());
				}
				map.put(i,list);
			}
			
			System.out.println(map);
			String r=solve(map);
			
			w.write("Case #" + (t + 1) + ": ");
			w.write(r);

			String nlsymbol = System.getProperty("line.separator");
			w.write(nlsymbol);
		}

	}
	
	String solve(Map<Integer, List<Integer>>map){
		for(int k:map.keySet()){
			Set<Integer>set=new HashSet<Integer>();
			Queue<Integer>q=new LinkedList<Integer>();
			q.offer(k);
			while(!q.isEmpty()){
				int x=q.poll();
				//System.out.println(x+"|"+q+"|"+set);
				if(set.contains(x)){
					//System.out.println(x+"|");
					return "Yes";
				}
				set.add(x);
				List<Integer>list=map.get(x);
				for(int z:list)
					q.offer(z);
			}
		}
		return "No";
	}
}
