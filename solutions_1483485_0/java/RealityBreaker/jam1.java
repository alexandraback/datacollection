import java.io.*;


public class jam1 {

	/**
	 * @param args
	 */
	static char decode (char c)
	{
		if(c=='a')
			return 'y';
		if(c=='b')
			return 'h';
		if(c=='c')
			return 'e';
		if(c=='d')
			return 's';
		if(c=='e')
			return 'o';
		if(c=='f')
			return 'c';
		if(c=='g')
			return 'v';
		
		if(c=='h')
			return 'x';
		if(c=='i')
			return 'd';
		if(c=='j')
			return 'u';
		if(c=='k')
			return 'i';
		if(c=='l')
			return 'g';
		if(c=='m')
			return 'l';
		if(c=='n')
			return 'b';
		
		if(c=='o')
			return 'k';
		if(c=='p')
			return 'r';
		if(c=='q')
			return 'z';
		if(c=='r')
			return 't';
		if(c=='s')
			return 'n';
		if(c=='t')
			return 'w';
		if(c=='u')
			return 'j';
		
		if(c=='v')
			return 'p';
		if(c=='w')
			return 'f';
		if(c=='x')
			return 'm';
		if(c=='y')
			return 'a';
		if(c=='z')
			return 'q';
		
			return ' ';
	}
	public static String decode(String input)
	{
		String ans = "";
		for(int i=0;i<input.length();i++)
		{
			ans+=decode(input.charAt(i));
		}
		return ans;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
		File fin1 = new File("d:\\A-small-attempt2.in");
    	FileInputStream fs1 = new FileInputStream(fin1);
    	BufferedReader br1 = new BufferedReader(new InputStreamReader(fs1));
    	
    	File fout6 = new File("d:\\cjamout1");
    	FileOutputStream fos6 = new FileOutputStream(fout6);
    	BufferedWriter wr6 = new BufferedWriter(new OutputStreamWriter(fos6));
        /*
    	System.out.println(decode("y qee"));
        System.out.println(decode("ejp mysljylc kd kxveddknmc re jsicpdrysi"));
        System.out.println(decode("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"));
        System.out.println(decode("de kr kd eoya kw aej tysr re ujdr lkgc jv"));
	    */
    	String line = br1.readLine();
    	int n = 1;
    	line = br1.readLine();
    	while(line!=null)
    	{
    	   if(!line.trim().equals(""))
    	   {
    		   wr6.write("Case #"+String.valueOf(n++)+": "+decode(line));
    	       wr6.newLine();
    	   }
    	   line = br1.readLine();
    	  
		}
    	br1.close();
    	fs1.close();
    	
    	wr6.close();
    	fos6.close();
	}
	catch(Exception e)
	{
		e.printStackTrace();
	}
}
	}
