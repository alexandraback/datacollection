import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.math.*;
import java.net.*;



public class Task{
    public static void main(String[] args) throws IOException{
        new Task().run();
    }
    
    StreamTokenizer in; 
    Scanner ins;
    PrintWriter out;

    int nextInt() throws IOException{
        in.nextToken();      
        return (int)in.nval;
    }
    
    long nextLong() throws IOException{
        in.nextToken();      
        return (long)in.nval;
    }
    
    double nextDouble() throws IOException{
        in.nextToken();      
        return in.nval;
    }
    
    char nextChar() throws IOException{
        in.nextToken();
        return (char)in.ttype;
    }
    
    String nextString() throws IOException{
        in.nextToken();
        return in.sval;
    }
    
    long gcdLight(long a, long b){
        a = Math.abs(a);
        b = Math.abs(b);
        while(a != 0 && b != 0){
            if(a > b)
                a %= b;
            else
                b %= a;
        }
        return a + b;
    }
    
    ForGCD gcd(int a,int b){
        ForGCD tmp = new ForGCD();
        if(a == 0){
            tmp.x = 0;
            tmp.y = 1;
            tmp.d = b;
        }else{
            ForGCD tmp1 = gcd(b%a, a);
            tmp.d = tmp1.d;
            tmp.y = tmp1.x;
            tmp.x = tmp1.y - tmp1.x*(b/a);
        }        
        return tmp;
    }         
    
   
    Set<Character> vowels = new HashSet<Character>(Arrays.asList('a' , 'e', 'i', 'o','u'));
    
    void run() throws IOException{        
        in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        ins = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try{
            if(System.getProperty("xDx")!=null){
                in = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
                ins = new Scanner(new FileReader("input.txt"));
                out = new PrintWriter(new FileWriter("output.txt"));
            }
        }catch(Exception e){
            
        }
        int t = nextInt();
        for(int i = 0; i < t; i++){
            String s = nextString();
            int n = nextInt();
            out.println(String.format("Case #%d: %d", i + 1, countSub(s,n)));
        }
        out.close();
    }   
    
    int countSub(String s, int n){
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j <= s.length(); j++){
                if(check(s.substring(i, j), n)){
                    res++;
                }
            }
        }
        return res;
    }

    private boolean check(String s, int n) {
        int cur = 0;
        for(int i = 0; i < s.length(); i++){
            if(vowels.contains(s.charAt(i))){
                cur = 0;
            }else{
                cur++;
                if(cur == n){
                    return true;
                }
            }
        }
        return false;
    }
   
    class ForGCD{
        int x,y,d;
    }

    class Boxes implements Comparable{
        public long k,a;
        public Boxes(long k, long a){
            this.k = k;
            this.a = a;
        }
        
        public int compareTo(Object obj){
            Boxes b = (Boxes) obj;
            if(k < b.k)                          
                return -1;
            else  
                if(k == b.k)
                    return 0;
                else
                    return 1;
        }        
    }
}