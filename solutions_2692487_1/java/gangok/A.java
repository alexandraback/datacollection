import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;


public class A {
	static BufferedReader in;
	static BufferedWriter out;
	
	static int A, N;
	static Integer[] mote;
	
	private static void input () throws IOException {
		String temp = in.readLine();
		String[] temp2 = temp.split(" ");
		A = Integer.parseInt(temp2[0]);
		N = Integer.parseInt(temp2[1]);
		mote = new Integer[300];
		temp = in.readLine();
		temp2 = temp.split(" ");
		for(int i=0;i<N;i++)
			mote[i] = Integer.parseInt(temp2[i]);
	}
	
	private static int run() {
		Arrays.sort(mote, 0, N, new Comparator<Integer>()
			    {
	        @Override
	        public int compare(Integer x, Integer y)
	        {
	            return x - y;
	        }
	    });
		int minCount = N;
		int nowA = A;
		int added = 0;
		
		for(int i=0;i<N;i++) {
			if (mote[i] < nowA) {
				nowA += mote[i];
				if(i == N-1) {
					int tempCount = added;
					if(tempCount < minCount)
						minCount = tempCount;
				}
			} else {
				int tempCount = added + (N - i);
				if(tempCount < minCount)
					minCount = tempCount;
				
				if(nowA < 2)
					break;
				added++;
				nowA = nowA + (nowA - 1);
				i--;
			}
		}
		
		return minCount;
	}
	
	private static void output(int i,int result) throws IOException {
		out.write("Case #" + (i+1) + ": " + result + "\n");
	}
	
	public static void main(String[] args) {
		try {
			in = new BufferedReader(new FileReader("inputA.txt"));
			out = new BufferedWriter(new FileWriter("outputA.txt"));
			String temp = in.readLine();
			int T = Integer.parseInt(temp);
			for(int i=0;i<T;i++) {
				input();
				int result = run();
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
