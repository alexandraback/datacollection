package qr2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static int caseCount;
	public static BufferedReader inbuf;
	public static BufferedWriter outbuf;
	public static String fileIn="data/qr2014/D-small-attempt0.in";
	public static String fileOut="data/qr2014/D-small-attempt0.out";
	
	public static int getMinIndex(double num,ArrayList<Double>nums,int ith){
		int len=nums.size();
		int index=-2;
		for(int i=ith;i<len;i++){
			if(nums.get(i)>num){
				index=i;
				break;
			}
		}
		return index;		
	}
	
	public static int getCheatScore(ArrayList<Double>nao,ArrayList<Double>ken){
		int N=nao.size();
		int score=0;
		int fail=0;
		for(int i=0;i<N;i++){
			if(nao.get(i)>ken.get(i-fail)){
				score++;
				continue;
			}
			else{
				fail++;
			}
		}
		return score;
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
			int N=Integer.valueOf(line);
			ArrayList<Double>nao=new ArrayList<Double>();
			ArrayList<Double> ken=new ArrayList<Double>();
			line=inbuf.readLine();
			String[]naostr=line.split(" ");
			for(int k=0;k<N;k++){
				nao.add(Double.valueOf(naostr[k]));
			}
			
			line=inbuf.readLine();
			String[]kenstr=line.split(" ");
			for(int k=0;k<N;k++){
				ken.add(Double.valueOf(kenstr[k]));
			}
			//排序
			Collections.sort(nao);
			Collections.sort(ken);
			
			int originScore=0,cheatScore=0;
			int minIndex=-1;
			int knao=0;
			for( knao=0;knao<N;knao++){
				 minIndex=getMinIndex(nao.get(knao),ken,minIndex+1);
				 if(minIndex==-2) break;					
			}
			originScore=N-knao;

			cheatScore=getCheatScore(nao,ken);
			
			outbuf.write(cheatScore+" "+originScore+"\r\n");
			
		}
		
		//关闭文件句柄	
		inbuf.close();
		outbuf.close();
		System.out.println("time:"+(System.currentTimeMillis()-sTime)/1000.0+"s");
	}

}
