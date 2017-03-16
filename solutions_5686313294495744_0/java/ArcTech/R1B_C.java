import java.io.IOException;
import java.util.*;

public class R1B_C {

	public static void main(String[] args) throws IOException
	
	{
		InputReader in = new InputReader("C-small-attempt0.in");
		OutputWriter out = new OutputWriter("Csmall.txt");
		int cases = Integer.parseInt(in.getCur());	
		for (int num = 1; num <= cases; num++)
		{
			String outline = "";
			int topics = Integer.parseInt(in.getNext());
			List<String> L1 = new ArrayList<String>(); 
			List<String> L2 = new ArrayList<String>(); 
			List<String> C1 = new ArrayList<String>();
			List<String> C2 = new ArrayList<String>();
			for (int i = 0; i < topics; i++)
			{
				String info = in.getNext();
				int space = info.indexOf(' ');
				String w1 = info.substring(0, space);
				String w2 = info.substring(space+1);
				L1.add(w1);
				L2.add(w2);
				C1.add(w1);
				C2.add(w2);
			}
			int t = topics;
			for (int i = 0; i < t; i++)
			{
				String w1 = L1.get(i);
				String w2 = L2.get(i);
				C1.remove(i);
				C2.remove(i);
				if (C1.contains(w1) && C2.contains(w2))
				{
					L1.remove(i);
					L2.remove(i);
					i--;
					t--;
				}
				else
				{
					C1 = new ArrayList<String>();
					C1.addAll(L1);
					C2 = new ArrayList<String>();
					C2.addAll(L2);
				}	
			}
			
			outline += (topics-L1.size());
			
			
			if (num < cases)
				outline += "\n";
			out.writeCase(outline, num);
		}	
	out.close();
	}
}

		