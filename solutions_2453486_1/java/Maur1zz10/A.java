import java.io.*;
import java.util.*;


public class A {
    static final String filename = "A";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        A solver = new A();
        solver.solve(s, w);
        w.close();
    }

    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        s.nextLine();
        for (int t = 1; t <= T; t++) {
            boolean b=true;
            char[][]B=new char[4][4];
            for(int i=0;i<4;i++){
                String ln=s.nextLine();
                for(int j=0;j<4;j++){
                    B[i][j]=ln.charAt(j);
                    if(B[i][j]=='.')
                        b=false;
                }
            }
            s.nextLine();
            String ans=solve(B,b);

            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";

            w.write(out);
            System.out.print(out);
        }

    }
    int[]dx={-1,-1,-1, 0,0, 1,1,1};
    int[]dy={-1, 0, 1,-1,1,-1,0,1};
    String solve(char[][]B,boolean b){
        if(check('X',B))
            return "X won";
        if(check('O',B))
            return "O won";
        if(b)
            return "Draw";
        return "Game has not completed";
    }

    boolean check(char c,char[][]B){
        for(int i=0;i<B.length;i++){
            for(int j=0;j<B[i].length;j++){
                for(int k=0;k<dx.length;k++){
                    int cnt=0;
                    int x=i,y=j;
                    for(int t=1;t<=4;t++){
                        if(x>=0&&x<4&&y>=0&&y<4
                                &&(B[x][y]=='T'||B[x][y]==c)){
                            cnt++;
                            x+=dx[k];
                            y+=dy[k];
                        }
                    }
                    if(cnt==4)
                        return true;
                }
            }
        }
        return false;
    }
}