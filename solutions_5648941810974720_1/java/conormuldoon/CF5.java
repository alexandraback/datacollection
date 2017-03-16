import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class CF5 {

    static BufferedReader br;
    public static void main(String[]args){
        br=new BufferedReader(new InputStreamReader(System.in));
        try{
        	String s0=readString();
        	String s1=readString();
        	int n=s0.length();
        	int n1=s1.length();
            br.close();
            int nml[]=new int[n+1];
            for(int i=1;i<=n;i++){
            	nml[i]=nml[i-1];
            	if(s0.charAt(n-i)=='1')nml[i]++;
            }
            
            int nmo[]=new int[n+1];
            for(int i=1;i<=n;i++){
            	nmo[i]=nmo[i-1];
            	if(s0.charAt(i-1)=='1')nmo[i]++;
            }
            long ttl=0;
            for(int i=0;i<n;i++){
            	int inc=Math.min(i+1, n1-n+1);
            	if(s1.charAt(i)=='1'){
            		ttl+=inc-nmo[inc];
            	}
            	else ttl+=nmo[inc];
            	
            }
            for(int i=n;i<n1;i++){
            	int inc=Math.min(n, n1-i);
            	if(s1.charAt(i)=='0'){
            		ttl+=nml[inc];
            	}else{
            		ttl+=inc-nml[inc];
            	}
            }
            System.out.println(ttl);
            
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    
    static public String readString() throws IOException{
        return br.readLine();
        
    }
    static public long readlong() throws IOException{
        return Long.parseLong(br.readLine());
    }
    
    static public int readInt() throws IOException{
        return Integer.parseInt(br.readLine());
    }
    
    static public int[] readIntArr() throws IOException{
        String[]str=br.readLine().split(" ");
        int arr[]=new int[str.length];
        for(int i=0;i<arr.length;i++)arr[i]=Integer.parseInt(str[i]);
        return arr;
    }
    
    static public double[] readDoubleArr() throws IOException{
        String[]str=br.readLine().split(" ");
        double arr[]=new double[str.length];
        for(int i=0;i<arr.length;i++)arr[i]=Double.parseDouble(str[i]);
        return arr;
    }
    static public long[] readLongArr() throws IOException{
        String[]str=br.readLine().split(" ");
        long arr[]=new long[str.length];
        for(int i=0;i<arr.length;i++)arr[i]=Long.parseLong(str[i]);
        return arr;
    }
    
    static public double readDouble() throws IOException{
        return Double.parseDouble(br.readLine());
    }
}