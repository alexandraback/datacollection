import java.util.*;

public class KingdomRush {
	int n;
	int a;
	int b;
	int caseNumber;
	ArrayList<intHolderTriple> stars;
	KingdomRush(){
		caseNumber=1;
		stars=new ArrayList<intHolderTriple>();
	}
	public void start() throws Exception{
		CodejamInput input=new CodejamInput();
		int answer=0;
		int cases=Integer.parseInt(input.nextInput());
		for(int i=0;i<cases;i++){
			//set variables here
			n=Integer.parseInt(input.nextInput());
			stars.clear();
			for(int j=0;j<n;j++){
				a=Integer.parseInt(input.nextInput());
				b=Integer.parseInt(input.nextInput());
				stars.add(new intHolderTriple(a,b,0));
			}
			answer=calcTimes();
			if(answer==-1){
				output("Too Bad");
			}
			else{
				output(String.valueOf(answer));
			}
		}
	}
	public void output(String out){
		System.out.println("Case #"+caseNumber+": "+out);
		caseNumber++;
	}
	public int calcTimes(){
		int times=0;
		int starCount=0;
		int bestIndex=-1;
		intHolderTriple temp;
		for(int i=0;i<stars.size(); i++){
			temp=stars.get(i);
			if(temp.two<=starCount){
				if(temp.three==0){
					starCount+=2;
				}
				else{
					starCount+=1;
				}
				times++;
				//System.out.println("Increased stars by 2 to "+starCount+" and times to "+times+" on a="+temp.one+" and b="+temp.two);
				stars.remove(i);
				bestIndex=-1;
				i=-1;
			}
			else if(temp.one<=starCount &&( bestIndex==-1|| temp.two>stars.get(bestIndex).two) && temp.three!=1){
				bestIndex=i;
			}
			if(i==(stars.size()-1) && (stars.size()!=0)){
				if(bestIndex!=-1){
					starCount+=1;
					times++;
					//System.out.println("Increased stars by 1 to "+starCount+" and times to "+times+" on a="+stars.get(bestIndex).one+" and b="+stars.get(bestIndex).two);
					stars.get(bestIndex).setThree(1);
					bestIndex=-1;
					i=-1;
				}
			}
		}
		if(stars.size()==0){
			return times;
		}
		else{
			return -1;
		}
	}
}
