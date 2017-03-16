import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Recycle {

	/**
	 * @param args
	 */
	
	static int t =0;
	
	//static ArrayList<ArrayList<String>> table = new ArrayList<ArrayList<String>>();	

		public static void inputF() throws FileNotFoundException{
			
			File inputFile = new File("C-large.in");
			Scanner in = new Scanner(inputFile);
			File outputFile = new File("C-large.out");
			PrintWriter out = new PrintWriter(outputFile);
			String result="";
			String input ="";
	  
			int n,m=0;
			
			t = in.nextInt();
			//System.out.println(n);
			input = in.nextLine();
			for (int i=1; i<=t; i++) {
				 n =in.nextInt();
				 m =in.nextInt();
				//System.out.println("length of the list: "+list.length);
				result = "Case #"+i+ ": "+ count(n,m);
				out.println(result);
			}
			in.close();
			out.close();
		}
	
	private static int count(int n, int m) {
		int result =0;	
		boolean isRecycle = false;
		ArrayList list = new ArrayList<Integer>();
		
		for (int i=n; i<=m;i++){
			String ori=Integer.toString(i);
			isRecycle = false;
			list = new ArrayList<Integer>();
			for(int j=1; j<ori.length();j++){
				String cut = ori.substring(j, ori.length());
				String res = (cut+ori).substring(0, ori.length());
				//System.out.println(res);
				int resInt = Integer.parseInt(res);
				if ((resInt>i)&(resInt<=m)) {
					if ((!isRecycle)|((isRecycle)& (!list.contains(resInt)))){
					result++;
					isRecycle=true;
					list.add(resInt);
					//System.out.println(i+"-->"+resInt);
					//out.println(resInt);
				}
				}
			}
		}
		return result;
		}

	public static void main(String[] args) throws FileNotFoundException {
		inputF();

	}

}
