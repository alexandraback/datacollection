import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;


public class GJ_QR_B {

    public static int solve(int N, int S, int p, int[] t){
        int[][] s = new int[31][2];
        for (int i=0; i<31; i++){
            if(i%3 == 0){
                if (3*p <= i) s[i][0] = 1;
                if ( (p>=2 && 3*(p-1) == i) || 3*(p-1) < i) s[i][1] = 1;
            }
            if(i%3 == 1){
                if ( (p>=1 && 3*p-2 == i) || 3*p-2 < i) s[i][0] = 1;
                if ( (p>=2 && 3*p-2 == i) || 3*p-2 < i) s[i][1] = 1;
            }
            if(i%3 == 2){
                if ( (p>=1 && 3*p-1 == i) || 3*p-1 < i) s[i][0] = 1;
                if ( (p>=2 && 3*p-4 == i) || 3*p-4 < i) s[i][1] = 1;
            }
            //System.out.println(i+":"+s[i][0]+"+"+s[i][1]);
        }
        ArrayList<Integer> a01 = new ArrayList<Integer>();
        ArrayList<Integer> a11 = new ArrayList<Integer>();
        ArrayList<Integer> a10 = new ArrayList<Integer>();
        ArrayList<Integer> a00 = new ArrayList<Integer>();
        for (int i=0; i<t.length; i++){
            if (s[t[i]][0] == 1 && s[t[i]][1] == 0)
                a10.add(i);
            if (s[t[i]][0] == 0 && s[t[i]][1] == 1)
                a01.add(i);
            if (s[t[i]][0] == 1 && s[t[i]][1] == 1)
                a11.add(i);
            if (s[t[i]][0] == 0 && s[t[i]][1] == 0)
                a00.add(i);
            /*
            if (s[t[i]][0] == 1) 
                System.out.println("  "+t[i]+":"+p+":");
            if (s[t[i]][1] == 1) 
                System.out.println("  "+t[i]+":"+p+":(*)");
                */
        }
        int res = a11.size();
        if (S <= a01.size())
            res += S + a10.size();
        else if (S <= a01.size() + a11.size())
            res += a01.size() + a10.size();
        else 
            res += a01.size()+ a10.size() ;
            
        System.out.println("N="+N+", S="+S+" : (a01)"+a01.size()+" : (a11)"+a11.size()+" : (a10)"+a10.size()+" : (a00)"+a00.size() + " ==> "+ res);
            
        return res;
    }
    

    public static void main(String[] args) throws NumberFormatException, IOException {
        java.io.BufferedReader stdin = new java.io.BufferedReader(new java.io.InputStreamReader(new FileInputStream("B-small-attempt2.in")));
        java.io.BufferedWriter stdout = new java.io.BufferedWriter(new OutputStreamWriter(new FileOutputStream("B-small-attempt2.out")));
        int T = Integer.parseInt(stdin.readLine());
        //T = 1;
        for (int ii=0; ii<T; ii++){
            String str = stdin.readLine();
            String[] words = str.split(" ");
            int N = Integer.parseInt(words[0]);
            int[] in = new int[N];
            for (int j = 0; j<N; j++)
                in[j] = Integer.parseInt(words[3+j]);
            
            System.out.print("Case #" + (1+ii) +" ");
            int res = solve(N, Integer.parseInt(words[1]), Integer.parseInt(words[2]), in);

            stdout.write("Case #" + (1+ii)+": " +res+'\n');
        }
        stdout.close();
    }

}
