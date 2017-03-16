package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class B {	
	private static final int ThreadCheckTime = 2000;
	private static final int TreadCount = 100;
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\inputB.in";
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\B-small-attempt0.in";
	private String inFileName = "H:\\Codejam\\src\\codejam2014\\B-large.in";
	private String outFileNeme = "H:\\Codejam\\src\\codejam2014\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;	
		long A,B,K;
		public TestCase(){
			A = getLong();
			B = getLong();
			K = getLong();			
		}		
		public void run(){
			if(A==K && B==K){
				Long l = new Long(K);
				BigInteger count = new BigInteger(l.toString());
				count = count.multiply(new BigInteger(new Long(K).toString()));
				result = count.toString();
			}
			if(K>A || K>B){
				Long l = new Long(A);
				BigInteger count = new BigInteger(l.toString());
				count = count.multiply(new BigInteger(new Long(B).toString()));
				result = count.toString();
			}else{
				Long l = new Long((A*B)-((A-K)*(B-K)));				
				BigInteger count = new BigInteger(l.toString());
				for (long i = K; i < A; i++) {
					for (long j = K; j < B; j++) {
						long num = i&j;
						if(num<K){
							count=count.add(BigInteger.ONE);
						}
					}
				}
				result = count.toString();
			}
		}
	}
	public void execute(){
		testCaseCount = getInt();
		System.out.println(testCaseCount + " cases");
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		}
		runParallel();
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
			System.out.println(op);
			writeLine(op);
		}
	}
	public void runParallel(){
		ExecutorService service = Executors.newFixedThreadPool(TreadCount);
		for(int i=0;i<testCaseCount;i++){service.execute(cases.get(i));}
		service.shutdown();
		while(true){if(service.isTerminated())break;
		try {Thread.sleep(ThreadCheckTime);} 
		catch (InterruptedException e) {e.printStackTrace();}
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
