import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ManageEnergy {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new File("output.txt"));
		
		int T = s.nextInt();
		int it=0;
		while(T-- > 0){
			it++;
			
			int E = s.nextInt();
			int R = s.nextInt();
			int N = s.nextInt();
			
			Gain[] gains = new Gain[N];
			int totalGain = 0;
			int[] energy = new int[N];
			int[] energy2 = new int[N];
			
			Arrays.fill(energy, E);
			
			for(int i=0; i<N; i++){
				gains[i] = new Gain(s.nextInt(), i);
			}
			
			Arrays.sort(gains);
			
			for(int i=N-1; i>=0; i--){
				Gain gain = gains[i];
				
				totalGain += (energy[gain.id] - energy2[gain.id]) * gain.gain;
				
				int tmp2 = energy[gain.id] - R;
				energy[gain.id] = energy2[gain.id];
				
				int tmp = energy[gain.id];
				
				int j = gain.id;
				int k = gain.id - 1;
				while(tmp < E && j<N){
					energy[j] = Math.min(tmp, energy[j]);
					tmp += R;
					j++;					
				}
				
				while(k >= 0 && tmp2 > 0){
					energy2[k] = Math.max(energy2[k],tmp2);
					tmp2 = tmp2 - R;
					k--;
				}
				
				
			}
			
			pw.printf("Case #%d: %d\n", it, totalGain);
			
		}
		
		pw.close();
		
	}

	static class Gain implements Comparable {
		int gain;
		int id;
		
		public Gain(int gain, int id){
			this.gain = gain;
			this.id = id;
		}
		
		@Override
	    public int compareTo(Object o) {
			Gain g = (Gain) o;
			return this.gain - g.gain;
	    }	
	}
}
