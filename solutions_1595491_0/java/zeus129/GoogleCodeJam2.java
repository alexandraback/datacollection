import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


class GoogleCodeJam2 {
	static BufferedReader br ;
	static PrintWriter pw;
	static String line;
	static HashSet<String> hs;
	
	public static void main (String [] args) throws IOException {
		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("C:\\Code\\google\\in.txt"))));
			pw = new PrintWriter(new File("C:\\Code\\google\\out.out"));
			start();
//			
//			do {
//				present = func(present, start);
//				if (present != null) {
//					for (int i : present)
//					{
//						System.out.print(i+",");
//					}
//				}
//				System.out.println();
//			}while (present!= null);
			 
			
//			Integer input[] = {1,2,3,8,9};
//			System.out.println(convert(input));
//			for (int i: convert(12389)) {
//				System.out.print(i+",");
//			}
			
			pw.flush();
			pw.close();
			br.close();
		}
		catch (NumberFormatException t) {
			//throw t;
		}
	}

	static void start() throws IOException {
		int n=0;
		int n1=0;
		int s=0;
		int p=0;
		String firstLine = br.readLine().trim();
		n = Integer.parseInt(firstLine.trim());

		for( int i=0; i<n; i++) {
			int finalSum=0;
			int sDone=0;
			String tLine = br.readLine().trim();
			String tLineArray[] = tLine.split(" ");
			
			n1 = Integer.parseInt(tLineArray[0].trim());
			s = Integer.parseInt(tLineArray[1].trim());
			p = Integer.parseInt(tLineArray[2].trim());
			
			int limit= ((p-1)*3);
			
			for (int j=3;j<n1+3;j++) {
				int t = Integer.parseInt(tLineArray[j].trim());
				if (p>1) {
					if (t>limit) {
						finalSum++;
					} else if (t == limit || t==limit-1) {
						if (sDone<s) {
							finalSum++;
							sDone++;
						}
					}
				} else if (p==1) {
					if (t>=1) {
						finalSum++;
					}
				}
				else if (p<=0) {
					finalSum++;
				}
//				else if (p==2) {
//					if (t==1||t==0){
//						
//					} else if (t==2 || t==3) {
//						if (sDone<s) {
//							finalSum++;
//							sDone++;
//						}
//					}
//					else {
//						finalSum++;
//					}
//				}
			}
			pw.println("Case #"+(i+1)+": "+finalSum);

		}
	}		
}