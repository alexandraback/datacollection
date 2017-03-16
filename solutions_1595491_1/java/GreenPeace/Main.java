import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					String[] number = br.readLine().split(" ");
					int n = Integer.valueOf(number[0]);
					int s = Integer.valueOf(number[1]);
					int p = Integer.valueOf(number[2]);
					int result = 0;
					for (int j = 3; j < 3 + n; j++) {
						int total = Integer.valueOf(number[j]);
						int avg = total/3;
						if (avg >= p || (avg == p-1 && total % 3 > 0)) {
							result++;
						}
						else if (s > 0 && (avg == p-2 && total % 3 == 2 || avg == p-1 && avg != 0)) {
							s--;
							result++;
						}
					}
					out.write("Case #"+ (i + 1) +": " + result + "\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}