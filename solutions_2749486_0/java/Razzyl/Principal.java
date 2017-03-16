import java.awt.Point;
import java.io.File;
import java.util.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/* Google Code Jam
 * arielperezch@gmail.com
 * Code Base
 * May 2013
 */

public class Principal {

	static Scanner input;
	static FileWriter output;

	/* User Input */
	static Scanner consoleScanner;

	static long time = 0;
	static long measure = 0;
	
	public static void startTimer()
	{
		time = System.currentTimeMillis();
	}
	
	public static void stopTimer()
	{
		measure = System.currentTimeMillis() - time;
	}

	
	// Asks the user for a String by printing a given prompt.
	public static String askUser(String prompt) throws IOException{
		System.out.print(prompt);
		String str = consoleScanner.next();			
		return str;
	}

	// Begins the consoleScanner for user input
	public static void begin(){
		consoleScanner = new Scanner(System.in);
	}

	// Terminates the program
	public static void end() throws IOException{
		System.out.println("Program finished!");
		
		input.close();
		consoleScanner.close();
		output.close();
	}

	// Initializes the 'input' scanner with a given file.
	// If no such file exists, it prompts the user to re-enter the file name.
	public static void openReader(String fileName) throws IOException{
		File f = new File(fileName);
		while(!f.exists()){
			fileName = askUser("Please enter a valid file name >> ");
			f = new File(fileName);
		}
		input = new Scanner(f);
	}

	// Initializes the 'output' FileWriter with a given file.
	// If no such file exists, it prompts the user to re-enter the file name.
	public static void openWriter(String fileName) throws IOException{
		File f = new File(fileName);
		output = new FileWriter(f);
	}

	public static void main(String[] args) throws IOException, ClassNotFoundException{

		// Initializes the user input
		begin();

		// Does the preprocessing
		preprocessing();

		// Opens the file selected by the user
		openReader(askUser("Please enter the name of the problem input file >> "));
		
		// Opens a file for output.
		openWriter("output.txt");
		
		// Solves the problem
		solve();

		// Terminates the program, closes all files
		end();
	}
	public static Hashtable<Point, String> map;
	
	// Does any preprocessing required
	public static void preprocessing() throws IOException, ClassNotFoundException{
		String s = "";
		while(!(s.equalsIgnoreCase("Y") || s.equalsIgnoreCase("N"))){
			s = askUser("Would you like to preprocess from scratch? (Y/N) >> ");
		}
		
		if(s.equalsIgnoreCase("N")){
			loadPreprocessing("preprocessing.data");
		}		
		else{
			// TODO
			map = new Hashtable<Point, String>();
			
			Stack<KeyValuePair<String, Point>> stack = new Stack<KeyValuePair<String, Point>>();
			stack.push(new KeyValuePair<String, Point>("",new Point(0, 0)));
			
			int jumpSize;
			Point point, northPoint, eastPoint, westPoint, southPoint;
			KeyValuePair<String, Point> newPair;
			while(!stack.isEmpty()){
				
				KeyValuePair<String, Point> pair = stack.pop();//.remove();
				point = pair.Value;
				jumpSize = pair.Key.length() + 1;
				
				if(jumpSize > 20)
					continue;
				
				char[] chars = new char[]{ 'N', 'S', 'W', 'E'};
				Point[] points = new Point[4];
				points[0] = new Point(point.x, point.y + jumpSize);				
				points[1] = new Point(point.x, point.y - jumpSize);
				points[2] = new Point(point.x - jumpSize, point.y);
				points[3] = new Point(point.x + jumpSize, point.y);
				
				for(int i = 0; i < 4; i++){					
					if(!map.contains(points[i]) || map.get(points[i]).length() > jumpSize){
						newPair = new KeyValuePair<String, Point>(pair.Key + chars[i], points[i]);
						map.put(newPair.Value, newPair.Key);
						stack.push(newPair);
					}
				}
			}
			
			savePreprocessing("preprocessing.data");
		}
		
		System.out.println("Ready!");
	}

	public static void savePreprocessing(String fileName) throws IOException{
		//openWriter(fileName);
		
		//TODO
		// Write to disk with FileOutputStream
		FileOutputStream f_out = new FileOutputStream(fileName);

		// Write object with ObjectOutputStream
		ObjectOutputStream obj_out = new ObjectOutputStream(f_out);

		// Write object out to disk
		obj_out.writeObject ( map );
		
		obj_out.close();
		f_out.close();
		
		System.out.println("Preprocessing saved to: " + '"' + fileName + '"');
		//output.close();
	}
	// Loads a preprocessing file into memory
	public static void loadPreprocessing(String fileName) throws IOException, ClassNotFoundException{
		//openReader(fileName);

		//TODO 		
		// Read from disk using FileInputStream
		FileInputStream f_in = new 
			FileInputStream(fileName);

		// Read object using ObjectInputStream
		ObjectInputStream obj_in = 
			new ObjectInputStream (f_in);

		// Read an object
		Object obj = obj_in.readObject();

		if (obj instanceof Hashtable<?, ?>)
		{
			// Cast object to a Vector
			map = (Hashtable<Point, String>) obj;

		}
		
		//input.close();
	}
	
	// Solves the problem.
	// In here the Scanner 'input' is assumed open and can be used to read data.
	public static void solve() throws IOException{
		//TODO
		
		startTimer();
		int T = input.nextInt();
		String result;
		int x, y;
		for(int i = 1; i <= T; i++){
			x = input.nextInt();
			y = input.nextInt();
			result = solveCase(x, y);
			output.write("Case #" + i + ": " + result + "\n");
		}
		stopTimer();
		System.out.println("Solved in " + measure + " millis");
	}
	
	public static String solveCase(int x, int y){
		
		Point p = new Point( x > 0? x : - x, y > 0? y : - y);
		if(false)//map.containsKey(p))
		{
			return map.get(p);
		}
		else
			return solveEasyCase(x, y);
	}
	
	public static String solveEasyCase(int x, int y){
		
		String result = "";
		for(int i = 0; i < x; i++){
			result += "WE";
		}
		for(int i = 0; i > x; i--){
			result += "EW";
		}
		
		for(int i = 0; i < y; i++){
			result += "SN";
		}

		for(int i = 0; i > y; i--){
			result += "NS";
		}
			
		return result;	
	}
	
}


class KeyValuePair<K, V> implements Comparable<KeyValuePair<K, V>> {
	public K Key;
	public V Value;
	
	public KeyValuePair(K key, V value){
		Key = key;
		Value = value;
	}
	
	public boolean equals(KeyValuePair<K, V> other){
		return Key != null && Key.equals(other.Key) && Value != null && 
				Value.equals(other.Value);
	}

    // todo move this to a helper class.
    private int compare(Object o1, Object o2) {
        return o1 == null ? o2 == null ? 0 : -1 : o2 == null ? +1
                : ((Comparable) o1).compareTo(o2);
    }
    
	@Override
	public int compareTo(KeyValuePair<K, V> other) {
		// TODO Auto-generated method stub
		return compare(Value, other.Value);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "(" + Key + " , " + Value + ")";
	}
}