import java.io.*;
import java.util.*;
import static java.lang.System.*;
public class C {
	public static void main (String [] args) throws Exception {new C().run();}
    int R,C, ar[];
    boolean found;
    HashSet<Integer> set;
    void recur(int r, int c, int left){
        if( left < 0 || found || (R-r)*c < left)return;
        if( r == R){
            if( left == 0){
                found = true;
                for(int i = 0; i<R; i++){
                    for(int j = 0; j<ar[i]; j++)
                        out.print("*");
                    for(int j = ar[i]; j<C; j++)
                        if( i == R-1 && j == C-1)
                            out.print("c");
                        else
                            out.print(".");
                    out.println();
                }
            }
            return;
        }
        
        int hash = r + c*(R+1) + left * (R+1)*(C+1);
        if( !set.add(hash)) return;
        
        ar[r] = c;
        recur(r+1, c, left-c);
        ar[r] = 0;
        
        if( r != R-1 || R==1){
            for(int i = Math.max(0,Math.min(C-2,c)); i>=0; i--){
                ar[r] = i;
                recur(r+1, i, left-i);
                ar[r] = 0;
            }
        }
        
    }
	public void run() throws Exception{
		Scanner file = new Scanner(new File("C-large.in.txt"));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d:%n",asdf+1);
            R = file.nextInt(); C = file.nextInt();
            int M = file.nextInt();
            found = false;
            ar = new int[R];
            set = new HashSet<Integer>();
            if( R*C == M + 1 ){
                for(int r = 0; r<R; r++){
                    for(int c = 0; c<C; c++)
                        if( r==R-1 && c == C-1)
                            out.print("c");
                        else
                            out.print("*");
                    out.println();
                }
            }else{
                recur(0,C, M);
                if( !found)
                    out.println("Impossible");
            }
		}
	}
}