import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.Math;
import java.math.*;
import java.text.*;


class solve{
	
	public solve(){
		
	}
	
	
	public static float helper(float present, int[] pinput, int n, float sum, float votesleft){
		System.out.println("sum= "+sum+" present= "+present);
		int[] temp=new int[n];
		
		for (int oi=0; oi<n; oi++) {
			temp[oi]=pinput[oi];
		}  ///copy creation
		
		float perc=0; ///required by opponents
		
		int numberofless=0;
		for (int oi=0; oi<n; oi++) {   ///temp will contain values <=present
			if (present>=temp[oi]) {
				perc+=(100*(present-(float)temp[oi]))/(sum);
				temp[oi]= (int)present;
				numberofless++;
			}
		}
		int indicator=0;
		float min=10000000;
		
		/// check if (100-perc)/numberofless*100  * sum + present is less than rest
		float old;
		old=present;
		
		if (perc>=votesleft) {
			return 0;
		}
		float max=0;
		present+=((votesleft-perc)/((float)numberofless*100))*sum;
		for (int oi=0; oi<n; oi++) {
			if (temp[oi]>old) {
				max=1;
			}
			if (temp[oi]!=old) {
				if (temp[oi]>=present) {
					continue;
				}
				else {
					if (temp[oi]<min) {
						min=temp[oi];
						indicator=1;
					}
				}
				
			}
		}
		//System.out.println("perc= "+perc);
		//System.out.println(" min= "+min+" old= "+old+" present= "+present);
		
		if (min>=present) {
			if (max==1) {   //there exists a number greater than the present
				return ((votesleft-perc)/((float)numberofless));
			}
			else {
				//System.out.println("noless= "+numberofless);
				System.out.println("number votes left= "+votesleft+" min= "+min);
				return (votesleft-perc)/numberofless;
			}

		}
		else {
			////// increase all to min
			for (int oi=0; oi<n; oi++) {
				if (temp[oi]<min) {
					temp[oi]=(int)min;
				}
			}
			//System.out.println("perc= "+perc+" votesleft="+votesleft+" and+ "+((min-old)*100*numberofless/sum)); 
			return helper(min,temp,n,sum,votesleft-perc-((min-old)*100*numberofless/sum))+(min-old)*100/sum;
		}
	}
	
	public static void main(String[] args){
		
		try {
			int counter=1;
			BufferedReader bf = new BufferedReader(new FileReader("input.txt"));
			String line;
			float sum=0;
			String finish="";
			
			while ((line=bf.readLine())!=null) {
				sum=0;
				String ans="";
				String[] input=line.split(" ");
				int n=Integer.parseInt(input[0]);
				int min1=100000;
				int[] pinput=new int[n];
				
				for (int ui=1; ui<=n; ui++) {
					pinput[ui-1]=Integer.parseInt(input[ui]);
					sum+=pinput[ui-1];
					if (pinput[ui-1]<min1) {
						min1=pinput[ui-1];
					}
				}
				finish+="Case #"+counter+":";
				for (int ui=0; ui<n; ui++) {
					float add2ans=helper(pinput[ui],pinput,n,sum,100);
					finish+=" "+add2ans;
				}
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
				
				finish+="\n";
				counter++;
			}
			BufferedWriter f=new BufferedWriter(new FileWriter("output.txt"));
			f.write(finish);
			f.close();
		}
		catch (Exception e) {
			System.out.println("error!!");
		}
	}
}