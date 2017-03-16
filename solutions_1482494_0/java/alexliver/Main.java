import java.util.*;
import java.io.*;
class pt implements Comparable
{
	int lv;
	int star;
	int id;
	public pt(int i, int j,int id) {
		lv = i;
		star = j;
		this.id = id;
	}
	@Override
	public int compareTo(Object arg0) {
		
		return star - ((pt)arg0).star;
	}
}
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		sc.nextLine();
		
		for(int cs = 1; cs<=cases; cs++)
		{
			int n = sc.nextInt();
			
			int [] lower = new int[n];
			int [] upper = new int[n];
			for(int i=0; i<n; i++)
			{
				lower[i] = sc.nextInt();
				upper[i] = sc.nextInt();
			}

			int min = Integer.MAX_VALUE;
			for(int tok = 0; tok < (1<<n); tok++)
			{

				Vector <pt> v = new Vector<pt>();
				for(int i=0; i<n; i++)
				{
					if((tok &(1<<i)) == (1<<i))
					{
						v.add(new pt(1,lower[i],i));
					//	System.out.print(i);
					}
					
					v.add(new pt(2, upper[i],i));
							
				}
				//System.out.println();
				Collections.sort(v, new Comparator(){

					@Override
					public int compare(Object arg0, Object arg1) {
						
						return ((pt)arg0).star - ((pt)arg1).star;
					}
					
				});
				int total = 0;
				boolean found = false;
				Set<Integer> used = new TreeSet<Integer>();
				for(int i=0; i<v.size(); i++)
				{
					if(v.get(i).star>total)
					{
						found = true;
						break;
					}
					if(used.contains(v.get(i).id))
					{
						if(v.get(i).lv == 2)
							total++;
					}
					else
					{
						total += v.get(i).lv;
						used.add(v.get(i).id);
					}
				}
				if(!found)
					min = Math.min(v.size(), min);
			}
			
			if(min!=Integer.MAX_VALUE)
				out.println("Case #"+cs+": "+min);
			else
				out.println("Case #"+cs+": Too Bad");
		}
		out.close();
		fis.close();
	}



}
