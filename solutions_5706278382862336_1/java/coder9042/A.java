import java.io.*;
class A{
	static Long counter = Long.parseLong("0");
	static Long vals[] = new Long[2];
	static boolean flag = false;
	public static Long[] separate(String str){
		int index = str.indexOf("/");
		Long ans[] = new Long[2];
		ans[0] = Long.parseLong(str.substring(0,index));
		ans[1] = Long.parseLong(str.substring(index+1, str.length()));
		return ans;
	}
	public static Long check(Long count){
		//System.out.println(vals[0]+"/"+vals[1]);
		Long temp[] = new Long[2];
		if(vals[0] == 0){
			return Long.parseLong("-1");
		}
		temp[0] = vals[0];
		temp[1] = vals[1];
		vals[0] = vals[0] * 2;
		vals[0]= vals[0] - vals[1];
		counter += 1;
		if(counter == 40){
			return Long.parseLong("-1");
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
	public static Long check2(){
		Long temp[] = new Long[2];
		temp[0] = vals[0];
		temp[1] = vals[1];
		return Long.parseLong("0");
	}
	public static Long HCF(Long a, Long b){
		if(b == 0)
			return a;
		else
			return HCF(b, a%b);
	}
	public static Long[] reduce(Long a, Long b){
		Long h = HCF(a,b);
		a = a/h;
		b = b/h;
		Long ans[] = new Long[2];
		ans[0] = a;
		ans[1] = b;
		return ans;
	} 
	public static void main(String args[])throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		Long ans[] = new Long[T];
		for(int i=0;i<T;i++){
			Long c1 = Long.parseLong("0"), c2 = Long.parseLong("0");
			String str = in.readLine();
			vals = separate(str);
			c1 = check(Long.parseLong("0"));
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
					check(Long.parseLong("0"));
				}
				if(flag == false){
					ans[i] = Long.parseLong("-1");
				}
				else{
					//System.out.println("final");
					//System.out.println(vals[0]+"/"+vals[1]);
					vals = reduce(vals[0], vals[1]);
					if(vals[0] == 0 || (vals[0] == vals[1]))
						ans[i] = c1;
					else
						ans[i] = Long.parseLong("-1");
				}
			}
			else{
				ans[i] = Long.parseLong("-1");
			}
			counter = 0L;
		}
		for(int i=0;i<T;i++){
			if(ans[i] != Long.parseLong("-1"))
				System.out.println("Case #"+(i+1)+": "+ans[i]);
			else
				System.out.println("Case #"+(i+1)+": impossible");
		}
	}
}