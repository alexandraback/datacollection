import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Speaking_in_Tongues {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			String googlerese = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
			String origin____ = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
			String[] mapping = new String[26];
			boolean[] done = new boolean[26];
			for(int i=0; i<26; i++)
			{
				mapping[i] = null;
				done[i] = false;
			}
			mapping['y'-'a'] = "a";
			done['a'-'a']=true;
			mapping['e'-'a'] = "o";
			done['o'-'a']=true;
			mapping['q'-'a'] = "z";
			done['z'-'a']=true;
			for(int i=0; i<origin____.length(); i++)
			{
				if(googlerese.charAt(i)!=' ')
				{
					mapping[googlerese.charAt(i)-'a'] = origin____.substring(i,i+1);
					done[origin____.charAt(i)-'a']=true;
				}
			}
			int index_origin = -1, index_google = -1;
			for(int i=0; i<26;i++)
			{
				if(mapping[i]==null)
					index_google=i;
				
				if(done[i]==false)
					index_origin=i;
			}
			mapping[index_google] = new Character((char) ('a'+index_origin)).toString();
			
			
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			PrintWriter pw = new PrintWriter(args[1]);
			String line = br.readLine();
			System.out.println(line);
			int T = Integer.valueOf(line.trim());
			for (int i=0; i<T; i++)
			{
				line = br.readLine();
				System.out.println(line);
				String new_line = new String();
				
				for(int j=0; j<line.length(); j++)
				{
					if(line.charAt(j)==' ')
						new_line+=" ";
					else
						new_line+=mapping[line.charAt(j)-'a'];
				}
				
				pw.println("Case #"+(i+1)+": "+new_line);
				System.out.println("Case #"+(i+1)+": "+new_line);
			}
			pw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
