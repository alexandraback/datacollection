package Osmos;
import java.util.*;
public class Execute {
	 List<Integer> thisCase;
	 String result;
	 int armin;
	 List<Integer> toAbsorb=new ArrayList<Integer>();
     public Execute(List<Integer> thisCase){
    	 this.thisCase=thisCase;
    	 this.core();
     }
     private void core(){
    	 this.ini();
    	 Collections.sort(toAbsorb);
    	 this.result=this.operate(armin,toAbsorb)+"";
         System.out.println(this.toAbsorb.toString());
     }
     
     private int operate(int armin, List<Integer> tA){
    	 if(armin==1) return tA.size();
    	 int count=0;
    	 if(tA.size()==0) return count;
    		 if(armin<=tA.get(0)){
    			 int steps=this.countStep(armin,tA.get(0));
    			 System.out.println("s"+steps+"a"+armin);
    			 if(steps>=tA.size()){
    				 return count=count+tA.size();
    			 }
    			 else {
    				 int tra=armin;
    				 for(int j=0;j<steps;j++){
    					 tra=tra*2-1;
    				 }
    				 List<Integer> tr=tA.subList(1, tA.size());
    				 int nsteps=this.operate(tra+tA.get(0), tr);
    				 if(nsteps+steps<=tA.size()){
    					 count=count+nsteps+steps;
    					 return count;
    				 }
    				 else return count=count+tA.size();
    			 }
    		 }
    	 count=count+this.operate(armin+tA.get(0), tA.subList(1, tA.size()));
    	 return count;
     }
     
     private int countStep(int a,int ta){
    	 int steps=1;
    	 if(a*2-1<=ta){
    		 steps=steps+this.countStep(a*2-1, ta);
    	 }
    	 return steps;
     }
     private void ini(){
    	 this.armin=thisCase.get(0);
    	 for(int i=0;i<thisCase.get(1);i++){
    		 this.toAbsorb.add(thisCase.get(2+i));
    	 }
     }
     public String output(){
    	 return result;
     }
     
}
