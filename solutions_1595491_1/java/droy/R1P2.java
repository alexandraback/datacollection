import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class R1P2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{

		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("large2.out"));
		String inLine;
		int t = Integer.parseInt(in.readLine());
		int counter = 0;
		while((inLine = in.readLine()) != null){
			counter++;
			int n, s, p;
			String[] toks = inLine.split(" ");
			n = Integer.parseInt(toks[0]);
			s = Integer.parseInt(toks[1]);
			p = Integer.parseInt(toks[2]);
			//System.out.println(n+ " " + s + " " + p);
			int j1 = p;
			int j2 = p - 1;
			int j3 = p - 2;
			if(j2 < 0) j2 = 0;
			if(j3 < 0) j3 = 0;
			int nTotal = j1 + j2 + j2;
			int sTotal = j1 + j3 + j3;
			//System.out.println(nTotal + " " + sTotal);
			int pos = 0;
			for(int i=3; i<toks.length; i++){
				int score = Integer.parseInt(toks[i]);
				if(score>=nTotal) pos++;
				else if(score >= sTotal && s > 0){
					pos++;
					s--;
				}
			}
			System.out.println("Case #" + counter + ": " + pos);
			bw.write("Case #" + counter + ": " + pos);
			bw.newLine();
			
		}
		in.close();
		bw.close();
	}

}
