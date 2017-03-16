import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class CF0 {

    static BufferedReader br;
    public static void main(String[]args){
        br=new BufferedReader(new InputStreamReader(System.in));
        try{
        	int[]arr=readIntArr();
        	int[]ar2=readIntArr();
        
        	int nd=0;
        	int hv=0;
        	for(int i=0;i<3;i++){
        		nd+=Math.max(ar2[i]-arr[i],0);
        		int sp=Math.max(arr[i]-ar2[i], 0);
        		hv+=sp/2;
        		
        	}
        	
        	if(hv>=nd){
        		System.out.println("Yes");
        	}else System.out.println("No");
            br.close();
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