package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class QualD {	
	private static final int ThreadCheckTime = 2000;
	private static final int TreadCount = 10;
	private String inFileName = "F:\\codejam\\D-large.in";
	private String outFileNeme = "F:\\codejam\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;	
		int n;
		List<Double> a,b,c,d;
 		public TestCase(){
			n = getInt();
			a = new ArrayList<Double>(n);
			b = new ArrayList<Double>(n);
			for(int i=0;i<n;i++){
				a.add(getDouble());
			}
			for(int i=0;i<n;i++){
				b.add(getDouble());
			}
			Collections.sort(a);
			Collections.sort(b);
			c = new ArrayList<Double>(a);
			d = new ArrayList<Double>(b);			
		}		
		public void run(){
			int count=0;
			while(a.size()>0){
				double num = a.get(a.size()-1);
				if(num>b.get(b.size()-1)){
					count++;
					a.remove(a.size()-1);
					b.remove(0);
				}else if (num<b.get(0)){
					break;
				}else{
					int index=0;
					for(int j=0;j<b.size()-1;j++){
						if(num>b.get(j) && num<b.get(j+1)){
							index=j+1;
							break;
						}
					}
					a.remove(a.size()-1);
					b.remove(index);
				}
			}
			int count2=0;
			while(c.size()>0){
				if(c.get(c.size()-1)<d.get(d.size()-1)){
					c.remove(0);
					d.remove(d.size()-1);
				}else{
					count2++;
					c.remove(c.size()-1);
					d.remove(d.size()-1);
				}
			}
			result = new Integer(count2).toString() + " " + new Integer(count).toString();
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
	public QualD() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {e.printStackTrace();}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		QualD st = new QualD();
		st.execute();
		st.complete();
	}
}
