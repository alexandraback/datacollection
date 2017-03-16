#include<cstdio>
int a[55];
void dfs(int t,int s)
{
	if (t>25 || s+2>9) return;
	if (s+2<10){
		a[t]=1;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		for (int i=0;i<=t;i++) printf("%d",a[i]);
		puts("");
		}
	if (s+2<10){
		a[t]=1;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		printf("0");
		for (int i=0;i<=t;i++) printf("%d",a[i]);	
		puts("");
		}
	if (s+3<10){
		a[t]=1;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		printf("1");
		for (int i=0;i<=t;i++) printf("%d",a[i]);	
		puts("");
		}
	if (s+6<10){
		a[t]=1;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		printf("2");		
		for (int i=0;i<=t;i++) printf("%d",a[i]);
		puts("");
		}
	if (s+8<10){
		a[t]=2;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		for (int i=0;i<=t;i++) printf("%d",a[i]);
		puts("");
		}
	if (s+8<10){
		a[t]=2;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		printf("0");
		for (int i=0;i<=t;i++) printf("%d",a[i]);
		puts("");
		}
	if (s+9<10){
		a[t]=2;
		for (int i=t;i>=0;i--) printf("%d",a[i]);
		printf("1");
		for (int i=0;i<=t;i++) printf("%d",a[i]);
		puts("");
		}
	for (int i=0;i<2;i++) a[t]=i,dfs(t+1,s+i*2);
}
int main()
{
	freopen("list.txt","w",stdout);
	puts("1");
	puts("2");
	puts("3");
	dfs(0,0);
	return 0;
}


/*python
def find(x):
    if (x<=L[0]):
        return -1
    l=0
    r=n-1
    while (l<r):
        m=(l+r)//2
        if (l==m):
            m=m+1
        #print(l,m,x,L[m],L[m]<x)
        if (L[m]<x):
            l=m
        else:
            r=m-1
    #print(l)
    return l
    
List=open('ListPy.txt','r')
In=open('C.in','r')
Out=open('C.out','w')
n=54133
L=[0 for i in range(0,n)]
for i in range(0,n):
    s=List.readline()
    L[i]=int(s.split()[0])

s=In.readline()
T=int(s.split()[0])
for i in range(T):
    s=In.readline()
    Q=s.split()
    QL=int(Q[0])
    QR=int(Q[1])
    ans=find(QR+1)-find(QL);
    Out.write('Case #')
    Out.write(str(i+1))
    Out.write(': ')
    Out.write(str(ans))
    Out.write('\n')

List.close()
In.close()
Out.close()
*/