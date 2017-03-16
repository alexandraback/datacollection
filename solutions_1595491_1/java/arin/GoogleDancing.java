package qual;

import java.util.Scanner;

public class GoogleDancing {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
        
		int T = in.nextInt();
		
		in.nextLine();
		
	    for(int t=0;t<T;t++)
	    {
	    	String s = in.nextLine();
	    	String[] inputs = s.split(" ");
	    	int noOfGooglers = Integer.parseInt(inputs[0]);
	        int surprising = Integer.parseInt(inputs[1]);
	        int p = Integer.parseInt(inputs[2]);
	        int count = 0;
	        for(int i=0;i<noOfGooglers;i++)
	        {
	        	int ni = Integer.parseInt(inputs[3 + i]);
	        	int rem = ni - p;
	        	if(p==0)
	        		count++;
	        	else
	        	if(p==1)
	        	{
	        		if(ni>=1)
	        			count++;
	        	}
	        	else	
	        	if(rem>= (2*p - 2))
	        		count++;
	        	else if(rem>= (2*p - 4) && surprising>0)
	        	{
	        		count++;
	        		surprising--;
	        	}
	        }
	        System.out.println("Case #" + (t+1) + ":" + " " + count);
	    }

	}

}
