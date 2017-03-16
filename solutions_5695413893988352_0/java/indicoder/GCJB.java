import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class GCJB {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		new solve().sol();

	}

}
class solve {
	void sol() throws Exception{
		ModScanner ms=new ModScanner();
		PrintWriter out=new PrintWriter("D://gcj//a.out");
		int t=ms.nextInt();
		for(int tc=1;tc<=t;tc++){
				String coders=ms.nextToken();
				String jammers=ms.nextToken();
				int min=9999;
				String ans1="";
				String ans2="";
				for(int i=0;i<=999;i++){
					String gen=""+i;
					if(coders.length()<gen.length())
						break;
					while(coders.length()!=gen.length())
						gen="0"+gen;
					boolean fl=false;
					for(int j=0;j<coders.length();j++){
						if(coders.charAt(j)=='?')
							continue;
						if(coders.charAt(j)!=gen.charAt(j)){
							fl = true;
							break;
						}
					}
					if(fl)
						continue;
					//System.out.println("valud "+gen);
					for(int j=0;j<=999;j++){
						String gen1=""+j;
						if(jammers.length()<gen1.length())
							break;
						while(jammers.length()!=gen1.length())
							gen1="0"+gen1;
						boolean fl1=false;
						for(int k=0;k<jammers.length();k++){
							if(jammers.charAt(k)=='?')
								continue;
							if(jammers.charAt(k)!=gen1.charAt(k)){
								fl1 = true;
								break;
							}
						}
						if(fl1)
							continue;
						
						int diff=Math.abs(i-j);
						if(diff<min){
							
							min=diff;
							ans1=gen;
							ans2=gen1;
						}
					}
				}
				System.out.println("Case #"+tc+": "+ans1+" "+ans2);
				out.println("Case #"+tc+": "+ans1+" "+ans2);
	
		}
		out.flush();
		out.close();
	}
}
class ModScanner {
	BufferedReader br;
	StringTokenizer st;
 
	public ModScanner() throws Exception {
		//br = new BufferedReader(new InputStreamReader(System.in));
		br = new BufferedReader(new FileReader("D://gcj//a.in"));
	}
 
	String nextToken() throws Exception {
		while (st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(br.readLine());
			
		}
		return st.nextToken();
	}
 
	int nextInt() throws Exception, Exception {
		return Integer.parseInt(nextToken());
	}
 
	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}
 
	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
}
