
import java.io.*;
import java.util.Arrays;

public class A1 {

private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

public static void main ( String [] args ) throws IOException
{
int N = Integer.parseInt(br.readLine());

for(int i = 0;i < N; i++)
	System.out.println("Case #" + (i+1) + ": " + cal());
}

private static String cal() throws IOException {

	String[] buffer = br.readLine().split("\\s");
	
	int n=Integer.parseInt(buffer[0]);
	int m=Integer.parseInt(buffer[1]);
	
	double[] possibility=new double[100000];
	
	buffer=br.readLine().split("\\s");
	
	
	for(int i=0;i<buffer.length;i++)	
		possibility[i]=Double.parseDouble(buffer[i]);
	
	double EnterDirect=m+2;
	double KeepType;
	double[] delete=new double[n];
	
	double correctCandi=1;
	
	for(int i=0;i<n;i++)
		correctCandi*=possibility[i];

	KeepType=correctCandi*(m-n+1)+(1-correctCandi)*(2*m-n+2);
	
		for(int j=0;j<n;j++){
		correctCandi=1;
		for(int i=0;i<n-j-1;i++)
			correctCandi*=possibility[i];
		delete[j]=correctCandi*+(2*j+m-n+3)+
			(1-correctCandi)*(2*j+4+2*m-n);
				
	}
	
	Arrays.sort(delete);
	//System.out.println("delete[0] "+delete[0]);
	//System.out.println("Eneter "+EnterDirect);
	//	System.out.println("keeptype "+KeepType);


	double result = Math.min(delete[0],EnterDirect);
	result = Math.min(result,KeepType);
	
	
return Double.toString(result);
}

}