
import java.io.*;

public class A implements Runnable{
	
	BufferedReader in;
	BufferedWriter out;
	static String inputFile="";
	static String outputFile="";
	static {
		inputFile = A.class.getName()+".in";
		outputFile = A.class.getName()+".out";
	}
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	public Double dread() throws Exception {
		return Double.parseDouble(readword());
	}
	public String readword() throws Exception {
		int k = in.read();
		if(k < 0) return "";
		while(k >= 0 && k <= ' ') k=in.read();
		StringBuilder bld = new StringBuilder();
		while(k > ' ') {
			bld.append((char)k);
			k = in.read();
		}
		return bld.toString();
	}
	
	
	public void solve() throws Exception {
		int tests = iread();
		for (int T=0; T<tests; T++) {
						double A = dread();
			double B = dread();
			double[] p = new double[(int)A];
			double[] mult = new double[(int)A];
			double correctp = 1;
			
			for(int i = 0; i < p.length; i++){
				p[i]=dread(); 
				correctp *= p[i];
				mult[i]= correctp; //mult[0] = p[o] mult[1] = p[0]*p[1] 
			}
			
			double[] opt = new double[(int)A];
			double min = B+2;
			for(int i = 0; i < (int)A ; i++) {
			opt[i]= (B-A+1+2*i)*mult[(int)(A-1-i)] + (2*B-A+2+2*i)*(1-mult[(int)(A-1-i)]);
			min = Math.min(min,opt[i]);
			}
						
			out.write("Case #"+(T+1)+": "+min+"\n");
		}		
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(inputFile));
			out = new BufferedWriter(new FileWriter(outputFile));
			solve();
			out.flush();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		
		new Thread(new A()).start();
	}
}
