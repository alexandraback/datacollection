
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author CuteCoke
 */
public class A {
    final String TASK_NAME = "A-small-attempt0";
    //final String TASK_NAME = "A-large-practice";
    //final String TASK_NAME = "sample";
    final String IN_FILE = TASK_NAME+".in";
    final String OUT_FILE = TASK_NAME+".out";

	// In
	int N=0;
	int M=0;
	int[][] adj=null;
	int[][] reachCnt=null;
	// Out
	String ans = "";
	
	private int calcRCnt(int i, int j){
		int cnt = 0;
		if (reachCnt[i][j] > -1) return reachCnt[i][j];
		for(int c=0; c<adj[i].length; c++){
			//System.out.println("adj["+i+"]["+c+"]==j ? "+adj[i][c]+"=="+j+" ==> "+(adj[i][c]==j));
			if (adj[i][c]==j) 
				cnt += 1;
			else
				cnt += calcRCnt(adj[i][c], j);
		}
		reachCnt[i][j] = cnt;
		return cnt;
	}
	
    public void solve(){
		reachCnt = new int[N+1][N+1]; // telling whether a can go to b 
		
		// Calc Reach Count
		int max = Integer.MIN_VALUE;
		for(int i=1;i<=N; i++) for(int j=1;j<=N; j++) reachCnt[i][j] = -1;
		for(int i=1;i<=N; i++) for(int j=1;j<=N; j++) if (i!=j){
			max = Math.max(max, calcRCnt(i,j));
			//System.out.println("reachCnt["+i+"]["+j+"] = "+(reachCnt[i][j]));
			if (max>=2) break;
		}
		ans = (max>=2)?"Yes":"No";
    }

    public void doMain() throws Exception{
    try{

        Scanner sc1 = null;
        BufferedReader br = new BufferedReader(new FileReader(IN_FILE));
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE));

        int T = Integer.parseInt(br.readLine());
        for (int a=0; a<T; a++){
            bw.write("Case #"+(a+1)+": ");
            sc1 = new Scanner(br.readLine());
            N = sc1.nextInt();
			adj = new int[N+1][];
			for (int b=0; b<N; b++){
				sc1 = new Scanner(br.readLine());
				M = sc1.nextInt();
				adj[b+1] = new int[M+1];
				for (int c=0; c<M; c++){
					adj[b+1][c] = sc1.nextInt();
					//System.out.println("adj["+(b+1)+"]["+c+"] = "+adj[b+1][c]);
				}
			}
			solve();
            bw.write(ans+"\n");
        }
        br.close();
        bw.close();

    }catch(FileNotFoundException e){
        System.err.println("In File: "+(new File(IN_FILE)).getAbsolutePath());
        System.err.println("Out File: "+(new File(OUT_FILE)).getAbsolutePath());
        e.printStackTrace(System.err);
    }
    }

    public static void main(String[] s) throws Exception{
        try{
            (new A()).doMain();
        }catch(Exception e){
            e.printStackTrace(System.err);
        }


    }
}



