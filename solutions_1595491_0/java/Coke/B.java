
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
public class B {
    final String TASK_NAME = "B-small-attempt2";
    //final String TASK_NAME = "sample";
    final String IN_FILE = TASK_NAME+".in";
    final String OUT_FILE = TASK_NAME+".out";

	public int solve(int N, int S, int p, int[] t){
		int res = 0;
		
		for(int i=0; i<N; i++){
			if (t[i]>=(p*3-2)){
				res++;
			}else if (t[i]>=2 && t[i]>=(p*3-4) && S>0){
				res++;
				S--;
			}
		}
        return res;
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
            int N = sc1.nextInt();
            int S = sc1.nextInt();
            int p = sc1.nextInt();
			int[] t = new int[N];
			for (int b=0; b<N; b++){
				t[b] = sc1.nextInt();
			}
            int ans = solve(N, S, p, t);
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
            B test = new B();
            test.doMain();
        }catch(Exception e){
            e.printStackTrace(System.err);
        }


    }
}
