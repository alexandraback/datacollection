import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CodeJam2016R1AP3 {
	//static int[] bff;
	static int gc = 0;
	static boolean found = false;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int caseid=1; caseid<=T; caseid++)
		{
			gc = 0;
			found = false;
			int N = Integer.parseInt(br.readLine());
			int[] bff = new int[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i =0 ; i <N; i++ ) {
				bff[i] = Integer.parseInt(st.nextToken())-1;
			}
			//System.out.println("BFF: " + Arrays.toString(bff));
			int[] arr = new int[N];
			for(int i = 0; i < N; i++) {
				arr[0] = i;
				arr[1] = bff[i];
				find(2, N, arr, bff);
			}
			System.out.println("Case #"+caseid + ": " + gc);
		}
	}
	public static void find(int len, int N, int[] arr, int[] bff) {
		//System.out.println("::  " + Arrays.toString(arr));
		//if(found) return;
		if(len == N) {
			if(bff[arr[N-1]] == arr[0] || bff[arr[N-1]] == arr[N-2]) {
				gc = N;
			}
			return;
		}
		int c = arr[len - 1];
		int cbff = bff[c];
		if(cbff == arr[0]) {
			if(len> gc) {
				gc = len;
			}
			return;
		}else if( cbff == arr[len - 2]) {
			if(len > gc) {
				gc = len;
			}
			for(int i = 0; i < N; i++) {
				boolean yes = false;
				for(int j = 0; j< len; j++) {
					if(arr[j] == i) yes = true;
				}
				if(!yes) {
				if(bff[i] == c && i != cbff) {
					arr[len] = i;
					find(len + 1, N, arr, bff);
				}
				}
			}
		} else {
			arr[len] = cbff;
			find(len + 1, N, arr, bff);
		}
	}
}
