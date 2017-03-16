import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class ManageEnergy {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        ManageEnergy me=new ManageEnergy();
        me.manageEnergy();
	}
	public long getMaxGain(long maxEnergy,long energy,long regain,int[] val,int index)
	{
		long maxGain=0;
		long gain=0;
		if(energy>maxEnergy)
			energy=maxEnergy;
		if(index==val.length)
			return 0;
		for(long en=0;en<=energy;en++)
		{
		  gain=getMaxGain(maxEnergy,energy-en+regain,regain,val,index+1);
		  gain+=en*val[index];
		  if(gain>maxGain)
			  maxGain=gain;
		}
		return maxGain;
	}
	public void manageEnergy()
	{
		String inputFile,outputFile;
		
		inputFile="C:\\CodeJam\\input.in";
		outputFile="C:\\CodeJam\\MaxEnergySmallOut.txt";
		int cases;
		BufferedReader br;
		BufferedWriter bw;
		String line;
		String[] input;
		
		
		
		
		long energy, regain;
		int totAct;
		
		int i;
		long gain=0;
		int values[];
		
		
		try{
			br=new BufferedReader(new FileReader(inputFile));
			bw=new BufferedWriter(new FileWriter(outputFile));
			cases=Integer.parseInt(br.readLine());
			
			for(i=0;i<cases;i++)
			{
				
				line=br.readLine();
				input=line.split(" ");
				energy=Long.parseLong(input[0]);
				
				regain=Long.parseLong(input[1]);
				
				totAct=Integer.parseInt(input[2]);
				values=new int[totAct];
				line=br.readLine();
				input=line.split(" ");
				for(int j=0;j<totAct;j++)
				{
					values[j]=Integer.parseInt(input[j]);
				}
			
			   
				//System.out.println("Case "+(i+1));
				gain=getMaxGain(energy,energy,regain,values,0);
				System.out.println("Case #"+(i+1));
				bw.write("Case #"+(i+1)+": "+(gain)+"\n");
				
				//+": "+gStatus[gameStatus]);
				
			}
			br.close();
			bw.close();

		}catch(Exception ex)
		{
			System.out.println(ex);
			ex.printStackTrace();
		}
	}

}
