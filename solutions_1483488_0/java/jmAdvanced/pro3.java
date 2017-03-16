
import java.io.*;

public class pro3 {

private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

public static void main ( String [] args ) throws IOException
{
int N = Integer.parseInt(br.readLine());

for(int i = 0;i < N; i++)
System.out.println("Case #" + (i+1) + ": " + cal());
}

private static String cal() throws IOException {
	int start;
	int end;
	int lenth;
	int count=0;
	
	String[] buffer = br.readLine().split("\\s");
	
	start=Integer.parseInt(buffer[0]);
	end=Integer.parseInt(buffer[1]);
	
	lenth=Integer.toString(start).length();
	
	String digit= new String();
	String tempdigit=new String();
	
	for(int i=start;i<=end;i++){
		digit=Integer.toString(i);
		
		
		for(int j=1;j<lenth;j++){
			tempdigit=digit.substring(j).concat(digit.substring(0,j));
			if(Integer.parseInt(tempdigit)<=end
			   && Integer.parseInt(tempdigit)>=start){
				if(digit.compareTo(tempdigit)==0)
					break;
				/*System.out.println("digit "+digit);
				System.out.println("tempdigit"+tempdigit);
				*/count++;
			}
		}
			
		}
		

	
	

return Integer.toString(count/2);
}

}