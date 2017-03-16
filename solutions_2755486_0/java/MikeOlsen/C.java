import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;

public class C {
    static String in = "src/in";
    static String out = "src/out";
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File(in));
        BufferedWriter writer = new BufferedWriter(new FileWriter(out));
        int numLines = sc.nextInt();        
        for(int x = 1; x <= numLines; x++){
            int numTribes = sc.nextInt();
            int[] d = new int[numTribes];
            int[] n = new int[numTribes];
            int[] w = new int[numTribes];
            int[] e = new int[numTribes];
            int[] s = new int[numTribes];
            int[] deltaD = new int[numTribes];
            int[] deltaP = new int[numTribes];
            int[] deltaS = new int[numTribes];
            
            for(int y = 0; y < numTribes; y++){
                d[y] = sc.nextInt();
                n[y] = sc.nextInt();
                w[y] = sc.nextInt() + 200;
                e[y] = sc.nextInt() + 200;
                s[y] = sc.nextInt();
                deltaD[y] = sc.nextInt();
                deltaP[y] = sc.nextInt();
                deltaS[y] = sc.nextInt();
            }
            
            int[] wall = new int[401];
            int answer = 0;
            int totalAttacks = 0;
            int numAttacks = 0;
            boolean[] attacking = new boolean[numTribes];
            int currentDay = 0;
            
            for(int y = 0; y < numTribes; y++){
                totalAttacks += n[y];
            }
            
            while(numAttacks != totalAttacks){
                Arrays.fill(attacking, false);
                
                //find min value in d, make bool true for all attacking tribes
                
                int minD = -1;
                for(int y = 0; y < numTribes; y++){
                    if(d[y] < minD && n[y] > 0) minD = d[y];
                    if(minD == -1 && n[y] >0) minD = d[y];
                }
                for(int y = 0; y < numTribes; y++){
                    if(d[y] == minD && n[y] > 0) attacking[y] = true;
                }
                
                // check wall for each attack
                
                
                for(int y = 0; y < numTribes; y++){
                    if(attacking[y] == false) continue;
                    for(int z = w[y]; z <= e[y]; z++){
                        System.out.println(z);
                        if(wall[z] < s[y]){
                            answer++;
                            break;
                        }
                    }
                }
                System.out.println(answer);
                //strengthen wall, increment everything
                
                for(int y = 0; y < numTribes; y++){
                    if(attacking[y] == false) continue;
                    
                    for(int z = w[y]; z <= e[y]; z++){
                        if(wall[z] < s[y]){
                            wall[z] = s[y];
                        }
                    }
                    
                    numAttacks++;
                    d[y] += deltaD[y];
                    s[y] += deltaS[y];
                    w[y] += deltaP[y];
                    e[y] += deltaP[y];
                    n[y] --;
                
                }
                
                
            }
            
            
            
            
            
            writer.write("Case #" + x + ": " + answer);
            writer.newLine();
        }
        sc.close();
        writer.close();
    }
    
    static String generate(){
        String answer = "";
        return answer;
    }
}