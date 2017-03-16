package codeJam;
import java.util.Scanner;
import java.util.ArrayList;
public class Slides {
	static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args){
		int cases=Integer.parseInt(sc.nextLine());
		for(int caseNo=0;caseNo<cases;caseNo++) runOnce(caseNo);
	}
	
	public static void runOnce(int caseNo){
		ArrayList<String> answers=new ArrayList<String>();
		int J=sc.nextInt();
		int P=sc.nextInt();
		int S=sc.nextInt();
		int K=sc.nextInt();
		sc.nextLine();
		
		
		int count=0;
		
		int[] JP=new int[J*P];
		int[] JS=new int[J*S];
		int[] PS=new int[P*S];
		
		for(int x=0;x<JP.length;x++) JP[x]=K;
		for(int x=0;x<JS.length;x++) JS[x]=K;
		for(int x=0;x<PS.length;x++) PS[x]=K;
		
		String ans="";
		
		for(int j=0;j<J;j++){
			for(int p=0;p<P;p++){
				for(int s=0;s<S;s++){
					if(JP[(P*j)+p]>0 && JS[(S*j)+s]>0 && PS[(S*p)+s]>0){
						count++;
						//ans=ans+(j+1)+" "+(p+1)+" "+(s+1)+"\n";
						answers.add(""+(j+1)+" "+(p+1)+" "+(s+1));
						JP[(P*j)+p]--;
						JS[(S*j)+s]--;
						PS[(S*p)+s]--;
					}
				}
			}
		}
		System.out.println("Case #"+(caseNo+1)+": "+count);
		for(int x=0;x<answers.size();x++) System.out.println(answers.get(x));
		//System.out.println("Case #"+(caseNo+1)+": "+count);
		//System.out.println(ans.substring(0, ans.length()-1));
	}
}