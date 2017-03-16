import java.io.*;

class Main2
{
    public static void main(String args[]) throws IOException
    {
        String in = null;
        BufferedReader br = new BufferedReader(new FileReader("inp.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        int nooftest = Integer.parseInt(br.readLine());
        for(int i=0;i<nooftest;i++)
        {
            double C, F, X, ans = 0;
            String hh[] = br.readLine().split(" ");
            C = Double.parseDouble(hh[0]);
            F = Double.parseDouble(hh[1]);
            X = Double.parseDouble(hh[2]);
            double nooffarms = 0;
             double t1 = 1, t3 = 0;
            double time = 0;
            while(t1 > t3)
            {
                //no more farms
                double rate = F * nooffarms + 2.0;
                t1 = X/rate + time;
        
                //one more farm
                double t2 = C/rate;
                nooffarms++;
                rate = F * nooffarms + 2.0;
                t3 = X/rate + t2 + time;
                
                time = time + t2;
            }
            ans = t1;
            bw.write("Case #"+(i+1)+": "+ans+"\n");
        }
        bw.flush();
        bw.close();
        System.out.println("done");
    }
}