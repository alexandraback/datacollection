import java.util.LinkedList;
import java.util.*;


public class Main {

    public int index;
    public int delta;
    public Main prev;
    public Main mm;
    

    static int r, c, w;
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);

        
        int t = s.nextInt();
        
        for(int cas = 1; cas <= t; cas++)
        {
            r = s.nextInt();
            c = s.nextInt();
            w = s.nextInt();
            
            System.out.printf("Case #%d: %d\n", cas, solve());
            
        }
        

//        System.out.println(win[n-1]);

        s.close();
    }
    
    public static int solve()
    {
        if(c%w == 0)
            return (c/w) * r + (w-1);
        else
            return (c/w) * r + (w);
    }
    
    public static long reverse(long n)
    {
        String str = Long.toString(n);
        String newstr = "";
        for(int i=str.length()-1; i>=0; i--)
        {
            newstr = newstr.concat(str.substring(i, i+1));
        }
        return Long.parseLong(newstr);
    }
    
    public int recurse(int x, int y){
        return 1;
    }
}
