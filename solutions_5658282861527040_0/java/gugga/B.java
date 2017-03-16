package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class B {	
	private static final int ThreadCheckTime = 2000;
	private static final int TreadCount = 10;
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\inputB.in";
	private String inFileName = "H:\\Codejam\\src\\codejam2014\\B-small-attempt0.in";
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\B-large.in";
	private String outFileNeme = "H:\\Codejam\\src\\codejam2014\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;	
		int A,B,K;
		public TestCase(){
			A = getInt();
			B = getInt();
			K = getInt();			
		}		
		public void run(){
			int[] arr = new int[3];
			BigInteger count = BigInteger.ZERO;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					int num = i&j;
					if(num<K){
						count=count.add(BigInteger.ONE);
					}
				}
			}
			result = count.toString();
		}
	}	
	public void execute(){
		testCaseCount = getInt();
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		}
		runSerial();
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
			writeLine(op);
		}
	}	
	public void runSerial(){
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			cs.run();
		}
	}
	public TestCase getCase(){
		return new TestCase();
	}	
	public void writeLine(String line){outSc.format(line+'\n');}
	public String nextLine(){return inSc.nextLine();}
	public String getWord(){return inSc.next();}	
	public Integer getInt(){return inSc.nextInt();}	
	public Double getDouble(){return inSc.nextDouble();}	
	public Long getLong(){return inSc.nextLong();}	
	public BigInteger getBigInt(){return  new BigInteger(getWord());}	
	public BigDecimal getBigDecimal(){return  new BigDecimal(getWord());}
	public void closeOutputFile(){outSc.flush();outSc.close();}	
	Scanner inSc;
	Formatter outSc;	
	public B() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {e.printStackTrace();}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		B st = new B();
		st.execute();
		st.complete();
	}
}
