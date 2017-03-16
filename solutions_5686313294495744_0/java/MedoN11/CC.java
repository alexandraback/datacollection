import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class CC {

	static int t;
	static BufferedWriter writer = null;
	static StringBuilder sb = new StringBuilder();
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String str;
	static StringTokenizer st;
	static TreeMap<String,Integer> mapFirst = new TreeMap();
	static TreeMap<String,Integer> mapSecond = new TreeMap();

	static boolean getBit(int num, int idx) {
		return ((num >> idx) & 1) == 1;
	}


	static class Submission
	{
		String first,second;

		public Submission(String first,String second)
		{
			this.first =first;
			this.second = second;
		}

	}
	public static void main(String[]args)throws Throwable
	{
		int t;
		t = new Integer(br.readLine());

		ArrayList<Submission> arr = new ArrayList();
		int tc = 1;
		File file = new File("example.txt");
		writer = new BufferedWriter(new FileWriter(file));

		while(t-- > 0)
		{

			int n = new Integer(br.readLine());
			arr.clear();
			mapFirst.clear();
			mapSecond.clear();

			for(int i = 0 ; i < n ; i++){
				st = new StringTokenizer(br.readLine());
				String first,second;
				first = st.nextToken();
				second = st.nextToken();
				arr.add(new Submission(first,second));
			}

			int best = 0;
			TreeSet<String> Tf = new TreeSet();
			TreeSet<String> Ts = new TreeSet();
			boolean ok = true;
			for(int msk = 0 ; msk < 1 << n ; msk++)
			{

				Tf.clear();
				Ts.clear();
				ok = true;
				for(int i = 0 ; i < n ; i++) if(getBit(msk,i))
				{
					Tf.add(arr.get(i).first);
					Ts.add(arr.get(i).second);
				}

				int cnt = 0;
				for(int i = 0 ; i < n ; i++) if(!getBit(msk,i))
				{
					if(Tf.contains(arr.get(i).first) && Ts.contains(arr.get(i).second)) ok &= true;
					else ok &= false;
					cnt++;

				}
				if(ok) best = Math.max(best,cnt);

			}
			writer.write("Case #"+(tc++)+": "+best+"\n");
		}
		writer.flush();



	}
}
