import java.io.*;

class Main2
{
    public static void main(String args[]) throws IOException
    {
        String in = null;
        BufferedReader br = new BufferedReader(new FileReader("inp.txt"));
        int nooftest = Integer.parseInt(br.readLine());
        for(int i=0;i<nooftest;i++)
        {
            double C, F, X, ans = 0;
            String hh[] = br.readLine().split(" ");
            C = Double.parseDouble(hh[0]);
            F = Double.parseDouble(hh[1]);
            X = Double.parseDouble(hh[2]);
            ans = solve(0,C,F,X,0);
            System.out.println("Case #"+(i+1)+": "+ans);
        }
    }
    
    static double solve(double nooffarms, double C, double F, double X, double time)
    {
        //no more farms
        double rate = F * nooffarms + 2.0;
        double t1 = X/rate + time;
        
        //one more farm
        double t2 = C/rate;
        nooffarms++;
        rate = F * nooffarms + 2.0;
        double t3 = X/rate + t2 + time;
        
        if(t1 <= t3)
            return t1;
        else
        {
            return solve(nooffarms,C,F,X,time+t2);
        }
    }
}