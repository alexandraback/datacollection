
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A
{
    BufferedReader m_in;
    PrintWriter m_out;
    StringTokenizer m_st;
    
    public static void main(String[] args)
    {
        try
        {
            new A().run();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    
    String nt() throws Exception
    {
        while (m_st==null||!m_st.hasMoreTokens())
        {
            m_st = new StringTokenizer(m_in.readLine());
        }
        return m_st.nextToken();
    }
    
    String nl() throws Exception
    {
        m_st = null;
        return m_in.readLine();
    }
    
    int ni() throws Exception
    {
        return Integer.parseInt(nt());
    }
    
    double nd() throws Exception
    {
        return Double.parseDouble(nt());
    }
    
    void add(String s)
    {
        m_out.print(s);
    }
    
    void addln(String s)
    {
        m_out.println(s);
    }
    
    void prc(String s)
    {
        System.out.print(s);
    }
    
    void prcln(String s)
    {
        System.out.println(s);
    }
    
    public void run() throws Exception
    {
        m_in = new BufferedReader(new FileReader("A-small-attempt0.in"));
        m_out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
//        m_in = new BufferedReader(new InputStreamReader(System.in));
//        m_out = new PrintWriter(System.out);      

        //
        int cnt = ni();
        
        for (int i = 0; i < cnt; i++)
        {
            String s = nt();
            int n = ni();
            
            addln("Case #"+(i+1)+": "+solve(s, n));
        }
                
        //
        m_in.close();
        m_out.flush();
        m_out.close();
    }
    
    private long solve(String s, int n)
    {
        long total = 0;
        int len = s.length();
        for (int i = 0; i < len; i++){
            for (int j = i; j < len; j++){
                if (check(s.substring(i, j + 1), n)){
                    total++;
                }
            }
        }
        return total;
    }
    
    public static HashSet<Character> hs = new HashSet<Character>();
    static{
        hs.add('a');
        hs.add('e');
        hs.add('i');
        hs.add('o');
        hs.add('u');
    }
    
    boolean check(String s, int n){
        int k = 0;
        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if (!hs.contains(ch)){
                k++;
            }
            else{
                k = 0;
            }
            if (k >= n)
                return true;
        }
        return false;
    }
}
