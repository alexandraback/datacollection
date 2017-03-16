import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class Jump {

    private static String inputFile = "/Users/Abhishek/input1.txt";
    private static String outputFile = "/Users/Abhishek/output1.txt";
    public static void main(String[] arg) throws Exception
    {
        BufferedReader reader = new BufferedReader(new FileReader(new File(inputFile)));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File(outputFile)));
        int testCaseCount = Integer.parseInt(reader.readLine());
        
        for(int testCase=1;testCase<=testCaseCount;testCase++)
        {
            String entries[] = reader.readLine().split(" ");
            int x = Integer.parseInt(entries[0]);
            int y = Integer.parseInt(entries[1]);
            String moves = findMoves(x,y);
            writer.write("Case #"+testCase+": "+moves+"\n");
            //System.out.println("Case #"+testCase+": "+count+"\n");
        }
        
        writer.close();
        reader.close();
    }
    public static String findMoves(int x,int y)
    {
        int curX=0;
        int curY=0;
        int count=1;
        StringBuffer moves = new StringBuffer();
        
        char xDir = 'E';
        char nXDir = 'W';
        char yDir = 'N';
        char nYDir = 'S';
        
        if(x<0)
        {
            xDir = 'W';
            nXDir = 'E';
            x=x*-1;
        }
        
        if(y<0)
        {
            yDir = 'S';
            nYDir = 'N';
            y=y*-1;
        }
        
        
        
        while(true)
        {
                if(curX+count<=x)
                {
                    moves.append(xDir);
                    curX=curX+count;
                }
                else if(curY+count<=y)
                {
                    moves.append(yDir);
                    curY=curY+count;
                }
                else if(curX!=x)
                {
                    moves.append(nXDir+""+xDir);
                    curX++;
                    count++;
                }
                else if(curY!=y)
                {
                    moves.append(nYDir+""+yDir);
                    curY++;
                    count++;
                }
                else
                {
                    break;
                }
                
                count++;
        }
        
        if(moves.length()>=500)
        {
            System.out.println("problem with "+x+" "+y+" "+moves);
        }
        return moves.toString();
    }
    
}
