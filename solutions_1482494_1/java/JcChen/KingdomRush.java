import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			PrintWriter pw = new PrintWriter(args[1]);
			String line = br.readLine();
			System.out.println(line);
			int T = Integer.valueOf(line.trim());
			for (int i=0; i<T; i++)
			{
				line = br.readLine();
				System.out.println(line);
				int N = Integer.valueOf(line.trim());
				int[] complete = new int[N];
				starRequirement_a[] as = new starRequirement_a[N];
				starRequirement_b[] bs = new starRequirement_b[N];
				
				for(int j=0; j<N; j++)
				{
					complete[j] = 0;
					line = br.readLine();
					System.out.println(line);
					String ab[] = line.trim().split(" ");
					int a = Integer.valueOf(ab[0].trim());
					int b = Integer.valueOf(ab[1].trim());
					as[j] = new starRequirement_a(a, b, j);
					bs[j] = new starRequirement_b(b, j);
				}
				
				Arrays.sort(as);
				Arrays.sort(bs);

				int index_a=0, index_b = 0;
				int counter = 0, start = 0;
				boolean isToobad = false;
				int rounds = 0;
				while(counter<N)
				{
					if(start >= bs[index_b].b)
					{
						counter++;
						if(complete[bs[index_b].index]==1)
							start++;
						else
							start+=2;
						complete[bs[index_b].index]=2;
						index_b++;
					}
					else
					{
						while(index_a!=N && complete[as[index_a].index]!=0)
						{
							index_a++;
						}
						if(index_a==N)
						{
							isToobad = true;
							break;
						}
						int tmp_index = index_a;
						int take_a = index_a;
						while(tmp_index<N && as[tmp_index].a<=start)
						{
							if(complete[as[tmp_index].index]==0)
								take_a =as[take_a].b>as[tmp_index].b?take_a:tmp_index;
							tmp_index++;
						}
						
						if(start >= as[take_a].a)
						{
							start++;
							complete[as[take_a].index]=1;
						}
						else
						{
							isToobad = true;
							break;
						}
					}
					
					rounds++;
				}
				
				if(isToobad)
				{
					pw.println("Case #"+(i+1)+": Too Bad");
					System.out.println("Case #"+(i+1)+": Too Bad");
				}
				else
				{
					pw.println("Case #"+(i+1)+": "+rounds);
					System.out.println("Case #"+(i+1)+": "+rounds);
				}
			}
			pw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}

class starRequirement_a implements Comparable
{
	int a;
	int b;
	int index;
	starRequirement_a(int a, int b, int i)
	{
		this.a = a;
		this.b = b;
		this.index = i;
	}
	@Override
	public int compareTo(Object that) {
		// TODO Auto-generated method stub
		if(this.a!=((starRequirement_a)that).a)
			return this.a-((starRequirement_a)that).a;
		else
			return ((starRequirement_a)that).b - this.b;
	}
}

class starRequirement_b implements Comparable
{
	int b;
	int index;
	starRequirement_b(int b, int i)
	{
		this.b = b;
		this.index = i;
	}
	@Override
	public int compareTo(Object that) {
		// TODO Auto-generated method stub
		return this.b-((starRequirement_b)that).b;
	}
}