#include <bits/stdc++.h>
using namespace std;

#define MAXC 25

int T, R, C, W, ct[MAXC];

int main() {
	FILE *in, *out;
	in = fopen("input.txt","r"), out=fopen("output.txt","w");
	fscanf(in, "%d",&T);
	for(int i=1;i<=T;i++) {
		memset(ct, 0, sizeof ct);
	    fscanf(in, "%d %d %d",&R,&C,&W);
	    int parto = W-1, ans=0;
	    if(W==1) ans=R*C;
	    else if(W==C) ans = R-1+C;
	    else {
		 for(int j=0; j+W<=C; j++) 
			 for(int k=0; k < W; k++) ++ct[j+k];
		 
		 int dietro=0;
	     for(; parto<C; parto+=W) {
			int navi = ct[parto];
			if(navi>1) ans=max(ans, dietro+W+1);
			else ans=max(ans, dietro+W);
			++dietro;
		 }
		 ans *= R;
	    }
	    fprintf(out, "Case #%d: %d\n",i,ans);
    }
    fclose(in), fclose(out);
	return 0;
}
