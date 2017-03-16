import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class TC {


	static BufferedWriter writer = null;

	static StringBuilder sb = new StringBuilder();
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String str;
	static StringTokenizer st;
	static char[] a, b;
	static ArrayList<Integer> a1 = new ArrayList();
	static ArrayList<Integer> b1 = new ArrayList();


	public static void gena(int idx,int num)
	{
		if(idx == a.length){
			a1.add(num);
			return;
		}
		if(a[idx] != '?')
		{
			num*=10; num += a[idx]-'0';
			gena(idx+1,num);
		}
		else
		{
			for(int j = 0 ; j <= 9 ; j++)
			{
				gena(idx+1,(num*10)+j);
			}
		}
	}


	public static void genb(int idx,int num)
	{
		if(idx == b.length){
			b1.add(num);
			return;
		}
		if(b[idx] != '?')
		{
			num*=10; num += b[idx]-'0';
			genb(idx+1,num);
		}
		else
		{
			for(int j = 0 ; j <= 9 ; j++)
			{
				genb(idx+1,(num*10)+j);
			}
		}
	}
	public static void main(String[]args)throws Throwable
	{

		File file = new File("example.txt");
		writer = new BufferedWriter(new FileWriter(file));

		int tc = 1;
		int t;
		t = new Integer(br.readLine());
		while(t-- > 0)
		{

			st = new StringTokenizer(br.readLine());
			a = st.nextToken().toCharArray();
			b = st.nextToken().toCharArray();
			a1.clear();
			b1.clear();
			gena(0,0);
			genb(0,0);
			
			int szA = a1.size();
			int szB = b1.size();
			int diff = 1 << 29;
			int first= 1<<22; 
			int second = 1 << 22;
			for(int i = 0 ; i< szA ; i++)
			{
				for(int j = 0 ; j < szB ; j++)
				{
					int fst = a1.get(i);
					int snd = b1.get(j);
					int curr = Math.abs(fst-snd);
					if(curr < diff)
					{
						diff = curr;
						first = fst;
						second = snd;
					}
					else
					{
						if(diff == curr)
						{
							if(fst < first)
							{

								first = fst;
								second = fst;
							}
							else
							{
								if(fst == first)
								{
									if(snd < second)
									{
										first = fst;
										second = snd;
									}

								}
							}
						}
					}
				}

			}
			
			String r1 = Integer.toString(first);
			String r2 = Integer.toString(second);
			int sz = r1.length();
			while(sz++ < a.length) r1 = "0" + r1;
			sz = r2.length();
			while(sz++ < b.length) r2 = "0" + r2;
			writer.write("Case #"+tc+": "+r1+" "+r2+"\n");
			tc++;

		}
		writer.flush();
	}
}
