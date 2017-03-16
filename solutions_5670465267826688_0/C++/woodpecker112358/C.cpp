#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10005],str[100005];
void evaluate(char &cur,int &sgn,char s)
{
    //cout<<cur<<" "<<sgn<<" "<<s[i]<<endl;
    if(cur=='1')
    {
        cur=s;
    }
    else if(cur==s)
    {
        sgn=-sgn;
        cur='1';
    }
    else if((cur=='i'&&s=='j')||(cur=='j'&&s=='k')||(cur=='k'&&s=='i'))
    {
        cur='i'+'j'+'k'-cur-s;
        //cout<<"here1"<<endl;
    }
    else
    {
        //cout<<"here2"<<endl;
        cur='i'+'j'+'k'-cur-s;
        sgn=-sgn;
    }
}
bool do_eval(char *str,int n)
{
    char cur='1';
    int sgn=1,pos=0;
    while((cur!='i'||sgn!=1)&&pos<n)
    {
        evaluate(cur,sgn,str[pos++]);
    }
    if(pos==n)
        return false;
    //cout<<"first "<<pos<<endl;
    cur='1';
    sgn=1;
    while((cur!='j'||sgn!=1)&&pos<n)
    {
        evaluate(cur,sgn,str[pos++]);
    }
    if(pos==n)
        return false;
    //cout<<"second"<<endl;
    cur='1';
    sgn=1;
    while(pos<n)
    {
        evaluate(cur,sgn,str[pos++]);
    }
    //cout<<cur<<" "<<sgn<<endl;
    if(cur=='k'&&sgn==1)
        return true;
    else
        return false;
}
int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("Cout.txt","w",stdout);
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        int l;
        long long x;
        cin>>l>>x;
        scanf("%s",s);
        bool ans=false;
        if(x<9)
        {
            str[0]='\0';
            for(int i=0;i<x;i++)
                strcat(str,s);
            ans=do_eval(str,l*x);
        }
        else
        {
            for(int i=1;i<4&&!ans;i++)
                for(int j=1;j<4&&!ans;j++)
                    for(int k=1;k<4&&!ans;k++)
                    {
                        if((i+j+k)%4==x%4)
                        {
                            str[0]='\0';
                            for(int m=0;m<i+j+k;m++)
                                strcat(str,s);
                            ans=do_eval(str,(i+j+k)*l);
                        }
                    }
        }
        if(ans)
            printf("Case #%d: YES\n",cas);
        else
            printf("Case #%d: NO\n",cas);
    }
    return 0;
}
