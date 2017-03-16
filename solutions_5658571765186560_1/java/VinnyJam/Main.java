package problem4;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("D-large.in"));
        //Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        
        int t = in.nextInt();
        for (int i=0; i<t; i++){
            int x = in.nextInt();
            int r = in.nextInt();
            int c = in.nextInt();
            int n = Math.min(r, c);
            int m = Math.max(r, c);
            if (x>6) {
                out.println("Case #"+(i+1)+": RICHARD");
            }
            if (x==1) {
                out.println("Case #"+(i+1)+": GABRIEL");
            }
            if (x==2) {
                if ((n*m)%2==0){
                    out.println("Case #"+(i+1)+": GABRIEL");
                }
                else{
                    out.println("Case #"+(i+1)+": RICHARD");
                }                    
            }
            if (x==3) {
                if (((n*m)%3==0)&&(n>1)){
                    out.println("Case #"+(i+1)+": GABRIEL");
                }
                else{
                    out.println("Case #"+(i+1)+": RICHARD");
                }
            }
            if (x==4) {
                if (((n*m)%4==0)&&(n>2)){
                    out.println("Case #"+(i+1)+": GABRIEL");
                }
                else{
                    out.println("Case #"+(i+1)+": RICHARD");
                }
            }
            if (x==5){
                if (((n*m)%5==0)&&(n>2)){
                    out.println("Case #"+(i+1)+": GABRIEL");
                }
                else{
                    out.println("Case #"+(i+1)+": RICHARD");
                }
            }
            if (x==6){
                if (((n*m)%6==0)&&(n>3)){
                    out.println("Case #"+(i+1)+": GABRIEL");
                }
                else{
                    out.println("Case #"+(i+1)+": RICHARD");
                }
            }
        }
        out.flush();
        out.close();
        
    }
    
}
