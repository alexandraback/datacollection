import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Problem3C {

	public static void main(String[] args){
		List<Long> res = new ArrayList<Long>();
		try {
			FileInputStream fstream = new FileInputStream("C-small-attempt0.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			int cases = Integer.valueOf(br.readLine());
			for(int i = 0; i < cases; i++) {
				String line = br.readLine();
				int N = Integer.valueOf(line.split(" ")[0]);
				int M = Integer.valueOf(line.split(" ")[1]);
				long[] Nval = new long[N];
				long[] Ntypes = new long[N];
				long[] Mval = new long[M];
				long[] Mtypes = new long[M];
				String[] tokens = br.readLine().split(" ");
				for(int j = 0; j < N; j++){
					Nval[j] = Long.valueOf(tokens[j*2]);
					Ntypes[j] = Long.valueOf(tokens[j*2+1]);
				}
				tokens = br.readLine().split(" ");
				for(int j = 0; j < M; j++){
					Mval[j] = Long.valueOf(tokens[j*2]);
					Mtypes[j] = Long.valueOf(tokens[j*2+1]);
				}	
				res.add(solve(Nval, Ntypes, Mval, Mtypes));
			}
			in.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
		
		try {
			// Create file
			File fout = new File("out.txt");
			FileWriter fstream = new FileWriter(fout);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < res.size(); i++){
				out.write("Case #" + (i+1) + ": " + res.get(i));
				out.newLine();
			}
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	private static long sumAllOfType(long[] values, long[] types, long type, int start, int end){
		long sum = 0;
		for(int i = start; i < end; i++){
			if(types[i] == type)
				sum += values[i];
		}
		return sum;
	}
	
	private static long solve(long[] Nval, long[] Ntypes, 
			long[] Mval, long[] Mtypes){
		long res = 0;
		//eight cases:
		//1. N : x
		if(Nval.length == 1){
			res = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			return res;
		}
		//2. N: x, x
		if(Nval.length == 2 && Ntypes[0] == Ntypes[1]){
			res = Math.min(Nval[0]+Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			return res;
		}
		//3. N: x, y
		if(Nval.length == 2 && Ntypes[0] != Ntypes[1]){
			//only x is used:
			res = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			//only y is used:
			long tmp = Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			//only y is used:
			for(int i = 0; i < Mtypes.length; i++){
				if(Mtypes[i] == Ntypes[1]){
					tmp = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, i)) + 
							   Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], i, Mval.length));
					if(tmp > res)
						res = tmp;
				}
			}
			return res;
		}
		//4. N : x x x
		if(Nval.length == 3 && Ntypes[0] == Ntypes[1] && Ntypes[0] == Ntypes[2]){
			 res = Math.min(Nval[0]+Nval[1]+Nval[2], 
					 sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			 return res;
		}
		//5. N: x x y
		if(Nval.length == 3 && Ntypes[0] == Ntypes[1] && Ntypes[0] != Ntypes[2]){
			//only x is used:
			res = Math.min(Nval[0]+Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			//only y is used:
			long tmp = Math.min(Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[2], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			for(int i = 0; i < Mtypes.length; i++){
				if(Mtypes[i] == Ntypes[2]){
					tmp = Math.min(Nval[0]+Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, i)) + 
							   Math.min(Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[2], i, Mval.length));
					if(tmp > res)
						res = tmp;
				}
			}
			return res;
		}
		//6. N: x y y
		if(Nval.length == 3 && Ntypes[0] != Ntypes[1] && Ntypes[1] == Ntypes[2]){
			//only x is used:
			res = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			//only y is used:
			long tmp = Math.min(Nval[1]+Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[1], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			for(int i = 0; i < Mtypes.length; i++){
				if(Mtypes[i] == Ntypes[1]){
					tmp = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, i)) + 
							   Math.min(Nval[1]+Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[1], i, Mval.length));
					if(tmp > res)
						res = tmp;
				}
			}
			return res;
		}
		//7. N: x y x
		if(Nval.length == 3 && Ntypes[0] == Ntypes[2] && Ntypes[0] != Ntypes[1]){
			//only x is used:
			res = Math.min(Nval[0]+Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			//only y is used:
			long tmp = Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			for(int i = 0; i < Mtypes.length; i++){
				if(Mtypes[i] == Ntypes[1]){
					for(int j = i; j < Mtypes.length; j++){
						if(Mtypes[i] == Ntypes[1]){
							tmp = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, i)) + 
							   		Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], i, j+1)) + 
							   		Math.min(Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[2], j+1, Mval.length));
							if(tmp > res)
								res = tmp;
						}
					}
				}
			}
			return res;
		}
		//8. N: x y z
		if(Nval.length == 3 && Ntypes[0] != Ntypes[2] && Ntypes[0] != Ntypes[1]){
			//only x is used:
			res = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, Mval.length));
			//only y is used:
			long tmp = Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			//only z is used
			tmp = Math.min(Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[2], 0, Mval.length));
			if(tmp > res)
				res = tmp;
			//only x && y are used
			long[] NvalTmp = new long[2];
			long[] NtypesTmp = new long[2];
			NvalTmp[0] = Nval[0];
			NvalTmp[1] = Nval[1];
			NtypesTmp[0] = Ntypes[0];
			NtypesTmp[1] = Ntypes[1];
			tmp =  solve(NvalTmp, NtypesTmp, Mval, Mtypes);
			if(tmp > res)
				res = tmp;
			//only x and z are used
			NvalTmp[0] = Nval[0];
			NvalTmp[1] = Nval[2];
			NtypesTmp[0] = Ntypes[0];
			NtypesTmp[1] = Ntypes[2];
			tmp =  solve(NvalTmp, NtypesTmp, Mval, Mtypes);
			if(tmp > res)
				res = tmp;
			//only y and z are used
			NvalTmp[0] = Nval[1];
			NvalTmp[1] = Nval[2];
			NtypesTmp[0] = Ntypes[1];
			NtypesTmp[1] = Ntypes[2];
			tmp =  solve(NvalTmp, NtypesTmp, Mval, Mtypes);
			if(tmp > res)
				res = tmp;
			//all x,y, z are used
			for(int i = 0; i < Mtypes.length; i++){
				if(Mtypes[i] == Ntypes[1]){
					for(int j = i; j < Mtypes.length; j++){
						if(Mtypes[i] == Ntypes[1]){
							tmp = Math.min(Nval[0], sumAllOfType(Mval, Mtypes, Ntypes[0], 0, i)) + 
							   		Math.min(Nval[1], sumAllOfType(Mval, Mtypes, Ntypes[1], i, j+1)) + 
							   		Math.min(Nval[2], sumAllOfType(Mval, Mtypes, Ntypes[2], j+1, Mval.length));
							if(tmp > res)
								res = tmp;
						}
					}
				}
			}
			return res;
		}
		
		return -1;
	}
	
}
