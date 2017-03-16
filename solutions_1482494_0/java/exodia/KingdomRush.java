package _2012.round1A;

import java.util.Scanner;

public class KingdomRush {
	public static void main(String[] args) {
		Scanner consola = new Scanner(System.in);
		int []star1;
		int []star2;
		int []complete;
		int minDif, dif, cont, ant, stars, i, lvls, times = consola.nextInt();
		for(int t = 1; t <= times; t++){
			lvls = consola.nextInt();
//			System.out.println(lvls);
			star1 = new int[lvls];
			star2 = new int[lvls];
			complete = new int[lvls];
			for(i = 0; i < lvls; i++){
				star1[i] = consola.nextInt();
				star2[i] = consola.nextInt();
				if(star2[i] > lvls * 2 - 1){
					System.out.println("Case #" + t + ": Too Bad");
					for(int k = i + 1; k < lvls; k++){
						consola.nextInt();
						consola.nextInt();
					}
					break;
				}
			}
			if(i < lvls)
				continue;
			
//			System.out.println(star1[lvls - 1] + " - " + star2[lvls - 1]);
			stars = 0;
			cont = 0;
			while(stars < lvls * 2){
				ant = stars;
				minDif = Integer.MAX_VALUE;
				for(int j = 0; j < lvls; j++){
					if(complete[j] < 2){ 
						if(star2[j] <= stars){
							stars += 2 - complete[j]; 
							complete[j] = 2;
							cont++;
//							System.out.println("2: " + j);
						}
						else{
							dif = star2[j] - stars;
							if(dif < minDif)
								minDif = dif;
						}
					}
				}
//				System.out.println(minDif);
				if(ant == stars){
					for(int j = 0; j < lvls; j++){
						if(complete[j] == 0 && star1[j] <= stars){
							stars++; 
							complete[j] = 1;
							cont++;
							minDif--;
//							System.out.println("1: " + j);
						}
						if(minDif == 0)
							break;
					}
					if(minDif > 0 && ant == stars){
						System.out.println("Case #" + t + ": Too Bad");
						break;
					}
				}
			}
			if(stars == lvls * 2)
				System.out.println("Case #" + t + ": " + cont);
		}
	}
}