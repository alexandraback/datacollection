import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class B {
	static BufferedReader in;
	static BufferedWriter out;
	
	static int N,X,Y;
	
	static final int MAX = 100;
	
	static int[] fact;
	static int[][] comb;
	
	private static void input () throws IOException {
		String temp = in.readLine();
		String temp2[] = temp.split(" ");
		N = Integer.parseInt(temp2[0]);
		X = Integer.parseInt(temp2[1]);
		Y = Integer.parseInt(temp2[2]);
	}
	
	static void addData(double[][] prob, int[] comList, int start, int phase, int combNum, int length) {
		int bunmo = 1;
		bunmo = bunmo << combNum;
		for(int i=start;i<start+length;i++) {
			int x = phase * 2 - i;
			int y = 0 + i;
			prob[x][y] += (double)comList[i-start] / (double)bunmo;
		}
	}
	
	static int fact(int n) {
		if(fact[n] != 0)
			return fact[n];
		else {
			int ret = fact(n-1) * n;
			fact[n] = ret;
			return fact[n];
		}
	}
	
	static int comb(int a,int b) {
		if(comb[a][b] != 0)
			return comb[a][b];
		else {
			comb[a][b] = fact(a) / (fact(b) * fact(a-b));
			return comb[a][b];
		}
	}
	
	static int[] makeComList(int num, int length) {
		int[] ret = new int[length];
		for(int i=0;i<num;i++) {
			if(i < length)
				ret[i] = comb(num-1,i);
			else
				ret[0] += comb(num-1,i);
		}
		return ret;
	}
	
	static void add(double[][] prob, int phase, int count, int thisEnd) {
		if (count == thisEnd - 1) {
			prob[0][phase * 2] += 1;
		} else {
			int max = phase * 2  + 1;
			int combNum = count + 1;
			if(combNum > max) combNum = max;
			
			int center = (thisEnd / 2);
			int start;
			int length;
			if(count < center) {
				start = 0;
				length = count + 1;
			}
			else {
				start = count - center;
				length = thisEnd - count - 1;
			}
			
			
			int[] comList = makeComList(combNum, length);
			//int[] aftercomList = adjustComList(comList, combNum, length);
			addData(prob, comList, start, phase, combNum, length);
		}
	}
	
	private static double run() {
		double[][] prob = new double[1600][1600];
		for(int i=0;i<1600;i++)
			for(int j=0;j<1600;j++)
				prob[i][j] = 0;
		System.out.println("Init end");
		
		int phase = 0;
		int count = 0;
		int thisEnd = 4 * phase + 1;
		
		for(int i=0;i<N;i++) {
			add(prob,phase,count, thisEnd);
			count++;
			if(thisEnd == count) {
				phase++;
				thisEnd = 4 * phase + 1;
				count = 0;
			}
		}
		if (X < 0) X = X * -1;
		if (Y < 0) return 0;
		if (X > 1600) return 0;
		if (Y > 1600) return 0;
		return prob[X][Y];
	}
	
	private static void output(int i,double result) throws IOException {
		out.write("Case #" + (i+1) + ": " + result + "\n");
	}
	
	public static void main(String[] args) {
		try {
			in = new BufferedReader(new FileReader("inputB.txt"));
			out = new BufferedWriter(new FileWriter("outputB.txt"));
			String temp = in.readLine();
			
			fact = new int[MAX];
			comb = new int[MAX][MAX];
			for(int i=0;i<100;i++) {
				fact[i] = 0;
				for(int j=0;j<100;j++)
					comb[i][j] = 0;
			}
			fact[0] = 1;
			fact[1] = 1;
			int T = Integer.parseInt(temp);
			for(int i=0;i<T;i++) {
				input();
				double result = run();
				output(i,result);
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


	}
}


