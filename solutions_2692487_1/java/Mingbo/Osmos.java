package Osmos;

public class Osmos {
    public static void main(String args[]){
    	ReadFile RF=new ReadFile("A-large.in");
    	WriteResult WR=new WriteResult();
    	//System.out.println(RF.cases.toString());
    	for(int caseIndex=0;caseIndex<RF.caseNum;caseIndex++){
    		//System.out.println(RF.cases.get(caseIndex).toString());
            WR.addCaseResult(new Execute(RF.cases.get(caseIndex)).output());
    		//break;
    	}
    	WR.printResult();
    }
}
