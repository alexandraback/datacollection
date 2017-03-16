import java.util.*;
import java.io.*;

public class solveOmino {
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                 PrintWriter writer = new PrintWriter("omino.txt", "UTF-8");
                 int _n = Integer.parseInt(in.nextLine());
                 for (int l=0; l<_n; l++) {
                     String[] s= in.nextLine().split(" ");
                     int x = Integer.parseInt(s[0]);
                     int r = Integer.parseInt(s[1]);
                     int c = Integer.parseInt(s[2]);;
                     //System.out.println("case #: "+l+" "+x+" "+r+" "+c);
                     if (x==1) {
                         writer.println("Case #"+(l+1)+": GABRIEL");
                     }
                     else if (x==2) {
                         if ((r*c)%2==0) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
                         }
                         else {
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                     }
                     else if (x==3) {
                         if ((r*c)%3==0 && (r*c)>3) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
                         }
                         else {
                             writer.println("Case #"+(l+1)+": RICHARD");
                         }
                     }
                     else if (x==4) {
                         if ((r*c)%4==0 && (r*c)>8) {
                             writer.println("Case #"+(l+1)+": GABRIEL");
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