import java.util.Arrays;

import verethragna.cjutils.FileProcessor;

/**
 * @author Verethragna
 */

public class B_Main {
	public static void main(String[] args) {
		FileProcessor fp = new FileProcessor(true);
		for(int i = 0; i < fp.cases; i++){
			int[] f = fp.getIntArray();
			int[] e = fp.getIntArray();
			Arrays.sort(e);
			int x = 0;
			int max = f[0];
			while(f[0] > 0 && f[2] > 0){
				f[2]--;
				x += f[0] * e[f[2]];
				f[0] = Math.min(f[1],max);
			}
			fp.writeCase(String.valueOf(x));
		}
		fp.finish();
	}
}
