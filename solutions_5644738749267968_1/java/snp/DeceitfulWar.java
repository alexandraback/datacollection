import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class DeceitfulWar {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		DeceitfulWar me = new DeceitfulWar();
		FileReader fr = new FileReader("D-large.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);

		int T = Integer.valueOf(br.readLine());
		int N = 0;
		String[] tokens = null;
		double[] n1 = null;
		double[] n2 = null;
		int result1 = 0;
		int result2 = 0;

		for (int i = 1; i <= T; i++) {
			N = Integer.valueOf(br.readLine());
			tokens = br.readLine().split(" +");
			n1 = new double[tokens.length];
			n2 = new double[tokens.length];
			for (int m = 0; m < tokens.length; m++) {
				n1[m] = Double.valueOf(tokens[m]);
			}
			tokens = br.readLine().split(" +");
			for (int m = 0; m < tokens.length; m++) {
				n2[m] = Double.valueOf(tokens[m]);
			}

			Arrays.sort(n1);
			Arrays.sort(n2);

			result1 = me.getResultDWar(n1, n2);
			result2 = me.getResultWar(n1, n2);

			bw.write("Case #" + i + ": " + result1 + " " + result2);
			bw.write('\n');

		}

		br.close();
		fr.close();
		bw.close();
		fw.close();
	}

	private int getResultDWar(double[] n1_in, double[] n2_in) {
		
		double[] n1 = n1_in.clone();
		double[] n2 = n2_in.clone();
		
		int p =0;
		int min2 = 0;
		int max2 = n2.length - 1;
		
		for(int i = 0;i< n1.length && max2>=min2;i++){
			
			if(n1[i]< n2[min2]) {
				n2[max2] = 0;
				max2 --;
			}else{
				n2[min2] =0;
				min2 ++;
				p++;
			}
		}
		
		
		
		return p;
	}

	private int getResultWar(double[] n1_in, double[] n2_in) {
		
		double[] n1 = n1_in.clone();
		double[] n2 = n2_in.clone();
		
		int p = 0;
		boolean kenpicksmall;
		
		for (int i = 0; i < n1.length; i++) {
			kenpicksmall = true;
			
			for (int m = 0; m < n2.length; m++) {
				if (n2[m] > n1[i]) {
					n2[m] = 0;
					kenpicksmall = false;
					break;
				}
			}
			
			if(kenpicksmall){
				for(int m = 0;m< n2.length;m++){
					if(n2[m]==0) continue;
					else n2[m] = 0; break;
				}
				
				p++;
			}
	
		}// i loop

		return p;
	}

}
