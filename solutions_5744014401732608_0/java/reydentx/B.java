package Round1C;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	static Scanner scan;
	static PrintWriter writer;
	
	static String[] N2 = new String[] {"12"};
	static String[] N3 = new String[] {"13","123"};
	static String[] N4 = new String[] {"14","124","134","1234"};
	static String[] N5 = new String[] {"15", "125", "135", "145", "1235", "1245" ,"1345" , "12345"};
	static String[] N6 = new String[] {"16","126","136","146","156", "1236","1246","1256","1346","1356","1456","12346","12356","13456","12456","123456"};
	public static void main(String[] args) {
		File file = new File("D://B-small-attempt0.in");
		File out = new File("D://outB.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				// input go here
				int b = scan.nextInt();
				int m = scan.nextInt();
				String[] arr = null;
				if(b == 2) {
					arr = N2;
				} 
				if(b == 3) {
					arr = N3;
				}
				if(b == 4) {
					arr = N4;
				}
				if(b == 5) {
					arr = N5;
				}
				if(b == 6) {
					arr = N6;
				}
				
				if(m > arr.length) {
					writer.println("IMPOSIBLE");
				} else {
					writer.println("POSSIBLE");
					int[][] A = new int[6][6];
					
					for(int j=0; j<m; j++) {
						String a = arr[j];
						char[] ch = a.toCharArray();
						
						for(int k=0; k<ch.length -1; k++) {
							int x = ch[k] - '0';
							int y = ch[k + 1] - '0';
							
							A[x-1][y-1] = 1;
						}
					}
					
					for(int v = 0; v<b; v++) {
						for(int n=0; n<b; n++) {
							writer.print(A[v][n]);
						}
						writer.println();
					}
				}
			}
		} catch (Exception ex) {
			
		} finally {
			writer.close();
		}
	}
}
