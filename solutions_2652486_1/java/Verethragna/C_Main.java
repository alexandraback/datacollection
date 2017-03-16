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
			String[] ins = fp.getStringArray();
			long[] in = new long[ins.length];
			for(int j = 0; j < ins.length; j++)
				in[j] = Long.parseLong(ins[j]);
			int[] pos = new int[f[2]-1];
			Arrays.fill(pos, 0);
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
			
			String tout;
			while(true){
				tout = "\n";
				out += '\n';
				int k = f[1];
				pos2 = pos.clone();
				for(int l = f[2]-2; l >= 0 && k > 0; l--)
					for(;pos[l] > 0 && k > 0; pos[l]--){
						k--;
						tout += (l+2);
					}
				
				if(k > 0){
					pos = pos2.clone();
					if(pos[6] > 0 && (int)(Math.random()*(f[2]-1)) == 6){
						System.out.println(i + " " + 8 + " " + pos[6]);
						pos[6]--;
						pos[2]++;
						pos[0]++;
					} else if(pos[4] > 0 && (int)(Math.random()*(f[2]-1)) == 6){
						System.out.println(i + " " + 6 + " " + pos[4]);
						pos[4]--;
						pos[1]++;
						pos[0]++;
					} else if(pos[2] > 0 && (int)(Math.random()*(f[2]-1)) == 6){
						System.out.println(i + " " + 4 + " " + pos[2]);
						pos[2]--;
						pos[0] += 2;
					} else
						for(;k > 0; k--)
							pos[(int)(Math.random()*(f[2]-1))]++;
				} else
					break;
			}
			out += tout;
			
		}
		fp.writeCase(out);
		fp.finish();
	}
}
