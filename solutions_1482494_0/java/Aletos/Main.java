
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static StringBuilder output = new StringBuilder("");
	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the name of the input file: ");
		String inputFileName = in.nextLine();
		String outputFileName = inputFileName + ".out";
		InputQueue input = new InputQueue(new FileReader(new File(inputFileName) ), "[\n\r]+");
		int numCases = input.nextInt();
		int caseNum = 1;
		do
		{
			int numLevels = input.nextInt();
			ArrayList<Level> levels = new ArrayList<Level>();
			for(int i = 0; i < numLevels; i++)
			{
				Level level = new Level();
				Integer [] reqs = input.arrayInt();
				level.oneStarReq = reqs[0];
				level.twoStarReq = reqs[1];
				levels.add(level);
			}
			String ans = solve(levels);
			print(String.format("Case #%d: ", caseNum++));
			print(ans + "\n");
//			int min = solve(levels, 0, 0, levels.size()*2 );
			/*print(String.format("Case #%d: ", caseNum++));
			if(min == Integer.MAX_VALUE)
				print("Too Bad\n");
			else
				print(String.valueOf(min)+"\n");*/
		}while(input.isNotDepleted());
		
		PrintWriter writeOutput = new PrintWriter(new File(outputFileName));
		writeOutput.print(output.toString());
		writeOutput.close();
	}
	
	
	public static String solve(ArrayList<Level> levels)
	{
		int completed = 0;
		int stars = 0;
		
		while(!levels.isEmpty())
		{
			for(int i = 0; i < levels.size(); i++)
			{
				Level level = levels.get(i);
				if(stars >= level.twoStarReq)
				{
					stars += 2 - level.starsGiven;
					levels.remove(i);
					i = -1;
					completed++;
				}
				
			}
			Level bestChoice = null;
			for(int i = 0; i < levels.size(); i++)
			{
				Level level = levels.get(i);
				if( stars >= level.oneStarReq && level.starsGiven == 0)
				{
					if(bestChoice == null ||  level.twoStarReq > bestChoice.twoStarReq)
						bestChoice = level;	
				}
			}
			if(bestChoice != null && stars >= bestChoice.oneStarReq && bestChoice.starsGiven == 0)
			{
				stars++;
				bestChoice.starsGiven = 1;
				completed++;
			}
			else
				break;
		}
		
		if(levels.size() == 0)
			return String.valueOf(completed);
		else
			return "Too Bad";
	}
	
//	public static int solve(ArrayList<Level> levels, int stars, int levelsCompleted, int needed)
//	{
//		if(stars == needed)
//		{
//			return levelsCompleted;
//		}
//		else if(levels.isEmpty())
//			return -1;
//		int min = Integer.MAX_VALUE;
//		for(int i = 0; i < levels.size(); i++ )
//		{
//			Level level = levels.get(i);
//			if(stars >= level.twoStarReq)
//			{
//				levels.remove(i);
//				min = Math.min(min, solve(levels, stars + 2-level.starsGiven, levelsCompleted+1, needed ));
//				levels.add(i, level);
//			}
//			else if(stars >= level.oneStarReq && level.starsGiven == 0)
//			{
//				level.starsGiven = 1;
//				min = Math.min(min, solve(levels, stars+1, levelsCompleted+1, needed));
//				level.starsGiven = 0;
//			}
//		}
//		return min;
//		
//	}
	
	public static void print( String s)
	{
		System.out.print(s);
		output.append(s);
	}
}

class Level implements Comparable<Level>
{
	public int oneStarReq;
	public int twoStarReq;
	public int starsGiven = 0;
	@Override
	public int compareTo(Level o) {
		return this.oneStarReq - o.oneStarReq;
	}
	@Override
	public String toString() {
		return "Level [oneStarReq=" + oneStarReq + ", twoStarReq=" + twoStarReq
				+ ", starsGiven=" + starsGiven + "]";
	}
}


class InputQueue{
 
 private Queue<String> data;
 private BufferedReader in;
 private String delimiter;
 private String secondary_delimiter;
 /**
  * The default delimiter is \\s+
  * This is at least one or more white space characters
  */
 public final static String DEFAULT_DELIMITER = "\\s+";
 public final static String DEFUALT_SECONDARY_DELIMITER = "\\s+";
 /**
  * Defaults to reading System.in
  * Defaults to using the following delimiter:  \\s+
  * @throws IOException
  */
InputQueue() throws IOException
 {
  this(new InputStreamReader(System.in), DEFAULT_DELIMITER);
 }
 
 /**
  * Build QueueMagic from any reader
  * Defaults to using the following delimiter: \\s+
  * @param reader
  * @throws IOException
  */
InputQueue(Reader reader) throws IOException
 {
  this(reader, DEFAULT_DELIMITER);
 }
 
