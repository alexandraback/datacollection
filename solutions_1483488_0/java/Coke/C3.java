/*
Ana:
- For a given number of digit, e.g. 5, there are n-1 number will be its recycle number, i.e. 5-1=4 distinct paris, as follows:
- 12345 => 
- 51234
- 45123
- 34512
- 23451
- Since leading 0 is not count, 100, 001 are not pairs, so any number if the swap number start with 0 will not have pairs.
- Divide the number into 2 parts, left, right by a mid point.
- Then compare the left right to the range-left, range-right, if within that range that marks as pairs

- There must be another number which is this number pairs
- Same Digit
- The number of pairs within a range = Num of itm in range * (Num of Digit - 1), e.g. 1111~2222 => (2222-1111+1) * (4-1) = 3336.
- Since n<m 
- All Digit same cannot be count: 1111, 2222... so 3336 - 2 = 3334
- if 4321 should not map 3214. 



2 pairs is recycle if and only if 
al = br && ar=bl && 
al within Al,Bl
ar within Ar,Br
therefore, all number that left witin A,B and right within A,B will be recycle number
With each mid, you may count the number of itm for left, and number of itm for right
*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author CuteCoke
 */
public class C3 {
    final String TASK_NAME = "C-small-attempt0";
    //final String TASK_NAME = "B-large";
    //final String TASK_NAME = "sample";
    final String IN_FILE = TASK_NAME+".in";
    final String OUT_FILE = TASK_NAME+".out";
	
	private boolean contains(int[] arr, int tar){
		for(int a: arr){
			if (a==tar) return true;
		}
		return false;
	}
	
	public int solve(int A, int B){
		int res = 0;
		String s=A+"";
		int len =s.length();
		int[] al = new int[len];
		int[] ar = new int[len];
		int[] bl = new int[len];
		int[] br = new int[len];
		for(int i=1; i<len; i++){
			int tn = (int)Math.pow(10,i);
			al[i] = A / tn;
			ar[i] = A % tn;
			bl[i] = B / tn;
			br[i] = B % tn;
		}
		
		for(int i=A; i<=B; i++){
			String sTmp = i+"";
			if ("".equals(sTmp.replaceAll(sTmp.charAt(0)+"",""))) continue;
			int[] used = new int[len];
			int usedcnt = 0;
			for(int j=1; j<len; j++){
				int tn = (int)Math.pow(10,j);
				int l = i / tn;
				int r = i % tn;
				int k = len-j;
				if (l==r) continue;
				if ((r+"").length() != j) continue;
				if ((l+"").length() != (len-j)) continue;
				int tn2 = (int)Math.pow(10,len-j);
				int nw = r*tn2+l;
				if (i>=nw) continue;
				if (r>al[k] && r<bl[k]){
					if (!contains(used, nw)){
						res++;
						used[usedcnt++]=nw;
						//System.out.println("j="+j+"("+l+","+r+"); add1("+i+") nw="+nw);
					}
				}else{
					if (nw>=A && nw<=B){
						if (!contains(used, nw)){
							res++;
							used[usedcnt++]=nw;
							//System.out.println("j="+j+"("+l+","+r+"); add2("+i+") nw="+nw);
						}
					}
				}
			}
			
		}
        return res;
    }

    public void doMain() throws Exception{
    try{

        Scanner sc1 = null;
        BufferedReader br = new BufferedReader(new FileReader(IN_FILE));
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE));

        int T = Integer.parseInt(br.readLine());

        for (int a=0; a<T; a++){
            bw.write("Case #"+(a+1)+": ");
            sc1 = new Scanner(br.readLine());
            int A = sc1.nextInt();
            int B = sc1.nextInt();
            int ans = solve(A, B);
            bw.write(ans+"\n");
        }
        br.close();
        bw.close();

    }catch(FileNotFoundException e){
        System.err.println("In File: "+(new File(IN_FILE)).getAbsolutePath());
        System.err.println("Out File: "+(new File(OUT_FILE)).getAbsolutePath());
        e.printStackTrace(System.err);
    }
    }

    public static void main(String[] s) throws Exception{
        try{
            C3 test = new C3();
            test.doMain();
        }catch(Exception e){
            e.printStackTrace(System.err);
        }


    }
}
