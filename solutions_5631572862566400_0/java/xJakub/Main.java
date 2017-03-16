import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	static FileReader fr;
	static Scanner sc;
	static FileWriter fw;

	public static void openFiles(String inFile, String outFile) throws IOException {	
		fr = new FileReader(inFile);
		fw = new FileWriter(outFile);
		sc = new Scanner(fr);
		sc.useLocale(Locale.US);
	}
	public static void closeFiles() throws IOException {
		sc.close();
		fw.close();
		fr.close();
	}
	public static void writeLine(String line) throws IOException {
		write(line + "\n");
	}
	public static void write(String str) throws IOException {
		System.out.print(str);
		fw.write(str);
	}


	public static void main(String[] args) throws IOException {
		openFiles("C-small-attempt0.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		for (int i=1; i<=t; i++) {
			write("Case #"+i+": ");
			processCase(t);
			writeLine("");
		}

		closeFiles();
	}

	public static int n;
	public static int bff[];
	public static int selection[];
	public static boolean used[];
	
	public static int getBest(int nextPrependPos, int nextAppendPos) {
		int result = 0;
		
		for (int i=1; i<=n; i++) {
			if (used[i]) continue;

			// check if possible to prepend
			if (bff[i] == selection[nextPrependPos+1]
					|| bff[selection[nextPrependPos+1]] == i
					) {
				used[i] = true;
				selection[nextPrependPos] = i;
				result = Math.max(result, 1+getBest(nextPrependPos-1, nextAppendPos));
				selection[nextPrependPos] = 0;
				used[i] = false;
			}

			// check if possible to append
			if (bff[i] == selection[nextAppendPos-1]
					|| bff[selection[nextAppendPos-1]] == i
					) {
				used[i] = true;
				selection[nextAppendPos] = i;
				result = Math.max(result, 1+getBest(nextPrependPos, nextAppendPos+1));
				selection[nextAppendPos] = 0;
				used[i] = false;
			}

			// check if possible to append group
			int next = i;
			int count = 0;
			boolean ok = false;
			while(!used[next]) {
				selection[nextAppendPos+count] = next;
				count++;
				used[next] = true;
				if (bff[bff[next]] == next && !used[bff[next]]) {
					ok = true;
				}
				next = bff[next];
			}
			
			if (ok) {
				result = Math.max(result, count+getBest(nextPrependPos, nextAppendPos+count));
			}
			
			while(count > 0) {
				count--;
				int old = selection[nextAppendPos+count];
				selection[nextAppendPos+count] = 0;
				used[old] = false;
			}
		}
		
		return result;
	}
	
	public static void processCase(int caseNumber) throws IOException {
		n = sc.nextInt();
		bff = new int[n+1];
		
		for (int i=1; i<=n; i++) {
			bff[i] = sc.nextInt();
		}
		
		used = new boolean[n+1];
		selection = new int[2*n+3];
		
		int best = getBest(n+1, n+2);
		
		for (int i=1; i<=n; i++) {
			int next = i;
			int count = 0;
			used = new boolean[n+1];
			
			while(!used[next]) {
				used[next] = true;
				next = bff[next];
				count++;
			}
			
			if (next == i) {
				best = Math.max(best, count);
			}
		}
		
		write(best+"");
	}
}
