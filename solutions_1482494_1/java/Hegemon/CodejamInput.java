import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class CodejamInput {
	BufferedReader reader;
	ArrayList<String []> inputList;
	int index;
	ListIterator<String []> iterator;
	String[] current;
	CodejamInput()throws Exception{
		inputList=new ArrayList<String []>();
		String input=null;
		reader = new BufferedReader(new InputStreamReader(System.in));
		while(reader.ready()){
			input =reader.readLine();
			inputList.add(input.trim().split(" "));
		}
		iterator=inputList.listIterator();
		if(iterator.hasNext()){
			current=iterator.next();
		}
		else{
			current=null;
		}
		index=0;
	}
	String nextInput(){
		while(current!=null){
			if(index<current.length){
				index++;
				return current[index-1];
			}
			else if(iterator.hasNext()){
				current=iterator.next();
				index=1;
				return current[index-1];
			}
			else{
				current=null;
				return null;
			}
		}
		return null;
	}
	String nextInputLine(){
		String temp=null;
		if(current!=null){
			for(int i=0;i<current.length;i++){
				if(temp==null){
					temp=current[i];
				}
				else{
					temp=temp+" "+current[i];
				}
			}
			if(iterator.hasNext()){
				current=iterator.next();
				index=0;
			}
			else{
				current=null;
			}
			return temp;
		}
		return null;
	}
}

