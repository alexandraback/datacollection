#include <stdio.h>

int main(){
	int tn, t;
	scanf("%d", &tn);
	
	int n = 20, i;
	int s[500];
	for(i=0;i<500;i++)
			s[i] = 0;
	
	int st[500];
	for(i=0;i<500;i++)
			st[i] = 0;
	int l;
	
	int s1, s2;
	
	for(t=0;t<tn;t++){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d", &s[i]);
		
		s1 = s2 = 0;
		
		for(i=0;i<n;i++)
			st[i] = -1;
		
		l = 0;
		printf("Case #%d:\n", t+1);
		while(l >= 0){
			if(st[l] < 2){
				if(st[l] == 1){
					s1 -= s[l];
					s2 += s[l];
				} else if(st[l] == 0){
					s1 += s[l];
				}
				st[l]++;
			} else {
				st[l] = -1;
				s2 -= s[l];
				l--;
				continue;
			}
			
			if(s1 == s2 && s1 > 0){
				for(i=0;i<n;i++)
					if(st[i] == 1)
						printf("%d ", s[i]);
				printf("\n");
				for(i=0;i<n;i++)
					if(st[i] == 2)
						printf("%d ", s[i]);
				printf("\n");
				break;
			}
			if(l < n - 1)
				l++;
		}
		
		if(l < 0)
			printf("Impossible\n");
	}
}
