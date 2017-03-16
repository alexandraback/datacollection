import java.util.*;
import java.io.*;


public class problem1
{
    private final Scanner sc;
    private static final boolean debug = true;

    static void debug(Object ... objects)
    {
        if(debug)
            System.err.println(Arrays.toString(objects));        
    }

    problem1()
    {
        sc = new Scanner(new BufferedInputStream(System.in));
    }

    public static void main(String [] args)
    {
        (new problem1()).solve();
    }
    
    
    void solve()
    {
        int T = sc.nextInt();
        int cs = 0;

        String [] trans = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv","qz"};
        String [] words = {"our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up","zq"};

        char dict[] = new char[256];
        char revDict[] = new char[256];
        

        for(int i=0;i<trans.length;i++)
        {
            for(int j=0;j<trans[i].length();j++)
            {
                dict[trans[i].charAt(j)] = words[i].charAt(j);
                revDict[words[i].charAt(j)] = trans[i].charAt(j);
            }
        }

        sc.nextLine();

        while(cs < T)
        {
            cs++;
            char [] chars  = sc.nextLine().trim().toCharArray();
            for(int i=0;i<chars.length;i++)
                chars[i] = dict[chars[i]];
            String ans = new String(chars);

            System.out.println("Case #" + cs+ ": "+ ans);
        }

    }
}
