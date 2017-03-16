package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;


public class Googlerese {
	BufferedReader _in;
	PrintWriter _out;
	
	int _numTestCases;
	Input[] _inputs;
	
	HashSet<Character> allCharacters = new HashSet<Character>();
	HashSet<Character> assignableCharacters = null;
	HashSet<Character> charactersNeedingAssignment = null;
	private HashMap<Character, Character> _mapping = new HashMap<Character, Character>();
	
	public Googlerese(BufferedReader in) throws Exception {
		this._in = in;
		this._out = new PrintWriter("answers.out");
	}

	public void calculate() throws Exception {
		this._inputs = readInputs();
		
		calculateMapping();

		for(int i=0; i < _inputs.length; i++) {
			processInput(_inputs[i], i+1);
		}
		_out.flush();
		_out.close();
	}
	
	private void calculateMapping() {
		
		for(char c = 'a'; c <= 'z' ; c++) {
			allCharacters.add(Character.valueOf(c));
		}
		
		_mapping.put(Character.valueOf('y'), Character.valueOf('a'));
		_mapping.put(Character.valueOf('e'), Character.valueOf('o'));
		_mapping.put(Character.valueOf('q'), Character.valueOf('z'));
		
		String trainingSetInput[] = new String[3];
		String trainingSetOutput[] = new String[3];
		trainingSetInput[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		trainingSetInput[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		trainingSetInput[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		trainingSetOutput[0] = "our language is impossible to understand";
		trainingSetOutput[1] = "there are twenty six factorial possibilities";
		trainingSetOutput[2] = "so it is okay if you want to just give up";
		for(int index =0; index < 3; index++) {
			for(int i=0; i < trainingSetInput[index].length(); i++) {
				_mapping.put(trainingSetInput[index].charAt(i), trainingSetOutput[index].charAt(i));
			}
		}
		
		assignableCharacters = (HashSet<Character>)allCharacters.clone();
		charactersNeedingAssignment = (HashSet<Character>)allCharacters.clone();
		for(Map.Entry<Character,Character> aMapping : _mapping.entrySet()) {
			charactersNeedingAssignment.remove(aMapping.getKey());
			assignableCharacters.remove(aMapping.getValue());
		}
		
		_mapping.put(charactersNeedingAssignment.iterator().next(), assignableCharacters.iterator().next());
	}
	
	private void processInput(Input input, int caseIndex) {
		char[] outputChars = new char[input.googlerese.length];
		int numOutputChars = 0;
		for(char c: input.googlerese) {
			outputChars[numOutputChars++] = _mapping.get(Character.valueOf(c));
		
		}
		
		_out.println("Case #" + caseIndex +": " + new String(outputChars));
	}
	
	private Input[] readInputs() throws Exception {
		
		Scanner scanner = new Scanner(_in);
		_numTestCases = scanner.nextInt();
		Input[] inputs = new Input[_numTestCases];
		scanner.nextLine();
		for(int i=0; i < _numTestCases; i++) {
			char[] googlerese = scanner.nextLine().toCharArray();			
			inputs[i] = new Input(googlerese);
		}
		return inputs;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		new Googlerese(in).calculate();
	}
	
	
	private class Input {
		char[] googlerese;
		
		public Input(char[] googlerese) {
			this.googlerese = googlerese;
		}
	}
}
