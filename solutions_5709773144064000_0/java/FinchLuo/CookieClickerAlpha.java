package qr2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CookieClickerAlpha {

	/**
	 * @param args
	 */
	public static int caseCount;
	public static BufferedReader inbuf;
	public static BufferedWriter outbuf;
	public static String fileIn="data/qr2014/B-small-attempt0.in";
	public static String fileOut="data/qr2014/B-small-attempt0.out";
	
	public static double calTime(double C,double F,double X){
		double time=0.0;
		if(X<=C) return X/2.0;
		double fr=Math.ceil(((X-C)*F/C-2.0)/F);
		double part1=0.0;
		double part2=(X-C)/(2.0+fr*F);
		for(int i=0;i<=fr;i++){
			part1+=(C/(2.0+i*F));
		}
		return part1+part2;
		
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//打开文件句柄
		long sTime=System.currentTimeMillis();
		inbuf=new BufferedReader(new FileReader(fileIn));
		outbuf=new BufferedWriter(new FileWriter(fileOut));	
		caseCount=Integer.valueOf(inbuf.readLine());
		String line="";	
		for(int i=1;i<=caseCount;i++){
			outbuf.append("Case #"+i+": ");//注意这里的空格
			line=inbuf.readLine();
			String[] nums=line.split(" ");
			double C=Double.valueOf(nums[0]);
			double F=Double.valueOf(nums[1]);
			double X=Double.valueOf(nums[2]);
			double time=calTime(C,F,X);
			outbuf.write(String.format("%.7f", time)+"\r\n");
		}
		
		
		//关闭文件句柄	
		inbuf.close();
		outbuf.close();
		System.out.println("time:"+(System.currentTimeMillis()-sTime)/1000.0+"s");
	}

}
