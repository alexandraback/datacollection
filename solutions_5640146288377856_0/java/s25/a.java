
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class cc {
     public static void main(String []arg) throws FileNotFoundException{
    //Scanner s=new Scanner(new File(""));
         Scanner s=new Scanner(System.in);
        try (PrintWriter p = new PrintWriter(new File("d://a.out"))) {
            int n=s.nextInt();
            for(int i=0;i<n;i++){
                int w=s.nextInt();
                int h=s.nextInt();
                int l=s.nextInt();
                if(w*h==l)
                    p.println("Case #"+(i+1)+": "+l);
                else if(l==1)
                     p.println("Case #"+(i+1)+": "+w*h);
                else{
                int d=h/l;
                d=d*w;
                d=d+l-1;
                if(h%l!=0)d++;
                 p.println("Case #"+(i+1)+": "+(d));
                                }
                                }
            p.flush();
            p.close();
        }catch(Exception e){}
     }
}
