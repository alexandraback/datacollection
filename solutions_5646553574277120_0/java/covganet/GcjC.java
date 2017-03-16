import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;


public class GcjC {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output3.txt"));
		int nrT = Integer.parseInt(br.readLine());
		for(int tnr = 1; tnr <= nrT; tnr++) {
			String[] strs = br.readLine().split(" ");
			//int c = Integer.parseInt(strs[0]);
			//int d = Integer.parseInt(strs[1]);
			v = Integer.parseInt(strs[2]);
			
			strs = br.readLine().split(" ");
			int[] ds = new int[strs.length];
			for (int i = 0; i < ds.length; i++) {
				ds[i] = Integer.parseInt(strs[i]);
			}
			
			Arrays.sort(ds);
			
			int isPos = 1;
			for(int i = 1; i < (1 << ds.length); i++) {
				int cv = 0;
				for(int j = 0; j < ds.length; j++) {
					if((i & (1 << j)) != 0) {
						cv += ds[j];
					}
				}
				if(cv <= v) {
					isPos |= (1 << cv);
				}
			}
			
			int next = v + 1;
			for (int i = 1; i <= v; i++) {
				if((isPos & (1 << i)) == 0) {
					next = i;
					break;
				}
			}
			
			if(next == v + 1) {
				pw.println("Case #" + tnr + ": 0");
				continue;
			}
			
			isInDs = new boolean[v + 1];
			for (int i = 0; i < ds.length; i++) {
				if(ds[i] < isInDs.length) {
					isInDs[ds[i]] = true;
				}
			}
			
			res = ds.length + 5;
			cStep = 0;
			func(isPos, next);
			
			pw.println("Case #" + tnr + ": " + res);
		}
		br.close();
		pw.close();
	}
	
	static int res = 0;
	static boolean[] isInDs = null;
	static int cStep = 0, v = 0;
	
	static void func(int isPos, int next) {
		boolean[] possibleToAdd = new boolean[v + 1];
		for(int i = 1; i <= next; i++) {
			if(!isInDs[i] && (isPos & (1 << (next - i))) != 0) {
				possibleToAdd[i] = true;
				
				boolean allOk = true;
				for(int j = next + 1; j <= v; j++) {
					if((isPos & (1 << j)) == 0 && (isPos & (1 << (j - i))) == 0) {
						allOk = false;
						break;
					}
				}
				if(allOk) {
					res = Math.min(res, cStep + 1);
					return;
				}
			}
		}
		
		if(cStep > 4) {
			return;
		}
		
		cStep++;
		int isPosCopy = isPos;
		for(int i = 1; i < possibleToAdd.length; i++) {
			if(possibleToAdd[i]) {
				for(int j = next - i; j <= v - i; j++) {
					if((isPosCopy & (1 << j)) != 0) {
						isPos |= (1 << (j + i));
					}
				}
				isInDs[i] = true;
				int nNext = next;
				for(int j = next + 1; j <= v; j++) {
					if((isPos & (1 << j)) == 0) {
						nNext = j;
						break;
					}
				}
				
				func(isPos, nNext);
				isPos = isPosCopy;
				isInDs[i] = false;
			}
		}
		
		isPos = isPosCopy;
		cStep--;
	}
}
