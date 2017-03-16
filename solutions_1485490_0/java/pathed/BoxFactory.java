package se.pathed.codejam.practice.boxfactory;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;

public class BoxFactory {
	
	public BufferedReader getInputReader(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File f = new File(dataFolder + fileName);
		FileReader fReader = new FileReader(f);
		BufferedReader reader = new BufferedReader(fReader);
		
		return reader;
	}
	
	public PrintWriter getOutputWriter(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File outputFile = new File(dataFolder + fileName);
		if( outputFile.exists()) outputFile.delete();
		return new PrintWriter(outputFile);
	}


	public static void main(String[] args) throws IOException {
		new BoxFactory().run();

	}
	
	static class Entity{
		int id;
		long count;
	}
	
	static class Problem {
		Entity[] toys;
		Entity[] boxes;
	}
	
	Problem parseProblem() throws IOException{
		Problem p = new Problem();
		
		String[] line = reader.readLine().split(" ");
		int boxesCount = Integer.parseInt(line[0]);
		int toysCount = Integer.parseInt(line[1]);
		
		line = reader.readLine().split(" ");
		int counter = 0;
		p.boxes = new Entity[boxesCount];
		for( int i = 0; i < line.length; i+=2){
			Entity e = new Entity();
			e.count = Long.parseLong(line[i]);
			e.id = Integer.parseInt(line[i+1]);
			p.boxes[counter] = e;
			counter++;
		}
		
		line = reader.readLine().split(" ");
		counter = 0;
		p.toys = new Entity[toysCount];
		for( int i = 0; i < line.length; i+=2){
			Entity e = new Entity();
			e.count = Long.parseLong(line[i]);
			e.id = Integer.parseInt(line[i+1]);
			p.toys[counter] = e;
			counter++;
		}
		
		return p;
	}
	
	BufferedReader reader;
	void run() throws IOException{
		reader = getInputReader("C-small-attempt2.in");
		PrintWriter writer = getOutputWriter("out.txt");
		
		int cases = Integer.parseInt(reader.readLine());
		for( int i = 0; i < cases; i++){
			Problem p = parseProblem();
			
			BigInteger res = solve(p);
			writer.println("Case #" + (i+1) + ": " + res.toString());
		}
		writer.flush();
		writer.close();
	}
	
	BigInteger bestValue;
	Problem currP;
	BigInteger solve(Problem p){
		bestValue = BigInteger.valueOf(-1);
		currP = p;
		
		takeBox(0,0,0,0,BigInteger.ZERO);
		if( bestValue.equals(BigInteger.valueOf(-1)) ){
			return BigInteger.ZERO;
		} else if(  bestValue.compareTo(BigInteger.ZERO) == -1){
			throw new RuntimeException("Rollover occured");
		}
		else {
			return bestValue;
		}
	}
	
	long pack(long boxes, long toys){
		if(boxes > toys) return toys;
		else return boxes;
	}
	
	void takeBox(int boxIndex, int toyIndex, long takenBox, long takenToy, BigInteger packed){
		if( boxIndex >= currP.boxes.length || toyIndex >= currP.toys.length){
			// End reached
			if( packed.compareTo(bestValue) == 1){
				bestValue = packed;
			}
			return;
		}
		Entity box = currP.boxes[boxIndex];
		Entity toy = currP.toys[toyIndex];
//		takeBox(boxIndex+1, toyIndex, 0, takenToy, packed);
		if(box.id == toy.id){
			long canPack = pack( box.count - takenBox, toy.count - takenToy);
			if( box.count - takenBox - canPack > 0){
				takeBox(boxIndex, toyIndex + 1, takenBox+canPack, 0, packed.add(BigInteger.valueOf(canPack)) );
			}
			else if( toy.count - takenToy - canPack > 0){
				takeBox(boxIndex + 1, toyIndex, 0, takenToy + canPack, packed.add(BigInteger.valueOf(canPack)));
			} else {
				takeBox(boxIndex + 1, toyIndex + 1, 0, 0, packed.add(BigInteger.valueOf(canPack)));
			}
		}
		else {
			if(box.count - takenBox > 0){
				takeBox(boxIndex, toyIndex + 1, takenBox, 0, packed);
			} 
			takeBox(boxIndex + 1, toyIndex, 0, takenToy, packed);
		}
	}
}
