/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package cj1;

import java.io.*;

/**
 *
 * @author KHURSHEED
 */
public class Cj1 {

    int sampleNo=1;
    BufferedReader br;
    BufferedWriter bo;
    int NoOfSampleCases;  
    public String xf()
    {
        return "WE";
    }
    public String xb()
    {
        return "EW";
    }
    public String yu()
    {
        return "SN";
    }
    public String yd()
    {
        return "NS";
    }
    public String find(long x,long y)
    {
        String result="";
        long posx=(long)(x*Math.signum(x));
        long posy=(long)(y*Math.signum(y));
        for(long i=0;i<posx;i++)
        {
            if(x<0)
                result+=xb();
            else
            if(x>0)
                result+=xf();            
        }
        for(long i=0;i<posy;i++)
        {
            if(y<0)
                result+=yd();
            else
            if(y>0)
                result+=yu();            
        }
        
        return result;
    }
    public void readFile()
    {
		try {
			br = new BufferedReader(new FileReader("src/Cj1/Input.txt"));
                        bo = new BufferedWriter(new FileWriter("src/Cj1/output.txt"));
                
			NoOfSampleCases = Integer.parseInt(br.readLine());    
			do{
				readSamples();
				sampleNo++;
			}while(sampleNo<NoOfSampleCases+1);
		} catch (Exception e) {
		}
    }
    public void readSamples() throws IOException{
		
                Long armin,count,x,y;
		String temp[] = br.readLine().split(" ");                
		x=Long.parseLong(temp[0]);
                y=Long.parseLong(temp[1]); 
                
                writeResult(find(x, y));
                 
	}
	public void writeResult(String res) throws FileNotFoundException, IOException
        {
                String a;
                a="Case #"+sampleNo+": "+res+"\n";                
		System.out.print("Case #"+sampleNo+": ");                
		System.out.println(res);
                
	}

        public static void main(String[] args) 
        {
            Cj1 c=new Cj1();
            c.readFile();
    }
}
