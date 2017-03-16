import java.util.LinkedList;
import java.util.*;


public class Main {

    public int index;
    public int delta;
    public Main prev;
    public Main mm;
    

    static int k, l, s;
    static int max;
    static int totalCases;
    static String keys, word;
    static char[] words;
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);

        
        int t = s.nextInt();
        
        for(int cas = 1; cas <= t; cas++)
        {
            k = s.nextInt();
            l = s.nextInt();
            Main.s = s.nextInt();
            
            keys = s.next();
            word = s.next();
            
            System.out.printf("Case #%d: %.7f\n", cas, solve());
            
        }
        

//        System.out.println(win[n-1]);

        s.close();
    }
    
    public static double solve()
    {
        max = 0;
        totalCases = 0;
        words = new char[s];
        
        Main main = new Main();
        main.recurse(0);
        
        //max banana
        int maxB = max;
        
        int poss = 1;
        for(int i=0; i<s; i++)
        {
            poss *= k;
        }
        double exp = (double) totalCases / poss;
        //System.out.printf("max banana = %d, total cases = %d, possibilities = %d, exp = %f\n", maxB, totalCases, poss, exp);
        return (double)maxB - exp;
    }
    
    public void recurse(int index){
        
        if(index == s)
        {
            
            int count=0;
            int ind;
            //find words
            for(int i=0; i< s-l+1; i++)
            {
                boolean match = true;
                ind = i;
                for(int j=0; j< l; j++, ind++)
                    if( words[ind] != word.charAt(j) )
                        match = false;
                if(match)
                    count++;
            }
            //ck max
            if(max < count)
                max = count;
            totalCases += count;
            
        }
        
        else
        {
            for(int i=0; i< k; i++)
            {
                //pick it
                words[index] = keys.charAt(i);
                recurse(index+1);
            }
        }
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
}
