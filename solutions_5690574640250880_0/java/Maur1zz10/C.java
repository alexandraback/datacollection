import java.io.*;
import java.util.*;

public class C {
    static final String filename = "C";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        C solver = new C();
        solver.solve(s, w);
        w.close();
        s.close();
    }
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            R=s.nextInt();
            C=s.nextInt();
            M=s.nextInt();
            String ans=solve();
            String out="Case #" + t + ":\n";
            out+=ans;
            w.write(out);
            System.out.print(out);
        }
    }
    int R,C,M;
    char[][]B;
    String solve(){
        B=new char[R][C];
        r=0;
        c=0;
        m=M;
        init();
        if(m>0)
            if(R-r>=C-c)fill(1,0);
            else fill(0,1);
        int TBR=0;
        for(int i=r;i<R;i++)for(int j=c;j<C;j++)if(B[i][j]=='.')TBR++;
        W=new boolean[R][C];
        if(m>0){
            for(int i=r;i<R;i++)for(int j=c;j<C;j++)for(int p=r;p<R;p++)for(int q=c;q<C;q++)if(i!=p||j!=q)if(B[i][j]=='.'&&B[p][q]=='.'){
                B[i][j]='*';
                B[p][q]='c';
                if(check(p,q,TBR-2))return boardAsString();
                B[i][j]='.';
                B[p][q]='.';
            }
        }
        else
            for(int p=r;p<R;p++)for(int q=c;q<C;q++)if(B[p][q]=='.'){
                B[p][q]='c';
                if(check(p,q,TBR-1))return boardAsString();
                B[p][q]='.';
            }

        return "Impossible\n";
    }

    int r;
    int c;
    int m;
    int[]dx={-1,0,1,-1,1,-1,0,1};
    int[]dy={1,1,1,0,0,-1,-1,-1};
    boolean[][]W;
    private boolean check(int a, int b, int TBR) {
        if(TBR==0)return true;
        int cnt=0;
        for (boolean[] e:W)Arrays.fill(e, false);
        Queue<Integer>q=new LinkedList<Integer>();
        q.offer(a);
        q.offer(b);
        while(!q.isEmpty()){
            int x=q.poll();
            int y=q.poll();
            if(zero(x,y))
                for(int i=0;i<dx.length;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0||nx>=B.length||ny<0||ny>=B[0].length)continue;
                    if(W[nx][ny]||B[nx][ny]!='.')continue;
                    cnt++;
                    W[nx][ny]=true;
                    q.offer(nx);
                    q.offer(ny);
                }
        }
        return cnt==TBR;
    }

    boolean zero(int p, int q){
        for(int i=0;i<dx.length;i++){
            int np=p+dx[i];
            int nq=q+dy[i];
            if(np<0||np>=B.length||nq<0||nq>=B[0].length)continue;
            if(B[np][nq]=='*')
                return false;
        }
        return true;
    }

    void fill(int x,int y){
        int cnt=0;
        int i=r;
        int j=c;
        while(cnt<=m-2){
            B[i][j]='*';
            i+=x;
            j+=y;
            m--;
        }
    }
    void init() {
        while(m>0&&(R-r<=m||C-c<=m)){
            if(R-r<=m&&C-c<=m)
                if(C-c<=R-r){
                    m-=C-c;
                    r++;
                }
                else{
                    m-=R-r;
                    c++;
                }
            else
                if(C-c<=m){
                    m-=C-c;
                    r++;
                }
                else{
                    m-=R-r;
                    c++;
                }
        }
        for(int i=0;i<R;i++)for(int j=0;j<C;j++)B[i][j]='*';
        for(int i=r;i<R;i++)for(int j=c;j<C;j++)B[i][j]='.';
    }
    String boardAsString(){
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                sb.append(B[i][j]);
            sb.append("\n");
        }
        return sb.toString();
    }
}