import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.Scanner;


public class ProbB {
	public static void main(String[] args) throws Exception {
//		Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("B.in"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numCases=Integer.parseInt(sc.nextLine());
		for(int caseNum=1; caseNum<=numCases; caseNum++){
			String[] inps = sc.nextLine().split("\\s+");
			int realX = Integer.parseInt(inps[0]);
			int realY = Integer.parseInt(inps[1]);
			int x = Math.abs(realX);
			int y = Math.abs(realY);
			int sum = x+y;
			int n = 0;
			for(n=1; true; n++)
				if((n*(n+1))/2>=sum)
					break;
			int balanceGoal = -1;
			boolean used[] = new boolean[n];
			boolean balancer[] = new boolean[n];
			findN: for(; true; n++){
				int total = n*(n+1)/2;
				if((total-sum)%2!=0)
					continue;
				used = new boolean[n];
				balancer = new boolean[n];
				if(total - sum > 0){
					balanceGoal = (total-sum)/2;
//					used[balancer-1] = true;
					int tempSum = 0;
//					System.out.println("Balance goal: "+balanceGoal+" n:"+n);
					for(int i=n-1; i>=0; i--){
						if(tempSum+i+1<balanceGoal){
							used[i] = true;
							balancer[i] = true;
							tempSum += i+1;
//							System.out.println("Used "+(i+1));
						}else if(tempSum+i+1==balanceGoal){
							used[i] = true;
							balancer[i] = true;
							tempSum += i+1;
//							System.out.println("Used "+(i+1));
							break;
						}
					}
					if(tempSum!=balanceGoal)
						continue findN;
				}
				int tempSum = 0;
				int goal = x+(total-sum)/2;
//				System.out.println("Goal: "+goal);
				for(int i=n-1; i>=0; i--){
					if(used[i])
						continue;
					if((i+1+tempSum)<goal){
						used[i] = true;
						tempSum += i+1;
					}else if(i+1+tempSum == goal){
						used[i] = true;
						break findN;
					}
				}
			}
			System.out.print("Case #"+caseNum+": ");
			for(int i=0; i<n; i++){
				if(used[i] && !balancer[i]){
					if(realX>0)
						System.out.print("E");
					else
						System.out.print("W");
				}else if(used[i] && balancer[i]){
					if(realX>0)
						System.out.print("W");
					else
						System.out.print("E");
				}else{
					if(realY>0)
						System.out.print("N");
					else
						System.out.print("S");
				}
			}
			System.out.println();
		}
	}
}
