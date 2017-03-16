import java.util.*;
import java.io.*;


 class tower{

	public static void main(String args[])throws FileNotFoundException
	{
		PrintWriter resultFile = new PrintWriter("B-large(1).out");
		File myFile = new File("B-large(1).in");
		Scanner fileRead = new Scanner(myFile);
		int a,b,c;
		b = 0;
		c = 1;
		int cases = fileRead.nextInt();
		int levels;
		int[] onestar;
		int[] twostar;
		boolean[] checktwo;
		boolean[] checkone;
		int levelsDone;
		int stars;
		boolean found = false;
		for(int i = 0; i < cases; i++){
			levels = fileRead.nextInt();
			stars = 0;
			levelsDone = 0;
			onestar = new int[levels];
			twostar = new int[levels];
			checktwo = new boolean[levels];
			checkone = new boolean[levels];
			for(int j = 0; j < levels; j++){
				onestar[j] = fileRead.nextInt();
				twostar[j] = fileRead.nextInt();
				checktwo[j] = false;
				checkone[j] = false;
			}//end for loop
			while(!checkme(checktwo)){
			c = 1;
				found = false;
				for(int z = 0; z < levels; z++){
					if(twostar[z] <= stars && checktwo[z] == false){
						checktwo[z]= true;
						found = true;
						if(checkone[z] == true){
							stars++;
						}
						else{
							stars += 2;
						}
						levelsDone++;
					}//end outer if
				
				}//end for loop
				if(found)
					continue;
				a = - 1;
				//if no two stars can be used
				for(int z = 0; z < levels; z++){
					if(onestar[z] <= stars && checktwo[z] == false && checkone[z] == false){
						if(a <= twostar[z]){
						a = twostar[z];
						b = z;
						found = true;
						}
					
					}
				
				
				}//end for loop
				
				if(found){
					levelsDone++;
				   stars++;
					checkone[b] = true;
				
					continue;
				}//end if

				resultFile.println("Case #" + (i+1) + ": Too Bad");
				c = 0;
				break;
			}//end while loop
			
			if(c == 1)
			resultFile.println("Case #" + (i+1) + ": " + levelsDone);
		}//end for loop
		
		
		
		resultFile.close();
		
		

	}//end main

	public static boolean checkme(boolean[] meme){
		for(int z = 0; z < meme.length;z++){
			if(meme[z] == false)
			return false;
		}
	return true;
	}//end function

	
}//end class googlerese