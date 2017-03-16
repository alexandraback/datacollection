
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
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		String inputName;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter input file name: ");
		inputName = in.nextLine();
		StringBuilder output = new StringBuilder(1000);
		QueueMagic data = new QueueMagic(new FileReader(new File(inputName)));
		int caseNum =1;
		data.next();
		do {
			int N = data.nextInt();
			int S = data.nextInt();
			int P = data.nextInt();
			LinkedList<Integer> scores = new LinkedList<Integer>();
			for(int i = 0; i < N; i++)
				scores.add(data.nextInt());
			HashMap<Integer, HitScore> map = createMap(P);
			//int ans = DFS(map, scores, S, P);
			int ans = count(map, scores, S);
			String caseout = String.format("Case #%d: %d\n", caseNum++, ans);
			output.append(caseout);
			System.out.print(caseout);
			
		} while (data.isNotDepleted());
		
		//System.out.print(output);
		PrintWriter writer = new PrintWriter(new File(inputName+".output"));
		writer.print(output);
		writer.flush();
		writer.close();
	}
	
	public static int count(HashMap<Integer, HitScore> map, LinkedList<Integer> scores, int S)
	{
		int yes = 0;
		int surprise = 0;
		for(Integer score : scores)
		{
			HitScore hit = map.get(score);
			if(hit == HitScore.Yes)
				yes++;
			if(hit == HitScore.Surprise)
				surprise++;
		}
		if(surprise >= S)
			yes += S;
		else
			yes += surprise;
		return yes;
	}
	
	public static HashMap<Integer, HitScore> createMap(int P)
	{
		HashMap<Integer, HitScore> map = new HashMap<Integer, HitScore>();
		for(int i = 0; i <= 30; i++)
		{
			map.put(i, didit(i, P));
		}
//		int min = 3*P-4;
//		min = (int)Math.max(0, min);
//		int max = 3*P+4;
//		max = (int)Math.min(30, max);
//		for(int i = 0; i <= 30; i++)
//		{
//			if(i < min || i ==0)
//				map.put(i, HitScore.No);
//			else if(i > max)
//				map.put(i, HitScore.Yes);
//			else
//				map.put(i, HitScore.Surprise);
//		}
		return map;
	}
	
	public static HitScore didit(int score, int P)
	{
		//if(score >= 3*P-2)
		//	return HitScore.Yes;
		boolean foundSuprise = false;
		while(P <= 10 && P <= score)
		{
			if(score == 29)
				P = P;
			int rem = (int)Math.abs(P-score);
			
			for(int i = 0; i <= rem; i++)
			{
				int a = i;
				int b = rem - i;
				
				int r1 = (int)Math.abs(a-b);
				int r2 = (int)Math.abs(P-b);
				int r3 = (int)Math.abs(P-a);
				if( r1 <= 2 && r2 <= 2 && r3 <= 2 )
				{
					if(r1 < 2 && r2 < 2 && r3 < 2)
						return HitScore.Yes;
					foundSuprise = true;
				}
			}
			P++;
		}
		if(foundSuprise)
			return HitScore.Surprise;
		else
			return HitScore.No;
	}
	
	
	public static int DFS(HashMap<Integer, HitScore> map, LinkedList<Integer> scores, int S, int P )
	{
		if(scores.size() <= 0)
		{
			//if(S == 0)
				return 0;
			//else
			//	return Integer.MIN_VALUE;
		}
		Integer score = scores.removeFirst();
		
		HitScore hit = map.get(score);
		int max = Integer.MIN_VALUE;
		if(hit == HitScore.No)
			max = Math.max(max, 0+DFS(map,scores, S, P));
		else if(hit == HitScore.Surprise)
		{
			max = Math.max(max, 0+DFS(map,scores, S, P));
			if(S > 0)
				max = Math.max(max, 1+DFS(map,scores, S-1, P));
		}
		else if(hit == HitScore.Yes)
			max = Math.max(max, 1+DFS(map,scores, S, P));
		
		
		
		scores.addFirst(score);
		
		return max;
	}
}

enum HitScore { No, Surprise, Yes }



/**
 * Makes parsing input from Uva problems easy.
 */
class QueueMagic{
 
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
 public QueueMagic() throws IOException
 {
  this(new InputStreamReader(System.in), DEFAULT_DELIMITER);
 }
 
 /**
  * Build QueueMagic from any reader
  * Defaults to using the following delimiter: \\s+
  * @param reader
  * @throws IOException 
  */
 public QueueMagic(Reader reader) throws IOException
 {
  this(reader, DEFAULT_DELIMITER);
 }
 
 /**
  * Defaults to reading from System.in
  * @param delimiter
  * @throws IOException 
  */
 public QueueMagic(String regex) throws IOException
 {
  this(new InputStreamReader(System.in), regex);
 }
 
 public QueueMagic(Reader reader, String regex) throws IOException
 {
  this.in = new BufferedReader(reader);
  this.delimiter = regex;
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