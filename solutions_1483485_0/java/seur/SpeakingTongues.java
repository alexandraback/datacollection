
public class SpeakingTongues {
	static String test =  "3\nejp mysljylc kd kxveddknmc re jsicpdrysi\nrbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\nde kr kd eoya kw aej tysr re ujdr lkgc jv";
	static String input = "3\nour language is impossible to understand\nthere are twenty six factorial possibilities\nso it is okay if you want to just give up";
	static String val = "30\nejp mysljylc kd kxveddknmc re jsicpdrysi\nrbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\nde kr kd eoya kw aej tysr re ujdr lkgc jv\nhello i am the google code jam test data\nhow are you\naynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny ieeeeeeeee\ny n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd\nschr rkxc tesr aej dksl tkrb xc\ndtkwr yd rbc tksi zjkcr yd rbc wepcdr drcyia yd rbc xejsryks\nkr tyd rbc ncdr ew rkxcd kr tyd rbc nmjpdr ew rkxcd\nrpysdmyrksl rchr kd ser leped drpcslrb\ndrpcslrb kd leped drpcslrb\nejp feic uyx kd mkoc rbc varbylepcys rbcepcx\nrbcpc kd se ysdtcp\nlpccrksld fbccdc vevdkfmc rbc sjxncp aej bygc ikymci kd fjppcsrma ejr ew vepofbevd\neb seeeee lellymep kd bcyici wep rbc epvbysylc\neb xa lei mcrd xyoc ejr\ntba ie vpelpyxxcpd ymtyad xkh jv bymmetccs ysi fbpkdrxyd\nbet ypc aej bemiksl jv ncfyjdc kx y veryre\naej ncrrcp fjr rbc vkqqy ks wejp vkcfcd ncfyjdc kx ser bjslpa csejlb re cyr dkh\neb byk kx ks jp fexvjrcp cyrksl aejp fbccqnjplcpd ysi leelmcpcdksl aejp rchrq\nvscjxesejmrpyxkfpedfevkfdkmkfegemfysefeskedkd\nys cac wep ys cac ysi y vklces wep y vklces\nset kd rbc djxxcp ew ejp myfo ew ikdfesrcsr\nks y tepmi ew ikpctemgcd ysi mkesd dexcrkxcd rbc pypcdr fpcyrjpc kd y wpkcsi\nxa syxc kd ijl k bygc ujdr xcr aej ysi k meeegc aej\nwep rbedc tbe dvcyo ks y resljc ie ser dvcyo re erbcp vcevmc\nseneia jsicpdrysid rbcx dksfc rbca ypc dvcyoksl xadrcpkcd ks rbc dvkpkr\ntbeeeeeeeeeeeeeeeeeeeyyyyyyyyy k oset f vmjd vmjd\nna rbc vpkfoksl ew xa rbjxnd dexcrbksl tkfoci rbkd tya fexcd\n";
	public static void main(String[] args) {
		buildGooglerese(test,input);
		mapping[16] = 'z';mapping[25] = 'q';
		String[][] cases = CaseReader.getCases(val, 1);
		for (int i = 0;i < cases.length;i++) {
			parseCase(i + 1, cases[i][0]);
		}
	}
	public static void parseCase(int caseNum, String caseString) {
		char[] str = new char[caseString.length()];
		for (int i = 0;i < caseString.length();i++) {
			if (caseString.charAt(i) >= 'a' && caseString.charAt(i) <= 'z') {
				str[i] = mapping[caseString.charAt(i) - 'a'];
			} else {
				str[i] = caseString.charAt(i);
			}
		}
		System.out.println("Case #" + caseNum + ": " + new String(str));
	}
	
	static char[] mapping = "12345678901234567890123456".toCharArray();
	
	public static void buildGooglerese(String output, String input) {
		for (int i = 0;i < output.length();i++) {
			if (output.charAt(i) >= 'a' && output.charAt(i) <= 'z') {
				mapping[output.charAt(i) - 'a'] = input.charAt(i);
			}
		}
		System.out.println(mapping);
	}
}
