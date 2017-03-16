import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class R1C1 {
	private String[][] in;
	private int numCases;
	private String[] out;
	
	public R1C1() {
		String inFilename = "A-small-attempt1.in";
		readFile(inFilename);
		numCases = new Integer(in[0][0]);
		out = new String[numCases];
		calculateResult();
		String outFilename = "A-small-attempt1.out";
		writeOut(outFilename);
	}
	
	public void calculateResult() {
		//precalc
		long[] p2 = new long[40];
		p2[0] = 2;
		for(int i = 1; i < 40; i++) {
			p2[i] = p2[i-1]*2;
		}
		
		//result
		int arp = 1;
		for(int c = 0; c < numCases; c++) {
			long p = new Long(in[arp][0]);
			long q = new Long(in[arp][1]);
			
			if((p2[39]%q)!=0) {
				out[c] = "impossible";
			} else {
				long f = p2[39]/q;
				p*=f;
				q*=f;
				
				int i = 39;
				
				while(p2[i-1] > p) {
					i--;
				}
				
				out[c] = (new Integer(40-i)).toString();
			}
			
			arp++;
		}
	}
	
	public void readFile(String filename) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String cl;
			ArrayList<String[]> inal = new ArrayList<String[]>();
			while((cl = br.readLine()) != null) {
				String[] cle = cl.split("/");
				inal.add(cle);
			}
			in = inal.toArray(new String[0][]);
			br.close();
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void writeOut(String filename) {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
			for(int i = 0; i < out.length; i++) {
				int caseNum = i + 1;
				String caseTxt = "Case #" + caseNum + ": ";
				if(i > 0) {
					bw.newLine();
				}
				bw.write(caseTxt);
				bw.write(out[i]);
			}
			bw.close();
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void printInArray() {
		for(int i = 0; i < in.length; i++) {
			for(int j = 0; j < in[i].length; j++) {
				System.out.print(in[i][j]);
				System.out.print(" ");
			}
			System.out.print("\n");
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new R1C1();
	}

}
