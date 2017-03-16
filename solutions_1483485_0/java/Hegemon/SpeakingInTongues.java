import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SpeakingInTongues {
	BufferedReader reader;
	char [] charInput;
	int index;
	char []mapping;//Googlerese->English
	SpeakingInTongues()throws Exception{
		String input=null;
		reader = new BufferedReader(new InputStreamReader(System.in));
		while(reader.ready()){
			if (input==null){
				input =reader.readLine();
			}
			else{
				input =input+"\n" + reader.readLine();
			}
		}
		//input=input.trim().replaceAll(" ","");
		charInput=input.toCharArray();
		index=0;
		initializeMapping();
	}
	void initializeMapping(){
		mapping=new char[26];
		mapping[(int)'a'-97]='y';
		mapping[(int)'b'-97]='h';
		mapping[(int)'c'-97]='e';
		mapping[(int)'d'-97]='s';
		mapping[(int)'e'-97]='o';
		mapping[(int)'f'-97]='c';
		mapping[(int)'g'-97]='v';
		mapping[(int)'h'-97]='x';
		mapping[(int)'i'-97]='d';
		mapping[(int)'j'-97]='u';
		mapping[(int)'k'-97]='i';
		mapping[(int)'l'-97]='g';
		mapping[(int)'m'-97]='l';
		mapping[(int)'n'-97]='b';
		mapping[(int)'o'-97]='k';
		mapping[(int)'p'-97]='r';
		mapping[(int)'q'-97]='z';
		mapping[(int)'r'-97]='t';
		mapping[(int)'s'-97]='n';
		mapping[(int)'t'-97]='w';
		mapping[(int)'u'-97]='j';
		mapping[(int)'v'-97]='p';
		mapping[(int)'w'-97]='f';
		mapping[(int)'x'-97]='m';
		mapping[(int)'y'-97]='a';
		mapping[(int)'z'-97]='q';
	}
	char nextChar()throws Exception{
		if(index<charInput.length){
			int temp=index;
			index++;
			return charInput[temp];
		}
		else{
			return '\n';
		}
	}
	void start()throws Exception{
		char temp='\0';
		String num=String.valueOf(nextChar());
		temp=nextChar();
		while(temp!='\n'){
			num=num+temp;
			temp=nextChar();
		}
		int numCases=Integer.parseInt(num);
		int caseCount=0;
		System.out.printf("Case #1: ");
		while(caseCount!=numCases){
			temp=nextChar();
			if (temp=='\n'){
				caseCount++;
				System.out.println();
				if (caseCount<numCases){
					System.out.printf("Case #%d: ",caseCount+1);	
				}
			}
			else if(temp==' '){
				System.out.print(temp);
			}
			else if(((int)temp-97)>=0 && ((int)temp-97)<26){
				System.out.print(mapping[(int)temp-97]);
			}
			else {
				System.out.print(temp);
			}
		}
	}
}

