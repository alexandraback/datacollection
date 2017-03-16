#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main ()
{
    string s,s1,s2[32];
    int n,m,i,j,k,t;
    char c;
    cin>>n;
    cin.get(c);
    for(k=1;k<=n;k++)
    {
    getline(cin,s,'\n');
    m=s.size();
    s1="";
    for(i=0;i<m;i++)
                        {
                        if(s[i]==' '){s1+=' ';}
                        else
                        if(s[i]=='a'){s1+='y';}
                        else
                        if(s[i]=='b'){s1+='h';}
                        else
                        if(s[i]=='c'){s1+='e';}
                        else
                        if(s[i]=='d'){s1+='s';}
                        else
                        if(s[i]=='e'){s1+='o';}
                        else
                        if(s[i]=='f'){s1+='c';}
                        else
                        if(s[i]=='g'){s1+='v';}
                        else
                        if(s[i]=='h'){s1+='x';}
                        else
                        if(s[i]=='i'){s1+='d';}
                        else
                        if(s[i]=='j'){s1+='u';}
                        else
                        if(s[i]=='k'){s1+='i';}
                        else
                        if(s[i]=='l'){s1+='g';}
                        else
                        if(s[i]=='m'){s1+='l';}
                        else
                        if(s[i]=='n'){s1+='b';}
                        else
                        if(s[i]=='o'){s1+='k';}
                        else
                        if(s[i]=='p'){s1+='r';}
                        else
                        if(s[i]=='q'){s1+='z';}
                        else
                        if(s[i]=='r'){s1+='t';}
                        else
                        if(s[i]=='s'){s1+='n';}
                        else
                        if(s[i]=='t'){s1+='w';}
                        else
                        if(s[i]=='u'){s1+='j';}
                        else
                        if(s[i]=='v'){s1+='p';}
                        else
                        if(s[i]=='w'){s1+='f';}
                        else
                        if(s[i]=='x'){s1+='m';}
                        else
                        if(s[i]=='y'){s1+='a';}
                        else
                        if(s[i]=='z'){s1+='q';}
                        }
                        s2[k]=s1;
    }
    for(i=1;i<=n;i++)
    cout<<"Case #"<<i<<": "<<s2[i]<<endl;
    return 0;
}
