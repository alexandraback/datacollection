import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class P2javasol {

	public static void main(String[] args){
		BufferedReader inputStream = null;
		PrintWriter outputStream = null;

		File inputfile = new File("C:/users/Kevin/Desktop/B-small-attempt1.in");
		File outputFile = new File ("C:/users/Kevin/Desktop/P2.txt");
		try{
			inputStream = new BufferedReader(new FileReader(inputfile));
			outputStream = new PrintWriter(new FileWriter(outputFile));

			int num_cases = Integer.valueOf(inputStream.readLine()); //Grabs the # on the first line.
			for (int i=1; i<=num_cases; i++){
				StringBuffer sb = new StringBuffer("Case #" + i + ": ");
				String[] x_y = inputStream.readLine().split(" ");
				Coordinate c = new Coordinate(Integer.valueOf(x_y[0]), Integer.valueOf(x_y[1]));
				String outcome = findSolution(c);
				int x = 0;
				int y = 0;
				int dist = 1;
				for (int j=0; j < outcome.length(); j++){
					if (outcome.charAt(j) == 'E')
						x += dist;
					else if (outcome.charAt(j) == 'W')
						x -= dist;
					else if (outcome.charAt(j) == 'N')
						y += dist;
					else if (outcome.charAt(j) == 'S')
						y -= dist;
					dist++;
				}
				System.out.println(Integer.valueOf(x_y[0]) + " " + Integer.valueOf(x_y[1]) + " Directions: " + outcome + " x = " + x + " y = " + y);
				sb.append(outcome + "\n");
				outputStream.write(sb.toString());
			}	
		}catch (Exception e){
			e.printStackTrace();
		}finally{
			try {
				inputStream.close();
				outputStream.close();
			} catch (IOException e) {
				e.printStackTrace();
			}	
		}
	}
	public static String findSolution(Coordinate c){
		int x = 0;
		int y = 0;
		int dist = 1;
		
		StringBuffer directions = new StringBuffer("");
		//Start with x;
		while (x != c.x){
			int d = c.x - x;
			if (Math.abs(d) < dist){
				directions.append(delta(d, 'x'));
				dist += 2 * Math.abs(d);
				break;
			} else {
				if (d > 0){
					x += dist;
					directions.append("E");
				}
				else{
					x -= dist;
					directions.append("W");
				}
				dist++;
			}
		}
		while (y != c.y){
			System.out.println("y=" + y);
			int d = c.y - y;
			if (Math.abs(d) < dist){
				directions.append(delta(d, 'y'));
				dist += 2 * Math.abs(d);
				break;
			} else {
				if (d > 0){
					y += dist;
					directions.append("N");
				}
				else{
					y -= dist;
					directions.append("S");
				}
			}
			dist++;
		}
		return directions.toString();
	}
	public static String delta(int d, char direction){
		// if d > 0, we need to go east (or north) d units.
		// if d < 0, we need to go west (or south) d units.
		StringBuffer directions = new StringBuffer("");
		if (d > 0){
			for (int i=0; i<Math.abs(d);i++){
				if (direction == 'x')
					directions.append("WE");
				else
					directions.append("SN");
			}
		} else {
			for (int i=0; i<Math.abs(d);i++){
				if (direction == 'x')
					directions.append("EW");
				else
					directions.append("NS");
			}
		}
		return directions.toString();
	}
	
}
