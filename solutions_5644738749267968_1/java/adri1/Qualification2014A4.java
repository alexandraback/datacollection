package question;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Set;

import utils.FileTools;

public class Qualification2014A4 {
	public static void main(String[] args) {
		try {
			FileTools ft = new FileTools("D-large.in");
			int T = Integer.parseInt(ft.in.readLine());
			String line;

			for (int i = 0; i < T; i++) {
				int x=Integer.parseInt(ft.in.readLine());
				String block1=ft.in.readLine();
				String block2=ft.in.readLine();
				String[] bs1=block1.split(" ");
				String[] bs2=block2.split(" ");
				HashMap<Double, Integer> whose=new HashMap<Double, Integer>();
				
				ArrayList<Double> sortList=new ArrayList<Double>();
				for(String s:bs1){
					double a=Double.parseDouble(s);
					whose.put(a, 1);
					sortList.add(a);
				}
				for(String s:bs2){
					double a=Double.parseDouble(s);
					whose.put(a, 2);
					sortList.add(a);
				}
				Collections.sort(sortList);
				int war1=0;
				int war2=0;
				int dwar1=0;
				int dwar2=0;
				int dwarres=0;
				for(double d:sortList){
					int from=whose.get(d);
					if(from==1){
						war1++;
						if(dwar2>0){
							dwar2--;
							dwarres++;
						}else{
							dwar1++;
						}
					}
					else{
						if(war1>0){
							war1--;
						}else{
							war2++;
						}
						dwar2++;
					}
				}
				ft.out.write("Case #" + (i + 1) + ": "+dwarres+" "+war2);

				System.out.println("Case #" + (i + 1) + ": "+dwarres+" "+war2);
				ft.out.newLine();
//				ft.in.readLine();
			}

			ft.out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
