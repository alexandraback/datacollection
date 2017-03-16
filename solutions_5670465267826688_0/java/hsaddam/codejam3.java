
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class codejam3 {
    
    
    public static void main(String[] args) {
   
        String fileName = "C-small-attempt1.in";
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
        }
        
        
        catch(Exception ex) {}
        int L=0,X=0;
        for(int i=0;i<size;i++)
        {
            
            if(i%2 == 0)
            {
                String[] digitwords = array[i].split("\\D+");
                L = Integer.parseInt(digitwords[0]);
                X = Integer.parseInt(digitwords[1]);
                
               // System.out.println("L: " +L + " X: "+X);
            }else{
                
                //System.out.println("in temp X:"+X);
                String temp = "";
                int minus = 0;
                
                for(int j=0;j<X;j++)
                {
                    temp += array[i];
                }
                
                //System.out.println(temp);
                
                char arr[] = temp.toCharArray();
                int sizearr = temp.length();
                
                for(int x=1;x<sizearr;x++)
                {
                    if(arr[x-1] == 'i')
                    {
                        if(arr[x]== '1')
                        {
                            arr[x] = 'i';
                        }else if(arr[x]== 'i')
                        {
                            arr[x] = '1';
                            minus++;
                        }else if(arr[x]=='j')
                        {
                            arr[x]='k';
                        }else if(arr[x]=='k')
                        {
                            arr[x]='j';
                            minus++;
                        }
                    }
                    
                    if(arr[x-1] == 'j')
                    {
                        if(arr[x]== '1')
                        {
                            arr[x] = 'j';
                        }else if(arr[x]== 'i')
                        {
                            arr[x] = 'k';
                            minus++;
                        }else if(arr[x]=='j')
                        {
                            arr[x]='1';
                            minus++;
                        }else if(arr[x]=='k')
                        {
                            arr[x]='i';
                        }
                    }
                    
                    
                    if(arr[x-1] == 'k')
                    {
                        if(arr[x]== '1')
                        {
                            arr[x] = 'k';
                        }else if(arr[x]== 'i')
                        {
                            arr[x] = 'j';
                        }else if(arr[x]=='j')
                        {
                            arr[x]='i';
                            minus++;
                        }else if(arr[x]=='k')
                        {
                            arr[x]='1';
                            minus++;
                        }
                    }
                    
                    if(arr[x-1] == '1')
                    {
                        if(arr[x]== '1')
                        {
                            arr[x] = '1';
                        }else if(arr[x]== 'i')
                        {
                            arr[x] = 'i';
                        }else if(arr[x]=='j')
                        {
                            arr[x]='j';
                        }else if(arr[x]=='k')
                        {
                            arr[x]='k';
                        }
                    }
                    
                    
                }
                
                int final1 = Integer.parseInt((int)arr[sizearr-1]+"");
                
               // System.out.println("final :"+final1+" minus :"+minus);
                
                
                if(final1==49 && (minus%2)!=0)
                {
                    String temp1 = "Case #"+ (i+1)/2 +": YES";
                    try{write(temp1);
                }catch(Exception e)
                {
                    
                }
                }else{
                    String temp1 = "Case #"+ (i+1)/2 +": NO";
                    try{write(temp1);
                }catch(Exception e)
                {
                    
                }
                }
                
            }
            
        }
        
}
    
        static void write(String data) throws IOException
    {
        File file = new File("output.txt");
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
