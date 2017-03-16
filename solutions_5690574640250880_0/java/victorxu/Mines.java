import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Mines {
	public static void main(String[] args) throws IOException{
		BufferedReader buf =  new BufferedReader(new FileReader("Mines.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("MinesOut.txt"));
		int t = Integer.parseInt(buf.readLine());
		for(int i = 0; i < t; i++){
			out.println("Case #" + (i + 1) + ":");
			String[] s = buf.readLine().split(" ");
			int r = Integer.parseInt(s[0]);
			int c = Integer.parseInt(s[1]);
			int m = Integer.parseInt(s[2]);
			m = r*c - m;
			boolean impossible = false;
			if (Math.min(r, c) == 2 && (m % 2 == 1 || m < 4)) impossible = true;
			else if (((m % 2 == 1 && m < 8) || m == 2) && Math.min(r, c) > 1) impossible = true;
			else if (m < 0) impossible = true;
			if (m == 1) impossible = false;
			if(impossible) out.println("Impossible");
			if(!impossible){
				if(m == 1){
					for(int k = 0; k < r; k++){
						for(int j = 0; j < c; j++){
							if(j == 0 && k == 0) out.print("c");
							else out.print("*");
						}
						out.println("");
					}
				} else if(Math.min(r, c) > 2){
					if(r > c){
						if(m < 2 * r){
							if(m % 2 == 1){
								for(int k = 0; k < 3; k++){
									for(int j = 0; j < c; j++){
										if(j < 3) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										}
										else out.print("*");
									}
									out.println("");
								}
								for(int k = 3; k < (m - 3) / 2; k++){
									for(int j = 0; j < c; j++) {
										if(j < 2) out.print(".");
										else out.print("*");
									}
									out.println("");
								}
								for(int k = (m - 3) / 2; k < r; k++){
									for(int j = 0; j < c; j++) out.print("*");
									out.println("");
								}
							} else {
								for(int k = 0; k < m / 2; k++){
									for(int j = 0; j < c; j++) {
										if(j < 2) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										}
										else out.print("*");
									}
									out.println("");
								}
								for(int k = m / 2; k < r; k++){
									for(int j = 0; j < c; j++) out.print("*");
									out.println("");
								}
							}
						} else {
							if(m % r == 1){
								if(m / r == 2){
									for(int k = 0; k < 3; k++){
										for(int j = 0; j < c; j++){
											if(j < 3) {
												if(j == 0 && k == 0) out.print("c");
												else out.print(".");
											}
											else out.print("*");
										}
										out.println("");
									}
									for(int k = 3; k < (m - 3) / 2; k++){
										for(int j = 0; j < c; j++) {
											if(j < 2) out.print(".");
											else out.print("*");
										}
										out.println("");
									}
									for(int k = (m - 3) / 2; k < r; k++){
										for(int j = 0; j < c; j++) out.print("*");
										out.println("");
									}
								} else {
									for(int k = 0; k < 2; k++){
										for(int j = 0; j < c; j++){
											if(j < m/r+1) {
												if(j == 0 && k == 0) out.print("c");
												else out.print(".");
											}
											else out.print("*");
										}
										out.println("");
									}
									for(int k = 2; k < r - 1; k++){
										for(int j = 0; j < c; j++){
											if(j < m/r) {
												out.print(".");
											}
											else out.print("*");
										}
										out.println("");
									}
									for(int j = 0; j < c; j++){
										if(j < m/r - 1) {
											out.print(".");
										}
										else out.print("*");
									}
									out.println("");
								}
							} else {
								for(int k = 0; k < m % r; k++){
									for(int j = 0;j < c; j++){
										if(j < m/r + 1) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										}
										else out.print("*");
									}
									out.println("");
								}
								for(int k = m % r; k < r; k++){
									for(int j = 0; j < c; j++){
										if(j < m/r) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										}
										else out.print("*");
									}
									out.println("");
								}
							}
						}
					} else {
						if(m < 2 * c){
							if(m % 2 == 1){
								for(int k = 0; k < 2; k++){
									for(int j = 0; j < c; j++) {
										if(j < (m - 3) / 2) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										} else out.print("*");
									}
									out.println("");
								}
								for(int j = 0; j < c; j++) {
									if(j < 3) out.print(".");
									else out.print("*");
								}
								out.println("");
								for(int k = 3; k < r; k++){
									for(int j = 0; j < c; j++) {
										out.print("*");
									}
									out.println("");
								}
							} else {
								for(int k = 0; k < 2; k++){
									for(int j = 0; j < c; j++) {
										if(j < m / 2) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										} else out.print("*");
									}
									out.println("");
								}
								for(int k = 2; k < r; k++){
									for(int j = 0; j < c; j++) {
										out.print("*");
									}
									out.println("");
								}
							}
						} else {
							if(m % c == 1){
								if(m/c == 2){
									for(int k = 0; k < m/c; k++){
										for(int j = 0; j < c; j++) {
											if(j < c - 1) {
												if(j == 0 && k == 0) out.print("c");
												else out.print(".");
											}
											else out.print("*");
										}
										out.println("");
									}
									for(int j = 0; j < c; j++) {
										if(j < 1 + m/c) out.print(".");
										else out.print("*");
									}
									out.println("");
									for(int k = m/c + 1; k < r; k++){
										for(int j = 0; j < c; j++) out.print("*");
										out.println("");
									}
								} else {
									for(int k = 0; k < m/c - 1; k++){
										for(int j = 0; j < c; j++) {
											if(j == 0 && k == 0) out.print("c");
											else out.print(".");
										}
										out.println("");
									}
									for(int j = 0; j < c - 1; j++) out.print(".");
									out.println("*");
									out.print("..");
									for(int j = 2; j < c; j++) out.print("*");
									out.println("");
									for(int k = m/c + 1; k < r; k++){
										for(int j = 0; j < c; j++) out.print("*");
										out.println("");
									}
								}
							} else if(m % c == 0){
								for(int k = 0; k < m/c; k++){
									for(int j = 0; j < c; j++) {
										if(j == 0 && k == 0) out.print("c");
										else out.print(".");
									}
									out.println("");
								}
								for(int k = m/c; k < r; k++){
									for(int j = 0; j < c; j++) out.print("*");
									out.println("");
								}
							} else {
								for(int k = 0; k < m/c; k++){
									for(int j = 0; j < c; j++) {
										if(j == 0 && k == 0) out.print("c");
										else out.print(".");
									}
									out.println("");
								}
								for(int j = 0; j < c; j++){
									if(j < m % c) out.print(".");
									else out.print("*");
								}
								out.println("");
								for(int k = m/c + 1; k < r; k++){
									for(int j = 0; j < c; j++) out.print("*");
									out.println("");
								}
							}
						}
					}
				} else {
					if(r == 2){
						for(int k = 0; k < 2; k++){
							for(int j = 0; j < c; j++){
								if(j < m/r) {
									if(j == 0 && k == 0) out.print("c");
									else out.print(".");
								}
								else out.print("*");
							}
							out.println("");
						}
					} else if (r == 1){
						for(int j = 0; j < c; j++){
							if(j == 0) out.print("c");
							else if (j < m) out.print(".");
							else out.print("*");
						}
						out.println();
					} else if (c == 2){
						for(int k = 0; k < m/c; k++){
							if(k == 0) out.println("c.");
							else out.println("..");
						}
						for(int k = m/c; k < r; k++){
							out.println("**");
						}
					} else if (c == 1){
						for(int k = 0; k < m/c; k++){
							if(k == 0) out.println("c");
							else out.println(".");
						}
						for(int k = m/c; k < r; k++){
							out.println("*");
						}
					}
				}
			}
		}
		out.close();
	}
}
