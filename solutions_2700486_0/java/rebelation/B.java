import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    int N, X, Y;
    int sx, B;
    int slideLeft(int y, int x){
	return (y-1)*B + (x-1);
    }
    int slideRight(int y, int x){
	return (y-1)*B + (x+1);
    }
    boolean sim(int mask){
	int[] x = new int[N];
	int[] y = new int[N];
	HashSet<Integer> exist = new HashSet<Integer>();
	exist.add(sx);
	x[0] = sx; y[0] = 0;
	for(int i = 1; i < N; i++){
	    boolean left = ((int)((mask>>i)&1)==1);
	    int cx = sx;
	    int cy = N;
	    boolean stop = false;
	    while(!stop){
		if(exist.contains((cy-2)*B + cx)){
		    if(left){
			if(exist.contains(slideLeft(cy, cx))){
			    if(exist.contains(slideRight(cy, cx))){
				x[i] = cx; y[i] = cy;
				exist.add(cy * B + cx);
				stop = true;
			    }else{
				cx++;
			    }
			}else{
			    cx--;
			}
		    }else{ //right
			if(exist.contains(slideRight(cy, cx))){
			    if(exist.contains(slideLeft(cy, cx))){
				x[i] = cx; y[i] = cy;
				exist.add(cy * B + cx);
				stop = true;
			    }else{
				cx--;
			    }
			}else{
			    cx++;
			}
		    }
		}else if(exist.contains(slideLeft(cy, cx))){
		    if(exist.contains(slideRight(cy, cx))){
			x[i] = cx; y[i] = cy;
			exist.add(cy * B + cx);
			stop = true;
		    }else{
			cx++;
		    }
		}else if(exist.contains(slideRight(cy, cx))){
		    if(exist.contains(slideLeft(cy, cx))){
			x[i] = cx; y[i] = cy;
			exist.add(cy * B + cx);
			stop = true;
		    }else{
			cx--;
		    }
		}
		cy--;
		if(cy == 0){
		    x[i] = cx;
		    y[i] = cy;
		    exist.add(cy * B + cx);
		    stop = true;
		}
	    }
	}
	//if(mask==0){for(int i = 0; i < N; i++)System.out.printf("(%d,%d) ", x[i]-sx, y[i]);System.out.println();}
	return exist.contains(Y * B + X+sx);
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

	int T = sc.nextInt();
	for(int o = 1; o <= T; o++){
	    System.out.printf("Case #%d: ", o);
	    N = sc.nextInt();
	    X = sc.nextInt();
	    Y = sc.nextInt();
	    sx = N*2;
	    B = N*N*10;
	    int ans = 0;
	    int lim = 1<<N;
	    for(int s = 0; s < lim; s++){
		if(sim(s))ans++;
	    }
	    System.out.printf("%.7f\n", 1.0*ans/lim);
	}
    }
}
