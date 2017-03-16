package con2013R1B;

import java.io.*;
import java.util.*;

public class B {

	//private static final String islarge = "-large";
	private static final String fileName = "results/con2013R1B/"+B.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	private static int[] layers;
	
	private void solve() {
		int N = in.nextInt(),
			X = Math.abs(in.nextInt()),
			Y = in.nextInt();
		int layer = (X+Y)/2;
		double P = 0;
		if(N >= layers[layer]){
			P = 1;
		}
		else if(N <= layers[layer-1] || X == 0){
			P = 0;
		}
		else{
			int ds = (N-layers[layer-1]);
			if((Y+1) > ds){
				P = 0;
			}else if(ds >= ((layer*2)+(Y+1))){
				P = 1;
			}
			else{
				P = 0.5D;
				double[]chances = new double[ds];
				int maxHeight = (layer*2);
				chances[0]=0.5;
				for(int j=1;j<ds;j++){
					if(j==(maxHeight)) 
						chances[j]=1;
					else
						chances[j]=chances[j-1]+((1-chances[j-1])/2);
				}
				// y is the height
				for(int i=1;i<=Y;i++){
					double[] nChances = new double[ds];
					for(int j=i;j<ds;j++){
						nChances[j]=chances[j-1]*0.5D + nChances[j-1]*0.5D;
					}
					chances = nChances;
				}
				P = chances[ds-1];
			}
		}
		out.println(P);
		System.out.println(P);
	}
	
	public static void pre(){
		layers = new int[10002];
		layers[0]=1;
		// 1 6 15
		int plus = 5;
		for(int i=1;i<10001;i++){
			layers[i]=layers[i-1]+plus;
			plus+=4;
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		pre();
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
