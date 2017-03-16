#include<stdio.h>
#include<math.h>

FILE *fi, *fo;



long long partElf(long long dChild, long long dParent){
	if (dChild == 0)
		return 0;
	else if (dParent % dChild != 0){
		
		if (dParent % 2 == 0){	//茄率何葛 1 贸府
			if (dParent / dChild < 2){
				long long ans = partElf(dChild - dParent / 2, dParent);
				if (ans == 0)
					return 0;
				else{
					return 1;
				}
			}
			else{				//茄率何葛 0贸府
				long long ans = partElf(dChild, dParent / 2);
				if (ans != 0){
					return ans + 1;
				}
			}
		}	

		return 0;
	}
	else{
		long long i=0;
		long long temp, goal;
		temp = 1;
		goal = dParent / dChild;

		while (temp < goal){
			temp *= 2;
			i++;
		}
		if (temp == goal)
			return i;
		else
			return 0;
	}
}




int main(){
	fi = fopen("input.txt", "r");
	fo = fopen("output.txt", "w");
	
	long long dChild, dParent, ans;
	int t;
	int i;
	
	fscanf(fi, "%d", &t);

	for (i = 1; i <= t; i++){
		fscanf(fi, "%lld/%lld\n", &dChild, &dParent);
		ans = partElf(dChild, dParent);
		if (ans == 0){
			fprintf(fo, "Case #%d: impossible\n", i);
		}
		else{
			fprintf(fo, "Case #%d: %lld\n", i, ans);
		}
	}
	

	fclose(fi);
	fclose(fo);
	return 0;
}
