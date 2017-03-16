import java.io.*;
public class pro1 {
	

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main ( String [] args ) throws IOException{
		
		int N = Integer.parseInt(br.readLine());

		for(int i = 0;i < N; i++){
			System.out.print("Case #" + (i+1) + ": " );
			cal();
		}
	}
	private static void cal() throws IOException {
	
	
	String[] buffer = br.readLine().split("\\s");
	
	for(int i=0;i<buffer.length;i++){
		for(int j=0;j<buffer[i].toCharArray().length;j++){
			char temp=buffer[i].toCharArray()[j];
			
			if(temp=='a') System.out.print("y");
			if(temp=='b') System.out.print("h");
			if(temp=='c') System.out.print("e");
			if(temp=='d') System.out.print("s");
			if(temp=='e') System.out.print("o");
			if(temp=='f') System.out.print("c");
			if(temp=='g') System.out.print("v");
			if(temp=='h') System.out.print("x");
			if(temp=='i') System.out.print("d");
			if(temp=='j') System.out.print("u");
			if(temp=='k') System.out.print("i");
			if(temp=='l') System.out.print("g");
			if(temp=='m') System.out.print("l");
			if(temp=='n') System.out.print("b");
			if(temp=='o') System.out.print("k");
			if(temp=='p') System.out.print("r");
			if(temp=='q') System.out.print("z");
			if(temp=='r') System.out.print("t");
			if(temp=='s') System.out.print("n");
			if(temp=='t') System.out.print("w");
			if(temp=='u') System.out.print("j");
			if(temp=='v') System.out.print("p");
			if(temp=='w') System.out.print("f");
			if(temp=='x') System.out.print("m");
			if(temp=='y') System.out.print("a");
			if(temp=='z') System.out.print("q");
			
		}
		System.out.print(" ");
	}
		System.out.println();
	
	}
		
	}