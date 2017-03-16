import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class quesion_two {
	public static void main(String[] args){
		readFromFile();
	}
	public static void readFromFile(){
		Scanner scanner;
		try {
			scanner = new Scanner(new File("B-small-attempt0.in"));
			int noofTests = scanner.nextInt();
			int i=0;
			while(i<noofTests){
				double output = 0.0;				
				int K = scanner.nextInt();
				int L = scanner.nextInt();
				int S = scanner.nextInt();
				String keyboard = scanner.next();
				String word = scanner.next();
				
					boolean isAtleastMatch = false;
					for(int k =0;k<word.length();k++)
					{
						if(keyboard.indexOf(word.charAt(k)) == -1){
							isAtleastMatch = false;
							
						}else{
							isAtleastMatch = true;
						}
					}
					if(isAtleastMatch == false){
						output = 0.0;
					}else{
						int maxBananas = S/L;
						double intermediate=0.0;
						//generate all possible combinatons of 3 letter word
						double prob=1.0;
						for(int n=0;n<word.length();n++){
							double count=0;
							for(int j=0;j<keyboard.length();j++){
								if(word.charAt(n) == keyboard.charAt(j)){
									count++;
								}
							}
							prob *=(count/K);
						}
						intermediate+=prob;
						if((S-L) >= L)
						{
							int tempS = S-L;
							while(tempS >0){
								intermediate +=prob;
								tempS-=L;
							}
						}
						output = maxBananas-intermediate;
					}
				
				System.out.println("Case #" + (i+1) +": " + output);
				i++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
