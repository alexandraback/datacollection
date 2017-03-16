import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class B {
	PrintWriter out;
	BufferedReader f;
	public void run()throws Exception{
		f = new BufferedReader(new FileReader("B-small-attempt4.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	    	System.out.print("Case #"+(x+1)+": ");
	    	out.print("Case #"+(x+1)+": ");
	   		StringTokenizer a = new StringTokenizer(f.readLine());
			long E = Long.parseLong(a.nextToken()), R = Long.parseLong(a.nextToken()), N = Long.parseLong(a.nextToken());
			long E2 = E;
			long[] activities = new long[(int)N];
			a = new StringTokenizer(f.readLine());
			for(int y = 0; y<N; y++){
				activities[y] = Long.parseLong(a.nextToken());
			}
			//System.out.println(Arrays.toString(activities));
			long max = 0;
			for(int y = 0; y<N; y++){
				int away = -1;
				for(int z = y+1; z<N; z++){
					if(activities[z]>activities[y]){away = z-y;
						break;
					}
				}
				if(away==-1){
					System.out.println("act "+activities[y]+" "+E2);
					max+=activities[y]*E2;
					E2 = 0;
				}
				else{
					System.out.println("away "+away+" "+R);
					long spend = E2+away*R-E;
					if(spend>0){
						max+=spend*activities[y];
						E2-=spend;
					}
					y+=away-1;
				}
				E2 = E2+R*Math.abs(away)>E?E:E2+R*Math.abs(away);
				System.out.println(max);
				//System.out.println(E2);
			}
			System.out.println(max); 
			out.println(max); 
	    }
	    out.close();
	    System.exit(0);
	}
	
    public static void main (String [] args) throws Exception {
		new B().run();
    }
}
