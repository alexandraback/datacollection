package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class QualB {	
	private static final int ThreadCheckTime = 2000;
	private static final int TreadCount = 10;
	private String inFileName = "F:\\codejam\\B-large.in";
	private String outFileNeme = "F:\\codejam\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;	
		double C,F,X;
		public TestCase(){
			C=getDouble();
			F=getDouble();
			X=getDouble();
		}		
		public void run(){
			List<Double> l = new ArrayList<Double>();
			double previous = X/2;
			double cost = 0;
			double rate = 2.0;
			double result;
			while(true){
				result = cost + X/rate;
				if(result>previous)break;
				else previous=result;
				cost = cost + C/rate;
				rate = rate + F;
			}
			this.result= String.format("%.7f", previous);
		}
	}	
	public void execute(){
		testCaseCount = getInt();
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		}
		runParallel();
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
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
	public Integer getInt(){return inSc.nextInt();}	
	public Double getDouble(){return inSc.nextDouble();}
	public void closeOutputFile(){outSc.flush();outSc.close();}	
	Scanner inSc;
	Formatter outSc;	
	public QualB() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {e.printStackTrace();}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		QualB st = new QualB();
		st.execute();
		st.complete();
	}
}
