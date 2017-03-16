#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
#define fin in
#define fout out
#define Max 50
typedef unsigned uint;
uint T,col[Max],row[Max],temp[Max];
char mines[5][5];
bool checked[5][5];
struct context
{
    uint R;
    uint C;
    uint M;
    uint E;
    uint countEmpty()
    {
        E=R*C-M;
        return E;
    }
};
context c;
void fixData(uint& cc,uint& rr)
{
    if(c.E>=(2*c.R+2*c.C-4))
    {
        cc=c.C;
        rr=c.R;
        return;

    }
    uint length=(c.E+4)/2;
    cc=length/2;
    rr=length-cc;
    if(c.R>c.C&&rr<cc)
        swap(rr,cc);
    while(cc>c.C)
    {
        cc--;
        rr++;
    }
    while(rr>c.R)
    {
        rr--;
        cc++;
    }
}
bool Judge()
{
    uint m,i,cc,rr;
    memset(col,0,sizeof(uint)*c.C);
    if(c.M==0)//no mine
    {
        memset(col,c.R,sizeof(uint)*c.C);
        return true;
    }
    if(c.E==1)//only one empty
    {
        return true;
    }
    if(c.R>=c.C)//行大于列
    {
        if(c.C==1)
        {
            col[0]=c.E;
            return true;
        }
        else if(c.C==2)
        {
            if(c.M%2==1||c.E==2)
            {
                return false;
            }
            else
            {
                col[0]=col[1]=c.E/2;//modify
                return true;
            }
        }
    }
    else
    {
        if(c.R==1)
        {
            for(i=0;i<c.E;i++)
            {
                col[i]=1;//modify
            }            
            return true;
        }
        else if(c.R==2)
        {
            if(c.M%2==1||c.E==2)
            {
                return false;
            }
            else
            {
                for(i=0;i<c.E/2;i++)
                {
                    col[i]=2;//modify
                }
                return true;
            }
        }
    }
    if(c.E==2||c.E==3||c.E==5||c.E==7)
    {
        return false;
    }
    else 
    {
        fixData(cc,rr);
        m=c.E;
        for(i=2;i<cc;i++)
        {
            col[i]=2;
            m-=2;
        }
        col[0]=col[1]=rr;
        m=m-2*rr;
        for(i=2;i<cc;i++)
        {
            if(m>(rr-2))
            {
                col[i]+=(rr-2);
                m=m-rr+2;
            }
            else
            {
                col[i]+=m;
                break;
            }
        }        
        return true;
    }
}
void output(ostream& out)
{
    uint i,j;
    for(i=0;i<c.R;i++)
    {
        for(j=0;j<c.C;j++)
        {
            if(j==0&&i==0)
            {
                out<<"c";
                mines[i][j]='c';
            }
            else if(i<col[j])
            {
                out<<".";
                mines[i][j]='.';
            }
            else 
            {
                out<<"*";
                mines[i][j]='*';
            }
        }
        out<<endl;
    }
}
context k;
bool notmine(int i,int j)
{
    if(i<0||i>=c.R||j<0||j>=c.C)
    {
        return true;
    }
    return mines[i][j]!='*';
}
void ck(int i,int j)
{
    if(i<0||i>=(int)c.R||j<0||j>=c.C)
        return;
    if(checked[i][j])
        return;
    checked[i][j]=true;
    switch(mines[i][j])
    {
    case 'c':
        ck(i-1,j-1);
        ck(i-1,j);
        ck(i-1,j+1);
        ck(i,j-1);
        ck(i,j+1);
        ck(i+1,j-1);
        ck(i+1,j);
        ck(i+1,j+1);
        k.E++;
        break;
    case '.':
        k.E++;
        if(notmine(i-1,j-1)
            &&notmine(i-1,j)
            &&notmine(i-1,j+1)
            &&notmine(i,j-1)
            &&notmine(i,j+1)
            &&notmine(i+1,j-1)
            &&notmine(i+1,j)
            &&notmine(i+1,j+1))
        {
            ck(i-1,j-1);
            ck(i-1,j);
            ck(i-1,j+1);
            ck(i,j-1);
            ck(i,j+1);
            ck(i+1,j-1);
            ck(i+1,j);
            ck(i+1,j+1);
        }
        break;
    case '*':
        k.M++;
        break;
    }


}
bool check()
{
    memset(checked,0,sizeof(bool)*25);
    k.C=c.C;
    k.R=c.R;  
    k.E=0;
    k.M=0;
    ck(0,0);
    return k.E==c.E&&c.M==(k.R*k.C-k.E);
}
int main()
{
    ifstream fin("C-small-attempt3.in");
    ofstream fout("C.txt");
    in >> T;
    for (uint i = 0; i++<T;)
    {
        in>>c.R>>c.C>>c.M;
        c.countEmpty();
        out<<"Case #"<<i<<": "<<endl;
        if(Judge())
        {
            output(out);
            if(!check())
            {
                out<<"Case Error!"<<endl;
            }
        }
        else
            out<<"Impossible"<<endl;
    }
    fin.close();
    fout.close();
}

