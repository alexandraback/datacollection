
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
public class CodeJamProblemR1C {

	static class State {
		String input;
		int level;
		public State(String in,int l){
			input = in;
			level = l;
		}
	}
	public static void main(String[] args) {
		File file = new File("input2.txt");
		try {
			Parser in = new Parser(new FileInputStream(file));
			PrintWriter out = new PrintWriter("output2.txt");
			int T = in.nextInt();
			for (int i = 0; i < T; i++) {
				int n = in.nextInt();
				int[] bff = new int[n];
				for(int j = 0;j<n;j++){
					bff[j] = in.nextInt()-1;
				}
				Object[] output = new Object[]{-1,null};
				int first = 0;
				for(int j =0;j<n;j++){
					HashSet<Integer> set = new HashSet<>();
					set.add(j);
					String s = "" + j;
					Object[] temp = getMax(bff,j,set,j,s);

					if((Integer)temp[0] > (Integer)output[0]){
						output = temp;
						first = j;
					}
					set.remove(j);
				}

				out.println("Case #"+(i+1)+": "+output[0]);
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	static Object[] getMax(int[] bff,int i,HashSet<Integer> set,int first,String s){
		//System.out.println(first + ":  "+s);
		if(bff[i] == first){
			//System.out.println(s);
			return new Object[]{set.size(),s};
		}
		Object[] max = new Object[]{-1,s};
		int tempMax = 0;
		if(bff[bff[i]] == i){
			set.add(bff[i]);
			max = new Object[]{set.size(),s};
			s = s + " " + bff[i];
			for(int j = 0;j<bff.length;j++){
				if(!set.contains(j)){
					if((!set.contains(bff[j]) && bff[bff[j]] == j) || bff[j] == bff[i]){
						set.add(j);
						Object[] temp = getMax(bff,j,set,first,s+" "+j);
						if(tempMax < (Integer)temp[0]){
							tempMax = (Integer)temp[0];
							max = temp;
						}
						set.remove(j);
					}
				}
			}
			set.remove(bff[i]);
			//System.out.println(set);
			return max;
		}
		if(set.contains(bff[i])){
			if(bff[bff[first]] == first){
				return new Object[]{set.size(),s};
			}
			for(int j = 0;j<bff.length;j++){
				if(!set.contains(j)){
					if(bff[j] == first){
						return new Object[]{set.size() + 1,s+" "+j};
					}
				}
			}
			//System.out.println("end  "+s);
			return new Object[]{-1,null};
		}
		set.add(bff[i]);
		max = getMax(bff,bff[i],set,first,s+" "+bff[i]);
		set.remove(bff[i]);
		return max;
	}

	static class Parser {
		final private int BUFFER_SIZE = 1 << 16;

		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Parser(InputStream in) {
			din = new DataInputStream(in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public long nextLong() throws Exception {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		// reads in the next string
		public String next() throws Exception {
			StringBuilder ret = new StringBuilder();
			byte c = read();
			while (c <= ' ')
				c = read();
			do {
				ret = ret.append((char) c);
				c = read();
			} while (c > ' ');
			return ret.toString();
		}

		public int nextInt() throws Exception {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws Exception {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws Exception {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
	}
}
