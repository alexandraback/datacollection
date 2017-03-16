import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;


public class primo {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("/home/sharkk/Desktop/jam/A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/sharkk/Desktop/jam/out")));
		String l;
		l=in.readLine();
		int idx=0;
		HashMap<String, HashSet<String>> adj = new HashMap<String, HashSet<String>>();
		while((l=in.readLine())!=null)
		{
			idx++;
			int N = Integer.parseInt(l);
			for(int i=1;i<=N;i++)
			{
				l=in.readLine();
				String[] ll = l.split(" ");
				HashSet<String> a = adj.get(i);
				if(a==null)
				{
					a = new HashSet<String>();
					adj.put(i+"",a);
				}
				for(int j = 1; j<ll.length;j++)
					a.add(ll[j]);
			}
			out.print("Case #"+idx+": ");
			boolean ck=false;
			
			for(int i=1;i<=N;i++)
			{
				HashSet<String> visitati = new HashSet<String>();
				ArrayList<String> stack = new ArrayList<String>();
				stack.add(0, i+"");
				while(stack.size()!=0)
				{
					String pop = stack.get(0); stack.remove(0);
					if(!visitati.add(pop))
					{
						ck = true;
						break;
					}
					for(String s : adj.get(pop))
						stack.add(0,s);
				}
			}
			
			
			if(ck) out.println("Yes");
			else out.println("No");
		}
		out.close();
	}

}