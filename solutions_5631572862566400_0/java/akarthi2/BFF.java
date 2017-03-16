import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BFF {
    private static final String CASE = "Case #";
public static void main(String[] args) throws Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out), true);

    int tcs = Integer.parseInt(br.readLine());
    
    for(int t=1;t<=tcs;++t){
        String opFormat = CASE + t + ": ";
        int N = Integer.parseInt(br.readLine());
        int[] favs = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            favs[i] = Integer.parseInt(st.nextToken())-1;
        }
        int maxSize = 2;
        for(int i=0;i<N;++i){
            HashSet<Integer> setMembers = new HashSet<Integer>();
            ArrayList<Integer> path = new ArrayList<Integer>();
            int currentMember = i;
            while(setMembers.add(currentMember)){
                path.add(currentMember);
                currentMember = favs[currentMember];
            }
            
            //case 1
            if(favs[path.get(path.size()-1)]==path.get(0)){
                //case 3 can't go inside case 1
                maxSize = max(maxSize, path.size());
            }else //case 2
                if(favs[path.get(path.size()-1)]==path.get(path.size()-2)){
                    {
                        //case 3
                        int lastMember = path.get(path.size()-1);
                        for(int j=0;j<N;++j){
                            if(favs[j]==lastMember && !setMembers.contains(j)){
                                setMembers.add(j);
                                path.add(j);
                                maxSize = max(maxSize, path.size());
                                break;
                            }
                        }
                        
                    }
                    maxSize = max(maxSize, path.size());    
                }
                
            
        }
        
        pw.println(opFormat+""+maxSize);
    }

    pw.flush();
    pw.close();
    br.close();
}
private static int max(int a, int b){
    return (a>b)?(a):(b);
}
}

