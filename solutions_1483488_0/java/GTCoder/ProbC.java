import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.BitSet;


public class ProbC {
	
	public static long solve(int A, int B) {
		int[] basePower = new int[8];
		basePower[0] =1;
		for(int i=1; i<8; i++)
			basePower[i] = basePower[i-1] * 10;
		
		long count = 0;
		BitSet mask = new BitSet(B+1);
		int[] digits = new int[8];
		
		for(int i=A; i<=B; i++) {
			if(mask.get(i)) continue;
			mask.set(i);
			int candidate = i;
			int nCandidates = 1;
			int size = 0;
			while(candidate > 0) {
				digits[size] = candidate % 10;
				candidate /= 10;
				size++;
			}
			if(size > 1) {
			   for(int j=0; j<size-1; j++) {
				   int part1 = 0;
				   int part2 = 0;
				   for(int k=j; k>=0; k--) {
					   part1 = part1 * 10 + digits[k];
				   }
				   for(int k=size-1; k>j; k--) {
					   part2 = part2 * 10 + digits[k];
				   }
				   
				   if(part1 != 0) {
					   int value = part1 * basePower[size-1-j] + part2;
					   if(value >= A && value <=B && !mask.get(value)) {
						   nCandidates++;
						   mask.set(value);
					   }
				   }
			   }
			   count += (nCandidates-1) * nCandidates/2;
			}
		}
		return count;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for(int i=1; i<=T; i++) {
			line = in.readLine();
			String[] comp = line.split("\\s+");
			int A = Integer.parseInt(comp[0]);
			int B = Integer.parseInt(comp[1]);
			
			out.print("Case #" + i+ ": ");
			out.println(solve(A, B));
		}
		
		out.flush();
		in.close();
		out.close();
	}
}
