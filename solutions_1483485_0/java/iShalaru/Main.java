import java.io.*;
import java.util.*;
import java.text.*;

import org.omg.CORBA.DoubleSeqHolder;

public class Main implements Runnable{

	/**
	 * @param args
	 */
	private StringTokenizer stReader;
	private BufferedReader bufReader;
	private PrintWriter out;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		(new Main()).run();
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		bufReader = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		stReader = null;
		Solves();
		out.flush();
	}
	public String ReadLine() {
		String result = null;

		try {
			result = bufReader.readLine();
		} catch (IOException e) {
		}
		return result;
	}
	public String NextString(){
		if (stReader == null || !stReader.hasMoreTokens()){
			stReader = new StringTokenizer(ReadLine(),"\n\r ");
		}
		return stReader.nextToken();
	}
	public int NextInt(){
		return Integer.parseInt(NextString());
	}
	public long NextLong(){
		return Long.parseLong(NextString());
	}
	public double NextDouble(){
		return Double.parseDouble(NextString());
	}

	void Solves(){
		int n = NextInt();
		for(int i =0; i < n; i++){
			out.print("Case #" + (i + 1) + ": ");
			Solve();
			out.println();
			out.flush();
		}
		out.flush();
	}
	void Solve(){
		String tmpWork = ReadLine();
		int[] data = new int[26];
		data[GetPos('n')] = GetPos('b');
		data[GetPos('f')] = GetPos('c');		
		data[GetPos('i')] = GetPos('d');
		data[GetPos('c')] = GetPos('e');		
		data[GetPos('w')] = GetPos('f');
		data[GetPos('l')] = GetPos('g');		
		data[GetPos('b')] = GetPos('h');
		data[GetPos('k')] = GetPos('i');
		data[GetPos('u')] = GetPos('j');		
		data[GetPos('o')] = GetPos('k');
		data[GetPos('m')] = GetPos('l');		
		data[GetPos('x')] = GetPos('m');		
		data[GetPos('s')] = GetPos('n');		
		data[GetPos('e')] = GetPos('o');
		data[GetPos('v')] = GetPos('p');
		data[GetPos('p')] = GetPos('r');
		data[GetPos('d')] = GetPos('s');		
		data[GetPos('r')] = GetPos('t');
		data[GetPos('j')] = GetPos('u');
		data[GetPos('g')] = GetPos('v');		
		data[GetPos('t')] = GetPos('w');		
		data[GetPos('h')] = GetPos('x');
		data[GetPos('a')] = GetPos('y');


		data[GetPos('q')] = GetPos('z');
		data[GetPos('z')] = GetPos('q');
		
		for(int i =0; i < tmpWork.length(); i++){
			char element = tmpWork.charAt(i);
			if (element == ' ') out.print(' ');
			else {
				char val = (char)(data[element - 'a'] + 'a');
				out.print(val);
			}
		}
	}
	int GetPos(char value){
		return value - 'a';
	}

	
}

