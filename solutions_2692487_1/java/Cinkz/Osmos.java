import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Osmos {

	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
			int cases = Integer.valueOf(in.readLine());
			String line;
			String[] tmp;
			int A, N, ops, tmpOps;
			int[] motes;
			for (int c = 1; c <= cases; c++) {
				ops = 0;
				line = in.readLine();
				tmp = line.split(" ");
				A = Integer.valueOf(tmp[0]);
				N = Integer.valueOf(tmp[1]);
				motes = new int[N];
				line = in.readLine();
				tmp = line.split(" ");
				System.out.println("C# " + c + " " + A + "=> " + line);
				for (int i = 0; i < N; i++) {
					motes[i] = Integer.valueOf(tmp[i]);
				}
				Arrays.sort(motes);
				System.out.print("solution: ");
				for (int i = 0; i < N; i++) {
					if (A < 2) {
						ops = N;
						break;
					}
					System.out.print(motes[i] + " ");
					if (A > motes[i]) {
						A += motes[i];
					} else {
						tmpOps = 0;
						while (A <= motes[i]) {
							A = A * 2 - 1;
							tmpOps++;
						}
						if (tmpOps < N - i) {
							ops += tmpOps;
							A += motes[i];
						} else {
							ops += (N - i);
							break;
						}
					}
				}
				System.out.println();
				System.out.println("OP: " + ops);
				out.write("Case #" + c + ": " + ops + "\n");
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
