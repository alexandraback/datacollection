package codejam2012Round1C;
import java.io.*;
import java.util.*;

public class A {
	public static boolean[] marked;
	public static int N;
	public static ArrayList<Integer>[] Inherit;
	public static void main(String[] args) throws IOException{
		boolean large = false;
		//large = true;
		String dir = "C://Users//Aayush//Desktop//";
		Scanner st = new Scanner(System.in);
		String InputFile = st.next();
		String OutputFile = dir + (large ? "A-large.out" : "A-small.out");
		FileWriter fw = new FileWriter(OutputFile);
		st = new Scanner(new BufferedReader(new FileReader(InputFile)));
		//st = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int T = st.nextInt();
		for(int cases = 1; cases <= T; cases++){
			System.out.print("Case #" + cases + ": ");
			fw.write("Case #" + cases + ": ");
			N = st.nextInt();
			Inherit = new ArrayList[N + 1];
			for(int i = 1; i <= N; i++){
				Inherit[i] = new ArrayList<Integer>();
				int M = st.nextInt();
				for(int j = 0; j < M; j++){
					int a = st.nextInt();
					Inherit[i].add(a);
				}
			}


			//----------------Algorithm starts here----------------------
			boolean flag = false;
			for(int i = 1; i <= N; i++){
				marked = new boolean[N + 1];
				if(explore(i) == true){
					flag = true;
					break;
				}
			}				
			//----------------Algorithm ends here----------------------

			if(flag == false){
				System.out.print("No"+"\n");
				fw.write("No" + "\n");
			}else{
				System.out.print("Yes" + "\n");
				fw.write("Yes" + "\n");
			}
		}
		fw.flush();
		fw.close();
	}


	public static boolean explore(int X){
		marked[X] = true;
		boolean flag = false;
		for(int i = 0; i < Inherit[X].size(); i++){
			if(marked[Inherit[X].get(i)] == true) return true;
			if(explore(Inherit[X].get(i)) == true){
				flag = true;
				break;
			}
		}
		return flag;
	}

}
