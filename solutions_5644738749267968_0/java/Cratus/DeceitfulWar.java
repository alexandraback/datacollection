import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class DeceitfulWar {
	
	static String infile = "G:/Dev/workspace/CodeJam14/ProblemD/input.in", outfile = "G:/Dev/workspace/CodeJam14/ProblemD/output.out";
	static String prefix = "Case #";
	static BufferedReader br;
	static BufferedWriter bw;
	

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(infile));
		bw = new BufferedWriter(new FileWriter(outfile));
		solve();
		bw.flush();
		bw.close();
		br.close();
	}
	
	static void solve() throws NumberFormatException, IOException {
		int T = Integer.parseInt(getNextLine());
		for(int i=1;i<=T;i++) {
			int c = Integer.parseInt(getNextLine());
			double[] naomi = new double[c], kent = new double[c];
			String[] split = getNextLine().split(" ");
			for(int j=0;j<split.length;j++) {
				naomi[j] = Double.parseDouble(split[j]);
			}
			split = getNextLine().split(" ");
			for(int j=0;j<split.length;j++) {
				kent[j] = Double.parseDouble(split[j]);
			}
			Arrays.sort(naomi);
			Arrays.sort(kent);
			
			//deceitfulwar
			int k = 0;
			int naomiDeceitfulWin = 0;
			for(int j=0;j<kent.length;j++) {
				while(k < naomi.length && naomi[k]<kent[j]) {
					k++;
				}
				if(k<naomi.length) {
					naomiDeceitfulWin++;
					k++;
				} else
					break;
			}
			
			//war
			int naomiWin = 0;
			for(int j=0;j<c;j++) {
				boolean found = false;
				for(int l=0;l<kent.length;l++) {
					if(kent[l]==0)
						continue;
					if(kent[l]>naomi[j]) {
						kent[l] = 0;
						found = true;
						break;
					}
				}
				if(!found) {
					for(int l=0;l<kent.length;l++) {
						if(kent[l]==-1)
							continue;
						kent[l] = 0;
						naomiWin++;
						break;
					}
				}
			}
			writeLine(prefix + i + ": " + naomiDeceitfulWin + " " + naomiWin);
		}
		
	}

	static void writeLine(String next) throws IOException {
		bw.write(next);
		bw.write("\n");
	}
	
	static String getNextLine() throws IOException {
		String next = br.readLine();
		if(next==null) return null;
 		while(next!=null && next.trim().isEmpty()) {
			next = br.readLine();
		}
 		return next;
	}
}
