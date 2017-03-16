import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Hashtable;


public class GJ_QR_C {

    public static int recycle(int A, int n){
        String st = (new Integer(A)).toString();
        return Integer.parseInt(st.substring(n) + st.substring(0, n));
    }
    public static int solve(int A, int B){
        
        String st = (new Integer(A)).toString();
        String ed = (new Integer(B)).toString();
        int res = 0;
        
        int N = st.length();
        for (int i = A; i<B+1; i++) {
            String tmp = (new Integer(i)).toString();
            Hashtable ht = new Hashtable();
            for (int j = 1; j<N; j++) if(tmp.charAt(j)!='0' && tmp.charAt(j) >= tmp.charAt(0) && tmp.charAt(j) <= ed.charAt(0)){
                int rec = recycle(i, j);
                //System.out.println(i +" -> "+ rec);
                if (rec<=B && i<rec && !ht.containsKey(rec)){
                    res ++;
                    ht.put(rec, 1);
                    //System.out.println(i +"\t"+ rec);
                }
            }
        }
        return res;
    }
    

    public static void main(String[] args) throws NumberFormatException, IOException {
        java.io.BufferedReader stdin = new java.io.BufferedReader(new java.io.InputStreamReader(new FileInputStream("C-large.in")));
        java.io.BufferedWriter stdout = new java.io.BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-large.out")));
        int T = Integer.parseInt(stdin.readLine());
        //T = 3;
        for (int ii=0; ii<T; ii++){
            String str = stdin.readLine();
            String[] words = str.split(" ");
            int res = solve(Integer.parseInt(words[0]), Integer.parseInt(words[1]));
            stdout.write("Case #" + (1+ii) +": " + res+'\n');
        }
        stdout.close();
    }

}
