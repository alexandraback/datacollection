import java.io.*;
import java.util.*;
public class kingdomRush
{
	public static class Pair implements Comparable<Pair>
	{
		public int a, b;
		public Pair(int a, int b)
		{
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair d)
		{
			return d.b - b;
		}
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(new File("kingdomRush.in"))));
		PrintStream out = new PrintStream(new File("kingdomRush.out"));
		int tests = Integer.parseInt(in.readLine());
		for(int test = 0; test < tests; test++){
			int quant = Integer.parseInt(in.readLine());
			StringTokenizer s1;
			boolean[][] done = new boolean[quant][2];
			Pair[] value = new Pair[quant];
			for(int x = 0; x < quant; x++){
				value[x] = new Pair(0, 0);
				s1 = new StringTokenizer(in.readLine(), " ");
				value[x].a = Integer.parseInt(s1.nextToken());
				value[x].b = Integer.parseInt(s1.nextToken());
			}
			Arrays.sort(value);
			int levels = 0;
			int total = 0;
			boolean fail = false;
			looper: while(total < 2 * quant){
				boolean got2 = false;
				loop1:for(int x = 0; x < quant; x++){
					if(value[x].b <= total && !done[x][0] && !done[x][1]){
						done[x][0] = true;
						done[x][1] = true;
						total += 2;
						got2 = true;	
						levels++;
						break loop1;				
					}
				}
				if(got2)
					continue looper;
				boolean got1 = false;
				loop2:for(int x = 0; x < quant; x++){
					if(value[x].b <= total && !done[x][1]){
						done[x][1] = true;
						total++;
						got1 = true;
						levels++;
						break loop2;
					}	
				}
				if(got1)
					continue looper;
				boolean gotSomething = false;
				loop3:for(int x = 0; x < quant; x++){
					if(value[x].a <= total && !done[x][0]){
						done[x][0] = true;
						total++;
						gotSomething = true;
						levels++;
						break loop3;
					}
				}
				
				if(!(got1 || got2 || gotSomething)){
					fail = true;
					break;
				}
			}
			if(fail)
				out.println("Case #" + (test+1) + ": Too Bad");
			else
				out.println("Case #" + (test+1) + ": " + levels);
		}
	}
}