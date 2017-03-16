
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;



public class DiamondInheritance {
	static class T {
		public int index;
		public ArrayList<Integer> list;
		public T(int index) {
			this.index = index;
			this.list = new ArrayList<Integer>();
		}
	}
	static HashSet<String> set;
	static T[] t;
	static Queue<String> q;
	public static void main(String[] args) throws IOException 
	{
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("DiamondInheritance.txt"));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=1; i <= cases; i++)
		{
			q = new LinkedList<String>();
			set = new HashSet<String>();
			int counter = Integer.parseInt(reader.readLine());
			t = new T[counter];
			for(int j = 0; j < counter; j++) {
				t[j] = new T(j);
				String s = reader.readLine();
				String[] data = s.split(" ");
				for(int k=1; k<data.length; k++) {
					t[j].list.add(Integer.parseInt(data[k])-1);
					q.add(j + " " + (Integer.parseInt(data[k])-1));
					set.add(j + " " + (Integer.parseInt(data[k])-1));
				}

			}
			boolean found = false;
			while(!q.isEmpty()) {
				String s = q.poll();
				String[] data = s.split(" ");
				int first = Integer.parseInt(data[0]);
				int last = Integer.parseInt(data[data.length-1]);
				ArrayList<Integer> l = t[last].list;
				for(int j = 0; j < l.size(); j++) {
					if(set.contains(first + " " + l.get(j))) {
						found = true;
						break;
					}
					else
					{
						set.add(first+ " " + l.get(j));
						q.add(first + " " + l.get(j));
					}
				}
				if(found) break;
			}
			
			if(found)
				out.write("Case #" + i+ ": Yes\n");
			else
				out.write("Case #" + i+ ": No\n");
			//out.write("Case #" + i+ ":" + s+"\n");
		}
		out.close();
	}
}