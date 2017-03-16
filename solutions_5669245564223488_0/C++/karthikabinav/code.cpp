#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> at;
vector<int> perm;
bool mu[26];

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    int qq = 1;
    while(t--)
    {
        int n;
        cin>>n;

        int cnt = 0;
        
        at.clear();
        perm.clear();

        bool br = false;
        int i,j;
        
        for(i=0;i<26;i++)
          mu[i] = false;
        
        for(i=0;i<n;i++)
        {
            string r;
            cin>>r;
            at.push_back(r);
            perm.push_back(i);
            
            if(br)
              continue;
            j=0;
            while(at[i][j]==at[i][0] && j<at[i].length())
              j++;

            int k = at[i].length()-1;
            
            while(at[i][k] == at[i][at[i].length()-1] && k>=0)
              k--;
            
            for(;j<=k;)
            {
                if(mu[at[i][j]-'a'])
                  br = true;
                mu[at[i][j]-'a'] = true;
                int h = j;
                while(at[i][j] == at[i][h] && j<at[i].length())
                  j++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(mu[at[i][0]-'a'] || mu[at[i][at[i].length()-1]-'a'])
              br = true;
        }
        if(br)
        {
            cout<<"Case #"<<qq<<": "<<0<<endl;
            qq++;
            continue;
        }

        vector<string> att;
        for(i=0;i<n;i++)
        {
            string y;
            y.push_back(at[i][0]);
            y.push_back(at[i][at[i].length()-1]);
            att.push_back(y);
        }

        do
        {
            string kk;
            int i;
            br = false;
            for(i=0;i<perm.size();i++)
            {
                kk.append(att[perm[i]]);
            }

            bool used[26];
            for(i=0;i<26;i++)
              used[i] = false;

            for(i=0;i<kk.length();i++)
            {
                if(i == 0)
                {
                    used[kk[i]-'a'] = true;
                    continue; 
                }
                if(used[kk[i]-'a'] && kk[i-1]!=kk[i]) 
                {
                  br = true;
                  break;
                }
                used[kk[i]-'a']=true; 
            }

            if(!br) 
                cnt++;
        }
        while(next_permutation(perm.begin(),perm.end()));

        cout<<"Case #"<<qq<<": "<<cnt<<endl;
        qq++;
    }
}


