
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Pogo {
    static Scanner sc = null;
    static BufferedWriter bw = null;
    public static void main(String[] args) {
        try {
            sc = new Scanner(new File("B-small-attempt2.in"));
            bw = new BufferedWriter(new FileWriter(new File("output.out")));
        } catch (Exception ex) {
            
        }
        
        int c = sc.nextInt();
        for(int t=1;t<=c;t++){
            
            long x = sc.nextInt();
            long y = sc.nextInt();
            
            String h = "";
            
            if(x>0){
                h = h+"E";
                for(int i=1;i<x;i++) h = h+"WE";
            }else if(x<0){
                h = h+"W";
                for(int i=1;i<-x;i++) h = h+"EW";
            }
            
            if(y>0){
                h = x!=0? h+"SN" : h+"N";
                for(int i=1;i<y;i++) h = h+"SN";
            }else if(y<0){
                h = x!=0? h+"NS" : h+"S";
                for(int i=1;i<-y;i++) h = h+"NS";
            }
                       
            try {               
                bw.write("Case #"+String.valueOf(t)+": ");              
                bw.write(h);
                bw.newLine();
                bw.flush();             
            } catch (IOException ex) {
                
            }
        }
    }
    
    static boolean vow(char p){
         return (p=='a'||p=='e'||p=='i'||p=='o'||p=='u');
    }
}
