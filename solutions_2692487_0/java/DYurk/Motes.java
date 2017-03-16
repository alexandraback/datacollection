import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class Motes {

    Scanner sc;
    PrintWriter out;

    public static void main(String[] sArgs) throws IOException {
        new Motes();
    }

    Motes() throws IOException {
        sc = new Scanner(new File("Motes.in"));
        out = new PrintWriter("Motes.out");

        int T = Integer.parseInt(sc.nextLine());
	for(int count=1;count<=T;count++) {
	    int A = sc.nextInt(), N = sc.nextInt(); sc.nextLine();
	    int[] motes = new int[N], dif = new int[N];
	    String[] sAry = sc.nextLine().split(" ");
	    for(int i=0;i<N;i++)
		motes[i] = Integer.parseInt(sAry[i]);
	    Arrays.sort(motes);
	    int add=0, rem=0, ind=0, cur=0;
	    while(ind<N) {
		if(A<2) {
		    dif[0] = Integer.MAX_VALUE;
		    add = Integer.MAX_VALUE;
		    ind=N;
		    break;
		}
		if(A > motes[ind]) {
		    dif[ind] = cur;
		    cur=0;
		    A+=motes[ind];
		    ind++;
		    continue;
		}
		A+=A-1;
		cur++;
		add++;
	    }
	    ind--;
	    int aT=0, rT=0;
	    while(ind>-1) {
		rT++;
		aT+=dif[ind];
		if(rT<aT) {
		    rem+=rT;
		    add-=aT;
		    rT=0;
		    aT=0;
		}
		ind--;
	    }
	    out.println("Case #"+count+": "+(add+rem));
	    System.out.println("Case #"+count+": "+(add+rem));
	    System.out.println(add+" "+rem);
	}

        out.close();
    }
}