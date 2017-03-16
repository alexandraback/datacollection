package gcj2014.qual;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P3().run();
    }
    PrintWriter pw;

    void run() throws Exception {
        File infile = new File("C-small-attempt3.in");
        String outfile = "result";
        pw = new PrintWriter(outfile);
        int T = 0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc = new Scanner(infile);
        T = sc.nextInt();

        for (int case_i = 1; case_i <= T; case_i++) {
            int result = 0;
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            boolean imp=false;
            int offsetr=0,offsetc=0;
            int cr=0,cc=0;
            int remainm=M;
            char[][] str = new char[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    str[i][j] = '.';
                }
            }
            str[R - 1][C - 1] = 'c';
            if (M == (R * C - 1)) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        str[i][j] = '*';
                    }
                }
                str[R - 1][C - 1] = 'c';
            } else {
                while(true){
                    cr=R-offsetr;
                    cc=C-offsetc;
                    if(cr==2 && cc==2){
                        if(remainm!=0) {
                            imp=true;
                        }
                        break;
                    }
                    
                    if(cr>=cc){
                        if(remainm>=cc){
                            remainm-=cc;
                            for (int i = offsetc; i < C; i++) {
                                str[offsetr][i] = '*';
                            }
                            offsetr++;
                        }else{
                            if(remainm==(cc-1) && remainm!=0){
                                if((remainm==(cr-1) && remainm!=0)|| cc==2){
                                    if(cr==cc && cr>3){
                                        for(int i=offsetr;i<(offsetr+remainm-1);i++){
                                str[i][offsetc] = '*';
                                    }
                                        str[offsetr][offsetc+1]='*';
                                    }else
                                    imp=true;
                                }else{
                                    for(int i=offsetr;i<(offsetr+remainm);i++){
                                str[i][offsetc] = '*';
                                    }
                                }
                            }else{
                                for(int i=offsetc;i<(offsetc+remainm);i++){
                                str[offsetr][i] = '*';
                            }
                            }
                            
                            
                            break;
                        }
                    }else{
                        if(remainm>=cr){
                            remainm-=cr;
                            for (int i = offsetr; i < R; i++) {
                                str[i][offsetc] = '*';
                            }
                            offsetc++;
                        }else{
                            if(remainm==(cr-1)&& remainm!=0){
                                if((remainm==(cc-1) && remainm!=0)||cr==2){
                                    if(cr==cc && cr>3){
                                        for(int i=offsetr;i<(offsetr+remainm-1);i++){
                                str[i][offsetc] = '*';
                                    }
                                        str[offsetr][offsetc+1]='*';
                                    }else
                                    imp=true;
                                }else{
                                    for(int i=offsetc;i<(offsetc+remainm);i++){
                                str[offsetr][i] = '*';
                            }
                                }
                            }else{
                                for(int i=offsetr;i<(offsetr+remainm);i++){
                                str[i][offsetc] = '*';
                            }
                            }
                            
                            break;
                        }
                        
                        
                    }
                }
            }
            
            String outputstr = String.format("Case #%d:\n", case_i);
            pw.printf(outputstr);
            System.out.printf(outputstr);
            if(imp){
                pw.println("Impossible");
                System.out.println("Impossible");
            }else{
                 for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    pw.print(str[i][j]);
                    System.out.print(str[i][j]);
                }
                pw.println();
                     System.out.println("");
            }
            }
        }
        pw.close();
    }
}
