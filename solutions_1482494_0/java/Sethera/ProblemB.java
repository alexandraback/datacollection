import java.io.*;
import java.util.*;

/**
 *
 * @author Sethera
 */
public class ProblemB {
    
    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {

            String filename = "B-small-attempt2";

            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));
            //bw = new BufferedWriter(new OutputStreamWriter(System.out));

            ProblemB prob = new ProblemB();
            prob.solveFile();

        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }
    

    public void solveFile() throws Exception {
        int caseCount = Integer.parseInt(br.readLine());

        for (int caseNumber = 0; caseNumber < caseCount; caseNumber++) {
            int levels = Integer.parseInt(br.readLine());
            
            Level[] levelObjs = new Level[levels];
            for(int i = 0; i<levels; i++){
                String[] lineParts = br.readLine().split(" ");
                Level l = new Level();
                l.a = Integer.parseInt(lineParts[0]);
                l.b = Integer.parseInt(lineParts[1]);
                levelObjs[i] = l;
            }

            solveCase(caseNumber + 1, levelObjs);
        }
    }

    public void solveCase(int caseNumber, Level[] levelObjs) throws Exception {
        int stars = 0;  
        int levelsPlayed = 0;
        
        int levels = levelObjs.length;
        
        boolean foundOneThisPass = false;
        do{
            foundOneThisPass = false;
            
            for(int i = 0; i<levels; i++){
                if(levelObjs[i].starsEarned == 0 && stars >= levelObjs[i].b){
                    levelsPlayed++;
                    stars+=2;
                    levelObjs[i].starsEarned = 2;
                    //levelObjs[i].playedForTwoStars = true;
                    foundOneThisPass = true;
                    i = levels;
                }
            }
            
            if(!foundOneThisPass){
                for(int i = 0; i<levels; i++){
                    if(levelObjs[i].starsEarned == 1 && stars >= levelObjs[i].b){
                        levelsPlayed++;
                        stars+=1;
                        levelObjs[i].starsEarned = 2;
                        //levelObjs[i].playedForOneStar = true;
                        foundOneThisPass = true;
                        i = levels;
                    }else if(levelObjs[i].starsEarned == 0 && stars >= levelObjs[i].a){
                        levelsPlayed++;
                        stars+=1;
                        levelObjs[i].starsEarned = 1;
                        //levelObjs[i].playedForTwoStars = true;
                        foundOneThisPass = true;
                        i = levels;
                    }
                }
            }
            
        }while(foundOneThisPass);

   
        boolean found = true;
        for(int i =0; i<levels; i++){
            if(levelObjs[i].starsEarned != 2){
                found = false;
                break;
            }
        }
        
        
        if(found){
            bw.write("Case #" + caseNumber + ": " + levelsPlayed + "\r\n");
        }else{
            bw.write("Case #" + caseNumber + ": Too Bad\r\n");            
        }
        bw.flush();
    }
    
    
    public class Level{     
        public int a = 0;
        public int b = 0;
        public int starsEarned = 0;
        public boolean playedForOneStar = false;
        public boolean playedForTwoStars = false;
    }
    
}
