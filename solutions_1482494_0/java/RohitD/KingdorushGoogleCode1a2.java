import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class KingdorushGoogleCode1a2
{

    public static void main(String[] args) throws FileNotFoundException
    {
        
        Scanner sc = new Scanner(new File("KingdorushGoogleCode1a2SMALL.txt"));
        
        int numTests = sc.nextInt();
        
        for (int i = 0; i < numTests; i++)
        {
            int numLvl = sc.nextInt();
            int[] req1 = new int[numLvl];
            int[] req2 = new int[numLvl];
            
            for (int j = 0; j < numLvl; j++)
            {
                req1[j] = sc.nextInt();
                req2[j] = sc.nextInt();
            }
            
            int goal = 2*numLvl;
            int[] done= new int[numLvl];
            int numSt = 0;
            int steps = 0;
            while(true)
            {
                steps++;
                boolean noneFound = false;
                // Find the level that gives max coin gains.
                // Look for +2, then +1

                int foundLvl = -1;
                // look for 0->2
                for (int k = 0; k < numLvl; k++)
                {
                    if (numSt < req2[k]) // not enough stars
                        continue;
                    
                    if (done[k] > 0) // done at least one
                        continue;
                        
                    foundLvl = k;
                    break;
                }
                
                if (foundLvl >= 0)
                {
                    done[foundLvl] = 2;
                    numSt += 2;
                }
                else
                {
                    // look for 1->2
                    for (int k = 0; k < numLvl; k++)
                    {
                        if (numSt < req2[k]) // not enough stars
                            continue;
                        
                        if (done[k] > 1) // Completely done
                            continue;
                            
                        foundLvl = k;
                        break;
                    }
                    if (foundLvl >= 0)
                    {
                        done[foundLvl] = 2;
                        numSt += 1;
                    }
                    else
                    {
                        // look for 0->1
                        for (int k = 0; k < numLvl; k++)
                        {
                            if (numSt < req1[k]) // not enough stars
                                continue;
                            
                            if (done[k] > 0) // done at least one
                                continue;
                                
                            foundLvl = k;
                            break;
                        }
                        
                        if (foundLvl >= 0)
                        {
                            done[foundLvl] = 1;
                            numSt += 1;
                        }
                        else
                            noneFound = true;
                    }
                }// look for 0->2
                
                if (noneFound)
                {
                    System.out.println("Case #"+(i+1)+": Too Bad");
                    break;
                }
                
                if (numSt >= goal)
                {
                    System.out.println("Case #"+(i+1)+": "+steps);
                    break;
                }
                
            }
        }
    }
}
