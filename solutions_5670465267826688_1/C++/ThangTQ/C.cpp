#include<bits/stdc++.h>

using namespace std;

struct nInt
{
    int d, v;
};

nInt C[5][5], A[10004];

nInt operator * (nInt a, nInt b)
{
    nInt c; c.d=a.d*b.d;
    c.d*=C[a.v][b.v].d;
    c.v=C[a.v][b.v].v;
    return c;
}

nInt make(int d, int v)
{
    nInt t;
    t.v=v; t.d=d;
    return t;
}

bool operator == (nInt a, nInt b)
{
    return (a.d==b.d&&a.v==b.v);
}

nInt tM, S;
int N;
long long X;

void prep()
{
    C[0][0]=make(1,0); C[0][1]=make(1,1); C[0][2]=make(1,2); C[0][3]=make(1,3);
    C[1][0]=make(1,1); C[1][1]=make(-1,0); C[1][2]=make(1,3); C[1][3]=make(-1,2);
    C[2][0]=make(1,2); C[2][1]=make(-1,3); C[2][2]=make(-1,0); C[2][3]=make(1,1);
    C[3][0]=make(1,3); C[3][1]=make(1,2); C[3][2]=make(-1,1); C[3][3]=make(-1,0);
    tM=make(-1,0);
}

void nhap()
{
    scanf("%d%lld\n",&N,&X);
    S=make(1,0);
    for(int i=1; i<=N; i++)
    {
        char c=getchar();
        if (c=='i')
            A[i]=make(1,1);
        else if (c=='j')
            A[i]=make(1,2);
        else A[i]=make(1,3);
        S=S*A[i];
    }
    nInt T=make(1,0);
    for(int i=1; i<=X%4; i++)
        T=T*S;
    S=make(T.d,T.v);
}


bool ktr()
{
    S=make(1,0);
    nInt I = make(1,1), tK = make(1,3);
    int j=0;
    bool ok = 0;
    for(int i=1; i<=min(X,10ll)*N; i++)
    {
        j++; if (j>N) j-=N;
        S=S*A[j];
        //cout<<S.d<<' '<<S.v<<endl;
        if (S==tK)
        {
            if (ok)
                return 1;
        }
        if (S==I)
        {
            ok=1;
        }
    }
    return 0;
}

int main()
{
	//freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	prep();
	int T; scanf("%d\n",&T);
	for(int t=1; t<=T; t++)
    {
        nhap();
        if (!(S==tM))
        {
            printf("Case #%d: NO\n",t);
            continue;;
        }
        bool ok=ktr();
        if (ok)
            printf("Case #%d: YES\n",t);
        else printf("Case #%d: NO\n",t);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
