import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashSet;


public class A {
	
public static int a(String str){
	
	int retVal = 0;
	
	String arr[] = str.split(" ");
	int n = Integer.parseInt(arr[0]);
	int m = Integer.parseInt(arr[1]);
	
	for(int i = n ; i < m; i++){
		String cur = Integer.toString(i);
		cur += cur;
		HashSet<String> set = new HashSet<String>();
		for(int j = 1; j < cur.length()/2 ; j++){			
			String val = cur.substring(j, j+cur.length()/2);
			int intVal = Integer.parseInt(val);			
			if(set.add(val) && intVal > i && intVal <= m){				
				retVal++;
				//System.out.println(retVal + ":" +cur.substring(cur.length()/2)+" : "+intVal);
			}
		}
		
	}
	
	
	return retVal;
	
}	
	
public static void main(String args[]){
		
		File file = new File("C-small-attempt0.in");
		
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
						
						System.out.println("Case #"+currentCase+": " + a(str));
						currentCase++;
					}
			
			  in.close();
			    }catch (Exception e){
			  System.err.println("Error: " + e.getMessage());
			  }
		
		
		
	}
	
}
