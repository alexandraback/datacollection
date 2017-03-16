import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;


public class C {
	static int J,p,s,k;
	static public void main(String[] args)throws Exception{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt2.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int t =Integer.parseInt(br.readLine());
		String[]in;
		for(int z=1;z<=t;z++){
			in = br.readLine().split(" ");
			J = Integer.parseInt(in[0]);
			p = Integer.parseInt(in[1]);
			s = Integer.parseInt(in[2]);
			k = Integer.parseInt(in[3]);
			HashMap<String,Integer> map1 = new HashMap<String,Integer>();
			HashMap<String,Integer> map2 = new HashMap<String,Integer>();
			HashMap<String,Integer> map3 = new HashMap<String,Integer>();
			ArrayList<String>output = new ArrayList<String>();
			int res=0;
			for(int i=1;i<=J;i++){
				for(int j=1;j<=p;j++){
					for(int m=1;m<=s;m++){
						String s1 = Integer.toString(i)+" "+Integer.toString(j);
						String s2 = Integer.toString(i)+" "+Integer.toString(m);
						String s3 = Integer.toString(j)+" "+Integer.toString(m);
						if(map1.containsKey(s1) && map1.get(s1)==k)continue;
						if(map2.containsKey(s2) && map2.get(s2)==k)continue;
						if(map3.containsKey(s3) && map3.get(s3)==k)continue;
						if(map1.containsKey(s1))
							map1.put(s1, map1.get(s1)+1);
						else
							map1.put(s1, 1);
						
						if(map2.containsKey(s2))
							map2.put(s2, map2.get(s2)+1);
						else
							map2.put(s2, 1);
						
						if(map3.containsKey(s3))
							map3.put(s3, map3.get(s3)+1);
						else
							map3.put(s3, 1);
						
						res++;
						String now = Integer.toString(i)+" "+Integer.toString(j)+" "+Integer.toString(m);
						output.add(now);
					}
				}
			}
			out.println("Case #"+z+": "+res);
			for(int i=0;i<output.size();i++)
				out.println(output.get(i));
		}
		br.close();
		out.close();
	}
}
