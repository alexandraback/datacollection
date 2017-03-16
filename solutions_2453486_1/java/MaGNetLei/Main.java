
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	static Boolean DEBUG = true;
	static int[][] f = new int[100][100],p = new int[110][110];
	static char[] s;
	static PrintStream out;
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		if (DEBUG){
			BufferedInputStream in = new BufferedInputStream(new FileInputStream("std.in"));   
			System.setIn(in);
			out = new PrintStream(new FileOutputStream("std.dout"));   
			System.setOut(out);
		}
		Scanner sc = new Scanner(System.in);
		int case_num = sc.nextInt();
		String[] s = new String[10];
		String t,res=new String();
		Boolean flag = false;
		for (int case_n = 1; case_n <= case_num; case_n++) {
			flag = false;
			for (int i = 0; i < 4; i++) s[i] = sc.next();
			t = new String();
			for (int i = 0; i < 4; i++){
				t += s[i].charAt(i);
			}
			s[4]=t;
			t = new String();
			for (int i = 0; i < 4; i++){
				t += s[i].charAt(3-i);
			}
			s[5]=t;
			for (int i = 0; i < 4; i++){
				t = new String();
				for (int j = 0; j < 4; j++){
					t += s[j].charAt(i);
					if (s[j].charAt(i)=='.') flag = true;
				}
				s[6+i] = t;
			}
			for (int i=0;i<10;i++){
				if (s[i].equals("XXXX") || s[i].equals("TXXX") || s[i].equals("XTXX") || s[i].equals("XXTX") 
					|| s[i].equals("XXXT")){
					res = "X won";
					break;
				}
				else if (s[i].equals("OOOO") || s[i].equals("TOOO") || s[i].equals("OTOO") || s[i].equals("OOTO") 
				|| s[i].equals("OOOT")){
					res = "O won";
					break;
				}else if (flag){
					res = "Game has not completed";
				}else
					res = "Draw";
			}
			System.out.println("Case #"+case_n+": "+res);
		}
		try{
			out.close();
		}catch(Exception e){}
	}
	

}
