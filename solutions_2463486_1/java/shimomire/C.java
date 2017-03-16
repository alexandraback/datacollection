import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class C{
    public static Scanner sc = new Scanner(in);
    public static Random rand=new Random();

    public static PrintWriter out;
    static{
    	try {
			out=new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\shimomire\\Dropbox\\Project\\ProgramContest\\java\\GCJ\\res.out")));
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
    }

    public static int upper_bound(Long[] a,long val) {
		int f=0,l=a.length;
		int len=l-f;
		while(len>0){
			int half=len>>1;
			int mid=f+half;
			if(val<a[mid]){
				len=half;
			}else{
				f=mid;
				++f;
				len=len-half-1;
			}
		}
		return f;
	}

	//http://acm.cs.uct.ac.za/docs/libstdc++-3.4/stl__algo_8h-source.html#l02699
	public static int lower_bound(Long[] a,long val) {
		int f=0,l=a.length;
		int len=l-f;
		while (len>0)
		{
			int half=len>>1;
			int mid=f+half;
			if(a[mid]<val){
				f=mid;
				++f;
				len=len-half-1;
			}else{
				len=half;
			}
		}
		return f;
	}

    public LinkedList<Long> ps=new LinkedList<>();

    public boolean isPalindrome(char[] ch){
    	for(int j=0;j<ch.length;j++){
			if(ch[j]!=ch[ch.length-1-j])
				return false;
		}
    	return true;
    }

    public void run(){
    	{
    		ps.add(0L);
    		ps.add(1L);
    		ps.add(4L);
    		ps.add(9L);
    		ps.add(121L);
    		ps.add(484L);
    		ps.add(10201L);
    		ps.add(12321L);
    		ps.add(14641L);
    		ps.add(40804L);
    		ps.add(44944L);
    		ps.add(1002001L);
    		ps.add(1234321L);
    		ps.add(4008004L);
    		ps.add(100020001L);
    		ps.add(102030201L);
    		ps.add(104060401L);
    		ps.add(121242121L);
    		ps.add(123454321L);
    		ps.add(125686521L);
    		ps.add(400080004L);
    		ps.add(404090404L);
    		ps.add(10000200001L);
    		ps.add(10221412201L);
    		ps.add(12102420121L);
    		ps.add(12345654321L);
    		ps.add(40000800004L);
    		ps.add(1000002000001L);
    		ps.add(1002003002001L);
    		ps.add(1004006004001L);
    		ps.add(1020304030201L);
    		ps.add(1022325232201L);
    		ps.add(1024348434201L);
    		ps.add(1210024200121L);
    		ps.add(1212225222121L);
    		ps.add(1214428244121L);
    		ps.add(1232346432321L);
    		ps.add(1234567654321L);
    		ps.add(4000008000004L);
    		ps.add(4004009004004L);
    		ps.add(100000020000001L);
    		ps.add(100220141022001L);
    		ps.add(102012040210201L);
    		ps.add(102234363432201L);
    		ps.add(121000242000121L);
    		ps.add(121242363242121L);
    		ps.add(123212464212321L);
    		ps.add(123456787654321L);
    		ps.add(400000080000004L);
    		ps.add(10000000200000001L);
    		ps.add(10002000300020001L);
    		ps.add(10004000600040001L);
    		ps.add(10020210401202001L);
    		ps.add(10022212521222001L);
    		ps.add(10024214841242001L);
    		ps.add(10201020402010201L);
    		ps.add(10203040504030201L);
    		ps.add(10205060806050201L);
    		ps.add(10221432623412201L);
    		ps.add(10223454745432201L);
    		ps.add(12100002420000121L);
    		ps.add(12102202520220121L);
    		ps.add(12104402820440121L);
    		ps.add(12122232623222121L);
    		ps.add(12124434743442121L);
    		ps.add(12321024642012321L);
    		ps.add(12323244744232321L);
    		ps.add(12343456865434321L);
    		ps.add(12345678987654321L);

    	}


    	int T=sc.nextInt();

//    	CH:for(long i=0;i<=1000000000L;i++){
//    		char[] ch=(Long.toString(i*i)).toCharArray();
//    		if(isPalindrome(Long.toString(i).toCharArray()) && isPalindrome(ch))
//    			ln("ps.add("+i*i+"L);");
//    			//ln(Long.toString(i)+":"+Long.toString(i*i));
//    	}


    	StringBuilder sb=new StringBuilder();
    	for(int i=1;i<=T;i++){
    		long a=sc.nextLong(),b=sc.nextLong();
    		sb.append("Case #"+i+": ")
    		.append(upper_bound(ps.toArray(new Long[0]),b)-lower_bound(ps.toArray(new Long[0]),a)).append("\n");
    	}
    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new C().run();
    }

    public int[] nextIntArray(int n){
        int[] res=new int[n];
        for(int i=0;i<n;i++){
            res[i]=sc.nextInt();
        }
        return res;
    }
    public static void pr(Object o) {
    	out.print(o);
    }
    public static void ln(Object o) {
        out.println(o);
    }
    public static void ln() {
    	out.println();
    }

}