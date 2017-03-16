
import java.io.*;
import java.util.*;

public class GoodLuck1 {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    int K; 
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int[] prod = new int[K];
        int three = 0;
        int five = 0;
        int two = 0;
        int four = 0;
        int eight = 0;
        for(int i = 0; i<K; i++) {
            prod[i] = scan.nextInt();
            if(prod[i] % 125 == 0) {
                out.println("555");
                return;
            }
            if(prod[i] % 25 == 0) {
                five = 2;
            }
            else if(prod[i] % 5 == 0) {
                if(five==0) five = 1;
            }
            if(prod[i] % 27 == 0) {
                out.println("333");
                return;
            }
            if(prod[i] % 9 == 0) {
                three = 2;
            }
            else if(prod[i] % 3 == 0) {
                if(three==0) three = 1;
            }
            if(prod[i] % 64 == 0) {
                out.println("444");
                return;
            }
            if(prod[i] % 32 == 0) {
                out.println("244");
                return;
            }
            if(prod[i] % 16 == 0) {
                four = 2;
            }
            else if(prod[i] % 8 == 0) {
                eight = 1;
            }
            else if(prod[i] % 4 == 0) {
                if(four==0) four = 1;
            }
            else if(prod[i] % 2 == 0) {
                two = 1;
            }
        }
        
        if(five==2) {
            if(three==1) {
                out.println("355");
                return;
            }
            if(four==1) {
                out.println("455");
                return;
            }
            if(two==1) {
                out.println("255");
                return;
            }
            out.println("555");
            return;
        }

        if(three==2) {
            if(five==1) {
                out.println("335");
                return;
            }
            if(four==1) {
                out.println("334");
                return;
            }
            if(two==1) {
                out.println("233");
                return;
            }
            out.println("333");
            return;
        }
        
        if(four==2) {
            if(three==1) {
                out.println("344");
                return;
            }
            if(five==1) {
                out.println("445");
                return;
            }
            if(two==1) {
                out.println("244");
                return;
            }
            out.println("444");
            return;
        }
        
        if(three==1 && five==1) {
            if(two==1) {
                out.println("235");
                return;
            }
            if(four==1) {
                out.println("345");
                return;
            }
            out.println("335");
            return;
        }
        
        if(eight==1 && three==1) {
            out.println("234");
            return;
        }
        if(eight==1 && five==1) {
            out.println("245");
            return;
        }
        
        if(three==1) {
            if(four==1 && two==1) {
                out.println("223");
                return;
            }
            if(four==1) {
                out.println("344");
                return;
            }
            if(two==1) {
                out.println("223");
                return;
            }
            out.println("333");
            return;
        }

        if(five==1) {
            if(four==1 && two==1) {
                out.println("225");
                return;
            }
            if(four==1) {
                out.println("445");
                return;
            }
            if(two==1) {
                out.println("225");
                return;
            }
            out.println("555");
            return;
        }

        if(eight==1) {
            if(two==1) {
                out.println("222");
                return;
            }
            out.println("244");
            return;
        }
        
        out.println("222");
        return;
    }
    
    public void run() throws Exception {
        in.readLine();
        out.println("Case #1:");
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int R = scan.nextInt();
        scan.nextInt();
        scan.nextInt();
        K = scan.nextInt();
        for (int i = 1; i <= 100; i++) {
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new GoodLuck1().run();
    }

}
