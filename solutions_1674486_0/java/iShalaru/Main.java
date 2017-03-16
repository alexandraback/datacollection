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
	int color[];
	LinkedList<Integer>[] mas;
	void Solve(){
		int N = NextInt();
		color = new int[N];
		Arrays.fill(color, -1);
		mas = new LinkedList[N];
		int[] countPred = new int[N];
		for(int i =0; i < N;i++){
			int count  = NextInt();
			mas[i] = new LinkedList<Integer>();
			for(int j =0;j < count; j++)
			{
				int value = NextInt()-1;
				mas[i].addLast(value);
				countPred[i]++;
			}
		}
		int step = 0;
		boolean ans = false;
		for(int i = 0; i< N; i++){
			//if (countPred[i] > 1){//== 0
				Arrays.fill(color, -1);
				ans = DFS(i,step);
				if (ans) break;
				step++;
			//}
		}
		if (ans){
			out.print("Yes");
		}else {
			out.print("No");
		}
	}
	boolean DFS(int vertex,int step){
		boolean result = false;
		if (color[vertex] == step){
			result = true;
		}else if (color[vertex] == -1){
			
			color[vertex] = step;
			for(Integer newVertex : mas[vertex]){
				result = DFS(newVertex,step);
				if (result) break;
			}
		}
		return result;
	}
}
