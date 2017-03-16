import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class second {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		int N = Integer.parseInt(reader.readLine());
		int[][] arr = new int[2*N-1][N];
		
		for (int i = 0; i < 2*N-1; ++i) {
			String[] a = reader.readLine().split(" ");
			for (int j = 0; j < N; ++j) {
				arr[i][j] = Integer.parseInt(a[j]);
			}
		}
		
		int[] counts = new int[2501];
		for (int i = 0; i < counts.length; ++i) counts[i] = 0;
		
		for (int i = 0; i < 2*N-1; ++i) {
			for (int j = 0; j < N; ++j) {
				counts[arr[i][j]]++;
			}
		}
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < counts.length; ++i) {
			if (counts[i] %2 == 1) list.add(i);
		}
		
		Collections.sort(list);
		
		String out = "";
		for (int i = 0; i < list.size(); ++i) out += " " + list.get(i);
		
		return out;
	}
}