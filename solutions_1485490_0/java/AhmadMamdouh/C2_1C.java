import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class C2_1C {
	static class Product {
		long num;
		int type;

		public Product(long n, int t) {
			num = n;
			type = t;
		}
	}

	static Product[] box;
	static Product[] toy;

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int tt = 1; tt <= T; tt++) {
			int n = in.nextInt();
			int m = in.nextInt();
			box = new Product[n];
			toy = new Product[m];
			for (int i = 0; i < n; i++) {
				long ai = in.nextLong();
				int type = in.nextInt();
				box[i] = new Product(ai, type);
			}
			for (int i = 0; i < m; i++) {
				long ai = in.nextLong();
				int type = in.nextInt();
				toy[i] = new Product(ai, type);
			}
			long res = 0;
			if (n == 1) {
				for(int i=0;i<m;i++){
					if(box[0].type==toy[i].type){
						long min = Math.min(box[0].num, toy[0].num);
						box[0].num -= min;
						toy[0].num -= min;
						res += min;
					}
				}
			} else if (n == 2) {
				for (int i = 0; i <= m; i++) {
						Product[] curr = new Product[m];
						for (int k = 0; k < curr.length; k++) {
							curr[k] = new Product(toy[k].num, toy[k].type);
						}
						long[] arr = new long[2];
						arr[0] = box[0].num;
						arr[1] = box[1].num;
						long tres = 0;
						for (int k = 0; k < m; k++) {
							if (k <= i) {
								if (toy[k].type == box[0].type) {
									long min = Math.min(arr[0], curr[k].num);
									arr[0] -= min;
									curr[k].num -= min;
									tres += min;
								}
							}
							if (k >= i)
								if (toy[k].type == box[1].type) {
									long min = Math.min(arr[1], curr[k].num);
									arr[1] -= min;
									curr[k].num -= min;
									tres += min;
								}

						}
						res = Math.max(tres, res);
					}
				
			} else {
				for (int i = 0; i < m; i++)
				{
					for (int j = i; j < m; j++)
					{
						Product[] curr = new Product[m];
						for (int k = 0; k < curr.length; k++) {
							curr[k] = new Product(toy[k].num, toy[k].type);
						}
						long[] arr = new long[3];
						arr[0] = box[0].num;
						arr[1] = box[1].num;
						arr[2] = box[2].num;
						long tres = 0;
						for (int k = 0; k < m; k++) {
							if (k <= i) {
								if (toy[k].type == box[0].type) {
									long min = Math.min(arr[0], curr[k].num);
									arr[0] -= min;
									curr[k].num -= min;
									tres += min;
								}
							}
							if (k >= i && k <= j) {
								if (toy[k].type == box[1].type) {
									long min = Math.min(arr[1], curr[k].num);
									arr[1] -= min;
									curr[k].num -= min;
									tres += min;
								}
							}
							if (k >= j)
								if (toy[k].type == box[2].type) {
									long min = Math.min(arr[2], curr[k].num);
									arr[2] -= min;
									curr[k].num -= min;
									tres += min;
								}

						}
						res = Math.max(tres, res);
					}
				}
			}
			System.out.println("Case #" + tt + ": " + res);
		}
	}
}
