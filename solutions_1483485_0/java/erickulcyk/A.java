import java.util.Arrays;
import java.util.Scanner;


public class A {

	static int[] a = new int[26];

	static char[] b = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

	public A() {

		Scanner s = new Scanner(System.in);
		Arrays.fill(a, -1);

		for(int k =0; k<3; k++)
		{

			String in = s.nextLine();
			char[] out = s.nextLine().toCharArray();

			int i =0;
			for(char aa : in.toCharArray())
			{
				int index = aa-'a';
				if (index>=0 && index< 26)
				{
					//System.out.println("setting "+index+" "+out[i]);
					a[index]=out[i]-'a';
				}
				i++;
			}

		}


	}



	public static void main(String[] args) {
		B one = new B();
		/*
			for(int j =0; j <26; j++)
			{
				System.out.printf("'%c', ",one.a[j]>=0?one.a[j]+'a':'z');
			}

			System.out.println();
		 */
	}
}

class B
{
	public B()
	{

		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		s.nextLine();

		for(int i = 0; i < t; i ++)
		{
			System.out.print("Case #"+(i+1)+": ");

			char[] line = s.nextLine().toCharArray();
			for(char aa : line)
			{
				if(aa==' ')
					System.out.printf(" ");
				else
					System.out.printf("%c",A.b[aa-'a']);
			}
			System.out.println();
		}
		
	}
}
