import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class G_2 {

	public static void main(String[] args) throws Exception {
		G_2 instance = new G_2();
		instance.func();
	}

	class Data {
		int a, b;
		int key;

		public Data(int a, int b) {
			this.a = a;
			this.b = b;
			key = 0;
		}

	}

	Data[] datas;
	int star;
	int N;

	int find_b() {
		Data data;
		for (int j = 0; j < N; ++j) {
			data = datas[j];
			if (data.b <= star && data.key <= 1) {
				return j;
			}
		}
		return -1;
	}

	int find_a() {
		Data data;
		for (int j = 0; j < N; ++j) {
			data = datas[j];
			if (data.a <= star && data.key == 0) {
				return j;
			}
		}
		return -1;
	}

	class Cmpb implements Comparator<Data> {

		public int compare(Data a, Data b) {
			return b.b - a.b;
		}

	}

	public void func() throws Exception {
		PrintWriter bw = new PrintWriter(new FileWriter("1.txt"));
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int a, b;
		next_i: for (int i = 0; i < T; i++) {
			N = scan.nextInt();
			star = 0;
			datas = new Data[N];
			for (int j = 0; j < N; ++j) {
				a = scan.nextInt();
				b = scan.nextInt();
				datas[j] = new Data(a, b);
			}
			Arrays.sort(datas, new Cmpb());
			boolean valid = true;
			int count = 0;
			while (valid) {
				valid = false;
				int key = find_b();
				if (key != -1) {
					star += 2 - datas[key].key;
					datas[key].key = 2;
					valid = true;
					count++;
					continue;
				}
				key = find_a();
				if (key != -1) {
					star += 1;
					datas[key].key = 1;
					valid = true;
					count++;
					continue;
				}
			}
			for (int j = 0; j < N; ++j) {
				if (datas[j].key != 2) {
					System.out.println(String.format("Case #%d: Too Bad",
							(i + 1)));
					bw.write(String.format("Case #%d: Too Bad\n", (i + 1)));
					continue next_i;
				}
			}
			System.out.println(String.format("Case #%d: %d", (i + 1), count));
			bw.write(String.format("Case #%d: %d\n", (i + 1), count));
		}
		bw.flush();
		bw.close();
	}
}
