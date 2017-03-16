import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            out.print("Case #"+(i+1)+": ");
            in.readLine();
            int E=in.nextInt();
            int R=in.nextInt();
            int N=in.nextInt();

            int a[]=in.parseInt1D(N);
            max=0;
            ee=E;
            max=max(0,E,R,a);
            out.println(max);
        }
    }
    int max=0;
    int ee=0;
    public int max(int st,int E,int R,int a[]){
        if(st==a.length){
            return 0 ;
        }

        int max=0;
        for(int i=E;i>=0;i--){
            max=Math.max(max,a[st]*i+max(st+1,Math.min(ee,E-i+R),R,a));
        }
        return max;
    }
}

class InputReader {
    private BufferedReader br;
    private StringTokenizer st;
    public InputReader(InputStream in) {
        br=new BufferedReader(new InputStreamReader(in));
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public InputReader(String file)  {
        try {
            br=new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        } catch (FileNotFoundException e) {

        }
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public boolean readLine() {
        try {
            st=new StringTokenizer(br.readLine());

        } catch (IOException e) {
            return false;
        }
        catch (NullPointerException e){
            return false;
        }
        return true;
    }
    public int nextInt(){
        return Integer.parseInt(st.nextToken());
    }

    /**
     * Parse 1D array from current StringTokenizer
     */
    public int[] parseInt1D(int n){
        readLine();
        int r[]=new int[n];
        for(int i=0;i<n;i++){
            r[i]=nextInt();
        }
        return r;
    }


}

