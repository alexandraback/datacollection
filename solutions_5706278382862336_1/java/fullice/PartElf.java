import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class PartElf {
	static long P=0;
	static long Q=0;
	
	public static void main(String[] args) throws IOException{
		FileReader fr = new FileReader("PartElf.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("PartElf.out");
		String CaseCnt = null;
		
		if(br.ready()) CaseCnt = br.readLine();
		for(int i = 0; i < Integer.parseInt(CaseCnt);i++){ 
			String[] tokens = br.readLine().split("/");
			P = Long.parseLong(tokens[0]);
			Q = Long.parseLong(tokens[1]);
			
			fw.write("Case #" + (i+1) + ": ");
			long fractor = GCD(P,Q);
			P = P/fractor;
			Q = Q/fractor;
			fw.write(Calc() + "\r\n");
		}
		
		System.out.print("finish");
		fr.close();
		
		fw.flush();
		fw.close();
	}
	
	// Small dataset: no common factor
	// see Q is 2^i, and P is 2^j, then answer is (i-j)
	static String Calc(){
		if(P == 0) return "impossible";
		for(int i=0;i<41;i++){
			if(Q == Math.pow(2, i)){
				for(int j=40;j>=0;j--){
					if(P >= Math.pow(2, j))
						return String.valueOf(i-j);
				}
			}
		}
		return "impossible";
	}

	public static long GCD(long a, long b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
	
}
