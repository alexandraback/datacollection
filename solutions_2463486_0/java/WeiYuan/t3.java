import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.*;


public class t3
{
	private static BigInteger A;
	private static BigInteger B;
	private int T;
	


	public static String getString(String str, int index)
	{
		str = str.trim();
		while (index > 0){
			str = str.substring(str.indexOf(' ') + 1);
			index--;
		}

		if (str.indexOf(' ')==(-1)) {
			return str;
		}
		else {
			return str.substring(0, str.indexOf(' '));
		}
	}

	private static long transfer(){
		long res=0;
		long i;
		BufferedReader fis = null;
		long A1=0,B1=0; 
		
		try {
			fis = new BufferedReader(new FileReader("db.txt"));
			
			for(i=1;;i++){
				String str=fis.readLine();
				BigInteger aaa=new BigInteger(str);
				aaa=aaa.multiply(aaa);
				if(aaa.compareTo(A)>=0){
					A1=i-1;
					if(aaa.compareTo(B)>0){
						B1=i-1;
					}
					if(aaa.compareTo(B)==0){
						B1=i;
					}
					i++;
					break;
				}
				
			}
			if(B1==0){
				for(;;i++){
					String str=fis.readLine();
					BigInteger aaa=new BigInteger(str);
					aaa=aaa.multiply(aaa);
					if(aaa.compareTo(B)>0){
						B1=i-1;
						break;
					}
					if(aaa.compareTo(B)==0){
						B1=i;
						break;
					}
					
				}
			}
			res=B1-A1;
	
			
			if (fis != null) fis.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		return res;
	}

	private static boolean checkfair(BigInteger bi){
	    
	    bi=bi.multiply(bi);
	    String str=bi.toString();
	    
	    char[] chs = str.toCharArray();

	    for(int i=0, j=chs.length-1;i<j;i++,j--){
	    	if(chs[i]!=chs[j])
	    		return false;
	    }
		
		return true;
	}

	private static void setdb(int digits){
		int i,j;
		int oddcount1;
		int oddcount2;
		int evencount1;
		int evencount2;

		String oddstring1[];
		String oddstring2[];

		String evenstring1[];
		String evenstring2[];
		
		BufferedWriter fos;
		
		try {
			fos = new BufferedWriter(new FileWriter("db.txt"));
			
			fos.write("1");
			fos.newLine();
			fos.write("2");
			fos.newLine();
			fos.write("3");
			fos.newLine();

			fos.write("11");
			fos.newLine();
			fos.write("22");
			fos.newLine();

			oddcount1=3;
			oddcount2=2;
			oddstring1=new String[1000000];
			oddstring2=new String[1000000];
			oddstring1[0]="101";
			oddstring1[1]="111";
			oddstring1[2]="121";
			oddstring2[0]="202";
			oddstring2[1]="212";
			
			for(i=0;i<oddcount1;i++){
				fos.write(oddstring1[i]);
				fos.newLine();
			}
			for(i=0;i<oddcount2;i++){
				fos.write(oddstring2[i]);
				fos.newLine();
			}
			
			
			evenstring1=new String[1000000];
			evenstring2=new String[1000000];
			evencount1=2;
			evencount2=1;
			evenstring1[0]="1001";
			evenstring1[1]="1111";
			evenstring2[0]="2002";
			
			for(i=0;i<evencount1;i++){
				fos.write(evenstring1[i]);
				fos.newLine();
			}
			for(i=0;i<evencount2;i++){
				fos.write(evenstring2[i]);
				fos.newLine();
			}
			
			
			for(i=5;i<=digits;i++){
				if((i%2)==1){
					String str1[]=new String[oddcount1*2];
					String str2[]=new String[oddcount2];
					
					for(j=0;j<oddcount1;j++){
						str1[j]="10"+oddstring1[j].substring(1, oddstring1[j].length()-1)+"01";
						str1[j+oddcount1]="11"+oddstring1[j].substring(1, oddstring1[j].length()-1)+"11";
					}
					
					int oddcount1tmp=0;
					String str1tmp[]=new String[oddcount1*2];
					
					for(j=0;j<oddcount1*2;j++){
						BigInteger bi=new BigInteger(str1[j]);
						if(checkfair(bi)){
							str1tmp[oddcount1tmp]=str1[j];
							oddcount1tmp++;
							fos.write(str1[j]);
							fos.newLine();
						}
					}
					oddcount1=oddcount1tmp;


					for(j=0;j<oddcount2;j++){
						str2[j]="20"+oddstring2[j].substring(1, oddstring2[j].length()-1)+"02";
					}

					int oddcount2tmp=0;
					String str2tmp[]=new String[oddcount2];
					
					for(j=0;j<oddcount2;j++){
						BigInteger bi=new BigInteger(str2[j]);
						if(checkfair(bi)){
							str2tmp[oddcount2tmp]=str2[j];
							oddcount2tmp++;
							fos.write(str2[j]);
							fos.newLine();
						}
					}
					oddcount2=oddcount2tmp;

//					oddstring1=new String[oddcount1tmp];
					for(j=0;j<oddcount1tmp;j++){
						oddstring1[j]=str1tmp[j];
					}
//					oddstring2=new String[oddcount2tmp];
					for(j=0;j<oddcount2tmp;j++){
						oddstring2[j]=str2tmp[j];
					}

				}
				else{
					
					String str1[]=new String[evencount1*2];
					String str2[]=new String[evencount2];
					
					for(j=0;j<evencount1;j++){
						str1[j]="10"+evenstring1[j].substring(1,  evenstring1[j].length()-1)+"01";
						str1[j+evencount1]="11"+evenstring1[j].substring(1, evenstring1[j].length()-1)+"11";
					}
					
					int evencount1tmp=0;
					String str1tmp[]=new String[evencount1*2];
					
					for(j=0;j<evencount1*2;j++){
						BigInteger bi=new BigInteger(str1[j]);
						if(checkfair(bi)){
							str1tmp[evencount1tmp]=str1[j];
							evencount1tmp++;
							fos.write(str1[j]);
							fos.newLine();
						}
					}
					evencount1=evencount1tmp;


					for(j=0;j<evencount2;j++){
						str2[j]="20"+evenstring2[j].substring(1, evenstring2[j].length()-1)+"02";
					}

					int evencount2tmp=0;
					String str2tmp[]=new String[evencount2];
					
					for(j=0;j<evencount2;j++){
						BigInteger bi=new BigInteger(str2[j]);
						if(checkfair(bi)){
							str2tmp[evencount2tmp]=str2[j];
							evencount2tmp++;
							fos.write(str2[j]);
							fos.newLine();
						}
					}
					evencount2=evencount2tmp;

//					evenstring1=new String[evencount1tmp];
					for(j=0;j<evencount1tmp;j++){
						evenstring1[j]=str1tmp[j];
					}
//					evenstring2=new String[evencount2tmp];
					for(j=0;j<evencount2tmp;j++){
						evenstring2[j]=str2tmp[j];
					}

				}
				
			}

				
			if (fos != null) fos.close();				
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
	}


	public static void main(String[] args) {
		
		int T;
		long res;

//		setdb(52);

		BufferedReader fis = null;
		BufferedWriter fos = null;
		
		
		try {
			fis = new BufferedReader(new FileReader("C-small-attempt0.in"));
			
			fos = new BufferedWriter(new FileWriter("result.txt"));
			//byte[] str = new byte[1024];

			String str=fis.readLine();

			int i = 0;
			T=Integer.parseInt(getString(str, 0));
			for (i=0;i<T;i++){
				str=fis.readLine();

				A=new BigInteger(getString(str, 0));

				B=new BigInteger(getString(str, 1));
				
				res=transfer();
				
				fos.write("Case #" + String.valueOf(i+1) + ": " + String.valueOf(res) );
				fos.newLine();
				
//					fos.write("Case #", 0, 6);
//					fos.write(i);
//					fos.write(": ");
//					fos.write(res);
					
//					fos.write(str);
			}
			
			if (fis != null) fis.close();
			if (fos != null) fos.close();				
		}
		catch (Exception e) {
			e.printStackTrace();
		}

	}
}