 /**
  * Defaults to reading from System.in
  * @param delimiter
  * @throws IOException
  */
InputQueue(String regex) throws IOException
 {
  this(new InputStreamReader(System.in), regex);
 }
 
InputQueue(Reader reader, String regex) throws IOException
 {
  this.in = new BufferedReader(reader);
  this.delimiter = regex;
  this.secondary_delimiter = DEFUALT_SECONDARY_DELIMITER;
  readData();
 }
 
 
 /**
  * Reads in all bytes in the stream and splits it into string tokens based on the delimiter.
  * @throws IOException
  */
 private void readData() throws IOException
 {
  CharBuffer buf = CharBuffer.allocate(10000);
  StringBuilder input = new StringBuilder(10000);
  do
  {
   this.in.read(buf);
   input.append(buf.flip().toString());
  }while(this.in.ready());
  String [] parts = input.toString().split(this.delimiter);
  this.data = new LinkedList<String>(Arrays.asList(parts));
  close();
 }
 
 /**
  * Returns the next string
  * @return
  */
 public String next()
 {
  return data.poll();
 }
 
 public Integer nextInt()
 {
  return Integer.parseInt(next());
 }
 
 public Short nextShort()
 {
  return Short.parseShort(next());
 }
 
 public Byte nextByte()
 {
  return Byte.parseByte(next());
 }
 
 public Long nextLong()
 {
  return Long.parseLong(next());
 }
 
 public Float nextFloat()
 {
  return Float.parseFloat(next());
 }
 
 public Double nextDouble()
 {
  return Double.parseDouble(next());
 }
 
 public BigInteger nextBigInt()
 {
  return new BigInteger(next());
 }
 
 public BigDecimal nextBigDec()
 {
  return new BigDecimal(next());
 }
 
 /**
  * Returns the next token split by the secondary delimiter.
  * @return
  */
 public String [] arrayString()
 {
  return next().split(this.secondary_delimiter);
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Byte [] arrayByte()
 {
  String [] parts = arrayString();
  Byte [] vals = new Byte[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Byte.parseByte(parts[i]);
  }
  return vals;
 }
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Short [] arrayShort()
 {
  String [] parts = arrayString();
  Short [] vals = new Short[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Short.parseShort(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Integer [] arrayInt()
 {
  String [] parts = arrayString();
  Integer [] vals = new Integer[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Integer.parseInt(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Long [] arrayLong()
 {
  String [] parts = arrayString();
  Long [] vals = new Long[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Long.parseLong(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Float [] arrayFloat()
 {
  String [] parts = arrayString();
  Float [] vals = new Float[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Float.parseFloat(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public Double [] arrayDouble()
 {
  String [] parts = arrayString();
  Double [] vals = new Double[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = Double.parseDouble(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public BigInteger [] arrayBigInteger()
 {
  String [] parts = arrayString();
  BigInteger [] vals = new BigInteger[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = new BigInteger(parts[i]);
  }
  return vals;
 }
 
 /**
  * Split by the secondary delimiter
  * @return
  */
 public BigDecimal[] arrayBigDecimal()
 {
  String [] parts = arrayString();
  BigDecimal [] vals = new BigDecimal[parts.length];
  for (int i = 0; i < vals.length; i++) {
   vals[i] = new BigDecimal(parts[i]);
  }
  return vals;
 }
 
 public ArrayList<String> listString()
 {
  return new ArrayList<String>(Arrays.asList(arrayString()));
 }
 
 public ArrayList<Byte> listByte()
 {
  return new ArrayList<Byte>(Arrays.asList(arrayByte()));
 }
 
 public ArrayList<Short> listShort()
 {
  return new ArrayList<Short>(Arrays.asList(arrayShort()));
 }
 
 public ArrayList<Integer> listInt()
 {
  return new ArrayList<Integer>(Arrays.asList(arrayInt()));
 }
 
 public ArrayList<Long> listLong()
 {
  return new ArrayList<Long>(Arrays.asList(arrayLong()));
 }
 
 public ArrayList<Float> listFloat()
 {
  return new ArrayList<Float>(Arrays.asList(arrayFloat()));
 }
 
 public ArrayList<Double> listDouble()
 {
  return new ArrayList<Double>(Arrays.asList(arrayDouble()));
 }
 
 public ArrayList<BigInteger> listBigInteger()
 {
  return new ArrayList<BigInteger>(Arrays.asList(arrayBigInteger()));
 }
 
 public ArrayList<BigDecimal> listBigDecimal()
 {
  return new ArrayList<BigDecimal>(Arrays.asList(arrayBigDecimal()));
 }
 
 
 /**
  * @return true if there is no more data
  */
 public boolean isDepleted()
 {
  return this.data.isEmpty();
 }
 
 /**
  *
  * @return true if there is data
  */
 public boolean isNotDepleted()
 {
  return !isDepleted();
 }
 
 /**
  * The primary delimiter is used to split the data into tokens
  * @return
  */
 public String getDelimter()
 {
  return this.delimiter;
 }
 
 /**
  * The primary delimiter is used to split the data into tokens
  * @param regex
  */
 public void setDelimiter(String regex)
 {
  this.delimiter = regex;
 }
 
 /**
  * The secondary delimiter is used to split tokens into lists/arrays
  * @return
  */
 public String getSecondaryDelimiter()
 {
  return this.secondary_delimiter;
 }
 
 /**
  * The secondary delimiter is used to split tokens into lists/arrays
  * @param regex
  */
 public void setSecondaryDelimiter(String regex)
 {
  this.secondary_delimiter = regex;
 }
 
 public void close() throws IOException
 {
  if(this.in != null)
  {
   in.close();
  }
 }
}
