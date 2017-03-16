package Osmos;
import java.io.*;
import java.util.*;
public class ReadFile {
    public int caseNum;
    public List<List<Integer>> cases=new ArrayList<List<Integer>>();
    public ReadFile(String fileName){   	
		try {
			Scanner in = new Scanner(new File(fileName));
			this.startRead(in);
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			System.out.println("cannot found file");
		}    	
    }
    
    private void startRead(Scanner in){
    	try{
    		if(in.hasNext()) caseNum=in.nextInt();
    		for(int i=0;i<caseNum;i++){
    			List<Integer> temp=new ArrayList<Integer>();
    			temp.add(in.nextInt());
    			int toAdd1=in.nextInt();
    			temp.add(toAdd1);
    			for(int j=0;j<toAdd1;j++){
    				temp.add(in.nextInt());
    			}
    			this.cases.add(temp);
    		}
    	}
    	finally{
    		in.close();
    	}
    }
}
