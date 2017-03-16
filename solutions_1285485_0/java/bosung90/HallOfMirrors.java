import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;

public class HallOfMirrors {
	public static void main(String[] args) throws IOException {
		int testCaseNumber;

		String input;
		BufferedReader in = new BufferedReader(new FileReader("D-small-attempt1.in"));
		input = in.readLine();

		testCaseNumber = Integer.parseInt(input.trim());
		int[] totalAccountArray = new int[testCaseNumber];
		for(int i=0; i<testCaseNumber; i++){
			input = in.readLine();
			String[] dataArrayString = input.split(" ");
			int height = Integer.parseInt(dataArrayString[0]);
			int width = Integer.parseInt(dataArrayString[1]);
			int sight = Integer.parseInt(dataArrayString[2]);
			in.readLine();
			String[] map = new String[height-2];
			String[] mapHR = new String[height-2];
			String[] mapVR = new String[height-2];
			String[] mapHVR = new String[height-2];
			//in.readLine().substring(1, width-1);
			//String map = in.readLine();
			for(int j=0; j<height-2; j++){
				//map += in.readLine();
				String line = in.readLine().substring(1, width-1);
				map[j] = line;
				mapHR[j] = new StringBuffer(line).reverse().toString();
				mapVR[height-3-j] = line;
				mapHVR[height-3-j] = new StringBuffer(line).reverse().toString();
			}
			in.readLine();
			totalAccountArray[i] = getReflections(height-2,width-2,sight,map,mapHR,mapVR,mapHVR);
		}
		
		in.close();

		FileWriter fstream = new FileWriter("D-small-attempt1.out");
		BufferedWriter out = new BufferedWriter(fstream);

		for(int i=1; i<=testCaseNumber;i++){
			String outLine = "Case #"+i+": "+totalAccountArray[i-1]+"\n";
			out.write(outLine);
		}
		out.close();
		System.out.println("File created successfully.");
	}
	public static int getReflections(int height, int width, int sight, String[] map, String[] mapHR, String[] mapVR, String[] mapHVR){
		//System.out.println(map);
		//System.out.println(map.indexOf("X"));
		//System.out.println(Arrays.toString(map));
		HashMap<Point, Character> tiledMap = new HashMap<Point, Character>();

		int hrNum = (int)Math.ceil(sight/width)+1;
		int vrNum = (int)Math.ceil(sight/height)+1;
		boolean hFlip;
		boolean vFlip;

		for(int j=-(vrNum*height); j<=vrNum*height; j+=height){
			for(int i=-(hrNum*width); i<=hrNum*width; i+=width){
				//System.out.println(i + " " + j);
				hFlip = (Math.abs(i/width%2) == 1);
				vFlip = (Math.abs(j/height%2) == 1);
				String[] tempMap;
				if(vFlip){
					if(hFlip){
						tempMap = mapHVR;
					}
					else{
						tempMap = mapVR;
					}
				}
				else{
					if(hFlip){
						tempMap = mapHR;
					}
					else{
						tempMap = map;
					}
				}
				populateTiledMap(height,width,i,j,tempMap,tiledMap);
			}
		}

		//		System.out.println(Arrays.toString(map));
		//		System.out.println(Arrays.toString(mapHR));
		//		System.out.println(Arrays.toString(mapVR));
		//		System.out.println(Arrays.toString(mapHVR));

		Point startCoord = getStartPoint(height,width,map);
		//System.out.println(startCoord.x +" "+ startCoord.y);
		tiledMap.put(startCoord, '.');
		//tiledMap.remove(startCoord);
		int count = 0;
		for(int j=-(vrNum*height); j<vrNum*height+height; j++){
			String line = "";
			for(int i=-(hrNum*width); i<hrNum*width+width; i++){
				Point tempPoint = new Point(i,j);

				
				if(tiledMap.get(tempPoint) != null && tiledMap.get(tempPoint) == 'X' && getDistanceBtwTwoPoints(tempPoint,startCoord)<=sight){
					count ++;
					//System.out.println(i + " : " + j + " : "  +getDistanceBtwTwoPoints(tempPoint,startCoord));
					int gcd = gcd(Math.abs(i-startCoord.x),Math.abs(j-startCoord.y));
					//					if(gcd == 0)
					//						gcd = 1;
					int gcdY = (j-startCoord.y)/gcd;
					int gcdX = (i-startCoord.x)/gcd;
					//int d = 1;
					for(int d=0; d<100; d++){
						if(tiledMap.get(new Point(gcdX*d+startCoord.x,gcdY*d+startCoord.y)) != null && tiledMap.get(new Point(gcdX*d+startCoord.x,gcdY*d+startCoord.y)) == 'X'){
							tiledMap.put(new Point(gcdX*d+startCoord.x,gcdY*d+startCoord.y),'.');
							System.out.print(("("+(gcdX*d+startCoord.x)+"D"+(gcdY*d+startCoord.y))+")");
						}
					}
					System.out.print("("+(i-startCoord.x)+","+(j-startCoord.y)+")");
				}
				line += tiledMap.get(tempPoint);
			}
			System.out.println(line);
		}
		System.out.println(count);
		return count;
	}

	public static void populateTiledMap(int height, int width, int x, int y, String[] map, HashMap<Point, Character> tiledMap){
		for(int j=0; j<height; j++){
			for(int i=0; i<width; i++){
				tiledMap.put(new Point(i+x,j+y), map[j].charAt(i));
			}
		}
	}
	private static int gcd(int a, int b)
	{
		while (b > 0)
		{
			int temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}
	public static Point getStartPoint(int height, int width, String[] map){
		for(int j=0; j<height; j++){
			for(int i=0; i<width; i++){
				if(map[j].charAt(i) == 'X'){
					return new Point(i,j);
				}

			}
		}
		return null;
	}
	public static double getDistanceBtwTwoPoints(Point p1, Point p2){
		return Math.sqrt(Math.pow((p2.x - p1.x), 2) + Math.pow((p2.y - p1.y), 2));
	}

}
