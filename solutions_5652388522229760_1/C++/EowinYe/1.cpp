#include <stdio.h>

int main(){
	int flag[10];
	int cnt,Test;
	FILE *in=fopen("A-large.in","r");
	FILE *out=fopen("A-large.out","wt");
	fscanf(in,"%d",&Test);
	cnt=0;
	while (Test--){
		int i,n,now,tmp;
		cnt++;
		fscanf(in,"%d",&n);
		now=0;
		for (i=0;i<10;i++)
			flag[i]=0;
		if (n==0){
			fprintf(out,"Case #%d: INSOMNIA\n",cnt);
			continue;
		}
		while (true){
			now+=n;
			tmp=now;
			while (tmp>0){
				flag[tmp%10]=true;
				tmp=tmp/10;
			}
			int CAN=1;
			for (i=0;i<10;i++){
				if (!flag[i]){
					CAN=0;
					break;
				}
			}
			if (CAN){
				fprintf(out,"Case #%d: %d\n",cnt,now);
				break;
			}
		}
	}
	fclose(in);
	fclose(out);
}
