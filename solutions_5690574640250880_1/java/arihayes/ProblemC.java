import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemC {
    static String in = "src/c.in";
    static String out = "src/c.out";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        char layout[][] = new char[50][50];
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        for(int x = 0; x < numlines; x++) {
            int rows = scan.nextInt();
            int cols = scan.nextInt();
            int mines = scan.nextInt();

            int area = rows*cols;
            int safe = area - mines;

            write.write("Case #" + (x+1) + ":");
            write.newLine();
            if(rows == 1 || cols == 1 || safe == 1 || mines == 0 || ((safe % cols) != 1 && safe >= cols*2)) {
                int minesleft = mines;
                int arealeft = area;
                for(int a = 0; a < rows; a++) {
                    for(int b = 0; b < cols; b++) {
                        if(minesleft > 0) {
                            write.write("*");
                            minesleft--;
                        } else if(arealeft == 1) {
                            write.write("c");
                        } else {
                            write.write(".");
                        }
                        arealeft--;
                    }
                    write.newLine();
                }
            }
            else if((safe % rows) != 1 && safe >= rows * 2) {
                int safecols = safe/rows;
                int rem = safe - (safecols*rows);

                int minesleft = mines;
                int arealeft = area;
                for(int a = 0; a < rows; a++) {
                    for(int b = 0; b < cols; b++) {
                        if(a == 0 && b == 0) {
                            write.write("c");
                        } else if(a < rem && b == safecols) {
                            write.write(".");
                        } else if(b < safecols) {
                            write.write(".");
                        } else if(minesleft > 0) {
                            write.write("*");
                            minesleft--;
                        } else {
                            write.write(".");
                        }
                        arealeft--;
                    }
                    write.newLine();
                }
            }
            else if(safe < 4) {
                write.write("Impossible");
                write.newLine();
            }
            else if((rows-2)*(cols-2) >= mines) {
                int mr = cols-2;
                int mc = rows-2;
                while(mr*mc > mines) {
                    if(mr > mc) {
                        mr--;
                    }
                    else {
                        mc--;
                    }
                }
                int remainder = mines - mr*mc;
                int remr = 0;
                int remc = 0;
                if(mr > mc) {
                    remr = remainder;
                }
                else {
                    remc = remainder;
                }

                int minesleft = mines;
                int arealeft = area;
                for(int a = 0; a < rows; a++) {
                    for(int b = 0; b < cols; b++) {
                        if(a < mr && b < mc) {
                            write.write("*");
                            minesleft--;
                        } else if(a == mr && b < remc) {
                            write.write("*");
                            minesleft--;
                        } else if(b == mc && a < remr) {
                            write.write("*");
                            minesleft--;
                        } else if(arealeft == 1) {
                            write.write("c");
                        } else {
                            write.write(".");
                        }
                        arealeft--;
                    }
                    write.newLine();
                }
            }
            else {
                int goodr = 0;
                int goodc = 0;
                boolean good = false;
                outer: for(int a = 2; a <= rows; a++) {
                    inner: for (int b = 2; b <= cols; b++) {
                        int ab = a*b;
                        if(ab > safe) {
                            break inner;
                        }
                        int rem = safe - ab;
                        if(rem == 1) {
                            continue inner;
                        } else if(rem >= a || rem >= b) {
                            continue inner;
                        }
                        else if(rem == 3 && (a <= 3 || a == rows) && (b <= 3 && b == cols)) {
                            continue inner;
                        }
                        else {
                            goodr = a;
                            goodc = b;
                            good = true;
                            break;
                        }
                    }
                    if(2*a > safe) {
                        break;
                    }
                }
                if(!good) {
                    write.write("Impossible");
                    write.newLine();
                    System.out.println((x+1) + " Impossible!" + (safe) + "safe");
                    continue;
                }
                /*if(rows*rows >= safe && cols*cols >= safe) {
                    int root = 0;
                    for(int a = 0; a <= 50; a++) {
                        if(a*a <= safe) {
                            root = a;
                        }
                        else {
                            break;
                        }
                    }
                    goodr = root;
                    goodc = root;
                }
                else {
                    if(rows < cols) {
                        goodr = rows;
                        goodc = (safe/goodr);
                    }
                    else {
                        goodc = cols;
                        goodr = (safe/goodc);
                    }
                }*/
                int square = goodr * goodc;
                int remainder = safe - square;
                int remc = 0;
                int remr = 0;
                if(remainder == 2) {
                    if(rows < cols) {
                        remc = 2;
                    }
                    else {
                        remr = 2;
                    }
                }
                else if(remainder == 3) {
                    if(goodc == cols || goodr < 3) {
                        remr = remainder;
                    }
                    else {
                        remc = remainder;
                    }
                }
                else if(goodc == cols) {
                    remr = remainder;
                }
                else if(goodr == rows) {
                    remc = remainder;
                }
                else {
                    remr = remainder/2;
                    remc = remainder/2;
                    if(remainder % 2 != 0) {
                        remr++;
                    }
                }

                int minesleft = mines;
                int arealeft = area;
                int safeleft = safe;
                for(int a = 0; a < rows; a++) {
                    for(int b = 0; b < cols; b++) {
                        if(a < goodr && b < goodc) {
                            if(a == 0 && b == 0) {
                                write.write("c");
                            } else {
                                write.write(".");
                            }
                            safeleft--;
                        }
                        else if(b < remr && a == goodr && safeleft > 0) {
                            write.write(".");
                            safeleft--;
                        }
                        else if(a < remc && b == goodc && safeleft > 0) {
                            write.write(".");
                            safeleft--;
                        }
                        else if(a < goodr && b < goodc && safeleft > 0) {
                            write.write(".");
                            safeleft--;
                        }
                        else if(b < goodc && a < goodr && safeleft > 0) {
                            write.write(".");
                            safeleft--;
                        }
                        else if(a == 0 && b == 0) {
                            write.write("c");
                        } else if(a < 2 && b < 2) {
                            write.write(".");
                        }else if(minesleft > 0) {
                            write.write("*");
                            minesleft--;
                        } else {
                            write.write(".");
                            safeleft--;
                        }
                        arealeft--;
                    }
                    write.newLine();
                }
            }
        }
        scan.close();
        write.close();
    }
}
