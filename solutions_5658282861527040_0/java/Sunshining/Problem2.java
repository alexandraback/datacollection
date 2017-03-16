package round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


@SuppressWarnings("unused")
public class Problem2 implements Solution{
	
	int a;
	int b;
	int k;
	@Override
	public String execute(BufferedReader in, PrintWriter log)
			throws IOException {
		// TODO Auto-generated method stub
		String line;
		
		line = in.readLine().trim();
		String[] items = line.split("\\s+");
		a=Integer.parseInt(items[0]);
		b=Integer.parseInt(items[1]);
		k=Integer.parseInt(items[2]);
		
		
		
		int count=processSmall();
		
		String result = " " +Integer.toString(count);
		
		return result;
	}
	
	int processSmall() {
		int count=0;
		for (int x=0; x<a;++x) {
			for (int y=0; y<b;++y) {
				if ((x&y)<k) count++;
			}
		}
		
		return count;
	}

}
