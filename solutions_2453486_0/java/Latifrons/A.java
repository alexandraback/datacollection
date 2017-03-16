import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	static String pre = "1s";
	static String in = pre+".in";
	static String out = pre+".out";
	
	static String XWON = "X won";
	static String OWON = "O won";
	static String NC = "Game has not completed";
	static String DRAW = "Draw";
	static char X = 'X';
	static char O = 'O';
	static char dot = '.';
	static char T = 'T';
	
	private static String handle() {
		s.nextLine();
		char[][] b = new char[4][4];
		char[][] br= new char[4][4];
		boolean full = true;
		for (int i = 0 ; i < 4; i ++){
			String line = s.nextLine();
			for (int j = 0 ; j < 4; j++){
				b[i][j] = line.charAt(j);
				full &= (line.charAt(j) != dot);
			}
		}
		for (int i = 0 ; i < 4; i ++){
			for (int j = 0 ; j < 4; j++){
				br[i][j] = b[j][i];
			}
		}
		
		
		//row
		for (int i = 0 ; i < 4;i++){
			if (good(b[i],X)){
				return XWON;
			}
			if (good(b[i],O)){
				return OWON;
			}
			if (good(br[i],X)){
				return XWON;
			}
			if (good(br[i],O)){
				return OWON;
			}
		}
		//diag
		char[] diag1 =new char[]{
				b[0][0],b[1][1],b[2][2],b[3][3]};
		char[] diag2 =new char[]{
				b[0][3],b[1][2],b[2][1],b[3][0]};
		if (good(diag1,X)){
			return XWON;
		}
		if (good(diag1,O)){
			return OWON;
		}
		if (good(diag2,X)){
			return XWON;
		}
		if (good(diag2,O)){
			return OWON;
		}
		
		if (full){
			return DRAW;
		}else{
			return NC;
		}
	}
	
	private static boolean good(char[] bs, char c){
		boolean good = true;
		for (int i = 0; i < 4;i++){
			good &= ((bs[i] ==c) || bs[i] == T);
		}
		return good;
	}
	
	
	
	
	static Scanner s;
	static FileWriter fw;
	
	public static void main(String[] args) throws IOException{
		s = new Scanner(new FileInputStream(in));
		fw = new FileWriter(out);
		
		//init();
		
		int lines = s.nextInt();
		for (int i = 1 ; i <= lines ;i++){
			long start = System.currentTimeMillis();
			String result = handle();
			String output = String.format("Case #%d: %s\n", i,result);
			fw.write(output);
			System.out.printf("%3d %s",(System.currentTimeMillis()-start)/1000,output);
		}
		
		fw.close();
		System.out.println("Done");
	}

	
}
