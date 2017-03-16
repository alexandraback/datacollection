package Round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Power {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br;
		try {
			int N;
			br = new BufferedReader(new FileReader("B-small-attempt8.in"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line = br.readLine();
			N = Integer.parseInt(line);
			int count = 1;
			while (count <= N) {
				line = br.readLine();
				String[] strs = line.split(" ");
				System.out.println(line);
				int E = Integer.parseInt(strs[0]);
				int R = Integer.parseInt(strs[1]);
				int num = Integer.parseInt(strs[2]);
				int init = E;
				line = br.readLine();
				System.out.println(line);
				String[] values = line.split(" ");
				int gain = 0;
				for (int i = 0; i < values.length; i++) {
					int value = Integer.parseInt(values[i]);
					int nextValue = 0;
					int maxIndex = i;
					for (int j = i + 1; j < values.length; j++) {
						if (Integer.parseInt(values[j]) > Integer
								.parseInt(values[i])) {
							maxIndex = j;
							break;
						}
					}

					int totalGain = (maxIndex - i) * R;

					if (i < values.length - 1)
						nextValue = Integer.parseInt(values[i + 1]);
					int used = 0;
					// if (init >= R) {
					// if (nextValue >= value) {
					// int gap = E - init;
					// if (gap >= R)
					// used = 1;
					// else
					// used = (R - gap);
					// gain += used * value;
					// } else {
					// if (maxIndex > i + 1) {
					// if (totalGain < init)
					// used = totalGain;
					// else
					// used = init;
					// gain += used * value;
					// } else {
					// used = init;
					// gain += used * value;
					// }
					// }
					// } else {
					//
					// }
					if (nextValue >= value) {
						int gap = E - init;
						if (gap >= R) {
							used = R - 1;
						} else
							used = (R - gap);
						gain += used * value;
					} else {
						if (maxIndex > i + 1) {
							if (totalGain < init)
								used = totalGain;
							else
								used = init;
							// used = (gap - R);
							gain += used * value;
						} else {
							used = init;
							gain += used * value;
						}
					}
					init = init - used + R;
					System.out.println(gain + " " + used + " " + init + " "
							+ maxIndex + " " + totalGain);

					if (init > E)
						init = E;
				}
				System.out.println("Case #" + count + ": " + gain);
				pw.write("Case #" + count + ": " + gain + "\n");
				pw.flush();
				count++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
