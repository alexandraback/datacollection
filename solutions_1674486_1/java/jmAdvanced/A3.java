import java.io.*;

public class A3 {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main ( String [] args ) throws IOException
	{
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++)
	System.out.println("Case #" + (i+1) + ": " + cal());
	}

	private static String cal() throws IOException{

		int numbers= Integer.parseInt(br.readLine());
		
		int Inh[][] = new int[numbers][];
		
		boolean possible=false;
		
		for(int i=0;i<numbers;i++){
			String[] tmp=br.readLine().split("\\s");
			
			Inh[i]=new int[Integer.parseInt(tmp[0])]; 

			if(Integer.parseInt(tmp[0])>=1)
				for(int j=1;j<tmp.length;j++)
					Inh[i][j-1]=Integer.parseInt(tmp[j]);
				
		}

		
			for(int i=0;i<numbers;i++){
			if(Inh[i].length>=2){
				for(int k=0;k<Inh[i].length-1;k++){
					int temp=Inh[i][k]-1;
					for(int l=k+1;l<Inh[i].length;l++){
						int  temp2=Inh[i][l]-1;
						if(checks(temp,temp2,Inh)) 
							possible=true;
					
						}
							
					}
				}
					
			}
				
				
		
			


	return possible ? "Yes" : "No";
	}



public static boolean checks(int a,int b,int[][] Inh){

		
    if(Inh[a].length==0) 
	for(int j=0;j<Inh[b].length;j++)
	    if(a+1==Inh[b][j])
		return true;
	 
    if(Inh[b].length==0) 
	for(int j=0;j<Inh[a].length;j++)
	    if(b+1==Inh[a][j])
		return true;


    

	for(int i=0;i<Inh[a].length;i++)
		for(int j=0;j<Inh[b].length;j++)
			if(Inh[a][i]==Inh[b][j])
				return true;
			

	
	for(int i=0;i<Inh[a].length;i++)
	    if(checks(Inh[a][i]-1,b,Inh))
		return true;
	
	for(int i=0;i<Inh[b].length;i++)
	    if(checks(a,Inh[b][i]-1,Inh))
		return true;
	

		
		return false;
}
}
