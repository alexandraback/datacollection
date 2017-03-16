import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class qualA {
static String samp="ejp mysljylc kd kxveddknmc re jsicpdrysi"+
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+
	"de kr kd eoya kw aej tysr re ujdr lkgc jv";
static String trans="our language is impossible to understand"+
	"there are twenty six factorial possibilities"+
	"so it is okay if you want to just give up";

static char[] index=new char[26];

static void createIndex() {
	boolean[] assgn=new boolean[26];
	boolean[] assgnt=new boolean[26];
	index['q'-'a']='z';
	assgn['q'-'a']=true;
	int assgnm=1;
	for (int i = 0; i < samp.length(); i++) {
		if (samp.charAt(i)==' ') continue;
		if (!assgn[samp.charAt(i)-'a']) {
			index[samp.charAt(i)-'a']=trans.charAt(i);
			assgn[samp.charAt(i)-'a']=true;
			assgnt[trans.charAt(i)-'a']=true;
			assgnm++;
		}
	}	
	int j=0;
	while (assgn[j] && j<assgn.length) j++;
	char k=0;
	while (assgnt[k] && k<assgnt.length) k++;
	index[j]=(char) (k+'a');
}

public static void main(String[] args) {
	String prblm="A"; boolean fl=!true;
	String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
	String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
	createIndex();
	try {
		BufferedReader fr= new BufferedReader(new FileReader(filein));
		BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
		String s=fr.readLine();
		int n=Integer.parseInt(s);
		for (int i = 1; i <= n; i++) {
			s=fr.readLine();
			String out = "Case #"+i+": ";
			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j)==' ') out+=" ";
				else out+=index[s.charAt(j)-'a'];
			}
			System.out.println(out);
			fw.write(out+"\n");
		}
		fr.close();
		fw.close();
	} catch (Exception e) {			
		e.printStackTrace();
	}		
}

}
