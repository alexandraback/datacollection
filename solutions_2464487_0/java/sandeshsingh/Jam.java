/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package jam;

import java.util.*;

//import java.util.ArrayList;

/**
 *
 * @author sandesh
 */
public class Jam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner en=new Scanner(System.in);
			int casenum = en.nextInt();
	        for(int j = 0; j < casenum; j++){
	        	
                        long r=en.nextLong();
                        long t=en.nextLong();
                        long s=0,count=0,p=0;
                        for(int i=1;;i+=2)
                        {
                           p=(r+i)*(r+i)-(r+i-1)*(r+i-1);
			if(p<=t)
			{
				count++;
				t-=p;
			}
			else 
			break;
                        }
                        System.out.println("Case #"+(j+1)+": "+count);
                        
                        
                        
                        
                }
       
    }
}
