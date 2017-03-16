import java.io.*;
import java.util.*;
public class QR_B {
    static int[][] field;
    static int N, M;
	public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("B-large.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());
	    
	    int testn = Integer.parseInt(st.nextToken());    
	    int caseno=1;
	    while(testn-->0) {
		int here;
		if(caseno==6)
		    here =0;
		String result="YES";
		st = new StringTokenizer(f.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		field = new int[N][M];
	    	for (int i = 0; i < N; i++) {
	    	    st = new StringTokenizer(f.readLine());
	    	    for (int j = 0; j < M; j++) {
	    		field[i][j] = Integer.parseInt(st.nextToken());
		    }
		}
//	    	boolean access[][] = new boolean[N][M];
//	    	for (int i = 0; i < N; i++) {
//		    access[i][M-1]=true;
//		    access[i][0]=true;
//		}
//	    	for (int i = 0; i < M; i++) {
//		    access[N-1][i]=true;
//		    access[0][i]=true;
//		}
//	    	boolean cont = true;
//	    	int delta_x[] = {1,-1,0,0};
//	    	int delta_y[] = {0,0,1,-1};
//	    	while(cont){
//	    	    cont=false;
//	    	    for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//			    if(access[i][j]) continue;
//			    for (int dir = 0; dir < 4; dir++) {
//				if((i+delta_x[dir]>=0)&&(i+delta_x[dir]<N)&&
//					(j+delta_y[dir]>=0)&&(j+delta_y[dir]<M)&&
//					access[i+delta_x[dir]][j+delta_y[dir]]&&
//					field[i+delta_x[dir]][j+delta_y[dir]]<=field[i][j]){
//				    access[i][j]=true;
//				    cont=true;
//				}  
//			    }
//			    
//			}
//		    }
//	    	}
	    	boolean check = true;
	    	for (int i = 0; i < N && check; i++) {
		    for (int j = 0; j < M && check; j++) {
			int max = 0;
			for (int j2 = 0; j2 < N; j2++) {
			    max=Math.max(field[j2][j], max);
			}
			if(field[i][j]==max) continue;
			max=0;
			for (int j2 = 0; j2 < M; j2++) {
			    max=Math.max(field[i][j2], max);
			}
			if(field[i][j]!=max){
			    check=false;
			    result="NO";
			    break;
			}
		    }
		}
	    	System.out.println(result);
	    
	    out.println("Case #"+caseno+++": "+result);
	    }                           
	    
	    out.close();                                  
	    System.exit(0);                              
	  }
}