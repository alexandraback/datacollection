#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream fin;
ofstream fout;
void deal(int);

struct sub
{
    int a,m;
};

sub list[1000000];

string s;

int main()
{
    fin.open("gcj2013-1C-A.in");
    fout.open("gcj2013-1C-A.out");
    int t;
    fin>>t;
    fin.get();
    for (int i=0;i<t;i++)
        deal(i);
}

bool isv(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    

void deal(int p)
{
    getline(fin,s);
    int i=0,j=0,sum=0;
    int l=s.length()-1;
    int n=0,q=0;
    while(s[l]!=' ')
        l--;
    for (int k=l+1;k<s.length();k++)
        n=n*10+s[k]-48;
    while(i<l)
    {
        if (isv(s[i])) i++;
        else 
        {
            j=i;
            while(j<l && !isv(s[j]))
            {
                j++;
            }
            int m=j-i;
            if (m>=n) 
            {
                list[q].m=m;
                list[q].a=i;
                q++;
            }
            i=j;
        }
    }
    for (int i=0;i<q;i++)
    {
        int tl;
        if (i<q-1) tl=list[i+1].a+n-1;
        else tl=l;
        sum+=(tl+1-list[i].a-n)*(list[i].a+1+list[i].m-n)-(list[i].m+1-n)*(list[i].m-n)/2;
    }
    fout<<"Case #"<<p+1<<": "<<sum<<endl;
//    cout<<n<<' '<<l<<endl;
//    system("pause");
    
    
    
}
