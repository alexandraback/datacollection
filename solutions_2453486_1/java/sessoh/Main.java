import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));
			
			String[] message = { "", "X won", "O won", "Draw", "Game has not completed" };
			int T = Integer.parseInt(br.readLine());
			String[] param = new String[4];
			for (int i = 0; i < T; i++) {
				for (int j = 0; j < 4; j++) param[j] = br.readLine();
				br.readLine();
				pw.println("Case #" + (i+1) + ": " + message[analyze(param)]);
			}

			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static int analyze(String[] param) {
		char[] map = new char[4*4];
		int xnum = 0;
		int onum = 0;
		int tnum = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				map[i*4+j] = param[i].charAt(j);
				switch (map[i*4+j]) {
				case 'X': xnum++; break;
				case 'O': onum++; break;
				case 'T': tnum++; break;
				}
			}
		}
		int xrem, orem;
		if (xnum == onum) {
			orem = (4*4-xnum-onum-tnum)/2;
			xrem = (4*4-xnum-onum-tnum)-orem;
		} else {
			xrem = (4*4-xnum-onum-tnum)/2;
			orem = (4*4-xnum-onum-tnum)-xrem;
		}
		
		int korekara = 0;
		int x = 0, o = 0, t = 0;
		for (int i = 0; i < 4; i++) {
			switch (map[i*4+i]) {
			case 'X': x++; break;
			case 'O': o++; break;
			case 'T': t++; break;
			}
		}
		switch (lineCheck(x, o, t, xrem, orem)) {
		case 1: return 1;
		case 2: return 2;
		case 4: korekara++; break;
		}
		
		x = 0; o = 0; t = 0;
		for (int i = 0; i < 4; i++) {
			switch (map[i*4+(3-i)]) {
			case 'X': x++; break;
			case 'O': o++; break;
			case 'T': t++; break;
			}
		}
		switch (lineCheck(x, o, t, xrem, orem)) {
		case 1: return 1;
		case 2: return 2;
		case 4: korekara++; break;
		}

		for (int j = 0; j < 4; j++) {
			x = 0; o = 0; t = 0;
			for (int i = 0; i < 4; i++) {
				switch (map[j*4+i]) {
				case 'X': x++; break;
				case 'O': o++; break;
				case 'T': t++; break;
				}
			}
			switch (lineCheck(x, o, t, xrem, orem)) {
			case 1: return 1;
			case 2: return 2;
			case 4: korekara++; break;
			}
			x = 0; o = 0; t = 0;
			for (int i = 0; i < 4; i++) {
				switch (map[i*4+j]) {
				case 'X': x++; break;
				case 'O': o++; break;
				case 'T': t++; break;
				}
			}
			switch (lineCheck(x, o, t, xrem, orem)) {
			case 1: return 1;
			case 2: return 2;
			case 4: korekara++; break;
			}
		}
		
		if (korekara > 0) return 4;
		else return 3;
	}
	
	private static int lineCheck(int X, int O, int T, int xrem, int orem) {
		if (T <= 1) {
			if (X+T ==4) return 1;
			if (O+T ==4) return 2;
			if (O==0 && (X+T+xrem >= 4)) return 4;
			if (X==0 && (O+T+orem >= 4)) return 4;
		}
		return 0;
	}
}
