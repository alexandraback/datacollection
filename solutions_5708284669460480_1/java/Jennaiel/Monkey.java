/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package monkey;

/**
 *
 * @author Ravi
 */
import java.io.*;
public class Monkey {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            BufferedReader br = new BufferedReader(new FileReader("B-large(1).in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
            int keys[] = new int[26];            
            int word[] = new int[26];            
            String line = br.readLine();
            String parts[];
            int tests= Integer.parseInt(line);
            int no_keys,no_letters,no_tries,index,sequence,bananas;
            float prob,answer;
            char[] letters;            
            for(int i=1;i<=tests;i++){
                if(i!=1){
                    bw.write("\n");
                }
                for(int k=0;k<26;k++){
                word[k]=0;
                keys[k]=0;
                }
                prob=1.0f;
                line = br.readLine();
                parts=line.split("\\s+");
                no_keys= Integer.parseInt(parts[0]);
                no_letters = Integer.parseInt(parts[1]);
                no_tries= Integer.parseInt(parts[2]);
                line=br.readLine();
                letters = line.toCharArray();
                for(int j=0;j<no_keys;j++){
                    index = ((int)letters[j])-((int)'A');
                    keys[index]=keys[index]+1;
                }
                line=br.readLine();
                letters = line.toCharArray();
                for(int j=0;j<no_letters;j++){
                    index = ((int)letters[j])-((int)'A');
                    prob= prob*keys[index]/((float)no_keys); 
                   // System.out.println("In iteration prob index keys[index] nokeys are"+prob+" "+index+" "+keys[index]+" "+no_keys);
                }
                sequence=0;
                
                for(int j=1;j<no_letters && sequence==0;j++){                    
                    for(int k=0;k<no_letters-j;k++){
                        if(letters[k]!=letters[j+k]){
                            break;
                        }
                        if(j+k+1==no_letters){
                            sequence=k+1;
                        }
                    }
                }
                if(prob==0 || no_letters>no_tries ){
                    answer=0.0f;
                }
                else{
                    bananas = 1+(no_tries-no_letters)/(no_letters-sequence);
                    //System.out.println("bananas ="+bananas);
                    //System.out.println("sequence ="+sequence);
                   // System.out.println("prob="+prob);
                    prob = (no_tries-no_letters+1)*prob;
                    //System.out.println("final_prob="+prob);
                    answer = bananas-prob;
                    //System.out.println("answer="+answer);
                }
                bw.write("Case #"+i+": "+answer);
             }
            br.close();
            bw.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }
}
