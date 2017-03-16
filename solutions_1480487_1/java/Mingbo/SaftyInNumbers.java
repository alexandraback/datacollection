import java.io.*;
import java.util.*;

public class SaftyInNumbers {
	public static String result;
	
	public static double sum=0;
	public static void main(String args[]) throws IOException{
	   	 Scanner scan=new Scanner(new File("A-large.in"));
	   	 PrintWriter pw=new PrintWriter(new File("result.txt"));
	   	 int caseNum=Integer.parseInt(scan.nextLine());
	   	 for(int i=1;i<=caseNum;i++){
	   		 int numOfContestants=scan.nextInt();
	   		 int[] scores=new int[numOfContestants];
	   		 result="";
	   		 for(int j=0;j<scores.length;j++){
	   			 scores[j]=scan.nextInt();
	   			 System.out.println(scores[j]);
	   		 }
	   		 int count=scores.length;
	   		 sum=0;
	   		 double smallest=scores[0];
	   		 double secSmall=scores[0];
	   		 for(int j=0;j<scores.length;j++){
	   			 sum+=scores[j];
	   			 if(smallest>=scores[j]){
	   				 smallest=scores[j];
	   			 }
	   		 }
	   		 //System.out.println(smallest);
	   		
	   		 double tempsum=sum;
	   		 System.out.println(tempsum);
	   		 double average=sum*2/scores.length;
	   		 int[] temp=new int[scores.length];
	   		 for(int j=0;j<scores.length;j++){
	   			 temp[j]=scores[j];
	   		 }
	   		 Arrays.sort(temp);
	   		 
	   		 for(int j=0;j<scores.length;j++){
	   			 //System.out.println(temp[scores.length-1-j]);
	   			 if(temp[scores.length-1-j]>average){
	   				 count--;
	   				 tempsum=tempsum-temp[scores.length-1-j];
	   				 average=(sum+tempsum)/count;
	   				 System.out.println(tempsum);
	   			 }
	   		 }
	   		 System.out.println(count);
	   		 System.out.println(average);
	   		 //System.out.println(secSmall);
	   		 for(int j=0;j<scores.length;j++){
	   			 if(sum==0 || (average-scores[j])<=0) result=result+" "+0;
	   			 else result=result+" "+100*(average-scores[j])/(sum);
	   		 }
	   		 for(int j=0;j<scores.length;j++){
	   			 
	   		 }
	   		 pw.println("Case #"+i+":"+result);
	   		 System.out.println("Case #"+i+":"+result);
	   		 
	   		
	   		 
	   	 }
	   	 pw.flush();
	   	 pw.close();
    }
}

