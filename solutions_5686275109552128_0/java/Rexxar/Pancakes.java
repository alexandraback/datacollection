import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Pancakes {
    
    public static void main(String[] args) {
        
        String fileName = "B-small-attempt0.in";
        String line = null;
        String testCases;
        String array[] = new String[220];
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
        }catch(Exception ex) {}
        
        
        int D;
        for(int i=0;i<size;i++)
        {
            if(i%2 == 0)
            {
                D = Integer.parseInt(array[i]);
            }
            else
            {
                String[] digitwords = array[i].split("\\D+");
                int[] P = new int[digitwords.length];
                    for (int j = 0; j < P.length; j++) {
                            P[j] = Integer.parseInt(digitwords[j]);
                    }
                    
                    int tempMax = max(P);
                    int temp2 = 2;
                    
                    while(temp2<tempMax)
                    {
                        int sum = 0;
                        
                        for(int k=0;k<P.length;k++)
                        {
                            sum += ((P[k]-1)/temp2);
                        }
                        sum = sum+temp2;
                        
                       int temp3 = min(tempMax,sum);
                       
                       tempMax = temp3;
                        
                        temp2 += 1;
                    }
                    
                    String res = "Case #"+ ((i+1)/2) +": "+tempMax;
                     try{write(res);
                }catch(Exception e)
                {
                    
                }
                    
            }
        }
        
        
        
    }
    
    static int max(int a[])
    {
        int max=a[0];
        
        for(int i=1;i<a.length;i++)
        {
            if(max<a[i])
            {
                max = a[i];
            }
        }
        
        return max;
    }
    
    static int min(int a, int b)
    {
       if(a>b)
       {
           return b;
       }else{
           return a;
       }
    }
    
        static void write(String data) throws IOException
    {
        File file = new File("B-small-attempt0.txt");
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
