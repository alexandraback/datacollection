#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;


int main()
{
	int t;
    cin>>t;
    int count=1;
    while(t--)
    {
        string s;
        cin>>s;
        int cnt[10]={0};
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='Z')
                cnt[0]++;
            if(s[i]=='X')
                cnt[6]++;
            if(s[i]=='U')
                cnt[4]++;
            if(s[i]=='W')
                cnt[2]++;
            if(s[i]=='G')
                cnt[8]++;
        }
        int num4= cnt[4];
        int num8=cnt[8];
        int num6= cnt[6];
        int i=0;
        while(num4)
        {
            if(s[i]=='F')
                num4--;
            i++;
        }
        for(;i<s.length();i++)
            if(s[i]=='F')
                cnt[5]++;

        i=0;
        while(num8)
        {
            if(s[i]=='H')
                num8--;
            i++;
        }
        for(;i<s.length();i++)
            if(s[i]=='H')
                cnt[3]++;
        i=0;
        while(num6)
        {
            if(s[i]=='S')
                num6--;
            i++;
        }
        for(;i<s.length();i++)
            if(s[i]=='S')
                cnt[7]++;
        i=0;
        int cnnt= cnt[8]+cnt[5]+cnt[6];
        while(cnnt)
        {
            if(s[i]=='I')
                cnnt--;
            i++;
        }
        for(;i<s.length();i++)
            if(s[i]=='I')
                cnt[9]++;
        
        cnnt= cnt[0]+cnt[2]+cnt[4];
        i=0;
        while(cnnt)
        {
            if(s[i]=='O')
                cnnt--;
            i++;
        }
        for(;i<s.length();i++)
            if(s[i]=='O')
                cnt[1]++;

        
    	cout<<"Case #"<< count++ <<": ";
        for(int i=0;i<10;i++)
            while(cnt[i]--)
            {
                cout<<i;
            }
            cout<<endl;
    }
}