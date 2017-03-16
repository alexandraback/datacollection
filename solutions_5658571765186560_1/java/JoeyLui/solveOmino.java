import java.util.*;
import java.io.*;

public class solveOmino {
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                 PrintWriter writer = new PrintWriter("ominoLarge.txt", "UTF-8");
                 int _n = Integer.parseInt(in.nextLine());
                 for (int l=0; l<_n; l++) {
                     String[] s= in.nextLine().split(" ");
                     int x = Integer.parseInt(s[0]);
                     int r = Integer.parseInt(s[1]);
                     int c = Integer.parseInt(s[2]);;
                     int large = Math.max(r, c);
                     int small = Math.min(r, c);
                     //System.out.println("case: "+l+" "+x+" "+r+" "+c);
                     if ((r*c)%x != 0) {
                         writer.println("Case #"+(l+1)+": RICHARD");
                         continue;
                     } 
                     if (x==1) {
                         writer.println("Case #"+(l+1)+": GABRIEL");
                     }
                     else if (x==2) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
                     }
                     else if (x==3) {
                         if (r*c>3) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
                         }
                         else {
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                     }
                     else if (x==4) {
                         if (r*c>8) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
                         }
                         else {
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                     }
                     else {
                         if (large >= x && small >= (x+1)/2+1) {
                            writer.println("Case #"+(l+1)+": GABRIEL");
                         }
                         else if (small < (x+1)/2){
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                         else if (small == (x+1)/2) {
                             int ct =(x+1)/2;
                             int sq = (ct-1)*(ct-1)/2;
                             boolean flag =false;
                             //System.out.println(ct+" "+sq+" "+Integer.toString(large)+" "+Integer.toString((x+1)/2+1));
                             for (int i=1; i<=sq; i++) {
                                 flag= false;
                                 for (int j=1; j<= large-x/2-2; j++) {
                                     
                                     if ((i+j*small)%x==0) {
                                         flag = true;
                                         break;
                                     }
                                 }
                                 //System.out.println(i+" flag "+flag);
                                 if (!flag) {
                                     writer.println("Case #"+(l+1)+": RICHARD");
                                     break;
                                 }
                             }
                             
                             if (flag) {
                                 writer.println("Case #"+(l+1)+": GABRIEL");
                             }
                         }
                         else {
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                     }
                 }
                 writer.close();
            }
            catch(IOException e) {
            }
            in.close();
        }
        catch (FileNotFoundException e) {
        }
    }
}