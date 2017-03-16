import java.util.Scanner;


public class a {
public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	
	int cases = in.nextInt();
	outer: for (int i = 0; i < cases; i++) {
		char[][] map = new char[4][4];
		boolean over = true;
		for (int j = 0; j < map.length; j++) {
			String s = in.next();
			for (int k = 0; k < map.length; k++) {
				map[j][k] = s.charAt(k);
				if (map[j][k] == '.')
					over = false;
			}
		}
		char toCheck;
		for (int j = 0; j < map.length; j++) {
			toCheck = 'T';
			
			for (int k = 0; k < map.length; k++) {
				if (map[j][k] == '.') {
					toCheck = 'T';
					break;
				} else if (toCheck == 'T') {
					toCheck = map[j][k];
				} else if (map[j][k] == 'T') {
					continue;
				} else {
					if (toCheck != map[j][k]) {
						toCheck = 'T';
						break;
					}
				}
			}
			if (toCheck != 'T') {
				System.out.printf("Case #%d: %c won\n", i+1, toCheck);
				continue outer;
			}
				
			toCheck = 'T';
			for (int k = 0; k < map.length; k++) {
				if (map[k][j] == '.') {
					toCheck = 'T';
					break;
				} else if (toCheck == 'T') {
					toCheck = map[k][j];
				} else if (map[k][j] == 'T') {
					continue;
				} else {
					if (toCheck != map[k][j]) {
						toCheck = 'T';
						break;
					}
				}
			}
			
			if (toCheck != 'T') {
				System.out.printf("Case #%d: %c won\n", i+1, toCheck);
				continue outer;
			}
			
		}
		
		toCheck = 'T';
		for (int j = 0; j < map.length; j++) {
			if (map[j][j] == '.') {
				toCheck = 'T';
				break;
			} else if (toCheck == 'T') {
				toCheck = map[j][j];
			} else if (map[j][j] == 'T') {
				continue;
			} else {
				if (toCheck != map[j][j]) {
					toCheck = 'T';
					break;
				}
			}
		}
		if (toCheck != 'T') {
			System.out.printf("Case #%d: %c won\n", i+1, toCheck);
			continue outer;
		}
		
		
		toCheck = 'T';
		for (int j = 0; j < map.length; j++) {
			if (map[j][map.length - (j+1)] == '.') {
				toCheck = 'T';
				break;
			} else if (toCheck == 'T') {
				toCheck = map[j][map.length - (j+1)];
			} else if (map[j][map.length - (j+1)] == 'T') {
				continue;
			} else {
				if (toCheck != map[j][map.length - (j+1)]) {
					toCheck = 'T';
					break;
				}
			}
		}
		if (toCheck != 'T') {
			System.out.printf("Case #%d: %c won\n", i+1, toCheck);
			continue outer;
		}
		
		System.out.printf("Case #%d: %s\n", i+1, over ? "Draw" : "Game has not completed");
		
	}
}
}
