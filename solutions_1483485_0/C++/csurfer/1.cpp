#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
    char arr[123];
    arr[32] = ' ';
    //Characters
    arr[97]='y';
    arr[98]='h';
    arr[99]='e';
    arr[100]='s';
    arr[101]='o';
    arr[102]='c';
    arr[103]='v';
    arr[104]='x';
    arr[105]='d';
    arr[106]='u';
    arr[107]='i';
    arr[108]='g';
    arr[109]='l';
    arr[110]='b';
    arr[111]='k';
    arr[112]='r';
    arr[113]='z';
    arr[114]='t';
    arr[115]='n';
    arr[116]='w';
    arr[117]='j';
    arr[118]='p';
    arr[119]='f';
    arr[120]='m';
    arr[121]='a';
    arr[122]='q';

    char num[3];
    cin.getline(num,3);
    int tc = atoi(num);
    int total = tc;
    
    while(tc--)
    {
	char g[110];
        cin.getline(g,110);
        cout<<"Case #"<<total-tc<<": ";
        int len = strlen(g);
        for(int i=0;i<len;i++)
        {
            cout<<arr[(int)g[i]];
        }
        cout<<"\n";
    }
    return 0;
}
