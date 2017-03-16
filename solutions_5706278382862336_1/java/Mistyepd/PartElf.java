
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
/**
 * @author Kate Henderson
 *
 */
public class PartElf {

	private Scanner sc = null;
	private BufferedWriter bw = null;	
	private File inFile;
	private File outFile;
	private int cases;


	private long maxGen = (long) Math.pow(2, 40);
	private long gen;

	public PartElf(){
		inFile = new File("A-large.in");
		outFile = new File("A-large.out");
	}

	public static void main(String[] args) {
		PartElf p = new PartElf(); 
		p.solve();	
	}

	private void solve(){		
		try {
			sc = new Scanner(new FileReader(inFile));
			bw = new BufferedWriter(new FileWriter(outFile));

			cases = Integer.parseInt(sc.nextLine());

			for (int c = 1; c <= cases; c++) {
				StringBuilder sb = new StringBuilder();
				gen = 1;
				String frac = sc.nextLine();
				StringTokenizer fracSplit = new StringTokenizer(frac, "/"); 
				long P = Long.parseLong(fracSplit.nextToken()); 
				long Q = Long.parseLong(fracSplit.nextToken()); 

				if(P%2==0 && Q%2!=0){
					sb.append("Case #" + c + ": impossible\n");
				}else{
					long GCD = GCM(P, Q);
					P = P/GCD;
					Q = Q/GCD;
					if((Q&(Q-1))!=0){
						sb.append("Case #" + c + ": impossible\n");
					}else{
						double B = (double)P/Q * 2;
						while(B<1 && gen<=(maxGen+1)){
							B = B * 2;
							gen++;
							
						}
						//System.out.println("here"+B);
						if(gen<=maxGen)
							sb.append("Case #" + c + ": " + gen+"\n");
						else
							sb.append("Case #" + c + ": impossible\n");
					}
				}


				try {
					bw.write(sb.toString());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			bw.flush();
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public long GCM(long N, long D) {
		return D == 0 ? N : GCM(D, N % D);
	}

}
