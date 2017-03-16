import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class qt1 {
	public static void test(BufferedReader in) throws IOException {
		String ss = in.readLine();
		int cases = Integer.parseInt(ss);
		for (int j = 1;j<=cases;j++) {
			char matrix[][] = new char[5][5];
			String row[] = {"","","",""};
			boolean isDraw = true;
			String ans = "Game has not completed";
			System.out.print("Case #"+j+": ");
			
			for (int x = 0;x<4;x++) {
				String s = in.readLine();
				if (s.equals("XXXT")||s.equals("XXTX")||s.equals("XTXX")||s.equals("TXXX")||s.equals("XXXX")) {
					ans = "X won";
				}
				if (s.equals("OOOT")||s.equals("OOTO")||s.equals("OTOO")||s.equals("TOOO")||s.equals("OOOO")) {
					ans = "O won";
				}
				for (int y = 0;y<4;y++) {
					char c = s.charAt(y);
					if (c=='.') {
						isDraw = false;
					}
					matrix[x][y] = c;
					row[y]+=c;
				}			
			}
			if (!ans.equals("Game has not completed")) {
				System.out.println(ans);
				in.readLine();
				continue;
			}
			for (int i = 0;i<4;i++) {
				String s = row[i];
				if (s.equals("XXXT")||s.equals("XXTX")||s.equals("XTXX")||s.equals("TXXX")||s.equals("XXXX")) {
					ans = "X won";
					break;
				}
				if (s.equals("OOOT")||s.equals("OOTO")||s.equals("OTOO")||s.equals("TOOO")||s.equals("OOOO")) {
					ans = "O won";
					break;
				}
			}
			if (!ans.equals("Game has not completed")) {
				System.out.println(ans);
				in.readLine();
				continue;
			}
			String s = "";
			s += matrix[0][0];
			s += matrix[1][1];
			s += matrix[2][2];
			s += matrix[3][3];
			if (s.equals("XXXT")||s.equals("XXTX")||s.equals("XTXX")||s.equals("TXXX")||s.equals("XXXX")) {
				ans = "X won";
				System.out.println(ans);
				in.readLine();
				continue;
			}
			if (s.equals("OOOT")||s.equals("OOTO")||s.equals("OTOO")||s.equals("TOOO")||s.equals("OOOO")) {
				ans = "O won";
				System.out.println(ans);
				in.readLine();
				continue;
			}
			s = "";
			s += matrix[0][3];
			s += matrix[1][2];
			s += matrix[2][1];
			s += matrix[3][0];
			if (s.equals("XXXT")||s.equals("XXTX")||s.equals("XTXX")||s.equals("TXXX")||s.equals("XXXX")) {
				ans = "X won";
				System.out.println(ans);
				in.readLine();
				continue;
			}
			if (s.equals("OOOT")||s.equals("OOTO")||s.equals("OTOO")||s.equals("TOOO")||s.equals("OOOO")) {
				ans = "O won";
				System.out.println(ans);
				in.readLine();
				continue;
			}
			if (isDraw) {
				System.out.println("Draw");
				in.readLine();
			}
			else {
				System.out.println(ans);
				in.readLine();
			}	
		}	
		in.close();
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File conf = new File(args[0]);
		FileReader fr=new FileReader(conf);
		BufferedReader in=new BufferedReader(fr);
		test(in);
	}
}
