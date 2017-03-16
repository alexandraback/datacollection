
import java.io.BufferedReader;
import java.io.File;
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
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Main {
	public static HashMap<String, HashSet<String>> mem = new HashMap<String, HashSet<String>>();
	public static void main(String[] args) throws IOException {
		String inputName;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter input file name: ");
		inputName = in.nextLine();
		StringBuilder output = new StringBuilder(1000);
		QueueMagic data = new QueueMagic(new FileReader(new File(inputName)));
		int caseNum =1;
		data.next();
		do {
			int A = data.nextInt();
			int B = data.nextInt();
			ArrayList<String> recycled = new ArrayList<String>();
			for(int i = A; i <= B; i++)
			{
				String s = String.valueOf(i);
				recycled.addAll(findRecyled(s, i, B));
			}
			String caseout = String.format("Case #%d: %d\n", caseNum++, recycled.size());
			output.append(caseout);
			System.out.print(caseout);
			
		} while (data.isNotDepleted());
		
		//System.out.print(output);
		PrintWriter writer = new PrintWriter(new File(inputName+".output"));
		writer.print(output);
		writer.flush();
		writer.close();
	}
	
	public static HashSet<String> findRecyled(String s, int n, int B)
	{
		//if(mem.containsKey(s))
		//	return mem.get(s);
		HashSet<String> ans = new HashSet<String>();
		for(int i = 0; i < s.length()-1; i++)
		{
			String r = s.substring(i+1)+s.substring(0, i+1);
			int m = Integer.parseInt(r);
			if(n < m && m <= B)
				ans.add(r);
		}
		mem.put(s, ans);
		return ans;
	}
}




/**
 * Makes parsing input from Uva problems easy.
 * @author Adam Anderson
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