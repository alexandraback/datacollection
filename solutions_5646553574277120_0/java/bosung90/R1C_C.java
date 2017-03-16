import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class R1C_C {
	private final static String CLASS_NAME = R1C_C.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			long C = scan.nextLong();
			int D = scan.nextInt();
			long V = scan.nextLong();
			TreeMap<Long, String> hmap = new TreeMap<Long, String>();
			for(int d=0; d<D; d++)
			{
				hmap.put(scan.nextLong(), "");
			}
			
			String ans = "Case #"+(t+1)+": " + getAns(C, D, V, hmap);
			System.out.println(ans);
			writer.println(ans);
		}
		scan.close();
		writer.close();
	}
	
	private static String getAns(long C, int D, long V, TreeMap<Long, String> hmap)
	{
		long count = 0;
		TreeMap<Long, String> copy = new TreeMap<Long, String>();
		for(long l : hmap.keySet())
		{
			copy.put(l, "");
		}
		
		for(long i=1; i<=V; i++)
		{
			if(!copy.containsKey(i))
			{
				copy.put(i, "");
				hmap.put(i, "");
				count++;
			}
			
			ArrayList<Long> list = new ArrayList<Long>();
			for(long l : hmap.keySet())
			{
				if(l < i)
					continue;
				for(long c=1; c<=C; c++)
				{
					if(l==i && c==C)
						continue;
					long toAdd = l+(long)Math.pow(i, c);
					if(toAdd > V)
						break;
					list.add(toAdd);
				}
			}
			for(long l : list){
				copy.put(l, "");
				hmap.put(l, "");
			}
		}
		
		return "" + count;
	}
}
