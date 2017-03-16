import java.io.*;
import java.util.*;
import java.text.*;

public class Main implements Runnable{

	/**
	 * @param args
	 */
	private StringTokenizer stReader;
	private BufferedReader bufReader;
	private PrintWriter out;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		(new Main()).run();
	}

	@Override
	public void run(){
		// TODO Auto-generated method stub
		try {
			bufReader = new BufferedReader(new FileReader("input.txt"));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		stReader = null;
		Solves();
		out.flush();
	}
	public String ReadLine() {
		String result = null;

		try {
			result = bufReader.readLine();
		} catch (IOException e) {
		}
		return result;
	}
	public String NextString(){
		if (stReader == null || !stReader.hasMoreTokens()){
			stReader = new StringTokenizer(ReadLine(),"\n\r ");
		}
		return stReader.nextToken();
	}
	public int NextInt(){
		return Integer.parseInt(NextString());
	}
	public long NextLong(){
		return Long.parseLong(NextString());
	}
	public double NextDouble(){
		return Double.parseDouble(NextString());
	}
	void Solves(){
		int n = NextInt();
		for(int i =0; i < n; i++){
			out.print("Case #"  +(i + 1) + ": ");
			Solve();
			out.println();
		}
		out.flush();
	}
	
	int NeedAdd(int need){
		int result = 0;
		if (A <= need){
			while(A <= need){
				A += A-1;
				result++;
				if (result > mas.length) {result+= mas.length; break;}
			}
		}
		A+=need;
		return result;
	}
	long A;
	int[] mas;
	void Solve(){
		A = NextLong();
		int N = NextInt();
		mas = new int[N];
		for(int i =0;i < N; i++) mas[i] = NextInt();
		Arrays.sort(mas);
		int needAdd = 0;
		int [] countAdd = new int[mas.length];
		for(int i =0;i < N;i++){
			countAdd[i] = NeedAdd(mas[i]);
		}
		int min = Integer.MAX_VALUE;
		int countAllAdd = 0;
		for(int i =0; i< N; i++){
			countAllAdd += countAdd[i];
			int tmp = countAllAdd + countAdd.length - i - 1;
			if (tmp < min) min = tmp;
		}
		if (min > mas.length) min = mas.length;
		out.print(min);
	}
}
