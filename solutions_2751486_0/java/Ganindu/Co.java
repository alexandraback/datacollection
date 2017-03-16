
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Co {
    static Scanner sc = null;
    static BufferedWriter bw = null;
    public static void main(String[] args) {
        try {
            sc = new Scanner(new File("A-small-attempt0.in"));
            bw = new BufferedWriter(new FileWriter(new File("output.out")));
        } catch (Exception ex) {
            
        }
        
        int c = sc.nextInt();
        for(int t=1;t<=c;t++){
            
            String s = sc.next();
            int n = sc.nextInt();
            
            int l = s.length();
            int l1 = l-n;
            long nval = 0;
            
            int st=0;
      A:    for(int j=0;j<=l1;j++){
                for(int k=0;k<n;k++){
                    if(vow(s.charAt(j+k))) continue A;
                }
                nval += (j+1-st)*(l+1-j-n);
                st = j+1;
            }
                       
            try {               
                bw.write("Case #"+String.valueOf(t)+": ");              
                bw.write(String.valueOf(nval));
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
