#include<cstdio>
#include<iostream>

using namespace std;

struct Ma
{
    char x;
    char y;
}data[26];

void trans(string& source,char* target)
{
    int ln=source.size();
    for(int i=0;i<ln;i++)
    {
        if(source[i]==' ')
            target[i]=' ';
        else
        {
            for(int j=0;j<26;j++)
            {
                if(source[i]==data[j].y)
                {
                    target[i]=data[j].x;
                    break;
                }
            }
        }
    }
    target[ln]='\0';
}

int main()
{
    int t;
    cin>>t;
    getchar();
    char output[200];
    string in;
    for(int i=0;i<26;i++)
        data[i].x='a'+i;
    data[0].y='y',data[1].y='n',data[2].y='f',data[3].y='i',data[4].y='c',data[5].y='w',
    data[6].y='l',data[7].y='b',data[8].y='k',data[9].y='u',data[10].y='o',data[11].y='m',
    data[12].y='x',data[13].y='s',data[14].y='e',data[15].y='v',data[16].y='z',data[17].y='p',
    data[18].y='d',data[19].y='r',data[20].y='j',data[21].y='g',data[22].y='t',data[23].y='h',
    data[24].y='a',data[25].y='q';
    for(int casenum=1;casenum<=t;casenum++)
    {
        //getchar();
        getline(cin,in);
        trans(in,output);
        cout<<"Case #"<<casenum<<": "<<output<<endl;
    }
    return 0;
}
