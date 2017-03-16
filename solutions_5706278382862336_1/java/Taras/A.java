import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A {

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer tokenizer;
	
	
	
	public static void main(String[]args) throws IOException{
		File inF = new File("/home/taras/workspace/Google_Code_Jam_2014_1C/src/ASmall.txt");
		File outF = new File("/home/taras/workspace/Google_Code_Jam_2014_1C/src/ASmall_out.txt");
		
	
		FileReader reader = new FileReader(inF);
		FileWriter writer = new FileWriter(outF);
		br = new BufferedReader(reader);
		out = new PrintWriter(writer);
		
		tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		for(int i=0;i<n;i++){
			solveTest(i+1);
		}
		
		out.flush();
		out.close();
		
	}
	
	private static void solveTest(int testNum) throws IOException {
		
		boolean possible = true;
		String str = br.readLine();
		int pos = 0;
		while(str.charAt(pos)!='/')pos++;
		
		long n1 = Long.parseLong(str.substring(0, pos));
		long n2 = Long.parseLong(str.substring(pos+1, str.length()));
		long gcd =GCD(n1,n2);
		n1/=gcd;
		n2/=gcd;
		
		//is 2^n?
		long potoch = 1;
		int cnt = 0;
		while(potoch<n2){
			potoch*=2;
			cnt++;
		}
		if(potoch!=n2) possible = false;
		if(cnt>40) possible = false;//no more then 40 generations
		
		int res = 0;
		potoch = n2;
		long ansestorsCnt=1;
		long currentSum = 0;
		if(possible)
			for(int i=0;i<=cnt;i++){
				currentSum = potoch;
				if(currentSum==n1){
					res = i;
					break;
				}
				if(ansestorsCnt>1){
					currentSum = n1 - currentSum;
					if(currentSum>=0 && currentSum<=(ansestorsCnt-1)*potoch)
					{
						//out.append("currentSum="+currentSum+" (ansestorsCnt-1)*potoch ="+((ansestorsCnt-1)*potoch)+"\n");
						res = i;
						break;
					}
				}
				potoch/=2;
				ansestorsCnt*=2;
			}
		
		
		if(possible){
			out.append("Case #"+testNum+": "+res+"\n");
		}else{
			out.append("Case #"+testNum+": "+"impossible\n");
		}
	}

	private static long GCD(long n1, long n2) {
		if(n2==0)return n1;
		if(n1<n2)return GCD(n2,n1);
		else return GCD(n2,n1%n2);
	}

}
