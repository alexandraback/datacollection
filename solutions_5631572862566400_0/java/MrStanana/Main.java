import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws IOException {
		String file = "C-small-attempt0.in";
		BufferedReader br = new BufferedReader(new FileReader(file));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			int len = Integer.parseInt(br.readLine());
			String[] ss = br.readLine().split(" ");
			int[] ints = new int[len];
			for (int j = 0; j < len; j++) {
				ints[j] = Integer.parseInt(ss[j]);
			}
			int k = 0;
			for (int j = 0; j < len; j++) {
				ArrayList<Integer> arl = new ArrayList<>();
				arl.add(j + 1);
				boolean b = true;
				while (!arl.contains(ints[arl.get(arl.size() - 1) - 1])) {
					arl.add(ints[arl.get(arl.size() - 1) - 1]);
					if (arl.contains(ints[arl.get(arl.size() - 1) - 1]) && arl.size() >= 2 && ints[arl.get(arl.size() - 1) - 1] != arl.get(0) && ints[arl.get(arl.size() - 1) - 1] != arl.get(arl.size() - 2)) {
						b = false;
						break;
					}
				}
				if (ints[arl.get(arl.size() - 1) - 1] != arl.get(0))
					for (int l = 0; l < len; l++)
						if (!arl.contains(l + 1) && ints[l] == arl.get(arl.size() - 1)) {
							arl.add(l + 1);
							break;
						}
				if (b && arl.size() > k)
					k = arl.size();
			}
			bw.write("Case #" + (i + 1) + ": " + k);
			bw.newLine();
		}
		br.close();
		bw.close();
	}
}
