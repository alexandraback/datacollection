#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
void deal(int);

const int mid=500000;

struct att
{
    int e,w,d,s;
};

att a[1000000];

int w[mid*4];

int main()
{
    fin.open("gcj2013-1C-C.in");
    fout.open("gcj2013-1C-C.out");
    int t;
    fin>>t;
    for (int i=0;i<t;i++)
        deal(i);
}

bool cmp(att a1,att a2)
{
    return a1.d<a2.d;
}

void deal(int p)
{
    int n;
    fin>>n;
    int m=0,sum=0;
    memset(w,0,sizeof(w));
    for (int i=0;i<n;i++)
    {
        int d0,n0,w0,e0,dd,s0,p0,ds;
        fin>>d0>>n0>>w0>>e0>>s0>>dd>>p0>>ds;
        for (int j=0;j<n0;j++)
        {
            att t;
            t.e=e0+j*p0;
            t.w=w0+j*p0;
            t.d=d0+j*dd;
            t.s=s0+j*ds;
            a[m]=t;
            m++;
        }
    }
//    system("pause");
    sort(a,a+m,cmp);
//    system("pause");
    int i=0,j=0;
    while (i<m)
    {
        j=i;
        while (j<m && a[j].d==a[i].d)
        {
 //           cout<<a[j].d<<' '<<a[j].s<<' '<<a[j].w<<' '<<a[j].e<<endl;
            j++;
        }
        for (int k=i;k<j;k++)
        {
            for (int o=(mid+a[k].w)*2;o<=(mid+a[k].e)*2;o++)
                if (w[o]<a[k].s)
                {
                    sum++;
                    break;
                }
        }
        for (int k=i;k<j;k++)
        {
            for (int o=(mid+a[k].w)*2;o<=(mid+a[k].e)*2;o++)
                if (w[o]<a[k].s)
                {
                    w[o]=a[k].s;
                }
        }
        i=j;
    }
 //   system("pause");
    fout<<"Case #"<<p+1<<": "<<sum<<endl;    
}
