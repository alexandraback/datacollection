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
		vovels = new HashSet();
		vovels.add('a');vovels.add('e');vovels.add('i');
		vovels.add('o');vovels.add('u');
		int n = NextInt();
		for(int i =0; i < n; i++){
			out.print("Case #"  +(i + 1) + ": ");
			Solve();
			out.println();
		}
		out.flush();
	}
	HashSet vovels; 
	ArrayList<Integer> FoundPosition(char[] work,int n){
		ArrayList<Integer> result = new ArrayList<Integer>();
		int count = 0;
		for(int i =0;i < work.length; i++){
			if (vovels.contains(work[i])){
				count = 0;
			}else count++;
			if (count>=n){
				result.add(i - n+1);
				//count = 0;
			}
		}
		return result;
	}
	void Solve(){
		char[] work = NextString().toCharArray();
		int n = NextInt();
		ArrayList<Integer> position = FoundPosition(work,n);
		int pred = 0;
		int length = work.length;
		long result = 0;
		for(int item : position){
			if (pred == item){
				result += length - n - item+1;
				pred++;
			}else {
				int countLeft = item - pred+1;
				int countRight = length - item - n+1;
				result += countLeft*countRight;
				pred = item+1;
			}
		}
		out.print(result);
	}
	
}
