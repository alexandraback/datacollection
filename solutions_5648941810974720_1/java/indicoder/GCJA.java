import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class GCJA {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		new solve().sol();

	}

}

class solve {
	void sol() throws Exception{
		ModScanner ms=new ModScanner();
		PrintWriter out=new PrintWriter("D://gcj//a.out");
		int t=ms.nextInt();
		String arr[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
		int fingerPrint[][]=new int[10][26];
		for(int i=0;i<10;i++){
			String curr=arr[i];
			for(int j=0;j<curr.length();j++){
				fingerPrint[i][curr.charAt(j)-'A']++;
			}
		}
		for(int tc=1;tc<=t;tc++){
				String inp=ms.nextToken();
				int numArray[]=new int[10];
				int countArray[]=new int[26];
				for(int i=0;i<inp.length();i++){
					countArray[inp.charAt(i)-'A']++;
				}
				while(countArray['W'-'A']!=0){
					numArray[2]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[2][i];
				}
				while(countArray['Z'-'A']!=0){
					numArray[0]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[0][i];
				}
				while(countArray['X'-'A']!=0){
					numArray[6]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[6][i];
				}
				while(countArray['S'-'A']!=0){
					numArray[7]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[7][i];
				}
				while(countArray['G'-'A']!=0){
					numArray[8]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[8][i];
				}
				while(countArray['H'-'A']!=0){
					numArray[3]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[3][i];
				}
				while(countArray['V'-'A']!=0){
					numArray[5]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[5][i];
				}
				while(countArray['U'-'A']!=0){
					numArray[4]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[4][i];
				}
				while(countArray['I'-'A']!=0){
					numArray[9]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[9][i];
				}
				while(countArray['O'-'A']!=0){
					numArray[1]++;
					for(int i=0;i<26;i++)
						countArray[i]=countArray[i]-fingerPrint[1][i];
				}
				System.out.print("Case #"+tc+": ");
				out.print("Case #"+tc+": ");
				for(int i=0;i<10;i++){
					int count=numArray[i];
					for(int j=0;j<count;j++){
						System.out.print(i);
						out.print(i);
					}
						
				}
			    System.out.println();
			    out.println();
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