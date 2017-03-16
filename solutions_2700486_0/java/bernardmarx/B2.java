import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B2 {

	static int N, X, Y;
	
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("B.in"));
		StringBuffer buf = new StringBuffer();
		int t = Integer.parseInt(reader.readLine());
		StringTokenizer st;
		computeSZ();
		computeComb();
		computePots();
		for (int c = 1; c <= t; c++) {
			st = new StringTokenizer(reader.readLine());
			N = Integer.parseInt(st.nextToken()); 
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			buf.append("Case #"+c+": "+solve()+"\n");
		}
		System.setOut(new PrintStream("B.out"));
		System.out.print(buf);
	}

		static double solve(){
		if (X<0) X*=-1;
		if (Y<0) Y*=-1;
		int level = (X + Y)/2;
		if (level>=MS) return 0d;
		if (level == 0) return 1d;
		int hasta = sz[level];
		int menos = sz[level - 1];
		if (N>=hasta) return 1d;
		if (N<=menos) return 0d;
		int quedan = N - menos;
		int cuantos = hasta - menos;
		int altura = Y+1;
		//if (quedan < altura) return 0d;
		int maxAlt = (cuantos + 1)/2;
		while (quedan >= maxAlt){
			quedan-=2;
			altura--;
			maxAlt--;
		}
		if (altura<=0) return 1d;
		double ret=0;
		for (int j = altura; j <= quedan; j++) {
			ret += C[quedan][j]*pots[quedan];
		}
		return ret;
	}

	static int MAXNCOM = 1600;
	
	static double[][] C = new double[MAXNCOM][MAXNCOM]; 
	static double[] pots = new double[MAXNCOM];
	
	static void computePots(){
		pots[0]=1d;
		for (int i = 1; i < MAXNCOM; i++) {
			pots[i] = pots[i - 1]/2d; 
		}
	}
	
	static void computeComb(){
		for (int cn = 0; cn < MAXNCOM; cn++) {
			C[cn][0]=1;
		}
		for (int cn = 1; cn < MAXNCOM; cn++) {
			C[0][cn]=0;
		}
		for (int i = 1; i < MAXNCOM; i++) {
			for (int j = 1; j < MAXNCOM; j++) {
				C[i][j]=C[i-1][j]+C[i-1][j-1];
			}
		}
	}
	
	static int[] sz;
	static int MS = 1000;
	
	static void computeSZ(){
		sz = new int[MS];
		sz[0]=1;
		int mas = 5;
		for (int i = 1; i < MS; i++) {
			sz[i] = sz[i-1]+mas; 
			mas+=4;
		}
	}
}
