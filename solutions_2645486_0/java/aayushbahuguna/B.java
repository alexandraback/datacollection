package codejam2013Round1A;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
	public static int G = 0;
	public static int E, R, N;
	public static int[] V;
	public static int[] S;
	public static void main(String[] args) throws IOException {
		boolean large = false;
//		large = true;
		String dir = "/home/aayush/Dropbox/workspace/workspaceWindows/AlgorithmJava/GoogleCodeJam/codejam2013Round1A/";
		String OutputFile = dir + (large ? "B-large.out" : "B-small.out");
		BufferedWriter fw = new BufferedWriter(new FileWriter(OutputFile));
		String inputFile = dir + "B-small-attempt0.in";
		//Scanner st = new Scanner(System.in);
		Scanner st = new Scanner(new BufferedReader(new FileReader(inputFile)));
		int T = st.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			E = st.nextInt();
			R = st.nextInt();
			N = st.nextInt();
			V = new int[N];
			S = new int[N];
			G = 0;
			for(int i = 0; i < N; i++){
				V[i] = st.nextInt();
			}
			recurse(0, 0 ,E);
			fw.write("Case #" + cases + ": " + G + "\n");
			System.out.println("Case #" + cases + ": " + G);
		}
		fw.flush();
		fw.close();
	}
	
	public static void recurse(int activity, int gain, int currentEnergy){
		if(activity == N || currentEnergy < 0) return;
		
		if(activity == N - 1){
			G = Math.max(G, gain + currentEnergy * V[N - 1]);
		}
		for(int i = 0; i <= currentEnergy; i++){
			S[activity] = i;
			recurse(activity + 1, gain + i * V[activity], Math.min(currentEnergy - i + R, E));
		}
		
		
		
	}
	
}
