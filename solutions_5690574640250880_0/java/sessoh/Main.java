import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] str = br.readLine().split(" ");
			int R = Integer.parseInt(str[0]);
			int C = Integer.parseInt(str[1]);
			int M = Integer.parseInt(str[2]);
			pw.println("Case #"+(i+1)+":");
			int S = R, L = C;
			if (R > C) { S = C; L = R; }
			char[][] map = analyze(S, L, M);
			if (map == null) pw.println("Impossible");
			else {
				if (R > C) {
					for (int j = 0; j < R; j++) {
						for (int k = 0; k < C; k++) pw.print(map[k][j]);
						pw.println();
					}
				} else {
					for (int j = 0; j < R; j++) {
						for (int k = 0; k < C; k++) pw.print(map[j][k]);
						pw.println();
					}
				}
			}
		}

		pw.close();
		br.close();
	}
	
	private static char[][] analyze(int S, int L, int M) {
		if (L*S-M == 0) return null;
		char[][] map = new char[S][L];
		if (L*S-M == 1) {
			for (int i = 0; i < S; i++) for (int j = 0; j < L; j++) map[i][j] = '*';
			map[S-1][L-1]='c';
			return map;
		}
		if (S == 1) {
			for (int j = 0; j < M; j++) map[0][j] = '*';
			for (int j = M; j < L; j++) map[0][j] = '.';
			map[S-1][L-1]='c';
			return map;
		}
		if (S == 2) {
			if (L*S-M < 4) return null;
			if (M%2 > 0) return null;
			for (int i = 0; i < S; i++) {
				for (int j = 0; j < M/S; j++) map[i][j] = '*';
				for (int j = M/S; j < L; j++) map[i][j] = '.';
			}
			map[S-1][L-1]='c';
			return map;
		}
		if (L*S-M < 4) return null;
		if (M > (L-2)*S) {
			int rm = M-(L-2)*S;
			if (rm%2 == 0) {
				for (int i = 0; i < L-2; i++) {
					for (int j = 0; j < S; j++) map[j][i] = '*';
				}
				for (int i = L-2; i < L; i++) {
					for (int j = 0; j < rm/2; j++) map[j][i] = '*';
					for (int j = rm/2; j < S; j++) map[j][i] = '.';
				}
				map[S-1][L-1]='c';
				return map;
			}
		}
		if (M > (L-3)*S) {
			int rm = M-(L-3)*S;
			if (rm%3 == 0) {
				for (int i = 0; i < L-3; i++) {
					for (int j = 0; j < S; j++) map[j][i] = '*';
				}
				for (int i = L-3; i < L; i++) {
					for (int j = 0; j < rm/3; j++) map[j][i] = '*';
					for (int j = rm/3; j < S; j++) map[j][i] = '.';
				}
				map[S-1][L-1]='c';
				return map;
			}
		}
		if (M > (L-2)*S) return null;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < S; j++) {
				if (i*S+j < M) map[j][i] = '*';
				else map[j][i] = '.';
			}
		}
		if ((M+1)%S == 0) {
			map[0][(M+1)/S] = '*';
			map[S-2][M/S] = '.';
		}
		if (M == (L-2)*S-1) {
			if (S == 3) return null;
			map[0][L-1] = '*';
			map[S-3][L-3] = '.';
		}
		map[S-1][L-1]='c';
		return map;
	}
}
