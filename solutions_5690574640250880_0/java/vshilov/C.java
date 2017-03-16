import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            out.println("Case #"+(testCase+1)+":");
            int r=nextInt();
            int c=nextInt();
            int m=nextInt();
            int f=r*c-m;
            if(f==1){
                out.print('c');
                for(int i=1;i<c;i++)
                    out.print('*');
                out.println();
                for(int i=1;i<r;i++){
                    for(int j=0;j<c;j++)
                        out.print('*');
                    out.println();
                }
                continue;
            }
            if(r==1||c==1){
                if(r==1){
                    out.print('c');
                    for(int i=1;i<f;i++)
                        out.print('.');
                    for(int i=f;i<c;i++)
                        out.print('*');
                    out.println();
                }
                else {
                    out.println('c');
                    for (int i = 1; i < f; i++)
                        out.println('.');
                    for (int i = f; i < r; i++)
                        out.println('*');
                }
                continue;
            }
            boolean[][] field=new boolean[r][c];
            boolean bad=false;
            if(f%2!=0&&(c==2||r==2))bad=true;
            if(f/2<2)bad=true;
            int count=Math.min(f/2,c);
            for(int i=0;i<count;i++){
                field[0][i]=field[1][i]=true;
            }
            f-=count*2;
            if(f==1){
                if(r==2)bad=true;
                if(count<4)bad=true;
                if(!bad){
                    field[0][count-1]=field[1][count-1]=false;
                    field[2][0]=field[2][1]=field[2][2]=true;
                    f--;
                }
            }
            int j=2;
            while(!bad&&f!=0){
                if(f==1){
                    field[j-1][count-1]=false;
                    field[j][0]=field[j][1]=true;
                    f--;
                }
                for(int i=0;f!=0&&i<c;i++,f--)
                    field[j][i]=true;
                j++;
            }
            if(bad){
                out.println("Impossible");

            }
            else{
                for(int i=0;i<r;i++){
                    for(int k=0;k<c;k++)
                        if(field[i][k]){
                            if(i==0&&k==0)out.print('c');else out.print('.');
                        }else
                            out.print('*');
                    out.println();
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
