import java.io.*;

public class CSmall {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015/io/C-small-attempt8.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] str = input.readLine().split(" ");
			int L = Integer.parseInt(str[0]);
			int X = Integer.parseInt(str[1]);
			boolean isok = false;
			String st = input.readLine();
			StringBuilder sb = new StringBuilder();
			for(int j = 0 ; j < X ; j++){
				sb.append(st);
			}
			Status first = new Status();
			Status second = new Status();
			Status third = new Status();
			boolean readl = false;
			for(int j = 0 ; j < L * X - 2 ; j++){
				first = str(first, new Status(sb.charAt(j), false));
				//System.out.println(first.c+","+first.minus+","+"phase1:"+j);
				if(first.c != 'i' || first.minus)continue;
					for(int k = j + 1 ; k < L * X - 1 ; k++){
						second = str(second, new Status(sb.charAt(k), false));
						//System.out.println(second.c+","+second.minus+","+"phase2:"+k);
						if(readl){
							third = str(new Status(sb.charAt(k), true), third);
						}
						if(second.c != 'j'|| second.minus)continue;
						if(!readl){
							for(int l = k + 1 ; l < L * X ; l++){
								third = str(third, new Status(sb.charAt(l), false));
							}
							readl = true;
						}
						if(third.c == 'k' && !third.minus){
							//System.out.println(j+","+k+","+sb.length());
							isok = true;
							break;
						}
					}
					readl = false;
					second = new Status();
					third = new Status();
				if(isok)break;
			}
			if(isok){
				pw.println("Case #"+(i+1)+": YES");
			}else{
				pw.println("Case #"+(i+1)+": NO");
			}
			pw.flush();
		}
		input.close();
		pw.close();
	}

	public static Status str(Status st,Status st2){
		if(st.c == 'a')return new Status(st2.c,st.minus);
		if(st2.minus){
			if(st.minus){
				st.minus = false;
			}else{
				st.minus = true;
			}
		}
		if(st.c == '1'){
			if(st2.c == 'i'){
				st.c = 'i';
			}else if(st2.c == 'j'){
				st.c = 'j';
			}else if(st2.c == 'k'){
				st.c = 'k';
			}else if(st2.c == '1'){
				st.c = '1';
			}
		}else if(st.c == 'i'){
			if(st2.c == 'i'){
				st.c = '1';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == 'j'){
				st.c = 'k';
			}else if(st2.c == 'k'){
				st.c = 'j';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == '1'){
				st.c = 'i';
			}
		}else if(st.c == 'j'){
			if(st2.c == 'i'){
				st.c = 'k';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == 'j'){
				st.c = '1';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == 'k'){
				st.c = 'i';
			}else if(st2.c == '1'){
				st.c = 'j';
			}
		}else if(st.c == 'k'){
			if(st2.c == 'i'){
				st.c = 'j';
			}else if(st2.c == 'j'){
				st.c = 'i';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == 'k'){
				st.c = '1';
				if(st.minus){
					st.minus = false;
				}else{
					st.minus = true;
				}
			}else if(st2.c == '1'){
				st.c = 'k';
			}
		}
		return new Status(st.c,st.minus);
	}
}

class Status{
	boolean minus = false;
	char c = 'a';
	Status(char c,boolean minus){
		this.c = c;
		this.minus = minus;
	}
	Status(){
		minus = false;
		c = 'a';
	}
}
