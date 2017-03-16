
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B
{
    BufferedReader m_in;
    PrintWriter m_out;
    StringTokenizer m_st;
    
    public static void main(String[] args)
    {
        try
        {
            new B().run();
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
//        m_in = new BufferedReader(new FileReader("input.txt"));
        m_in = new BufferedReader(new FileReader("B-small-attempt1.in"));
        m_out = new PrintWriter(new FileWriter("B-small-attempt1.out"));
//        m_in = new BufferedReader(new InputStreamReader(System.in));
//        m_out = new PrintWriter(System.out);      

        //
        int cnt = ni();
        
        for (int i = 0; i < cnt; i++)
        {
            int x = ni();
            int y = ni();
            addln("Case #"+(i+1)+": "+solve(x, y));
        }
                
        //
        m_in.close();
        m_out.flush();
        m_out.close();
        //
        m_in.close();
        m_out.flush();
        m_out.close();
    }
    
    private String solve(int x, int y)
    {
        String result = "";
        
        if (x > 0)
            result += rep("WE", x);
        if (x < 0)
            result += rep("EW", -x);
        if (y > 0)
            result += rep("SN", y);
        if (y < 0)
            result += rep("NS", -y);
        return result;
    }

    String rep(String x, int n){
        StringBuffer result = new StringBuffer();
        for (int i = 0; i < n; i++){
            result.append(x);
        }
        return result.toString();
    }
    
}
