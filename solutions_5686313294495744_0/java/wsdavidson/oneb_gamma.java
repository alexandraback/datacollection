import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class oneb_gamma {
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
		String[][] arr = new String[N][2];
		HashMap<String, Integer> map1 = new HashMap<String, Integer>();
		HashMap<String, Integer> map2 = new HashMap<String, Integer>();
		for (int i = 0; i < N; ++i) {
			String[] sarr = reader.readLine().split(" ");
			arr[i][0] = sarr[0];
			arr[i][1] = sarr[1];
			
			if (!map1.containsKey(sarr[0])) {
				map1.put(sarr[0], 0);
			}
			if (!map2.containsKey(sarr[1])) {
				map2.put(sarr[1], 0);
			}
			
			map1.put(sarr[0], map1.get(sarr[0]) + 1);
			map2.put(sarr[1], map2.get(sarr[1]) + 1);
		}
		
		int cheat = 0;
		
		for (int i = 0; i < arr.length; ++i) {
			if (map1.get(arr[i][0]) > 1 && map2.get(arr[i][1]) > 1) {
				cheat++;
			}
		}
		
		return " " + cheat;
	}
}