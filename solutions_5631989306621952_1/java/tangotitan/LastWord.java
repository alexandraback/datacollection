import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class LastWord {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fstream = new FileInputStream("A-Large.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		String strLine;

		//Read File Line By Line
		int count = -1;
		while ((strLine = br.readLine()) != null)   {
		  // Print the content on the console
			count++;
			if(count==0){
				continue;
			}
			System.out.println("Case #" + count + ": " + helper(strLine));
			//System.out.println("Case #" + count + ": " + helper("ZXCASDQWEIOEWQRKDJSKLFJJDKSFJKDJFKJDKFJKDSJKFJDSALKJFLKJADSLKFJKLSDAJKFJKLSDJFKLJSDLKJFKLLKDSAJFLKDJSAKLFJKLDASJFKLJDSAKLFJKL"));
		  }
		//Close the input stream
		br.close();
	}

	private static String helper(String str){
		String result = "";
		for(int i=0;i<str.length();i++){
			if(i==0){
				result += str.charAt(0);
			}else{
				if(str.charAt(i)>=result.charAt(0)){
					result = str.charAt(i) + result;
				}else{
					result = result + str.charAt(i);
				}
			}
		}
		return result;
	}
}
