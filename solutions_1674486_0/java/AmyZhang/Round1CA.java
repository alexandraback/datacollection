import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Scanner;


public class Round1CA {

	static int t =0;
	//static ArrayList<ArrayList<String>> table = new ArrayList<ArrayList<String>>();
	
	static Boolean isFind = false;
	static int[][] record;
	static int[][] table;

		public static void inputF() throws FileNotFoundException{
			
			File inputFile = new File("A-small-attempt2.in");
			Scanner in = new Scanner(inputFile);
			File outputFile = new File("A-small-attempt2.out");
			PrintWriter out = new PrintWriter(outputFile);
			String result="";
			String input ="";
			
			int t,n=0;
			
			//double[] list;
			
			ArrayList<Integer> jud;
			ArrayList<Double> aud;
			
			t = in.nextInt();
			//System.out.println("t is :"+ t);
			//input = in.nextLine();
			for (int i=1; i<=t; i++) {
				n = in.nextInt();
				//System.out.println(n);
				//ArrayList<ArrayList<Integer>> table = new ArrayList<ArrayList<Integer>>();
				table = new int[n+1][n+1];
				table[0] = new int[n+1];
				//System.out.println(table);
				for (int j=1; j<=n; j++) {
					int q = in.nextInt();
					table[j][0] = q;
					//System.out.println("no :"+table[j][0]);
					if (table[j][0]!=0) {
						for (int l=1; l<=table[j][0];l++) {
							q = in.nextInt();
							table[j][l]=q;
						//	System.out.println(table[j][l]+" ");
						}
					}
					//System.out.println();
				}
				for (int j=1; j<=n; j++) {
					for (int k=0; k<=table[j][0];k++) {
						System.out.print(table[j][k]+ " ");
					}
					System.out.println();
				}
			
				result = "Case #"+i+ ": "+count(n,table);
				
				//out.format("Case #%d: %.6f%n",i, aud);
				out.println(result);
			}
				//System.out.format("%.3f%n", pi)
			in.close();
			out.close();
		}
		
	

	private static String count(int n, int[][] table) {
			String result="No";
			record = new int[n+1][n+1];
			isFind = false;
			for (int i=1; i<=n; i++) {
				if ((!isFind)&&table[i][0]!=0) {
					for (int j=1; j<=table[i][0];j++) {
						
						int k = table[i][j];
						System.out.println("k is "+k);
						if (record[i][k]!=0) {
							isFind = true;
							record[i][k]++;
						} else {
							//record[i][k]=1;
							//find(i,k,record,isFind);
							
							record[i][k]=1;
							if ((table[k][0]!=0)&(!isFind)) {
								//find(i,k,record,table,isFind);
								find(i,k);
								for (int l=1; l<=n; l++) {
									for (int m=1; m<=n;m++) {
										System.out.print(record[l][m]+" ");
									}
									System.out.println();
								}
								System.out.println();
								}
							}
						}
					}
				}
			
			for (int i=1; i<=n; i++) {
				for (int j=1; j<=n;j++) {
					System.out.print(record[i][j]+" ");
				}
				System.out.println();
			}
			System.out.println();
			if (isFind) {
				result = "Yes";
			}
			return result;
		}



	private static void find(int i, int k){
		if (!isFind) {
			for (int j=1; j<=table[k][0];j++) {
				int m = table[k][j];
				if (record[i][m]!=0) {
					isFind = true;
					record[i][m]++;
				} else {
					record[i][m]=1;
					if (table[m][0]!=0) {
						//find(i,m,record,table,isFind);
						find(i,m);
					}
				}
			}
		}
		//return isFind;
		
	}



	public static void main(String[] args) throws FileNotFoundException {
		inputF();

	}

}
