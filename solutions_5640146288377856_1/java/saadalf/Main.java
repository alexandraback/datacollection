
import java.util.Scanner;

public class Main {

    static Scanner stdin = new Scanner(System.in);    
    
    public static void main(String[] args) {
        int cases = stdin.nextInt();
        for (int i = 0; i < cases; i++) {
            Main mt = new Main();
            mt.input();
            mt.process();
            System.out.println("Case #"+(1+i)+": "+mt.solution());
        }
    }    

    int r,c,w,result;
    
    private String solution() {
        return ""+result;
    }

    private void input() {
        r = stdin.nextInt();
        c = stdin.nextInt();
        w = stdin.nextInt();
    }

    private void process() {
        int full = c/w;
        int first = full*r;
        result = first + w - 1 + (c%w==0?0:1);
    }
    
}
