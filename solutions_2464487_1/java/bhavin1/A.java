import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class A {

	Scanner in;
	//BufferedReader in;
	BufferedWriter out ;
	
	public A() throws IOException {
		in = new Scanner(new File("C:\\Bhavin\\workspace\\Test\\src\\prob.in"));
		//in = new BufferedReader(new FileReader("C:\\Bhavin\\workspace\\Test\\src\\prob.in"));

		out = new BufferedWriter(new FileWriter("C:\\Bhavin\\workspace\\Test\\src\\prob.out"));
	}
	public void solve() throws IOException{
		
		int numCases = in.nextInt();
		//int numCases = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= numCases; i++) {
			runCase(i);
		}
		out.close();in.close();
	}
	private void runCase(int caseNum) throws IOException {
		
		BigInteger two = new BigInteger("2");
		BigInteger diam = in.nextBigInteger().multiply(two);
		BigInteger paint=in.nextBigInteger();
		
		BigInteger one = new BigInteger("1");
		BigInteger r2 = new BigInteger("0");
		BigInteger ptreqd = new BigInteger("0");
		
		
		BigInteger rings=new BigInteger("1");
		
		BigInteger ringsLow = new BigInteger("1");
		BigInteger ringshigh = paint.divide(new BigInteger("2"));
		boolean exact = false;
		while(true) {
			
			if(ringsLow.compareTo(ringshigh) >=0) 
				break;
			rings = ringsLow.add(ringshigh.subtract(ringsLow).divide(two));
			ptreqd = rings.multiply(rings).multiply(two).subtract(rings).add(rings.multiply(diam));
			
			if(ptreqd.compareTo(paint) > 0) {
				if(ringshigh.compareTo(rings) ==0) {
					ringshigh=ringshigh.subtract(one);
				} else {
					ringshigh = rings;
				}
				
			} else if (ptreqd.compareTo(paint) < 0) {
				if(ringsLow.compareTo(rings) ==0) {
					ringsLow=ringsLow.add(one);
				} else {
					ringsLow = rings;
				}
			} else if (ptreqd.compareTo(paint) == 0) {
				exact=true;
				break;
			}
		
			
		}
		
		if(exact) {
			output(out, caseNum, rings.toString());
		} else {
			ptreqd = rings.multiply(rings).multiply(two).subtract(rings).add(rings.multiply(diam));
			if(ptreqd.compareTo(paint) > 0) {
				
				rings = rings.subtract(one);
				ptreqd = rings.multiply(rings).multiply(two).subtract(rings).add(rings.multiply(diam));
				if(ptreqd.compareTo(paint) <= 0) {
					output(out, caseNum, rings.toString());
				} else {
					output(out, caseNum, rings.subtract(one).toString());
				}
				
			} else if(ptreqd.compareTo(paint) < 0){
				
				rings = rings.add(one);
				ptreqd = rings.multiply(rings).multiply(two).subtract(rings).add(rings.multiply(diam));
				if(ptreqd.compareTo(paint) <= 0) {
					output(out, caseNum, rings.toString());
				} else {
					output(out, caseNum, rings.subtract(one).toString());
				}
				
			} else {
				output(out, caseNum, rings.toString());
			}
		}
		//if (ptused.compareTo(paint) >0) 
			//rings--;
		
		//output(out, caseNum, rings);
	}
	
	ArrayList<Integer> keysOut;
	int stars =0;
	int levplayed=0;
	String result;

	class Container implements Comparable<Container> {
		ArrayList keys;
		boolean opened;
		Integer order;
		int key;
		Integer sameKeyCount;

		public Container(int ord, int pkey) {
			order=ord;
			opened=false;
			key=pkey;
			sameKeyCount=0;
			keys=new ArrayList();
			
			
		}

		@Override
		public int compareTo(Container o) {
			
			if(key==o.key) {
				
				if(Collections.frequency(keysOut, key) > 1) {
					return o.order.compareTo(order);
				}
				
				if(sameKeyCount > 0 && o.sameKeyCount > 0) {
					return o.order.compareTo(order);
				}
				if(sameKeyCount.equals(o.sameKeyCount)) {
					return o.order.compareTo(order);
				} else {
					return sameKeyCount.compareTo(o.sameKeyCount);
				}
			} else {
				return o.order.compareTo(order);
			}
				
		}
	}
	
	private void openChest(Container openchest, ArrayList<Integer> keysOut) {
		openchest.opened=true;
		keysOut.remove(new Integer(openchest.key));
		keysOut.addAll(openchest.keys);
		result = result  + openchest.order + " ";
		
	}
	private void createContainer(ArrayList<Container> chests, Scanner in, int ord) {
		Container c = new Container(ord, in.nextInt());
		int kcnt = in.nextInt();
		
		for(int j=1; j<=kcnt; j++) {
			int key=in.nextInt();
			if (c.key==key) {
				c.sameKeyCount++;
			}
			c.keys.add(key);
		}
		
		chests.add(c);
	}
	

	public static void main(String[] args) throws IOException{
		A s = new A();
		s.solve();
		
	}
	
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}


}


