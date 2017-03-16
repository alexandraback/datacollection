import java.util.*;
import java.io.*;
import java.math.*;


// Author: vt12
// Google Code Jam 2014


public class SolutionC {
        public int min(int a, int b) {
            if (a< b) return a;
            else return b;
        }
        
        public int max(int a, int b) {
            if (a< b) return b;
            else return a;
        }                
        
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			int R = sc.nextInt(), C = sc.nextInt(), M = sc.nextInt();                                             
			
			pw.println("Case #" + caseNum + ":" );
                        char[][] m= new char[R+1][C+1];                        
                        
                        int cnt = 0;
                        boolean poss = true;
                        //k = i + j; assign by duong cheo
                        if (R == 1 || C== 1) {
                            for (int i = 1; i <= R; i++) {                                 
                                for (int j = 1; j <= C; j++) {
                                    if (cnt< M) {
                                        m[i][j]= '*';
                                        cnt++;
                                    }
                                    else 
                                        m[i][j]= '.';                                                                        
                                }
                            }
                            m[R][C] = 'c';
                        }
                        else { // R, C> 1
                            if (M+1 == R*C) { // 1 cell emtpy
                                //possible
                                cnt = M;
                                for (int i = 1; i <= R; i++) {
                                    for (int j = 1; j <= C; j++) {
                                        m[i][j] = '*';
                                    }                                
                                }
                                m[R][C] = 'c';

                            }
                            else if (M+2 == R*C || M+3 == R*C) { // 2 or 3 cells emtpy
                                poss = false;
                            }
                            else {// More than 3 empty cells
                                for (int i = 1; i <= R; i++) {
                                    for (int j = 1; j <= C; j++) {
                                        m[i][j] = '*';
                                    }                                
                                }
                                m[R][C] = 'c';
                                poss = false;
                                int d = R*C -M;
                                for (int h = R; h >= 2; h--) {
                                    int w = (d + h - 1)/h; // = d/h+1
                                    if (w == 2 && w*h== d) {
                                        poss = true;
                                        for (int i = R-h+1; i <= R; i++) {
                                            for (int j = C-w+1; j <= C; j++) {
                                                m[i][j] = '.';
                                            }
                                            
                                        }
                                        cnt = M;
                                        break;
                                    }
                                    else if (w>2 && C>= w && ( ((w*h-d)%h!= h-1) || ((w*h-d== h-1) && (w>=4) && (h>2))) ){
                                        int mines = w*h-d;
                                        System.out.println(R+ " "+ C + " " + M + " " + d + " "+ h + " " + w );
                                        poss = true;
                                        cnt = d;
                                        for (int j = C; j>= C-w+1;  j--) {
                                            for (int i = R; i >= R-h+1; i--) {
                                                if (cnt>0 ) {
                                                    m[i][j]= '.';
                                                    cnt--;
                                                }
                                                else 
                                                    m[i][j]= '*'; 
                                            }                                            
                                        }
                                        if (mines == h-1) {
                                            m[R-1][C-w+1]= '.';
                                            m[1][C-w+2]= '*';
                                        }
                                        cnt = M;
                                        break;
                                    }
                                }
                            }
                        }
                        
                        m[R][C] = 'c';
                        if (cnt == M && poss) {
                            for (int i = 1; i <= R; i++) {
                                for (int j = 1; j <= C; j++) {
                                    pw.print(m[i][j]);
                                }        
                                pw.println();
                            }
                        }
                        else {
                            pw.println("Impossible");
                        }    
                        
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new SolutionC()).doMain();
	}
}