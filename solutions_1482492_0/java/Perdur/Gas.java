package main;

import java.util.Vector;
import java.io.*;

public class Gas {
	
	static int numberOfElementForEachTest = 0;
	static int numberOfLinesPerTest = 0;
	
	public static void main(String[] args) {
		Vector<Double> timesOtherCar = new Vector<Double>();
		Vector<Double> posOtherCar = new Vector<Double>();
		Vector<Double> speedOtherCar = new Vector<Double>();
		Vector<Double> accelerations = new Vector<Double>();
		numberOfElementForEachTest = 0;
		
		Reader.setFile("input.txt");
		Writer.setFile("output.txt");
		
		String s = Reader.readLine();
		int numberTest = Integer.parseInt(s);
		
		for (int i=0; i<numberTest; i++) {
			System.out.println("Test " + i);
			numberOfElementForEachTest = 0;
			timesOtherCar = new Vector<Double>();
			posOtherCar = new Vector<Double>();
			speedOtherCar = new Vector<Double>();
			accelerations = new Vector<Double>();
			double distance = 0;
			int numberOfAccelerations = 0;
			
			String s1 = "";
			s = Reader.readLine();
			
			s1 = s.substring(0, s.indexOf(" "));
			s=s.substring(s.indexOf(" ")+1);
			distance = Double.parseDouble(s1);
			
			s1 = s.substring(0, s.indexOf(" "));
			s=s.substring(s.indexOf(" ")+1);
			numberOfElementForEachTest = Integer.parseInt(s1);
			
			numberOfAccelerations = Integer.parseInt(s);
			
//			System.out.println(s);
			
			for (int j=0; j<numberOfElementForEachTest; j++) {
				s = Reader.readLine();
				s1 = s.substring(0, s.indexOf(" "));
				s=s.substring(s.indexOf(" ")+1);
				timesOtherCar.add(Double.parseDouble(s1));
				posOtherCar.add(Double.parseDouble(s));
				speedOtherCar.add(0.);
			}

			s = Reader.readLine();
			for (int j=0; j<numberOfAccelerations-1; j++) {
				s1 = s.substring(0, s.indexOf(" "));
				s=s.substring(s.indexOf(" ")+1);
				accelerations.add(Double.parseDouble(s1));
			}
			accelerations.add(Double.parseDouble(s));
			
			// calcul other car à 1000
			double lastPosition = 0;
			double lastTime = 0;
			int lastIndex = 0;
			boolean isFound = false;
			for (int j=0; j<timesOtherCar.size(); j++)
			{
				if (posOtherCar.get(j)<=distance)
				{
					isFound = true;
					lastPosition = posOtherCar.get(j);
					lastTime = timesOtherCar.get(j);
					lastIndex = j;
				}
			}
			
			if (isFound == false)
			{
				lastPosition = distance;
				posOtherCar.insertElementAt(distance, 0);
				timesOtherCar.insertElementAt(0., 0);
			}
			
			if (lastPosition < distance)
			{
				double speedAtLastPosition = (posOtherCar.get(lastIndex+1) - posOtherCar.get(lastIndex))/(timesOtherCar.get(lastIndex+1)-timesOtherCar.get(lastIndex));
				double timeAtLastPosition = lastTime + (distance -  lastPosition) /  speedAtLastPosition;
				posOtherCar.insertElementAt(distance, lastIndex+1);
				timesOtherCar.insertElementAt(timeAtLastPosition, lastIndex+1);
			}
			
			for (int j=0; j<timesOtherCar.size()-1; j++)
			{
				if (posOtherCar.get(j)<distance)
				{
					double speed = (posOtherCar.get(j+1) - posOtherCar.get(j))/(timesOtherCar.get(j)-timesOtherCar.get(j));
					speedOtherCar.set(j, speed);
				}
			}
			
			Writer.writeln("Case #" + (i+1) + ":");
			
			for (int k=0; k<accelerations.size(); k++)
			{
				// pour chaque position de other car, on regarde si on est devant ou derriere
				double currentSpeed = 0;
				double currentPosition = 0;
				double currentTime = 0;
				double acceleration = accelerations.get(k);
//				for (int j=0; j<posOtherCar.size() && currentPosition<distance; j++)
				for (int j=0; currentPosition<distance; j++)
				{
					double newTime = timesOtherCar.get(j);
					double newPosition = posOtherCar.get(j);
					double potentialPosition = currentPosition + currentSpeed * (newTime - currentTime) + 0.5*acceleration * (newTime-currentTime)*(newTime-currentTime);
					
					if (potentialPosition > newPosition) potentialPosition = newPosition;
					double elapsedTimeSinceDeparture = (Math.sqrt(currentSpeed*currentSpeed+2*acceleration*(potentialPosition-currentPosition))-currentSpeed)/acceleration;
					currentSpeed = currentSpeed + acceleration * (elapsedTimeSinceDeparture);
					currentPosition = potentialPosition;
					currentTime = newTime;
					
					System.out.println("at " + currentTime + ": position " + currentPosition + ", speed " + currentSpeed);
					
					if (j==posOtherCar.size()-1 )
					{
						// other car has arrived, finish
						// remaing time
						double remainingTime = (Math.sqrt(currentSpeed*currentSpeed+2*acceleration*(distance-currentPosition))-currentSpeed)/acceleration;
//						currentTime = currentTime + (distance -  currentPosition) /  currentSpeed;
						currentTime += remainingTime;
						currentPosition = distance;
						System.out.println("termine tout seul at " + currentTime + ": position " + distance);
					}
				}
				
				Writer.writeln(""+currentTime);
			}

		}
		Writer.close();

	}
	
	public static final class Reader 
	{
		static BufferedReader in;
		
		public static void setFile(String fichier) {
			File file = new File(fichier);
			try {
				in =  new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
			}
		}

		public static String readLine() {
			String line = null;
			try {
				line =  in.readLine();
			}
			catch (IOException e) {}
			
			return line;
		}
		
		public static String readAll() {
			String text = "";
			String line = "";
			while (line != null) {
				try {
					line = in.readLine();
				} 
				catch (IOException e) {
				}
				if (line != null) text += line + "\n";
			}
			return text;
		}
	}
	
	public static final class Writer 
	{
		static BufferedWriter out;
		
		public static void setFile(String file) {
			try{
				FileWriter fstream = new FileWriter(file);
				out = new BufferedWriter(fstream);
			}
			catch (Exception e){}
		}
		
		public static void write(String ligne) {
			try {
				out.write(ligne);
			}
			catch (Exception e){}
		}
		public static void writeln(String ligne) {
			try {
				out.write(ligne);
				out.write("\n");
			}
			catch (Exception e){}
		}

		public static void close() {
			try {
				out.close();
			}
			catch (Exception e){}
		}
	}
		
}
