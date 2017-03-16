#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct trip
{
    int x,y,z;
};
trip A[1005];
int main()
{
    FILE *ptrin,*ptrout;
    ptrin=fopen("C:\\Users\\debrup\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\debrup\\Desktop\\out.txt","w");
    int t,T,i,j,p,s,k,K,l,nz,res;
    fscanf(ptrin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(ptrin,"%d%d%d%d",&j,&p,&s,&K);
        res=0;
        for(i=0;i<1000;i++)
            A[i].x=A[i].y=A[i].z=0;
        int comb[5][5][5]={},combjp[5][5]={},combps[5][5]={},combjs[5][5]={},c;
        if(j==1&&p==1&&s==1)
            res=1,A[0].x=A[0].y=A[0].z=1;
        else
        {
            while(true)
            {
                c=0;
                for(i=1;i<=j;i++)
                    for(k=1;k<=p;k++)
                        for(l=1;l<=s;l++)
                        {
                            if(combjp[i][k]<K&&combps[k][l]<K&&combjs[i][l]<K)
                            {
                                c++;
                                res++;
                                comb[i][k][l]++;
                                combjp[i][k]++;
                                combps[k][l]++;
                                combjs[i][l]++;
                            }
                        }
                if(c==0)
                    break;
            }
            for(i=1;i<=j;i++)
                for(k=1;k<=p;k++)
                    for(l=1;l<=s;l++)
                        if(comb[i][k][l])
                        {
                            for(nz=0;nz<1000;nz++)
                                if(A[nz].x==0)
                                    break;
                            for(;comb[i][k][l]--;nz+=2)
                                A[nz].x=i,A[nz].y=k,A[nz].z=l;
                        }
        }
        trip pre;
            pre.x=pre.y=pre.z=0;
            fprintf(ptrout,"Case #%d: %d\n",t,res);
            for(i=0;i<1000;i++)
                if(A[i].x&&A[i].x!=pre.x&&A[i].y!=pre.y&&A[i].z!=pre.z)
                    fprintf(ptrout,"%d %d %d\n",A[i].x,A[i].y,A[i].z);
    }
    fclose(ptrin);
    fclose(ptrout);
    return 0;
}
