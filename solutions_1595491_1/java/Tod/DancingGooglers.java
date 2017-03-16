import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class DancingGooglers {
	

	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
		Scanner sc;
		try {
			sc = new Scanner(new FileInputStream("B-large.in"));
		} catch (FileNotFoundException e) {
			sc = new Scanner(System.in); // file not exist, so get input from console
		}
		
		Writer out;
		
		try {
			out = new OutputStreamWriter(new FileOutputStream("B-large.out"));
		} catch (FileNotFoundException e) {
			out = new OutputStreamWriter(System.out); // use console
		}
		
		int T = sc.nextInt();
		
		for (int t = 0; t < T; t++) {
			int N = sc.nextInt(); // num dancers
			int S = sc.nextInt(); // num surprises
			int P = sc.nextInt(); // minimum best result
			
			int[] totals = new int[N]; // total scores for all dancers;
			int count = 0;
			
			for (int n = 0; n < N; n++)
				totals[n] = sc.nextInt();
			
			quickSortDesc(totals, 0, totals.length - 1);
			
			for (int n = 0; n < N; n++) {
				if (findBest(totals[n]) >= P)
					count++;
				else if (S > 0) {
					if (findSurpriseBest(totals[n]) >= P) {
						count++;
						S--;
					}
				}
			}
			
			// output
			System.out.println("Case #" + (t + 1) + ": " + count);
			try {
				out.write("Case #" + (t + 1) + ": " + count + "\n");
			} catch (IOException e) {
				// do nothing
			}
		}

		
		try {
			out.close();
		} catch (IOException e) {
			// do nothing
		}
	}
	
	public static void quickSortDesc (int arr[], int left, int right) {
		int i = left, j = right, tmp;
		int pivot = arr[(left + right) / 2];
		
		while (i < j) {
			while (arr[i] > pivot)
				i++;
			while (arr[j] < pivot)
            	j--;
			if (j >= i) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}
		}
		
		if (left < j)
			quickSortDesc(arr, left, j);
		if (i < right)
			quickSortDesc(arr, i, right);
	}

	static Boolean canSurprise(int t) {
		return (t%3 != 1);
	}
	
	static int findBest(int t) {
		if (t > 0) {
			if (t%3 == 0)
				return t/3;
			else return t/3 + 1;
		} else return t;
	}
	
	static int findSurpriseBest(int t) {
		if (t > 0) {
			if (t%3 == 2)
				return t/3 + 2;
			else return t/3 + 1;
		} else return t;	
	}

}
