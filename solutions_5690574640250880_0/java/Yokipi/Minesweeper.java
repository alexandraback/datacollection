package qualifiers2014;

import java.io.*;
import java.util.*;
import java.math.*;


public class Minesweeper {
    public static void main(String args[]) throws Exception {
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader in = new BufferedReader(new FileReader(new File("src/qualifiers2014/"
                + fin.readLine())));
        FileWriter out = new FileWriter(new File("src/qualifiers2014/Minesweeper.out"));

        int T = Integer.parseInt(in.readLine());
        for (int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int R = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
            int dots = R*C - M;
            
            out.write(String.format("Case #%d:\n", t));
            System.out.printf("This is a %dx%d grid, with %d dots:\n", R, C, dots);
            if (R == 1 || C == 1) {
                for (int r = 0; r < R; r++) {
                    for (int c = 0; c < C; c++) {
                        if (r==0 && c==0) {
                            out.write("c");
                            System.out.print("c");
                            dots--;
                        } else {
                            if (dots > 0) {
                                out.write(".");
                                System.out.print(".");
                                dots--;
                            } else {
                                out.write("*");
                                System.out.print("*");
                            }
                        }
                    }
                    out.write("\n");
                    System.out.print("\n");
                }
            } else if (R == 2 || C == 2) {
                if (dots > 1 && (dots % 2 != 0 || dots == 2)) {
                	out.write("Impossible\n");
                	System.out.print("Impossible\n");
                	dots = 0;
                } else {
                    for (int r = 0; r < R; r++) {
                        for (int c = 0; c < C; c++) {
                            if (r==0 && c==0) {
                                out.write("c");
                                System.out.print("c");
                                dots--;
                            } else {
                                if (dots > 0 && (C == 2 || c < (R*C-M)/2)) {
	                                out.write(".");
	                                System.out.print(".");
	                                dots--;
                                } else {
                                    out.write("*");
                                    System.out.print("*");
                                }
                            }
                        }
                        out.write("\n");
                        System.out.print("\n");
                    }
                }   
            } else {
            	if (dots > 1 && dots < 8 && (dots % 2 != 0 || dots == 2)) {
            		out.write("Impossible\n");
            		System.out.print("Impossible\n");
            		dots = 0;
            	} else {
	                for (int r = 0; r < R; r++) {
	                    for (int c = 0; c < C; c++) {
	                        if (r==0 && c==0) {
	                            out.write("c");
	                            System.out.print("c");
	                            dots--;
	                        } else {
	                            if (dots > 0 && ((R*C-M)<9 && c<(R*C-M)/2 ||
	                            				(R*C-M)>=9 && (
	                            					(R*C-M)%2==1 && ((r<3&&c<3) || c<(R*C-M-3)/2 && (dots != 2 || c != C-1)) ||
	                            					(R*C-M)%2==0 && c<(R*C-M)/2 && (dots != 2 || c != C-1)))) {
	                                out.write(".");
	                                System.out.print(".");
	                                dots--;
	                            } else {
	                                out.write("*");
	                                System.out.print("*");
	                            }
	                        }
	                    }
	                    out.write("\n");
	                    System.out.print("\n");
	                }
            	}
            }
            if (dots != 0) {
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            	System.out.println("ERROR");
            }
        }

        fin.close();
        in.close();
        out.close();
    }
}
