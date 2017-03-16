import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Qd {
	
	public int findHigh(int[] array, int start, int val) {
		for (int i = start; i >= 0; i--) {
			if (array[i] == val) {
				return i;
			}
		}
		return -1;
	}
	
	public int findLow(int[] array, int start, int val) {
		for (int i = start; i < array.length; i++) {
			if (array[i] == val) {
				return i;
			}
		}
		return -1;
	}
	
	public void solve(Scanner scan, PrintWriter out) {
		int blocks = scan.nextInt();
		double[] a = new double[blocks];
		double[] b = new double[blocks];
		for (int i = 0; i < blocks; i++) {
			a[i] = scan.nextDouble();
		}
		for (int i = 0; i < blocks; i++) {
			b[i] = scan.nextDouble();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		int[] ordered = new int[2*blocks];
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < blocks && j < blocks) {
			if (a[i] < b[j]) {
				ordered[k] = 1;
				i++;
			} else {
				ordered[k] = 2;
				j++;
			}
			k++;
		}
		if (i < blocks) {
			while (k < 2*blocks) {
				ordered[k] = 1;
				k++;
			}
		} else if (j < blocks) {
			while (k < 2*blocks) {
				ordered[k] = 2;
				k++;
			}
		}
		int[] ordered_copy = new int[2*blocks];
		System.arraycopy(ordered, 0, ordered_copy, 0, 2*blocks);
		int total = 0;
		int al = 0;
		int bl = 0;
		int ah = 2*blocks-1;
		int bh = 2*blocks-1;

		ah = findHigh(ordered, ah, 1);
		while (ah > bl) {
			bh = findHigh(ordered, bh, 2);
			if (ah > bh) {
				bl = findLow(ordered, bl, 2);
				if (bl == -1) {
					break;
				}
				ordered[bl] = 0;
				int alw = findLow(ordered, bl, 1);
				if (alw == -1) {
					break;
				}
				ordered[alw] = 0;
				total++;
			} else {
				al = findLow(ordered, al, 1);
				if (al == -1) {
					break;
				}
				ordered[al] = 0;
				ordered[bh] = 0;
			}
		}
		
		System.out.print(total + " ");
		out.print(total + " ");
		
		total = 0;
		al = 0;
		bl = 0;
		ah = 2*blocks-1;
		bh = 2*blocks-1;
		System.arraycopy(ordered_copy, 0, ordered, 0, 2*blocks);
		
		while (ah > bl) {
			ah = findHigh(ordered, ah, 1);
			bh = findHigh(ordered, bh, 2);
			if (ah == -1 && bh == -1) {
				break;
			}
			if (ah > bh) {
				total++;
				ordered[ah] = 0;
				bl = findLow(ordered, bl, 2);
				ordered[bl] = 0;
			} else {
				ordered[ah] = 0;
				ordered[bh] = 0;
			}
		}
		
		System.out.println(total);
		out.println(total);
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("inputqds.in"));
        PrintWriter out = new PrintWriter("outputqds.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Qd().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}