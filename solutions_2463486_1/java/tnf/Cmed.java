import java.util.*;

class C{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		Arrays.sort(list);		
		for(int kase = 1; kase<=T; kase++){
			long A = sc.nextLong();
			long B = sc.nextLong();
			sc.nextLine();
			int count = 0;
			for(int i = 0; i<list.length; i++){
				if(list[i]>=A &&list[i]<=B) count++;
			}
			System.out.println("Case #"+kase+": "+count);
		}
	}

static 	long[] list = {
(new Long("1")).longValue(),
(new Long("4")).longValue(),
(new Long("9")).longValue(),
(new Long("121")).longValue(),
(new Long("10201")).longValue(),
(new Long("12321")).longValue(),
(new Long("14641")).longValue(),
(new Long("484")).longValue(),
(new Long("40804")).longValue(),
(new Long("44944")).longValue(),
(new Long("1002001")).longValue(),
(new Long("100020001")).longValue(),
(new Long("102030201")).longValue(),
(new Long("104060401")).longValue(),
(new Long("1234321")).longValue(),
(new Long("121242121")).longValue(),
(new Long("123454321")).longValue(),
(new Long("125686521")).longValue(),
(new Long("4008004")).longValue(),
(new Long("400080004")).longValue(),
(new Long("404090404")).longValue(),
(new Long("10000200001")).longValue(),
(new Long("1000002000001")).longValue(),
(new Long("1002003002001")).longValue(),
(new Long("1004006004001")).longValue(),
(new Long("10221412201")).longValue(),
(new Long("1020304030201")).longValue(),
(new Long("1022325232201")).longValue(),
(new Long("1024348434201")).longValue(),
(new Long("12102420121")).longValue(),
(new Long("1210024200121")).longValue(),
(new Long("1212225222121")).longValue(),
(new Long("1214428244121")).longValue(),
(new Long("12345654321")).longValue(),
(new Long("1232346432321")).longValue(),
(new Long("1234567654321")).longValue(),
(new Long("40000800004")).longValue(),
(new Long("4000008000004")).longValue(),
(new Long("4004009004004")).longValue(),
(new Long("100000020000001")).longValue(),
(new Long("10000000200000001")).longValue(),
(new Long("10002000300020001")).longValue(),
(new Long("10004000600040001")).longValue(),
(new Long("100220141022001")).longValue(),
(new Long("10020210401202001")).longValue(),
(new Long("10022212521222001")).longValue(),
(new Long("10024214841242001")).longValue(),
(new Long("102012040210201")).longValue(),
(new Long("10201020402010201")).longValue(),
(new Long("10203040504030201")).longValue(),
(new Long("10205060806050201")).longValue(),
(new Long("102234363432201")).longValue(),
(new Long("10221432623412201")).longValue(),
(new Long("10223454745432201")).longValue(),
(new Long("121000242000121")).longValue(),
(new Long("12100002420000121")).longValue(),
(new Long("12102202520220121")).longValue(),
(new Long("12104402820440121")).longValue(),
(new Long("121242363242121")).longValue(),
(new Long("12122232623222121")).longValue(),
(new Long("12124434743442121")).longValue(),
(new Long("123212464212321")).longValue(),
(new Long("12321024642012321")).longValue(),
(new Long("12323244744232321")).longValue(),
(new Long("123456787654321")).longValue(),
(new Long("12343456865434321")).longValue(),
(new Long("12345678987654321")).longValue(),
(new Long("400000080000004")).longValue(),
(new Long("40000000800000004")).longValue(),
(new Long("40004000900040004")).longValue()
};

}
