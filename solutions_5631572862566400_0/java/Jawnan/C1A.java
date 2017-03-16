import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by Nejc on 16.04.2016.
 */
public class C1A {
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            int N = Integer.parseInt(br.readLine());
            String[] split = br.readLine().split(" ");
            int[] bff = new int[N];
            
            for(int i = 0; i < N; i++){
                bff[i] = Integer.parseInt(split[i])-1;
            }
            int max = 1;
            for(int i = 0; i < N; i++){
                ArrayList<Integer> current = new ArrayList<>();
                int additional = 0;
                int cur = i;
                current.add(i);
                boolean space = false;
                boolean check = true;
                while(true){
                    if(!current.contains(bff[cur])){
                        current.add(bff[cur]);
                    }
                    else{
                        if(current.get(current.size()-2).equals(bff[cur])){
                            //System.out.println(i +" ... "+ Arrays.toString(current.toArray()));
                            for(int j = 0; j < N; j++){
                                if(current.contains(j))continue;
                                ArrayList<Integer> next = new ArrayList<>();
                                next.add(j);
                                int c = j;
                                boolean chck = true;
                                while(true){
                                    if(current.get(current.size()-1).equals(bff[c])){
                                        break;
                                    }
                                    if(current.contains(bff[c]) || next.contains(bff[c])){
                                        chck = false;
                                        break;
                                    }
                                    next.add(bff[c]);
                                    c = bff[c];
                                }
                                if(chck){
                                    additional = Math.max(additional, next.size());
                                    //System.out.println(i +" ... "+Arrays.toString(current.toArray())+ Arrays.toString(next.toArray()) + " " + additional);
                                }
                            }
                            space=true;
                            //if(additional==0)System.out.println(i +" ... "+ Arrays.toString(current.toArray()));
                            break;
                        }
                        else if(current.get(0).equals(bff[cur])){
                            //System.out.println(i +" ... "+ Arrays.toString(current.toArray())+"-");
                            break;
                        }
                        else{
                            //System.out.println(i +" ... "+ Arrays.toString(current.toArray()));
                            check = false;
                            break;
                        }
                    }
                    cur = bff[cur];
                }
                //System.out.println(current.size());
                if(check){
                    int count = 0;
                    if(space){
                        for(int j = 0; j < N; j++){
                            if(bff[bff[j]] == j && !current.contains(j))count++;
                        }
                    }
                    max = Math.max(max, current.size() + additional + count);
                }
            }
    
            int count = 0;
            for(int j = 0; j < N; j++){
                if(bff[bff[j]] == j)count++;
            }
            max = Math.max(max, count);
            System.out.println("CASE #" + t + ": " + max);
        }
    }
}
