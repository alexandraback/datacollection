import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

    class Pair{
        int x,y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

    int[] color;
    int[] next;
    int n;
    ArrayList<Integer>[] g;

    ArrayList<Integer> dfs(int v){
        ArrayList<Integer> result=null;
        for(Integer x:g[v]){
            ArrayList<Integer> cur=dfs(x);
            if(result==null||result.size()<cur.size())result=cur;
        }
        if(result==null)result=new ArrayList<Integer>();
        result.add(v);
        return result;
    }


    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            n=nextInt();
            next=new int[n];
            color=new int[n];
            for(int i=0;i<n;i++)next[i]=nextInt()-1;
            g=new ArrayList[n];

            for(int i=0;i<n;i++)g[i]=new ArrayList<Integer>();
            for(int i=0;i<n;i++){
                g[next[i]].add(i);
            }
            int curC=1;
            int bestCycle=-1;
            int bestCycleL=-1;
            for(int i=0;i<n;i++)
                if(color[i]==0){
                    int v=i;
                    while(color[v]==0){
                        color[v]=curC;
                        v=next[v];
                    }
                    if(color[v]==curC){
                        int start=v;
                        int l=0;
                        do{
                            v=next[v];
                            l++;
                        }while(v!=start);
                        if(l>bestCycleL){
                            bestCycle=v;
                            bestCycleL=l;
                        }
                    }
                    curC++;
                }
            ArrayList<Pair> pairs=new ArrayList<Pair>();
            for(int i=0;i<n;i++)if(next[i]>i&&next[next[i]]==i)pairs.add(new Pair(i,next[i]));
            ArrayList<Integer> res=new ArrayList<Integer>();
            for(Pair pair:pairs){
                ArrayList<Integer> first=new ArrayList<Integer>();
                for(Integer x:g[pair.x])
                    if(x!=pair.y){
                        ArrayList<Integer> cur=dfs(x);
                        if(cur.size()>first.size())first=cur;
                    }
                ArrayList<Integer> second=new ArrayList<Integer>();
                for(Integer x:g[pair.y])
                    if(x!=pair.x){
                        ArrayList<Integer> cur=dfs(x);
                        if(cur.size()>second.size())second=cur;
                    }
                res.addAll(first);
                res.add(pair.x);
                res.add(pair.y);
                Collections.reverse(second);
                res.addAll(second);
            }
            if(res.size()<bestCycleL){
                res=new ArrayList<Integer>();
                int start=bestCycle;
                int v=start;
                do{
                    res.add(v);
                    v=next[v];
                }while (v!=start);
            }
            out.printf("Case #%d: %d\n",testCase+1,res.size());

        }
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    void run() throws IOException {
//        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
//        out = new PrintWriter(new OutputStreamWriter(System.out));
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
