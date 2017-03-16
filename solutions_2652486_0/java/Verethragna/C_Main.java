import java.util.ArrayList;
import java.util.Arrays;

import verethragna.cjutils.FileProcessor;

/**
 * @author Verethragna
 */

public class C_Main {
	public static void main(String[] args) {
		FileProcessor fp = new FileProcessor(false);
		fp.skipLine();
		int[] f = fp.getIntArray();
		String out = "";
		for(int i = 0; i < f[0]; i++){
			int[] in = fp.getIntArray();
			int[] pos = new int[f[2]-1];
			Arrays.fill(pos, 0);
			pos[0] = f[1];
			int[] pos2 = new int[f[2]-1];
			for(int j = 0; j < f[3]; j++){
				if(in[j] == 1) continue;
				Arrays.fill(pos2, 0);
				for(int k = f[2]-2; k >= 0;)
					if(in[j] % (k+2) == 0){
						in[j] /= (k+2);
						pos2[k]++;
					} else
						k--;
				for(int k = 0; k < f[2]-1; k++)
					pos[k] = Math.max(pos[k], pos2[k]);
			}
			out += '\n';
			int k = f[1];
			for(int l = f[2]-2; l >= 0 && k > 0; l--)
				for(;pos[l] > 0 && k > 0; pos[l]--){
					k--;
					out += (l+2);
				}
		}
		fp.writeCase(out);
		fp.finish();
	}
}
