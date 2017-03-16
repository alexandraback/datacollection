import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class MySolution {
	private char[] a;
	public void init(){
		a = new char[26];
		a[0]='y';
		a[1]='h';
		a[2]='e';
		a[3]='s';
		a[4]='o';
		a[5]='c';
		a[6]='v';
		a[7]='x';
		a[8]='d';
		a[9]='u';
		a[10]='i';
		a[11]='g';
		a[12]='l';
		a[13]='b';
		a[14]='k';
		a[15]='r';
		a[16]='z';
		a[17]='t';
		a[18]='n';
		a[19]='w';
		a[20]='j';
		a[21]='p';
		a[22]='f';
		a[23]='m';
		a[24]='a';
		a[25]='q';
	}
	public MySolution(){
		init();
	}
	
	public String translate(String before,int line){
		String after="Case #"+line+": ";
		for(int i=0;i<before.length();i++){
			if(before.charAt(i)==' '){
				after+=' ';
			}
			else {
				after+=a[before.charAt(i)-'a'];
			}
		}
		return after;
	}
	
	public static void main(String[] args){
		MySolution ms = new MySolution();
		File file = new File("A-small-attempt0.in");
		BufferedReader reader = null;
		try {
            //System.out.println("以行为单位读取文件内容，一次读一整行：");
            reader = new BufferedReader(new FileReader(file));
            String tempString = null;
            
            // 一次读入一行，直到读入null为文件结束
            tempString = reader.readLine();
            int line = Integer.parseInt(tempString);
            for(int i=0;i<line;i++){
            	tempString = reader.readLine();
            	System.out.println(ms.translate(tempString, i+1));
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
	}
}
