#include<cstdio>
#include<cstring>

char K[105];
char L[105];
int f[105];
int key[27];
int k, l, s;

void failure()
{
    for (int i=1, j=f[0]=-1; i<l; ++i)
    {
        while (j >= 0 && L[j+1] != L[i])
            j = f[j];
 
        if (L[j+1] == L[i]) j++;
 
        f[i] = j;
    }
}

bool can()
{
	int i;
	memset(key, 0, sizeof(key));
	for(i=0;i<k;i++){
		key[K[i]-'A']++;
	}
	for(i=0;i<l;i++){
		if(key[L[i]-'A']==0) return 0;
	}
	return 1;
}

int main()
{
	freopen("D:\\B-small-attempt0.in", "r", stdin);
	freopen("D:\\outB.txt", "w", stdout);
	int t, cases, maxx, ept, i;
	float ans;
	scanf("%d", &t);
	for(cases=1;cases<=t;cases++){
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s", K);
		scanf("%s", L);
		if(can()){
			memset(f, -1, sizeof(f));
			failure();
			maxx=1+(s-l)/(l-f[l-1]-1);
			//printf("%d\n", maxx);
			ept=1;
			for(i=0;i<l;i++) ept*=key[L[i]-'A'];
			ans=(float)ept;
			ans*=(s-l+1);
			//printf("pi=%f\n",ans);
			for(i=0;i<l;i++) ans/=(float)k;
			//printf("expected=%f\n",ans);
			ans=(float)maxx-ans;
			//printf("sub=%f\n",ans);
		}
		else ans=0;
		printf("Case #%d: %.7f\n",cases, ans);
	}
	return 0;
}
