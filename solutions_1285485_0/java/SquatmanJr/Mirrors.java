import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Mirrors {
	public static void main(String args[]) {
		try{
		     BufferedReader in = new BufferedReader(new FileReader("D-small-attempt0.in"));
			 BufferedWriter out = new BufferedWriter(new FileWriter("D-small.out"));
			
			 String line = in.readLine();
			 int caseCount = Integer.parseInt(line);
			 
			 StringBuffer outputWriter = new StringBuffer();
			 
			 int roomHeight, roomWidth, D;
			 double visibility;
			 
			 for(int i = 1; i <= caseCount; i++){
				 line = in.readLine();
				 Scanner s = new Scanner(line);
				 roomHeight = s.nextInt();
				 roomWidth = s.nextInt();
				 D = s.nextInt();
				 visibility = ((double)D)/2;
				 
				 int reflectionCount = 0;
				 int cornerCount = 0;
				 
				 int row = -1, column = -1; //where you (the X) is located
				 
				 for(int j = 0; j < roomHeight; j++){
					 line = in.readLine();
					 
					 if(line.indexOf('X') != -1){
						 row = j;
						 column = line.indexOf('X');
					 }					 					 
				 }
				 
				 double h0 = row - 0.5; //distance to top wall
				 double h1 = roomHeight - 2 - h0; //distance to bottom wall
				 double w0 = column - 0.5; //distance to left wall
				 double w1 = roomWidth - 2 - w0; //distance to right wall
				 
				 ArrayList<Double> verticals;
				 ArrayList<Double> horizontals;

				 //count wall1
				 verticals = getWallSegmentLengths(visibility, h0, roomHeight - 2);
				 horizontals = getWallSegmentLengths(visibility, w0, roomWidth -2);
				 reflectionCount += pathCount(verticals, horizontals, visibility);

				 //count wall2
				 verticals = getWallSegmentLengths(visibility, h0, roomHeight - 2);
				 horizontals = getWallSegmentLengths(visibility, w1, roomWidth -2);
				 reflectionCount += pathCount(verticals, horizontals, visibility);
				 
				 //count wall3
				 verticals = getWallSegmentLengths(visibility, h1, roomHeight - 2);
				 horizontals = getWallSegmentLengths(visibility, w0, roomWidth -2);
				 reflectionCount += pathCount(verticals, horizontals, visibility);
				 
				 //count wall4
				 verticals = getWallSegmentLengths(visibility, h1, roomHeight - 2);
				 horizontals = getWallSegmentLengths(visibility, w1, roomWidth -2);
				 reflectionCount += pathCount(verticals, horizontals, visibility);

				 //add the straight reflections
				 if(w0 <= visibility)
				 	reflectionCount++;
				 if(h0 <= visibility)
						reflectionCount++;
				 if(w1 <= visibility)
						reflectionCount++;
				 if(h1 <= visibility)
					reflectionCount++;
				 
				 outputWriter.append("Case #" + i + ": ");
				 outputWriter.append(reflectionCount);
				 if(i != caseCount)
					 outputWriter.append("\n");
			 }

			 out.write(outputWriter.toString()); 
			 System.out.println(outputWriter.toString());
			 
			 in.close();
			 out.close();
		} catch(Exception e){
			//swallow the exception
		}		
	}
	
	//assumes verticals not null, horizontals not null
	public static int pathCount(ArrayList<Double> verticals, ArrayList<Double> horizontals, double maxLength){
		int legalPaths = 0;
		
		ArrayList<Double> collisionList = new ArrayList<Double>();
		double currentVertical, currentHorizontal;
		for(int i = 0; i < verticals.size(); i++){
			currentVertical = verticals.get(i);
			for(int j = 0; j < horizontals.size(); j++){
				currentHorizontal = horizontals.get(j);
				if(currentVertical * currentVertical + currentHorizontal * currentHorizontal <=  maxLength * maxLength){
					//System.out.println(currentVertical + ", " + currentHorizontal);
					
					if(collisionList.contains(currentHorizontal/currentVertical)){
						//collision, similar triangle
						//System.out.println("This reflection already exists");
					} else {
						collisionList.add(currentHorizontal/currentVertical);
						legalPaths++;
					}
				} else {
					break;
				}
			}
		}
		
		return legalPaths;
	}
	
	public static ArrayList<Double> getWallSegmentLengths(double maxSegmentLength, double side0, int roomSize){
		ArrayList<Double> wallSegmentList = new ArrayList<Double>();
		double currentSegment = side0;
		int segmentCount = 0;
		while(currentSegment <= maxSegmentLength){
			wallSegmentList.add(currentSegment);
			segmentCount++;
			
			if(segmentCount%2 == 0){
				currentSegment = segmentCount/2 * roomSize + side0;
			} else {
				currentSegment = (segmentCount + 1)/2 * roomSize;
			}
		}
		
		return wallSegmentList;
	}
	
}
