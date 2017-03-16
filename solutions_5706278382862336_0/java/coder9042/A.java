import java.io.*;
class A{
	static int counter = 0;
	static int vals[] = new int[2];
	static boolean flag = false;
	public static int[] separate(String str){
		int index = str.indexOf("/");
		int ans[] = new int[2];
		ans[0] = Integer.parseInt(str.substring(0,index));
		ans[1] = Integer.parseInt(str.substring(index+1, str.length()));
		return ans;
	}
	public static int check(int count){
		//System.out.println(vals[0]+"/"+vals[1]);
		int temp[] = new int[2];
		if(vals[0] == 0){
			return -1;
		}
		temp[0] = vals[0];
		temp[1] = vals[1];
		vals[0] = vals[0] * 2;
		vals[0]= vals[0] - vals[1];
		counter += 1;
		if(counter == 40){
			return -1;
		}
		count ++ ;
		if(vals[0] >= 0){
			vals[0] = temp[0];
			vals[1] = temp[1];
			vals[0] = vals[0] * 2;
			vals = reduce(vals[0], vals[1]);
			//System.out.println("here1");
			//System.out.println(vals[0]+"/"+vals[1]);
			flag = true;
			return count;
		}
		else{
			vals[0] = temp[0];
			vals[1] = temp[1];
			vals[0] = vals[0] * 2;
			//System.out.println("here2");
			//System.out.println(vals[0]+"/"+vals[1]);
			vals = reduce(vals[0], vals[1]);
			return check(count);
		}
	}
	public static int check2(){
		int temp[] = new int[2];
		temp[0] = vals[0];
		temp[1] = vals[1];
		return 0;
	}
	public static int HCF(int a, int b){
		if(b == 0)
			return a;
		else
			return HCF(b, a%b);
	}
	public static int[] reduce(int a, int b){
		int h = HCF(a,b);
		a = a/h;
		b = b/h;
		int ans[] = new int[2];
		ans[0] = a;
		ans[1] = b;
		return ans;
	} 
	public static void main(String args[])throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		int ans[] = new int[T];
		for(int i=0;i<T;i++){
			int c1 = 0, c2 = 0;
			String str = in.readLine();
			vals = separate(str);
			c1 = check(0);
			if(flag == true){
				//ans[i] = c1;
				//System.out.println("after c1");
				//System.out.println(vals[0]+"/"+vals[1]);
				while(counter < 40){
					if(vals[0] == 0)
						break;
					vals[0] = vals[0] - vals[1];
					if(vals[0] == 0)
						break;
					vals = reduce(vals[0], vals[1]);
					flag = false;
					check(0);
				}
				if(flag == false){
					ans[i] = -1;
				}
				else{
					//System.out.println("final");
					//System.out.println(vals[0]+"/"+vals[1]);
					vals = reduce(vals[0], vals[1]);
					if(vals[0] == 0 || (vals[0] == vals[1]))
						ans[i] = c1;
					else
						ans[i] = -1;
				}
			}
			else{
				ans[i] = -1;
			}
			counter = 0;
		}
		for(int i=0;i<T;i++){
			if(ans[i] != -1)
				System.out.println("Case #"+(i+1)+": "+ans[i]);
			else
				System.out.println("Case #"+(i+1)+": impossible");
		}
	}
}