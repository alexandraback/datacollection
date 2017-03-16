import java.io.*;
import java.util.*;

public class LessMoneyMoreProblems{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        for(int ca=1; ca<=test; ca++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c, d, v;
            c = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            //HashSet<Integer> val = new HashSet<Integer>();
            //for(int i=1; i<=v; i++)val.add(i);
            ArrayList<Integer> den = new ArrayList<Integer>();
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<d; i++){
                den.add(Integer.parseInt(st.nextToken()));
            }
            int added = 0;
            int max = c;
            int currInd = 0;
            if(den.get(0) != 1){
                added++;
            }else{
                currInd++;
            }
            while (max < v){
                if( currInd >= den.size() || den.get(currInd) > max+1){
                    added++;
                    max += c* (max +1);
                }else{
                    max += den.get(currInd++) * c;
                }
            }
            System.out.println("Case #"+ca+": "+added);
        }
    }
}