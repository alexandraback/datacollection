import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;


public class B {
	
public static int b(String str){
	
	int retVal = 0;
	
	String arr[] = str.split(" ");
	
	int N = Integer.parseInt(arr[0]);
	int S = Integer.parseInt(arr[1]);
	int P = Integer.parseInt(arr[2]);
	
	if(P == 0){
		return N;
	}
	
	int sum = 3*P - 2;
	
	for(int i = 3; i < arr.length ; i++){
		
		int Ti = Integer.parseInt(arr[i]);
		if(Ti >= sum){
			retVal++;
		}
		else if(S >0 && Ti > 0 && Ti >= sum - 2){
			retVal++;
			S--;
		}
	}
	
	
	return retVal;
}	
	
public static void main(String args[]){
		
		File file = new File("B-large.in");
		
		int T = 0;
		try{
			  FileInputStream fstream = new FileInputStream(file);
			
			  DataInputStream in = new DataInputStream(fstream);
			  BufferedReader br = new BufferedReader(new InputStreamReader(in));
			  String strLine;
			  if ((strLine = br.readLine()) != null)   {
				  T = Integer.parseInt(strLine);
			  }
			  int currentCase = 1;
			  while(T > 0 && currentCase <= T){
						
						String str= br.readLine();
						
						System.out.println("Case #"+currentCase+": " + b(str));
						currentCase++;
					}
			
			  in.close();
			    }catch (Exception e){
			  System.err.println("Error: " + e.getMessage());
			  }
		
		
		
	}
	
}
