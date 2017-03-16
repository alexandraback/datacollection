package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

import tools.Tools;

public class CoinJam {
	long maxFactor = 100;
	public static void main(String[] args) throws IOException {
		CoinJam t = new CoinJam();
		//Tools.println(t.getValue(4294967296L,10));
		//t.test();
	     t.solve();
	}
	void test(){
		long[] p2 = Tools.power2(32);
		long max = p2[32]-1;
		Tools.println(getValue(max,9));
		Tools.println(Long.MAX_VALUE);
		int N=32;
		int J=500;
		String si = getOutput(N,J);
		Tools.println(si);
	}
	public void solve() throws IOException{
		String inputFile = Tools.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = Tools.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){
			int[] NJ = Tools.intArray(in.readLine(), " ");
			int N = NJ[0];
			int J = NJ[1];
			String s = getOutput(N,J);
			String output = "Case #"+caseN + ":"+s;
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	String getOutput(int N, int J){
		long[] p2 = Tools.power2(N);
		long min = p2[N-1]+1;
		long max = p2[N] - 1;
		long value = min;
		int count = 0;
		String s = "";
		while(count < J){
			BigInteger[] list = getValueList(value);
			long[] factors = factorList(list);
			if(factors!=null){
				count++;
				//Tools.println(count);
				s += "\n" + Long.toBinaryString(value) ;
				for(int i=2;i<=10;i++){
					s += " " + factors[i];
				}
			}
			if(count == J){
				return s;
			}
			value = value + 2;
			if(value > max)
				break;
		}
		return "";
	}
	long[] factorList(BigInteger[] list){
		long[] factors = new long[11];
		for(int base=2;base<=10;base++){
			BigInteger bi = list[base];
			long f = getFirstFactor(bi);
			if(f==0)
				return null;
			factors[base] = f;
		}
		return factors;
	}
	long getFirstFactor(BigInteger b){
		BigInteger factor = new BigInteger("2");
		if(b.mod(factor).longValue() == 0){
			return factor.longValue();
		}
		factor = factor.add(new BigInteger("1"));
		while(factor.longValue() < maxFactor){
			if(b.mod(factor).longValue() == 0){
				return factor.longValue();
			}
			factor = factor.add(new BigInteger("2"));
		}
		return 0;
	}
	BigInteger[] getValueList(long value){
		BigInteger[] x = new BigInteger[11];
		x[2] = new BigInteger(value+"");
		for(int i=3;i<=10;i++){
			x[i] = getValue(value,i);
		}
		return x;
	}
	BigInteger getValue(long value,int base){
		String s = Long.toBinaryString(value);
		int L = s.length();
		BigInteger result = new BigInteger("0");
		BigInteger power = new BigInteger("1");
		BigInteger bbase = new BigInteger(base+"");
		for(int i=L-1;i>=0;i--){
			char c = s.charAt(i);
			BigInteger v = c=='1'? new BigInteger("1"): new BigInteger("0");
			result = result.add(v.multiply(power));
			power = power.multiply(bbase);
		}
		return result;
	}

}
