package main;

public class Pancakes extends CodeJamBase {

	@Override
	public String doResolve(int count, String line, int lineNum) {
		int size = line.length();
		int flipCount=0;
		for(int i=size-1;i>=0;i--) {
			boolean isChanged = flipCount % 2 == 1;
			boolean isDown = line.charAt(i) == '-';
			if(isDown && !isChanged || !isDown && isChanged) {
				flipCount++;
//				line = flip(i+1, line);
			}
		}
		return ""+flipCount;
	}
	
	String flip(int topN, String line) {
		String result="";
		for(int i=0;i<topN;i++) {
			boolean isDown = line.charAt(i) == '-';
			if(isDown) {
			    result += '+'; 
			} else {
				result += '-'; 
			}
		}
		result += line.substring(topN, line.length());
		return result;
	}
	
	public static void main(String[] args) {
		Pancakes test = new Pancakes();
		test.start();
	}
}
