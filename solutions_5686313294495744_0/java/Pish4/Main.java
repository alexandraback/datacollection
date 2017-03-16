import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt1.in"));
		int n = Integer.parseInt(reader.readLine());

		for (int i = 1; i <= n; ++i) {
			List<String> firstl = new ArrayList<String>();
			List<String> secondl = new ArrayList<String>();
			HashSet<String> first = new HashSet<>();
			HashSet<String> second = new HashSet<>();
			int result = 0;
			int t = Integer.parseInt(reader.readLine());
			for (int j = 0; j < t; ++j) {
				String[] line = reader.readLine().split(" ");
				firstl.add(line[0]);
				secondl.add(line[1]);
				first.add(line[0]);
				second.add(line[1]);
			}
			for (int j = 0; j < firstl.size();++j) {	
				boolean found1=false,found2=false;
				for (int k = 0; k < firstl.size();++k) {
					if (j==k)continue;
					if (firstl.get(j).equals(firstl.get(k))) {
						found1=true;
					}
					if (secondl.get(j).equals(secondl.get(k))) {
						found2=true;
					}
				}
				if (found1&&found2) {
					result++;
				}
				
			}
			System.out.println("Case #" + i + ": " + result);
		}
		
	}

}
