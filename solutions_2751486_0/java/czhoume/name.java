import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Stack;

public class name{
	public static String out="";
	
	public static boolean isv(char c){
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
			return true;
		else
			return false;
	}
	public static int count(String s, int n){
		int i,j,co=0,res=0,t;
		int m=s.length();
		Stack<Integer> store= new Stack<Integer>();
		char[] arr=new char[m];
		for(i=0;i<m;i++){
			arr[i]=s.charAt(i);
		}
		for(i=0;i<m;i++){
			if(!isv(arr[i])){
				co++;
				if(co>=n)
					store.push(i);
			}else
				co=0;
		}
		t=m;
		while(!store.isEmpty()){
			j=store.pop();
			res+=(t-j)*(j-n+2);
			t=j;
		}
		return res;
	}
	
	public static void main(String[] args) {
		BufferedReader br = null;
		BufferedWriter writer = null;
		try {

			br = new BufferedReader(new FileReader("C:/codejam/A-small-attempt1.in"));
			int T, N, X, Y, j, i,n;
			String s;
			int res;
			String result;
			String tmpd;
			T = Integer.parseInt(br.readLine());
			for (i = 1; i < T + 1; i++) {
				out += "Case #" + i + ": ";
				tmpd = br.readLine();
				String[] d = tmpd.split(" ");
				s = d[0];
				n = Integer.parseInt(d[1]);
				res=count(s,n);
				System.out.println("Case #"+ i+ ": "+ res);
				out += res;
				out += "\n";
			}

			writer = new BufferedWriter(new FileWriter("C:/codejam/output.out"));
			System.out.println(out);
			writer.write(out);


		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException e) {
			}
		}

	}
}