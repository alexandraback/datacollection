import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


public class Lawnmower {
    public static void main(String[] args) throws IOException {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("B-large.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("LargeB.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        Lawnmower solver = new Lawnmower();
        solver.solve(1, in, out);
        out.close();
    }
    public void solve(int testNumber, BufferedReader in, PrintWriter out) throws IOException {
        int t=Integer.parseInt(in.readLine());
        for(int i=0;i<t;i++){
            out.print("Case #"+(i+1)+": ");
            StringTokenizer st=new StringTokenizer(in.readLine());
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int grid[][]=new int[n][m];
            for(int j=0;j<n;j++){
                st=new StringTokenizer(in.readLine());
                for(int k=0;k<m;k++){
                    grid[j][k]=Integer.parseInt(st.nextToken());
                }
            }
            out.println(isPossible(grid)?"YES":"NO");

        }

    }

    public boolean isPossible(int grid[][]){
        int k=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(isGreater(grid,i,j))return false;
            }
        }
        return true;
    }

    public boolean isGreater(int g[][],int i,int j){
        //column
        boolean a=false;
        for (int k=0;k<g.length;k++){
            if(g[k][j]>g[i][j]){
                a=true;
                break;
            }
        }
        if(!a)return a;
        a=false;
        for(int k=0;k<g[0].length;k++){
            if(g[i][k]>g[i][j]){
                a=true;
                break;
            }
        }
        return a;
    }

}

