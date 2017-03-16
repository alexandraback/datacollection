import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	static Set<BigInteger> numeros=new TreeSet<>();
	static BigInteger[] nums; 
	public static void main(String[] args)throws Exception{
		generateFile();
		System.out.flush();
		System.setOut(new PrintStream("C.out"));
		BufferedReader br=new BufferedReader(new FileReader("C-large-1.in"));
		final int T = Integer.parseInt(br.readLine());
		for(int t=0;t<T;t++){
			System.out.print("Case #"+(t+1)+": ");
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			BigInteger i=new BigInteger(st.nextToken()),f=new BigInteger(st.nextToken());
			int pI=Arrays.binarySearch(nums,i),pF=Arrays.binarySearch(nums,f.add(BigInteger.ONE));
			if(pI<0)pI=-(pI+1);
			if(pF<0)pF=-(pF+1);
			System.out.println(pF-pI);
		}
		br.close();
		System.out.close();
	}
	static void generateFile()throws Exception{
		if(!new File("C.sqr").exists()){
			R(1,1);R2();
			PrintWriter pw=new PrintWriter("C.sqr");
			for(BigInteger h:numeros)pw.println(h);
			pw.close();
		}
		numeros.clear();
		BufferedReader br=new BufferedReader(new FileReader("C.sqr"));
		List<BigInteger> numeros=new ArrayList<>();
		for(String h;(h=br.readLine())!=null;)numeros.add(new BigInteger(h).pow(2));
		br.close();
		nums=numeros.toArray(new BigInteger[0]);
	}
	public static void R(int p,long v){
		verificar(Long.toBinaryString(v));
		if(p>=25)return;
		for(int i=0;i<2;i++)R(p+1,v*2+i);
	}
	public static void R2(){
		String[] ceros=new String[25];
		ceros[0]="";numeros.add(new BigInteger("1"));numeros.add(new BigInteger("2"));numeros.add(new BigInteger("3"));
		for(int e=1;e<ceros.length;e++)ceros[e]=ceros[e-1]+"0";
		for(int e=0;e<ceros.length;e++){
			sirve("2"+ceros[e]+ceros[e]+"2");
			sirve("2"+ceros[e]+"0"+ceros[e]+"2");
			sirve("2"+ceros[e]+"1"+ceros[e]+"2");
		}
	}
	public static void verificar(String ini){
		String fin="";
		for(char c:ini.toCharArray())fin=c+fin;
		sirve(ini+fin);
		for(int e=0;e<3;e++)sirve(ini+e+fin);
	}
	public static void sirve(String num){
		if(num.length()>50)return;
		BigInteger b=new BigInteger(num),p=b.pow(2);
		if(isP(p.toString().toCharArray()))numeros.add(b);
	}
	public static boolean isP(char[] t){
		for(int e=0,i=t.length/2;e<i;e++)if(t[e]!=t[t.length-1-e])return false;
		return true;
	}
}