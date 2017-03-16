import java.io.File;
import java.util.HashMap;
import java.util.Scanner;


public class Dijkstra {
	public static void main(String[] args) throws Exception {
	Scanner s = new Scanner(new File("C-small-attempt0.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			String sizes = s.nextLine();
			String[] sizesArr = sizes.split("\\s+");
			
			int L = Integer.parseInt(sizesArr[0]);
			int X = Integer.parseInt(sizesArr[1]);
			String base = s.nextLine();
			StringBuilder build = new StringBuilder();
			for(int i = 0;i<X;i++) {
				build.append(base);
			}
			boolean result = canReduce(build.toString());
			System.out.print("Case #" + currentCase + ": ");
			if(result) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
			
		}
	}
	
	
	public static boolean canReduce(String s) {
		String firstProduct = s.charAt(0)+"";
		if(firstProduct.equals("i")) {
			boolean result = canReduce2(s.substring(1));
			if(result) return true;
		}
		for(int firstSplit = 1;firstSplit<s.length()-2;firstSplit++) {
			firstProduct = mult(firstProduct,s.charAt(firstSplit)+"");
			if(firstProduct.equals("i")) {
				boolean result = canReduce2(s.substring(firstSplit+1));
				if(result) return true;
			}
		}
		return false;
	}
	
	public static boolean canReduce2(String s) {
		//System.out.println("Checking " + s);
		String firstProduct = s.charAt(0)+"";
		if(firstProduct.equals("j")) {
			boolean result = getProduct(s.substring(1)).equals("k");
			if(result) return true;
		}
		for(int firstSplit = 1;firstSplit<s.length()-1;firstSplit++) {
			firstProduct = mult(firstProduct,s.charAt(firstSplit)+"");
			if(firstProduct.equals("j")) {
				boolean result = getProduct(s.substring(firstSplit+1)).equals("k");
				if(result) return true;
			}
		}
		return false;
	}
	static HashMap<String,String> memo = new HashMap<String,String>();
	public static String getProduct(String s) {
		if(memo.containsKey(s)) {
			return memo.get(s);
		}
		//System.out.println("Getting product of " + s);
		String product = "1";
		for(int i = 0;i<s.length();i++) {
			product = mult(product,s.charAt(i) + "");
		}
		//System.out.println(product);
		memo.put(s,product);
		return product;
	}
	
	
	static HashMap<String,String> products = new HashMap<String,String>();
	
	static {
		products.put("11","1");
		products.put("1i", "i");
		products.put("1j", "j");
		products.put("1k","k");
		
		products.put("i1","i");
		products.put("ii","-1");
		products.put("ij", "k");
		products.put("ik","-j");
		
		products.put("j1","j");
		products.put("ji","-k");
		products.put("jj","-1");
		products.put("jk", "i");
		
		products.put("k1","k");
		products.put("ki","j");
		products.put("kj","-i");
		products.put("kk","-1");
	}
	
	public static String mult(String a, String b) {
		int sign = 1;
		if(a.charAt(0)=='-') {
			sign *= -1;
			a = a.substring(1);
		}
		if(b.charAt(0)=='-') {
			sign *= -1;
			b = b.substring(1);
		}
	
		String product = products.get(a+b);
		if(product.charAt(0)=='-') {
			sign *= -1;
			product = product.substring(1);
		}
		return (sign==-1 ? "-" :"") + product;
		
	}
	
}
