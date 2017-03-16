import java.io.*;
import java.util.Vector;

class level
{
	public int one;
	public int two;
	public Boolean one_c;
	public Boolean two_c;
}

public class Star {
	public void cal(String filename) throws NumberFormatException, IOException
	{
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bar.txt")));
		int count = 1;
		String s = in.readLine();
		int all = Integer.parseInt(s);
		while((s = in.readLine()) != null)
		{
			int result = 0;
			if(count > all)
			{
				System.out.println("error");
				break;
			}
			String[] elements = s.split(" ");
			int size = Integer.parseInt(elements[0]);
			Vector<level> levels = new Vector<level>();
			for(int i = 0; i < size; i++)
			{
				s = in.readLine();
				elements = s.split(" ");
				level l = new level();
				l.one = Integer.parseInt(elements[0]);
				l.two = Integer.parseInt(elements[1]);
				l.one_c = false;
				l.two_c = false;
				levels.add(l);
			}
			int star = 0;
			int complete = 0;
			Boolean possible = false;
			while(complete < size)
			{
				possible = false;
				for(int i = 0; i < levels.size(); i++)
				{
					level l = levels.get(i);
					if(l.two <= star && (!l.two_c) && (!l.one_c))
					{
						star = star + 2;
						levels.get(i).two_c = true;
						complete = complete + 1;
						possible = true;
						break;
					}
				}
				
				if(!possible)
				{
					for(int i = 0; i < levels.size(); i++)
					{
						level l = levels.get(i);
						if(l.two <= star && (!l.two_c) && (l.one_c))
						{
							star = star + 1;
							levels.get(i).two_c = true;
							complete = complete + 1;
							possible = true;
							break;
						}
					}
				}
				
				if(!possible)
				{
					int index = 0;
					int num = 0;
					for(int i = 0; i < levels.size(); i++)
					{
						level l = levels.get(i);
						if(l.one <= star && (!l.one_c) && (!l.two_c))
						{
							if(num < l.two)
							{
								num = l.two;
								index = i;
							}
//							star = star + 1;
//							levels.get(i).one_c = true;
							possible = true;
						}
					}
					if(possible)
					{
						star = star + 1;
 						levels.get(index).one_c = true;
					}
				}
				
				
				if(!possible)
					break;
				result = result + 1;	
			}
			
			if(possible)
			    out.println("Case #" + count +": " + result);
			else
				out.println("Case #" + count +": Too Bad");
			count = count + 1;
		}
		out.close();
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Star s = new Star();
		s.cal("6.in");
	}

}
