import java.util.*;

public class D
{
    
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.print("Case #" + caseno + ": ");

	    int N = in.nextInt();
	    double mk[] = new double[N];
	    double mn[] = new double[N];
	    
	    for(int i = 0; i < N; i++)
		mn[i] = in.nextDouble();
	    for(int i = 0; i < N; i++)
		mk[i] = in.nextDouble();
	    
	    Arrays.sort(mn);
	    Arrays.sort(mk);

	    int kT = 0;
	    int kD = 0;
	    
	    int winsD = 0;
	    int winsT = 0;

	    for(int n = 0; n < N; n++){
		while(kT < N && mk[kT] < mn[n])
		    kT++;
		if(kT == N)
		    winsT++;
		else
		    kT++;

		if(mn[n] > mk[kD]){
		    kD++;
		    winsD++;
		}
	    }
	    
	    System.out.println("" +  winsD + " " + winsT);
	}
    }
}