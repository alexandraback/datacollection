
public class R2 {

	int answer[];
	public R2(String[] input){
		answer = new int[Integer.parseInt(input[0])];
		int stringCounter =1;
		for (int i =0; i< answer.length;i++){
			String[] desc = input[stringCounter].split(" ");
			stringCounter ++;
			int[][] l = new int[Integer.parseInt(desc[0])][2];
			for (int j = 0; j<l.length; j++){
				String[] level = input[stringCounter].split(" ");
				l[j][0] = Integer.parseInt(level[0]);
				l[j][1] = Integer.parseInt(level[1]);
				
				stringCounter ++;	
			}
			answer[i] =calc(l);
			System.out.println("Case #"+(i+1)+": " + (answer[i]==-1?"Too Bad":answer[i]));
		}	
	}
	
	public int calc(int[][] l){
		int points = 0;
		int moves = 0;
		
		
		java.util.Arrays.sort(l, new java.util.Comparator<int[]>() {
		    public int compare(int[] a, int[] b) {
		        return a[0] - b[0];
		    }
		});
		

		/*
		for (int i = 0; i< l.length; i++){
			if (l[i][1]== 0){
				moves ++;
				points +=2;
				l[i][0] = -1;
				l[i][1] = -1;
			}
			else{
				break;
			}
		}
		
*/
		
		
		int min1[] = findmin(0,l);
		int min2[] = findmin(1,l);
		
		while (min1[0]>-1 || min2[0]>-1){
			
			if (points>=min2[1]){
				moves++;
				if (l[min2[0]][0] == -1){
					points+= 1;
				}
				else{
					points+=2;
				}
				l[min2[0]][0] = -1;
				l[min2[0]][1] = -1;
			}
			else {

				int ndm = 0;
				for (int i = min1[0] +1; i <l.length; i++){
					if (l[i][0] <= points && l[i][0] != -1){
						ndm++;
					}
				}
				
				
				int[] min4 = findemptymin(1,l);

				int[] min3 = findnextmin(0,l);
				
				if (min4[1]<= (ndm+points -1) && min3[0] != -1){
					l[min3[0]][0] = -1;
					points ++;
					moves++;
				}
				
				
				
				else if(points>=min1[1]){
					l[min2[0]][0] = -1;
					moves ++;
					points +=1;
				}
				else{
					return -1;
				}
				
				
			}
			min1 = findmin(0,l);
			min2 = findmin(1,l);
		}
		return moves;
	}
	
	
	public int[] findmin(int x, int[][] l){
		int[] min = new int[2];
		min[0] = -1;
		min[1] = -1;
		for (int i = 0; i< l.length; i++){
			if (l[i][x] > -1){
				if (min[1] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] < min[1]){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] == min[1] && x==1 && l[min[0]][0] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
			}
		}
		return min;
	}
	
	public int[] findemptymin(int x, int[][] l){
		int[] min = new int[2];
		min[0] = -1;
		min[1] = -1;
		for (int i = 0; i< l.length; i++){
			if (l[i][x] > -1 && l[i][0] != -1){
				if (min[1] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] < min[1]){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] == min[1] && x==1 && l[min[0]][0] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
			}
		}
		return min;
	}
	
	
	
	public int[] findnextmin(int x, int[][] l){
		int[] min = new int[2];
		min[0] = -1;
		min[1] = -1;
		for (int i = 0; i< l.length; i++){
			if (l[i][x] > -1){
				if (min[1] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] < min[1]){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] == min[1] && x==1 && l[min[0]][0] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
			}
		}
		


		for (int i = 0; i< l.length; i++){
			if (l[i][x] > -1 && i != min[0]){
				if (min[1] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] < min[1]){
					min[0] = i;
					min[1] = l[i][x];
				}
				else if (l[i][x] == min[1] && x==1 && l[min[0]][0] == -1){
					min[0] = i;
					min[1] = l[i][x];
				}
			}
		}
		
		return min;
	}
	
}

