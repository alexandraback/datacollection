import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Problem3 {
	public static void main(String[] args) {
		FileReader input;
		try {
			input = new FileReader("C-small-attempt2.in.txt");
			BufferedReader reader = new BufferedReader(input);
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			int test = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= test; k++) {
				// Solution here
				Scanner scanner = new Scanner(reader.readLine());
				int tribes = scanner.nextInt();
				int[][] parameters = new int[tribes][8];
				for (int i = 0; i < tribes; i++) {
					scanner = new Scanner(reader.readLine());
					for (int j = 0; j < 8; j++) {
						parameters[i][j] = scanner.nextInt();
					}
				}
				boolean attack = false;
				for (int i = 0; i < tribes; i++) {
					if (parameters[i][1] != 0)
						attack = true;
				}
				int result = 0;
				HashMap<Integer, Integer> wall = new HashMap<Integer, Integer>();
				int left, right, day = 0, strength = 0;
				boolean success = false;
				while (attack) {
				
					success = false;
					attack = false;
					HashMap<Integer, Integer> update = new HashMap<Integer, Integer>();
					for (int i = 0; i < tribes; i++) {
						if (parameters[i][0] == day && parameters[i][1] > 0) {
							left = parameters[i][2];
							right = parameters[i][3];
							strength = parameters[i][4];
							for (int j = left; j < right; j++) {
								if(!wall.containsKey(j)){
									wall.put(j, 0);
								}
								if (wall.get(j) < strength) {
									success = true;
									if (update.containsKey(j)) {
										if (strength > update.get(j)) {
											update.put(j, strength);
										}
									} else {
										update.put(j, strength);
									}
								}
							}
							if (success) result++;
							parameters[i][0] += parameters[i][5];
							parameters[i][1]--;
						
							parameters[i][2] += parameters[i][6];
							parameters[i][3] += parameters[i][6];
							parameters[i][4] += parameters[i][7];
						}
					}
					for (int i = 0; i < tribes; i++){
						if(parameters[i][1]>0) attack = true;
					}
					for (int i : update.keySet()) {
						wall.put(i, update.get(i));
					}
					day++;
				}
				out.println("Case #" + k + ": "+result);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
