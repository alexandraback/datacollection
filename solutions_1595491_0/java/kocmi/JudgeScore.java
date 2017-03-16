package judgescore;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Kocmi
 */
public class JudgeScore {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;

            st = new StringTokenizer(br.readLine());
            int tests = Integer.parseInt(st.nextToken());
            int[] results = new int[tests]; //final result
            int dancers, surprises, limit;
            int[] scores;
            
            for (int i = 0; i < tests; i++) {
                st = new StringTokenizer(br.readLine());
                dancers = Integer.parseInt(st.nextToken());
                surprises = Integer.parseInt(st.nextToken());
                limit = Integer.parseInt(st.nextToken());
                scores = new int[dancers];
                
                for (int j = 0; j < dancers; j++) {
                    scores[j] = Integer.parseInt(st.nextToken());
                }
                
                results[i] = bestscore(scores, surprises, limit);
            }
            
            for (int i = 0; i < tests; i++) {
                System.out.println("Case #"+(i+1)+": "+results[i]);
            }
        } catch (Exception ex) {
        }
    }
    
    public static int bestscore(int[] scores,int surprises,int limit){
        int score = 0;
        int ifsur = 0;
        
        int root, rest;
        for (int i = 0; i < scores.length; i++) {
            root = scores[i]/3;
            rest = scores[i]%3;
            if(scores[i]==0){
                if(root>=limit){
                    score++;
                }
            }else if(rest==0){
                if(root>=limit){
                    score++;
                }else{
                    if((root+1)>=limit){
                        ifsur++;
                    }
                }
            }else if(rest==1){
                if((root+1)>=limit){
                    score++;
                }
            }else{
                if((root+1)>=limit){
                    score++;
                }else{
                    if((root+2)>=limit){
                        ifsur++;
                    }
                }
            }
        }
        
        if(ifsur<=surprises){
            return (score+ifsur);
        }else{
            return (score+surprises);
        }
    }
}
