/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package j1;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

/**
 *
 * @author KHURSHEED
 */

public class J1 
{
    
    ArrayList<Long> al = new ArrayList<Long>();
    
    int sampleNo=1;
    BufferedReader br;
    BufferedWriter bo;
    int NoOfSampleCases;        
    
    public void addElement(String t[])
    {
        al.clear();
        for(int i=0;i<t.length;i++)
        {
            al.add(Long.parseLong(t[i]));                    
        }
    }
    public void sort()
    {
        int i,j;
        int s=al.size(),pos = 0;
        long m = 0,temp;        
        for(i=0;i<s;i++)
        {
            m=al.get(i);
            pos=i;
            for(j=i+1;j<s;j++)
            {   
                if(m>al.get(j))
                {
                    m=al.get(j);
                    pos=j;
                }
            }
            temp=al.get(pos);
            al.set(pos,al.get(i));                
            al.set(i,temp);        
        }
        
    }
    public void print()
    {
        for(int i=0;i<al.size();i++)
            System.out.print("-->"+al.get(i));            
    }
    public long find1(long a)
    {        
        long count=0;
        long total=a;
        int i=0;
        while(i<al.size() )
        {
            
            if(total>al.get(i))
            {
                total=total+al.get(i);
                i++;
            }
            else
            {
                if(total+total-1>al.get(i))
                {
                    count++;
                    total+=total-1;
                }
                else
                {
                    count++;//remove
                    i++;         
                }
            }
            //System.out.print("\n-->"+i+"-->"+total);            
        }    
        
        
        return count;
    }
    public long find2(long a)
    {        
        long count=0;
        long total=a;
        int i=0;
        long prev=-1;
        while(i<al.size() && prev!=total)
        {
            
            if(total>al.get(i))
            {
                prev=total;
                total=total+al.get(i);
                i++;
            }
            else
            {
                prev=total;
                total+=total-1;
                //if(total>al.get(i))
                {
                    count++;                    
                }                
            }
            //System.out.print("\n-->"+i+"-->"+total);            
        }    
        if(prev==total)
            count=i+al.size();
                
        return count;
    }
    public void readFile()
    {
		try {
			br = new BufferedReader(new FileReader("src/j1/Input.txt"));
                        bo = new BufferedWriter(new FileWriter("src/j1/output.txt"));
                
			NoOfSampleCases = Integer.parseInt(br.readLine());    
			do{
				readSamples();
				sampleNo++;
			}while(sampleNo<NoOfSampleCases+1);
		} catch (Exception e) {
			//System.out.println("Text - File Exception : " +e);
		}
    }
    public void readSamples() throws IOException{
		
                Long armin,count,res1,res2;
		String temp[] = br.readLine().split(" ");                
		armin=Long.parseLong(temp[0]);
                count=Long.parseLong(temp[1]);
                String temp1[] = br.readLine().split(" ");                
                
                addElement(temp1);
                sort();
                //print();
                res1=find1(armin);
                res2=find2(armin);
		//System.out.print("\n-->1)"+res1+" : 2)"+res2);
                 if(res1<res2)
                  writeResult(res1);
                else
                    writeResult(res2);
	}
	public void writeResult(long res) throws FileNotFoundException, IOException
        {
                String a;
                a="Case #"+sampleNo+": "+res+"\n";                
		System.out.print("Case #"+sampleNo+": ");                
		System.out.println(res);
                //bo.write(a, a.length()+10,a.length());               
                
	}

    public static void main(String[] args) 
    {
               
        J1 j=new J1();
        j.readFile();
        
    }
}
