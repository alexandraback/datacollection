import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int[] list = times();
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++){
			solve(i, list);
		}
	}

	public static int[] times() throws IOException{
		int[] list = new int[1001];
		list[0] = 0;
		list[1] = 1;
		list[2] = 2;
		list[3] = 3;
		list[4] = 3;
		list[5] = 4;
		for (int i=6; i<=1000; i++){
			int a,b;
			if (i%2 == 0){
				a = i / 2;
				b = i / 2;
			}else{
				a = (i-1) / 2;
				b = (i+1) / 2;
			}
			list[i] = Math.min(Math.max(list[a], list[b])+1, i);
		}
		return list;
	}

	public static void solve(int num, int[] list) throws IOException{
		int P = Integer.parseInt(br.readLine());
		StringTokenizer data = new StringTokenizer(br.readLine(), " ");
		int[] counts = new int[1001];
		for (int i=0; i<=1000; i++){
			counts[i] = 0;
		}
		for (int i=0; i<P; i++){
			counts[Integer.parseInt(data.nextToken())]++;
		}

		int time = 0;
		int minTime = Integer.MAX_VALUE;

		for (int i=1000; i>0; i--){
			if (counts[i] == 0) continue;
			minTime = Math.min(minTime, time + i);

			int a,b;
			if (i%2 == 0){
				a = i / 2;
				b = i / 2;
			}else{
				a = (i-1) / 2;
				b = (i+1) / 2;
			}

			time += counts[i];
			counts[a] += counts[i];
			counts[b] += counts[i];
			counts[i] = 0;
		}
		System.out.println("Case #" + (num+1) + ": " + minTime);
	}
}
