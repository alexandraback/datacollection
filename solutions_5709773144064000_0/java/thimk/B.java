import java.util.*;

public class B{

    public static final boolean DEBUG = false;

    public static void debug(String s){
	if(DEBUG) System.out.println("*** " + s);
    }
    
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	
	int T = in.nextInt();
	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.print("Case #" + caseno +": ");

	    double C = in.nextDouble();
	    double F = in.nextDouble();	    
	    double X = in.nextDouble();
	    
	    int k = (int)(Math.round(Math.floor(X/C-2/F)));
	    if(k < 0) k =0;
	    debug("k = " + k);
	    

	    double time = X/(2+k*F);
	    for(int i = 0; i < k; i++)
		time += C/(2 + i*F);
	    
	    System.out.println(time);
	}
    }



}
