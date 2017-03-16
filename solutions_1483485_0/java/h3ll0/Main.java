import java.io.File;
import java.util.HashMap;
import java.util.Scanner;


public class Main {
	
	static HashMap<Character, Character>mymap = new HashMap<Character, Character>();
	static{
		
		mymap.put('a', 'y');
		mymap.put('b', 'h');
		mymap.put('c', 'e');
		mymap.put('d', 's');
		mymap.put('e', 'o');
		mymap.put('f', 'c');
		mymap.put('g', 'v');
		mymap.put('h', 'x');
		mymap.put('i', 'd');
		mymap.put('j', 'u');
		mymap.put('k', 'i');
		mymap.put('l', 'g');
		mymap.put('m', 'l');
		mymap.put('n', 'b');
		mymap.put('o', 'k');
		mymap.put('p', 'r');
		mymap.put('q', 'z');
		mymap.put('r', 't');
		mymap.put('s', 'n');
		mymap.put('t', 'w');
		mymap.put('u', 'j');
		mymap.put('v', 'p');
		mymap.put('w', 'f');
		mymap.put('x', 'm');
		mymap.put('y', 'a');
		mymap.put('z', 'q');
	}
	
	public static String decode(String line){
		char[] arr = line.toCharArray();
		for(int i=0;i<arr.length;i++){
			if(mymap.containsKey(arr[i])){
				arr[i] = mymap.get(arr[i]);
			}
		}
		return new String(arr);
	}
	
	public static void main(String[]args){
		Scanner sc = null;
		try{
			sc = new Scanner(new File("input.txt"));
			int T = Integer.parseInt(sc.nextLine());
			for(int i=0;i<T;i++){
				String line = sc.nextLine();
				//System.out.println(line);
				System.out.println("Case #"+(i+1)+": "+decode(line));
			}
		}catch(Exception e){
			e.printStackTrace();
		}finally{
			try{
				sc.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
}
