import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;


public class question1CodeJam {
	String Input1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	String Input2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	String Input3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	String Output1 = "our language is impossible to understand";
	String Output2 = "there are twenty six factorial possibilities";
	String Output3 = "so it is okay if you want to just give up";
	HashMap<Character,Character> _map = new HashMap<Character,Character>();
	HashMap<Character,Character> _InverseMap = new HashMap<Character,Character>();
	public void FigureOutMapping(){
		//'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'
		_map.put('a', 'y');	
		_InverseMap.put('a', 'y');
		_map.put('o', 'e');	
		_InverseMap.put('e', 'o');
		_map.put('z', 'q');	
		_InverseMap.put('q', 'z');
		for(int i=0;i<Input1.length();i++){
			if(Input1.charAt(i)!=' '){
				_map.put(Input1.charAt(i), Output1.charAt(i));	
				_InverseMap.put(Output1.charAt(i), Input1.charAt(i));
			}
		}
		for(int i=0;i<Input2.length();i++){
			if(Input2.charAt(i)!=' '){
				_map.put(Input2.charAt(i), Output2.charAt(i));
				_InverseMap.put(Output2.charAt(i), Input2.charAt(i));
			}
		}
		for(int i=0;i<Input3.length();i++){
			if(Input3.charAt(i)!=' '){
				_map.put(Input3.charAt(i), Output3.charAt(i));	
				_InverseMap.put(Output3.charAt(i), Input3.charAt(i));
			}
		}

		_map.put(' ', ' ');
	}
	public String Convert(String in){
		String out = new String();
		for(int i=0;i<in.length();i++){
			if(_map.get(in.charAt(i))!=null){
				out = out + _map.get(in.charAt(i));	
			} else {
				//find out what letter no one mapped to
				int j=97;
				for(j=97;j<=122;j++){
					if(_InverseMap.get((char) j)==null){
						break;
					}
				}
				_map.put(in.charAt(i), (char) j);
				_InverseMap.put((char) j, in.charAt(i));
				out = out + _map.get(in.charAt(i));
			}
		}
		return out;
	}
	public static void main(String[] args){
		
	    try{
		    File file = new File(args[0]);
		    
		    FileWriter fstream = new FileWriter(args[1]);
		    BufferedWriter out = new BufferedWriter(fstream);
		    
		    BufferedReader in = new BufferedReader(new FileReader(file));
		    
		    String line = in.readLine();
		    //here line is the number of rounds
		    int counter=0;
		    int testCase = Integer.parseInt(line);
		    question1CodeJam tmp = new question1CodeJam();
		    tmp.FigureOutMapping();
		    while (counter<testCase) {
		    	String inline = in.readLine();
		    	++counter;
		    	System.out.println("Case #" + counter + ": " + tmp.Convert(inline));
		    	//out.write(inline);
		    	out.write("Case #" + counter + ": " + tmp.Convert(inline));
		    	out.write("\n");
	    	}
		    out.close();
		    in.close();
	    }
	    catch(IOException e){
	    	
	    	System.out.println("IO Error");
	    }
	    catch (ArrayIndexOutOfBoundsException e){
	    	System.out.println("Array Error");
	    	e.printStackTrace();
	    }
		
	}
}
