import java.util.*;
import java.io.*;
public class B{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
    int t = Integer.parseInt(in.readLine());
    String[] input = new String[t];
    int[] sizes = new int[t];
    PrintWriter out = new PrintWriter("output.txt");
    for (int i = 0; i < t; i++){
	int size = Integer.parseInt(in.readLine());
	sizes[i] = size;
	String temp = in.readLine();
	for(int j = 1;j<2*size-1;j++){
        	temp+= " "+in.readLine();
	}
	input[i] = temp;
    }
    for(int i = 0;i<t;i++){
	int n = sizes[i];
	String j = input[i];
	String output = calc(n,j);
	out.println("Case #"+(i+1)+": "+output);
    }
    out.close();
    }
    private static String calc(int n, String input){
	int[] list = new int[2501];
	for(int i = 0;i<2501;i++){
	    list[i] = 0;
	}
	String[] lst = input.split(" ");
	int l = lst.length;
	for(int i = 0;i<l;i++){
	    int temp = Integer.parseInt(lst[i]);
	    list[temp]++;
	}
	int[] ans = new int[n];
	int count = 0;
	int i = 0;
	while(count<n){
	    i++;
	    if(list[i]%2==1){
		ans[count] = i;
		count++;
	    }
	}
	Arrays.sort(ans);
	String res = "";
	for(int d = 0;d<n-1;d++){
	    res+=ans[d]+" ";
	}
	res+=ans[n-1];
	return res;
    }
}
