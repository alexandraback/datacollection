import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;


public class Dijkstra {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		System.setIn(new FileInputStream("C-small-attempt1.in"));
		System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("Dijkstra.out")), true));
		int[][] r = new int[5][5];
		for(int i=1 ; i<5 ; i++) {
			r[i][1] = r[1][i] = i;
			r[i][i] = -1;
		}
		r[1][1] = 1;
		r[2][3] = 4;
		r[2][4] = -3;

		r[3][2] = -4;
		r[3][4] = 2;
		
		r[4][2] = 3;
		r[4][3] = -2;

		int[][] mul = new int[10001][10001];
		int[] str = new int[10001];
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int totalCaseNumber = Integer.parseInt( reader.readLine() );
		for(int caseNo=1 ; caseNo<=totalCaseNumber ; caseNo++ ) {
			String line = reader.readLine();
			String[] parts = line.split(" ");
			line = reader.readLine();
			int x = Integer.parseInt(parts[1]);
			char[] chrs = line.toCharArray();
			
			int i,len=0,j;
			for(i=0 ; i<x ; i++) {
				for(char ch : chrs) {
					if(ch == 'i') {
						str[len] = 2;
					} else if(ch == 'j') {
						str[len] = 3;
					} else {
						str[len] = 4;
					}
					len++;
				}
			}
			
			for(i=0 ; i<len ; i++) {
				mul[i][i] = str[i];
			}
			
			for(i=0 ; i<len ; i++) {
				for(j=i+1 ; j<len; j++) {
					if( mul[i][j-1] < 0 ) {
						mul[i][j] = -1 * r[ -1 * mul[i][j-1] ][ str[j] ];
					} else {
						mul[i][j] = r[ mul[i][j-1] ][ str[j] ];
					}
				}
			}

			boolean found = false;
			for(i=1 ; i<len ; i++) {
				for(j=i+1 ; j<len ; j++) {
					if( mul[0][i-1] == 2 && mul[i][j-1] == 3 && mul[j][len-1] == 4) {
						found = true;
						break;
					}
				}
				if( found ) {
					break;
				}
			}
			
			System.out.println("Case #" + caseNo + ": " + (found ? "YES" : "NO"));
		}
		reader.close();
	}
}
