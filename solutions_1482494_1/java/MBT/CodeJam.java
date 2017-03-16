/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

public class CodeJam {

    public ReadWriteTextFile rw = new ReadWriteTextFile();
  public Level[] array = null;
      
  
  
    public static void main(String[] args) {
        CodeJam codeJam = new CodeJam();
        
        
        int sampleSize = codeJam.rw.readIntLine();


        for (int i = 0; i < sampleSize; i++) {
           int count =0;
           int attempt = 0;
           int numberOfLevels = codeJam.rw.readIntLine();
           codeJam.array = new Level[numberOfLevels];
           for(int j=0;j<numberOfLevels;j++)
           {
           codeJam.array[j] = new Level(codeJam.rw.readInt(),codeJam.rw.readInt());
           
           codeJam.rw.readLine();
           
           }
           boolean BreakCondition = false;
           int NumberOfLevelsAccomplished = 0;
           while(true)
           {
           boolean levelAccomplishedThisTime = false;
           
           if(NumberOfLevelsAccomplished == numberOfLevels)
           {
            codeJam.rw.writeNextLine(attempt);
            break;
           }
               
           for(int k=0;k<numberOfLevels;k++)
           {
                if( codeJam.array[k].accomplished == false && codeJam.array[k].bi <= count)
                {
                count++;
                if(codeJam.array[k].attempted == false)
                        count++;
                levelAccomplishedThisTime = true;   
                NumberOfLevelsAccomplished++;
                codeJam.array[k].accomplished = true;
                attempt++;
                }
           }
           if (levelAccomplishedThisTime == false)
           {
               int  current1Advantage = -1;
               
                        for(int k=0;k<numberOfLevels;k++)
                    {
                            if( codeJam.array[k].attempted == false && codeJam.array[k].accomplished == false && codeJam.array[k].ai <= count)
                            {
                             
                             if(current1Advantage == -1 || codeJam.array[k].bi > codeJam.array[current1Advantage].bi)
                             {
                                    current1Advantage = k;
                             }
                            }
                    }
                 if (current1Advantage != -1)
                 {
                        count++;
                        attempt++;
                        levelAccomplishedThisTime = true;
                        codeJam.array[current1Advantage].attempted = true;
                 }
           
           }
           if(levelAccomplishedThisTime == false)
           {
           codeJam.rw.writeNextLine("Too Bad");
            break;
               
           }
           
           
           
           }
                   
                
           
        }
        codeJam.rw.close();
    }
}
