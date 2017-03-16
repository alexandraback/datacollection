import java.io.File;
import java.io.FileWriter; 
import java.util.Arrays;
import java.util.Scanner;


public class first {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception { 
		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			  
			int res=0;
		    int mob = sc.nextInt();
		    int N = sc.nextInt();
		    int [] mobs = new int [N];
		    for(int j = 0; j < N ; j++)
		    	mobs[j] = sc.nextInt();
		    Arrays.sort(mobs);
		    System.out.println(Arrays.toString(mobs));
		    int max = N;
		    int movessofar = 0;
		    int ind = 0;
		    while (mob!=1)
		    {
		    	System.out.println(mob+ "  mm");
		    	//System.out.println("mmm " + mob);
		    	 while(ind < N)
		    	 {
		    		 if(mobs[ind]< mob)
		    		 {
		    			 //System.out.println("swallowed ");
		    			 mob+=mobs[ind];
		    			 ind++; 
		    		 }
		    		 else{
		    			 break;
		    		 }
		    	 }
		    	 if(ind==N)
		    	 {	  
		    		 max = Math.min(max,movessofar);
		    	 	break;
		    	 }
		    	 if(max > movessofar+N-ind)		    		 
		    	  max = movessofar+N-ind;
		    	 movessofar++;
		    	 mob=2*mob-1;
		    	 
		    }
		    res = max;	
			 
			
			System.out.println(res);
			System.out.println("Case #"+i+": "+res );
			out.write("Case #"+i+": "+res +"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		} 
		out.flush();
		sc.close();
		out.close(); 
	}
	  
}
