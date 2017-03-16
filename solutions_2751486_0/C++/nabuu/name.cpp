#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
ifstream fin;
ofstream fout;
string name;
int n;
int process();
list<int> vlist;
bool hashtable[10000];
int main(int argc,char* argv[])
{
    int counter;
    for(int i=0;i<10000;i++)
    {
        hashtable[i]=false;
    }
    fin.open(argv[1]);
    fout.open("test.out");
    fin>>counter;
    for (int i = 0; i < counter; ++i)
    {
        int result;
        fin>>name>>n;
        result=process();
        fout<<"Case #"<<(i+1)<<": "<<result<<endl;
        vlist.clear();
        for(int i=0;i<10000;i++)
        {
            hashtable[i]=false;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

int code(int head,int tail)
{
    return head*100+tail;
}
int process()
{
    int sum=0;
    for(int i=0;i<=name.length()-n;i++)
    {
        bool flag=true;
        for(int j=i;j<i+n;j++)
        {
            if(name[j]=='a'||name[j]=='e'||name[j]=='i'||name[j]=='o'||name[j]=='u')
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            vlist.push_front(i);
        }
    }
    list<int>::iterator it;
    for(it=vlist.begin();it!=vlist.end();it++)
    {
        for(int h=*it;h>=0;h--)
        {
            for(int t=(*it)+n-1;t<name.length();t++)
            {
                if(!hashtable[code(h,t)])
                {
                    hashtable[code(h,t)]=true;
                    sum++;
                }
            }
        }
    }
    return sum;
}

