/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Hhhhh1111;

import java.io.*;

/**
 *
 * @author KHURSHEED
 */
public class Hhhhh1111
{

    int sno=1;
    BufferedReader br;
    BufferedWriter bo;
    int rsnosc;  
    public String x_forward()
    {
        return "WE";
    }
    public String x_backward()
    {
        return "EW";
    }
    public String y_up()
    {
        return "SN";
    }
    public String y_down()
    {
        return "NS";
    }
    public String solve(long x,long y)
    {
        String result="";
        long posx=(long)(x*Math.signum(x));
        long posy=(long)(y*Math.signum(y));
        for(long i=0;i<posx;i++)
        {
            if(x<0)
                result+=x_backward();
            else
            if(x>0)
                result+=x_forward();            
        }
        for(long i=0;i<posy;i++)
        {
            if(y<0)
                result+=y_down();
            else
            if(y>0)
                result+=y_up();            
        }
        
        return result;
    }
    public void rf()
    {
		try {
			br = new BufferedReader(new FileReader("src/Hhhhh1111/Input.txt"));
                        bo = new BufferedWriter(new FileWriter("src/Hhhhh1111/output.txt"));                
			rsnosc = Integer.parseInt(br.readLine());    
			do{
				rs();
				sno++;
			}while(sno<rsnosc+1);
		} catch (Exception e) {
		}
    }
    public void rs() throws IOException{
		
                Long armin,count,x,y;
		String temp[] = br.readLine().split(" ");                
		x=Long.parseLong(temp[0]);
                y=Long.parseLong(temp[1]); 
                
                wr(solve(x, y));
                 
	}
	public void wr(String res) throws FileNotFoundException, IOException
        {
                String a;
                a="Case #"+sno+": "+res+"\n";                
		System.out.print("Case #"+sno+": ");                
		System.out.println(res);
                
	}

        public static void main(String[] args) 
        {
            Hhhhh1111 c=new Hhhhh1111();
            c.rf();
    }
}
