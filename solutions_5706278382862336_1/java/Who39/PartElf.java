import java.util.*;
import java.io.*;
import java.math.*;
import java.util.concurrent.*;

public class PartElf implements Solution {
	private static final int MAX_THREAD_NUM = 3;
	private static final int RECHECK_TIME = 500;
	private static final Map<String, Callable<Datum>> cache = new HashMap<String, Callable<Datum>>();
	
	public int getMaxThreadNumber(){
		return MAX_THREAD_NUM;
	}
	
	public int getRecheckTime(){
		return RECHECK_TIME;
	}
	
	public Callable<Datum> createCallable(final BufferedReader input, int caseNum, long caseStartTime) throws IOException{
		Input datum = new Input(input, caseNum, caseStartTime);
		if(cache.containsKey(datum.getRawInputDatum())) return cache.get(datum.getRawInputDatum());
		return datum;
	}
	
	private static class Input implements Solution.Datum, Solution.Calculator, Callable<Datum> {
		private final Output output;
		private final long p,q;
        
        public Input(final BufferedReader input, int caseNum, long caseStartTime) throws IOException{
			this.output = new Output(caseNum, caseStartTime);
			StringBuilder builder = new StringBuilder(); 
			//parse input here
			String[] datum = getLine(input, "\\/", "require p/q", builder);
			p = Long.parseLong(datum[0]);
			q = Long.parseLong(datum[1]);
			this.output.setRawInputDatum(builder.toString()); 
        }
		
        private long gcd(long a, long b){
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(-1 * b, a);
            if (a == 0) return b == 0 ? 1 : b;
            if (b == 0 || a == b) return a;
            if (a < b) return gcd(a, b % a);
            return gcd(b, a % b);
        }
		
		private Long generationAgo(long p, long q){
			if(q == 0L) return null;
			if(p==1 && p == q) return 1L;
			if((q & 1L) == 1) return null;
			long c = gcd(p,q);
			p = p/c;
			q = q/c;
			boolean found = false;
			for(long i = 1L; i <= 40L; i++){
				long v = 1L << i;
				if(v == q) found = true;
			}
			if(!found) return null;
			for(long i = 1L; i <= 40L; i++){
				long v = q >> i;
				if(p>=v) return i;
			}
			return null;
		}
		
		private void compute(){
			//Algorithm to compute goes here
			String result = null;
			Long ago = generationAgo(p, q);
			if(ago == null) result = "impossible";
			else result = Long.toString(ago);
			output.setResult(result);
		}
		
		public Datum getResult(){
			if(output.requireComputingResult()) compute();
			return output;
		}
		
		private static String getLine(final BufferedReader input, String errorMsg, StringBuilder builder) throws IOException {
            preCondition(input.ready(), errorMsg);
			String line = input.readLine();
			builder.append(line).append("\n");
            //System.out.println(line);
			return line;
		}
		
        private static String[] getLine(final BufferedReader input, String delimit, String errorMsg, StringBuilder builder) throws IOException {
            return getLine(input, errorMsg, builder).split(delimit);
        }
		
		private static void preCondition(boolean condition, String errorMsg){
			if(!condition) throw new IllegalArgumentException(errorMsg);
		}
		
		@Override
		public Datum call() throws Exception {
			return getResult();
		}
        
        public List<String> getLines(){
            List<String> result = new ArrayList<String>();
            result.add(this.toString());
            return result;
        }
		
		public long getStartTime(){
			return output.getStartTime();
		}
        
        @Override
        public String toString(){
            return getRawInputDatum();
        }

		public boolean containAResult(){
			return output.containAResult();
		}
		
		public String getRawDatum(){
			return getRawInputDatum();
		}
		
		public String getRawInputDatum(){
			return output.getRawInputDatum();
		}
	}
    
    private static class Output implements Solution.Datum {
		private static final double PRECISION_FACTOR = 10e7;
		private final StringBuilder debugBuilder;
		private boolean hasResult;
		private boolean hasRawInputDatum;
		private int caseNum;
		private long startTime;
		private String rawInputDatum;
        private String result;
		
		private static String getRoundedString(double result){
			double data = Math.round(result * PRECISION_FACTOR) / PRECISION_FACTOR;
			double factor = PRECISION_FACTOR;
			int precision = 0;
			while(factor > 0){
				factor=(factor - (factor % 10))/10;
				precision++;
			}
			String format = new StringBuilder().append("%.").append(precision).append("f").toString();
			return String.format(format, data);
		}
		
        public Output(int caseNum, long startTime){
			this.caseNum = caseNum;
			this.startTime = startTime;
			this.debugBuilder = new StringBuilder();
			this.hasRawInputDatum = false;
			this.hasResult = false;
			this.rawInputDatum = null;
			this.result = null;
        }
		
        public Output(String rawInputDatum, int caseNum, long startTime){
			this.caseNum = caseNum;
			this.rawInputDatum = rawInputDatum;
			this.startTime = startTime;
			this.debugBuilder = new StringBuilder();
			this.hasRawInputDatum = true;
			this.hasResult = false;
			this.result = null;
        }
		
		public boolean requireComputingResult(){
			return !hasResult;
		}
		
		public void appendDebugInfoLine(int info){
			debugBuilder.append(info).append("\n");
		}
		
		public void appendDebugInfo(int info){
			debugBuilder.append(info);
		}
		
		public void appendDebugInfoLine(long info){
			debugBuilder.append(info).append("\n");
		}
		
		public void appendDebugInfoLine(double info){
			debugBuilder.append(info).append("\n");
		}
		
		public void appendDebugInfo(double info){
			debugBuilder.append(info);
		}
		
		public void appendDebugInfo(long info){
			debugBuilder.append(info);
		}
		
		public void appendDebugInfoLine(String info){
			debugBuilder.append(info).append("\n");
		}
		
		public void appendDebugInfo(String info){
			debugBuilder.append(info);
		}
		
		public void setRawInputDatum(String rawInputDatum){
			if(!this.hasRawInputDatum) updateRawInputDatum(rawInputDatum);
		}
		
		public void updateRawInputDatum(String rawInputDatum){
			this.rawInputDatum = rawInputDatum;
			this.hasRawInputDatum = true;
		}
		
		public void setResult(String result){
			if(!hasResult) updateResult(result);
		}
		
		public void updateResult(String result){
			System.out.println("\nCase #" + caseNum + ": " + result);
			this.result = result;
			this.hasResult = true;
		}
        
        public List<String> getLines(){
            List<String> result = new ArrayList<String>();
            result.add(this.toString());
            return result;
        }
        
        @Override
        public String toString(){
            return new StringBuilder().append(result).toString();
        }
		
		public long getStartTime(){
			return startTime;
		}

		public boolean containAResult(){
			return hasResult;
		}
		
		public String getRawDatum(){
			StringBuilder builder = new StringBuilder();
			builder.append("Case ").append(caseNum).append(":\n");
			builder.append("Input:\n").append(rawInputDatum).append("\n");
			builder.append("Debug Info:\n").append(debugBuilder.toString()).append("\n");
			builder.append("Result:\n").append(this.toString());
			return builder.toString();
		}
		
		public void printToScreen(int caseNum){
			if(this.caseNum == caseNum){
				printToScreen();
			}
		}
		
		public void printToScreen(){
			System.out.println(getRawDatum());
		}
		
		public String getRawInputDatum(){
			return rawInputDatum;
		}
		
		public int getCaseNum(){
			return caseNum;
		}
    }
}