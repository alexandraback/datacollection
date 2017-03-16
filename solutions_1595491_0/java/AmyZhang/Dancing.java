import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Dancing {

	/**
	 * @param args
	 */
	
	static int t =0;
	//static ArrayList<ArrayList<String>> table = new ArrayList<ArrayList<String>>();	

		public static void inputF() throws FileNotFoundException{
			
			File inputFile = new File("B-small-attempt1.in");
			Scanner in = new Scanner(inputFile);
			File outputFile = new File("B-small-attempt1.out");
			PrintWriter out = new PrintWriter(outputFile);
			String result="";
			String input ="";
			
			int n,s,p=0;
			int[] list;
			
			t = in.nextInt();
			//System.out.println(n);
			input = in.nextLine();
			for (int i=1; i<=t; i++) {
				n = in.nextInt();
				s = in.nextInt();
				p = in.nextInt();
				
				list = new int[n];
				for (int j=0; j<n; j++) {
					list[j]=in.nextInt();
				}
				
				//System.out.println("length of the list: "+list.length);
				result = "Case #"+i+ ": "+ count(n,s,p,list);
				out.println(result);
			}
			in.close();
			out.close();
		}
		
	
	
	private static int count(int n, int s, int p, int[] list) {
			int result=0;
			for (int i=0; i<n;i++) {
				int medium = (list[i]-p)/2;
				//System.out.println("("+list[i]+"-"+p+")/2="+medium+" :: "+p);
				
				if ((medium >p-2) & (list[i]>=p)) {
					result++;
				} else if ((medium==p-2) & (s>0)) {
					result++;
					s--;
				}
			}
			return result;
		}



	public static void main(String[] args) throws FileNotFoundException {
		inputF();

	}

}
