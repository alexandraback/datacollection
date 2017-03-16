public class C {
	public static Boolean isPalindrome(String str){
		int len = str.length();
		int mid_len =  len/2;
		for(int i=0; i <= mid_len; i++){
			if (!(str.substring(i,i+1).equals(str.substring(len-i-1, len-i)))){
				return Boolean.FALSE;
			}
		}
		return Boolean.TRUE;
	}
	
	public static java.util.List<java.math.BigInteger> create_target_list(java.util.Map<Integer, java.util.List<String>> src){
		java.util.List<java.math.BigInteger> list = new java.util.ArrayList<java.math.BigInteger>();
		for(int i = 1; i<= 50; i++){
			try{
				java.util.List<String> src_list = src.get(new Integer(i));
				java.util.Iterator<String> iterator = src_list.iterator();
				while(iterator.hasNext()){
					list.add( (new java.math.BigInteger(iterator.next())).pow(2) );
				}
			}catch(Exception e){
				continue;
			}
		}
		return list;
	}
	
	public static java.util.Map<Integer, java.util.List<String>> create_source_list() {
		java.util.Map<Integer, java.util.List<String>> src = new java.util.HashMap<Integer, java.util.List<String>>();
		java.util.List<String> one = new java.util.ArrayList<String>();
		one.add("1");
		one.add("2");
		one.add("3");
		java.util.List<String> two = new java.util.ArrayList<String>();
		two.add("11");
		two.add("22");
		src.put(new Integer("1"), one);
		src.put(new Integer("2"), two);
		
		String temp;
		String result;
		int mid_len;
		for(int i=4; i<= 50; i=i+2){
			java.util.List<String> new_list_d = new java.util.ArrayList<String>();
			java.util.List<String> new_list_s = new java.util.ArrayList<String>();
			
			java.util.List<String> cur_list = src.get(new Integer(i-2));
			java.util.Iterator<String> iterator = cur_list.iterator();
			while(iterator.hasNext()){
				temp = iterator.next();
				mid_len = (i-2)/2;
				result = temp.substring(0, mid_len) + "11" + temp.substring(mid_len);
				if ( isPalindrome( (new java.math.BigInteger(result)).pow(2).toString()) == Boolean.TRUE)
				new_list_d.add(result);
				
				result = temp.substring(0, mid_len) + "00" + temp.substring(mid_len);
				if ( isPalindrome( (new java.math.BigInteger(result)).pow(2).toString()) == Boolean.TRUE)
				new_list_d.add(result);
				
				
				result = temp.substring(0, mid_len) + "1" + temp.substring(mid_len);
				if ( isPalindrome( (new java.math.BigInteger(result)).pow(2).toString()) == Boolean.TRUE)
				new_list_s.add(result);
				
				result = temp.substring(0, mid_len) + "0" + temp.substring(mid_len);
				if ( isPalindrome( (new java.math.BigInteger(result)).pow(2).toString()) == Boolean.TRUE)
				new_list_s.add(result);
				
				result = temp.substring(0, mid_len) + "2" + temp.substring(mid_len);
				if ( isPalindrome( (new java.math.BigInteger(result)).pow(2).toString()) == Boolean.TRUE)
				new_list_s.add(result);
			}
			
			src.put(new Integer(i), new_list_d);
			src.put(new Integer(i-1), new_list_s);
		}
		return src;
	}
	
	public static java.util.List<java.math.BigInteger> create_list () {
		java.util.List<java.math.BigInteger> list = new java.util.ArrayList<java.math.BigInteger>();
		java.math.BigInteger max_big = new java.math.BigInteger("10");
		max_big = max_big.pow(100);

		java.math.BigInteger min_big = new java.math.BigInteger("1");
		
		int check, len;
		while( min_big.pow(2).compareTo(max_big)<=0 ){
			 if (isPalindrome(min_big.toString())==Boolean.TRUE && isPalindrome(min_big.pow(2).toString())==Boolean.TRUE){
				 list.add(min_big.pow(2));
				 //System.out.println(min_big.pow(2).toString());
				 System.out.println(min_big.toString());
			 }
			 min_big = min_big.add(new java.math.BigInteger("1"));
			 //len = min_big.toString().length();
			 //if (len == 1){
			//	 min_big = min_big.add(new java.math.BigInteger("1"));
			 //}else{
			//	 check = Integer.parseInt(min_big.toString().substring(0,1));
			//	 if (check <=2 ){
			//		 min_big = min_big.add(new java.math.BigInteger("1"));
			//	 }else{
			//		 min_big = new java.math.BigInteger("10");
			//		 min_big = min_big.pow(len+1);
			//		 min_big = min_big.add(new java.math.BigInteger("1"));
			//	 }
			 //}
		}
		return list;
	}
	
	public static void main(String[]args) throws Exception {
		java.io.File file = new java.io.File(args[0]);
		java.io.FileInputStream finput = new java.io.FileInputStream(file);
		java.io.DataInputStream dinput = new java.io.DataInputStream(finput);
		java.io.BufferedReader breader = new java.io.BufferedReader(new java.io.InputStreamReader(dinput));
		
		java.io.File result_file = new java.io.File(args[0]+"_result.txt");
		java.io.FileOutputStream foutput = new java.io.FileOutputStream(result_file);
		java.io.DataOutputStream doutput = new java.io.DataOutputStream(foutput);
		java.io.BufferedWriter bwriter = new java.io.BufferedWriter(new java.io.OutputStreamWriter(doutput));
		
		
		
		String line;
		
		line = breader.readLine();
		int times=Integer.parseInt(line);
		String[]strRange;
		java.math.BigInteger[]range = new java.math.BigInteger[2];
		int cnt; 
		
		
		java.util.List<java.math.BigInteger> search_list = create_target_list(create_source_list());
		java.math.BigInteger tmp_big;
		
		for ( int i=1; i<=times; i++){
			line = breader.readLine();
			cnt = 0;
			strRange = line.split(" ");
			range[0] = new java.math.BigInteger(strRange[0]);
			range[1] = new java.math.BigInteger(strRange[1]);
			
			java.util.Iterator<java.math.BigInteger> iterator = search_list.iterator();
			while(iterator.hasNext()){
				tmp_big = iterator.next();
				if (tmp_big.compareTo(range[0]) >=0 && tmp_big.compareTo(range[1]) <= 0) {
					cnt++;
				}
			}
			
			bwriter.write("Case #"+i+": "+cnt);
			if ( i != times) {
				bwriter.newLine();
			}
			bwriter.flush();
		}
		doutput.close();
		dinput.close();
	}
}
