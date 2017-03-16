#include <stdio.h>

int check(int* b,int c, int r){
	int i;

	//printf("debug:");
	//for(i=0;i<r;i++){ printf(" %d",b[i]);} printf("\n");
	if(r>=2){
		for(i=0;i<r-1;i++){ if(b[i] == c-1) return 0; }
		if(b[r-1] != c-1 && b[r-1] != b[r-2]) return 0;
		return 1;
	}else{
		return 1;
	}
}

int main(){
	int n;
	int i,j,l;
	int r,c,m;
	int s,b;
	int buf[50];
	int ret;
	scanf("%d",&n);
	for(l=1;l<=n;l++){
		printf("Case #%d:\n",l);
		scanf("%d %d %d",&r,&c,&m);
		s = c<r?c:r;
		b = c+r-s;
		if(s>=3){
			buf[s-1] = 0;
			buf[s-2] = 0;
			for(i=0;i<s-2;i++){
				if(m>=b-2){ buf[i] = b-2; }
				else { buf[i] = m; }
				m -= buf[i];
			}
			//printf("debug x1: %d",m);
			//for(i=0;i<s;i++){printf(" %d",buf[i]);}printf("\n");
			if(m>0){
				if(m%2==1){ buf[s-3]--; m++; }
				buf[s-1] = m/2<b-3?m/2:b-3;
				buf[s-2] = buf[s-1];
				m -= (buf[s-1]*2);
			}
			//printf("debug x2: %d",m);
			//for(i=0;i<s;i++){printf(" %d",buf[i]);}printf("\n");
			if(m>0){
				int fc = m/2<s-3?m/2:s-3;
				for(i=0;i<fc;i++){ buf[i] += 2; }
				m-= fc*2;
			}
			//printf("debug x3: %d",m);
			//for(i=0;i<s;i++){printf(" %d",buf[i]);}printf("\n");
			if(m>0){
				if(buf[s-3] == b-3){buf[s-3]++;m--;}
				buf[s-3] += 2<m?2:m; m-=2<m?2:m;
				for(i=0;i<3;i++){
					for(j=0;j<2;j++){
						if(m>0){ buf[s-2+j]++; m--;}
					}
				}
			}
			//printf("debug x4: %d",m);
			//for(i=0;i<s;i++){printf(" %d",buf[i]);}printf("\n");
		}else{
			int adder = m/s;
			for(i=0;i<s;i++){
				buf[i] = adder;
				m -= adder;
			}
			buf[0] += m;
		}
		if(check(buf,b,s)){
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					if(s==r){
						if(i==r-1 && j==c-1){printf("c");}
						else if(buf[i]>j){printf("*");}
						else{printf(".");}
					}else{
						if(i==r-1 && j==c-1){printf("c");}
						else if(buf[j]>i){printf("*");}
						else{printf(".");}
					}
				}
				printf("\n");
			}
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
}
