import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Kingdom_Rush {
	public static void main(String[] args)throws IOException {
		Scanner scan = new Scanner(new File(System.getProperty("user.dir")+"/input.in"));
		FileWriter file = new FileWriter("output.out");
		int n=Integer.parseInt(scan.nextLine());
		for(int i=0;i<n;i++){
			int levels = scan.nextInt();
			int[][] stars = new int[levels][2];
			for(int j=0;j<levels;j++){
				stars[j][0]=scan.nextInt();
				stars[j][1]=scan.nextInt();
			}
			int currentStars = 0;
			int[] starsLeft = new int[levels];
			for(int j=0;j<levels;j++){
				starsLeft[j]=2;
			}

			int starsNeeded = 0;
			for(int j=0;j<levels;j++){
				starsNeeded = Math.max(starsNeeded,stars[j][1]);
			}
			
			int moves=0;
			boolean stuck=true;
			boolean gameOver=true;
			
			while(currentStars<starsNeeded){
				gameOver=true;
				for(int j=0;j<levels;j++){
					if(starsLeft[j]>0&&stars[j][1]<=currentStars){
						gameOver=false;
						currentStars+=starsLeft[j];
						starsLeft[j]=0;
						moves++;
						stuck=false;
					}
				}
				if(stuck){
					boolean first=true;
					int maxI = -1;
					for(int k=0;k<levels;k++){
						if(starsLeft[k]>1&&stars[k][0]<=currentStars){
							gameOver=false;
							if(first){
								maxI=k;
								first=false;
							}else{
								if(stars[k][1]>stars[maxI][1])
									maxI=k;
							}
						}
					}
					if(maxI==-1){
						gameOver=true;
						break;
					}
					currentStars+=1;
					starsLeft[maxI]=1;
					moves++;
				}
				stuck=true;
			}
			if(gameOver){
				file.write("Case #"+Integer.toString(i+1)+": Too Bad\r\n");
			}else{
				for(int j=0;j<levels;j++){
					if(starsLeft[j]>0)
						moves++;
				}
				file.write("Case #"+Integer.toString(i+1)+": "+Integer.toString(moves)+"\r\n");
			}
		}
		file.close();
	}
}
