import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class BinarioMasUno {

	public static boolean win(char w, char[][] tic){
		String diag1="";
		String diag2="";
		for (int i = 0; i < tic.length; i++) {
			if(isWin(new String(tic[i]),w))
				return true;
			String vert="";
			for (int j = 0; j < tic.length; j++) {
				vert+=tic[j][i];
				if(j==i){
					diag1+=tic[i][j];
				}
				if(j+i==3){
					diag2+=tic[i][j];
				}
			}
			if(isWin(vert,w)){
				return true;
			}
		}
		return isWin(diag1, w) || isWin(diag2,w);
	}
	static boolean isWin(String row, char w){
		String s = new String(row).replace(w+"", "");
		if(s.equals("T") || s.equals("")){
			return true;
		}
		return false;
	}
	static void pr(Object... ob) {System.out.println(Arrays.deepToString(ob).replace("],", "],\n"));}
	
	public void solve() throws Exception{
//		Scanner in = new Scanner(new File("/Users/rc/Eclipse-Workspaces/Algorithm-Competitions-EWS/HuaHCodingProject/src/input_temp_case"));
		Scanner in = new Scanner(new File("/Users/rc/test1/A-large.in"));
		
		//Scanner in = new Scanner(new File("D:/in.txt"));
		String writtenFile = "/Users/rc/test1/out-large.txt";
//		PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File(writtenFile));
		int casos = Integer.parseInt(in.nextLine());
		System.err.println(casos);
		for (int i = 0; i < casos; i++) {

			char[][] c=new char[4][4];
			for (int j = 0; j < 4; j++) {
				c[j]=in.nextLine().toCharArray();
			}
//			pr(c);
			if(i!=casos-1)
				in.nextLine();
			String res="";
			if(win('O',c)){
				res= "O won";
			}
			else if(win('X',c)){
				res= "X won";
			}
			boolean is=false;
			for (int j = 0; j < c.length; j++) {
				if(new String(c[j]).contains(".")){
					is=true;
					break;
				}
			}
			if(res.equals(""))
				if(is){
					res = "Game has not completed";
				}
				else 
					res = "Draw";
			out.println("Case #"+(i+1)+": "+res);
//			return;
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws Exception {
		new BinarioMasUno().solve();
	}
}