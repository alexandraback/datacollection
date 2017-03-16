import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;

public class A {
    static String in = "src/in";
    static String out = "src/out";
    
    static char[] name;
    static int n;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File(in));
        BufferedWriter writer = new BufferedWriter(new FileWriter(out));
        int numLines = sc.nextInt();        
        for(int x = 1; x <= numLines; x++){
            name = sc.next().toCharArray();
            n = sc.nextInt();
            
            if(n==0){
                int answer = n*(n+1)/2;
                writer.write("Case #" + x + ": " + answer);
                writer.newLine();
                continue;
            }
            
            int nextN = 0;
            nextN = nextLeft(nextN);
            System.out.println("case " + x + ": nextN = " + nextN);
            int countFrom = 0;
            long count = 0;
            
            while(countFrom < name.length && nextN < name.length){
                count+= (nextN - countFrom + 1) * (name.length - nextN - n + 1);
                countFrom = nextN + 1;
                nextN = nextLeft(nextN + 1);
            }
            
            
            
            writer.write("Case #" + x + ": " + count);
            writer.newLine();
        }
        sc.close();
        writer.close();
    }
    
    static int nextLeft(int given){
        int count = 0;
        while(count < n && given < name.length){
            if(name[given] == 'a' || name[given] == 'e' || name[given] == 'i' || name[given] == 'o' || name[given] == 'u'){
                count = 0;
            } else {
                count++;
            }
            given++;
        }
        if(count == n) return given - n;
        return given;
    }
    
    
    
    
    static String generate(){
        String answer = "";
        return answer;
    }
}