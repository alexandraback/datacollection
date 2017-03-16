import java.util.*;
import java.lang.*;

public class countingSheep
{
	static boolean isAsleep(boolean[] arr){
		for(int i = 0; i < 10; i++){
			if (!arr[i]){
				return false;
			}
		}
		return true;
	}

	static String getLastSheep(int n){
		if (n == 0){
			return "INSOMNIA";
		}
		else {
			boolean[] seenArray = new boolean[10];
			long currNum = n;
			while(!isAsleep(seenArray)){
				long temp = currNum;
				while (temp != 0){
					seenArray[(int)(temp%10)] = true;
					temp = temp/10;
				}
				currNum += n;
			}
			return Long.toString(currNum - n);
		}
	}

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfTests = in.nextInt();
        for (int i = 0; i < numberOfTests; i++)
        {
        	int n = in.nextInt();
            System.out.println("Case #" + (i + 1) + ": " + getLastSheep(n));
        }  
    }
}