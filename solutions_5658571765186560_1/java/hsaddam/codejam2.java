
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class codejam2 {
    
    
    
    public static void main(String[] args) {
   
        String fileName = "D-small-attempt0.in";
        String line = null;
        String testCases;
        String array[] = new String[100];
        int a[] = new int[2000];
        int size = 0;
        boolean flag = false;
        try{
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            testCases = bufferedReader.readLine();     
            while((line = bufferedReader.readLine()) != null) {
                array[size] = line;
                size++;
            }
            bufferedReader.close();
        }
        catch(Exception ex) {}
        
        
        for(int i=0 ; i<size; i++)
        {
            
            
                   String[] digitwords = array[i].split("\\D+");
int[] result = new int[digitwords.length];
/*for (int j = 0; j < result.length; j++) {
    result[i] = Integer.parseInt(digitwords[i]);
  
      }
*/

int X = Integer.parseInt(digitwords[0]);
int R = Integer.parseInt(digitwords[1]);
int C = Integer.parseInt(digitwords[2]);
            
           // System.out.println("X:" + X);
            //System.out.println("R: "+R);
            //System.out.println("C: "+C);

int min;

if(R>C)
{
    min = C;
}else{
    min = R;
}


            boolean ans = true;

            if(X>=7)
            {
                ans = false;
            }else if(X> R && X> C)
            {
                ans = false;
            }else if ((R * C % X) != 0)
            {
                ans = false; 
            }else if(((X+1)/2)>min){
            ans = false;
            }
            else if(X == 1 || X == 2 || X == 3)
            {
                ans = true;
            }else if (X == 4)
            {
                if(R>C)
                {
                    if(C>2)
                    {
                        ans = true;
                    }else{
                        ans=false;
                    }
                }else{
                    if(R>2)
                    {
                        ans = true;
                    }else{
                        ans=false;
                    }
                }
                
            }else if (X == 5)
            {
                boolean temp,temp2;
                
                if(R>C)
                {
                    if(C==3)
                    {
                        temp = true;
                    }else{
                        temp=false;
                    }
                }else{
                    if(R==3)
                    {
                        temp = true;
                    }else{
                        temp=false;
                    }
                }
                
                
                if(R>C)
                {
                    if(R==5)
                    {
                        temp2 = true;
                    }else{
                        temp2=false;
                    }
                }else{
                    if(C==5)
                    {
                        temp2 = true;
                    }else{
                        temp2=false;
                    }
                }
                
                if(temp && temp2)
                {
                    ans = false;
                }else{
                    ans = true;
                }
                
                
            }else if (X == 6){
                
                
                
                if(R>C)
                {
                    if(C>3)
                    {
                        ans = true;
                    }else{
                        ans=false;
                    }
                }else{
                    if(R>3)
                    {
                        ans = true;
                    }else{
                        ans=false;
                    }
                }
                
                
            }
            
            
     
            
            if(ans)
            {
                String temp1 = "Case #"+ (i+1) +": GABRIEL";
                try{write(temp1);
                }catch(Exception e)
                {
                    
                }
            }else{
                String temp1 = "Case #"+ (i+1) +": RICHARD";
                try{write(temp1);
                }catch(Exception e)
                {
                    
                }
            }

        }      
}
    
    static void write(String data) throws IOException
    {
        File file = new File("D-small-attempt0.txt");
        if (!file.exists()) {
				file.createNewFile();
			}
        FileWriter fileWriter = new FileWriter(file,true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        PrintWriter out = new PrintWriter(bufferedWriter);
        out.println(data);
        bufferedWriter.close();
    }
}
