import java.util.Scanner;

public class A {

	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int T = scan.nextInt();
		int caseNum = 0;
		while(caseNum<T){
			caseNum++;

			String word = scan.next();
			int n = scan.nextInt();
			
			word = word.replaceAll("[bcdfghjklmnpqrstvwxyz]", "c");
//			word.replace("quartz", "c");
//			word.replace('a', 'c');
//			word.replaceAll("b", "c");
//			word.replaceAll("c", "c");
			word = word.replaceAll("[aeiou]","v");
			
			
			int total = 0;
			
			int lastIndex = 0;
			
			int count = 0;
			for(int i=0; i<word.length(); i++){
				if(word.charAt(i)=='c'){
					count++;
				}
				else
					count = 0;
				
				if(count==n){
					//from index i-(count-1) to index (count-1)
					int start = i-(count-1);
					int end = i;
					int multiplier = start-lastIndex+1;
					//end to end of word
					int number = word.length() - end;
					
					total+= multiplier * number;
					
					count --;
					lastIndex= start +1;
					
				}
				

			}
			
			
			
			
			System.out.println("Case #"+(caseNum)+": "+total);
		}
	}

}
