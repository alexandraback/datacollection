#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
    int T;
    int N;
    cin>>T;
    string str;
    for (int t = 0; t < T; ++t){
        int N;
        cin>>N;
        string store[N];
        set<int> pos[26][4];
        for (int n = 0; n < N; ++n)
        {
            cin>>str;
            string tmp = "";
            for (int s = 0; s < str.length(); ++s)
            {
                if(s==0) tmp = tmp + str[s];
                else if(tmp[(int)tmp.length()-1]!=str[s]) tmp = tmp + str[s];
            }
            store[n] = "";
            store[n] = store[n] + tmp[0];
            if(tmp.length()==1){
                pos[tmp[0]-'a'][3].insert(n);
                continue;
            }
            store[n] = store[n] + tmp[(int)tmp.length()-1];
            for (int s = 0; s < tmp.length(); ++s)
            {
                if(s==0) pos[tmp[s]-'a'][0].insert(n);
                else if(s+1==tmp.length()) pos[tmp[s]-'a'][2].insert(n);
                else pos[tmp[s]-'a'][1].insert(n);
            }
        }
        bool flag = false;
        for (int i = 0; i < 26; ++i)
        {
            flag = flag || (pos[i][1].size()>1) ;
            flag = flag || (pos[i][1].size()==1 && (pos[i][0].size()+pos[i][2].size()+pos[i][3].size())>0 );
            set<int> intersect;
            set_intersection(pos[i][0].begin(),pos[i][0].end(),pos[i][2].begin(),pos[i][2].end(),std::inserter(intersect,intersect.begin()));
            flag =  flag || (intersect.size()>0);
        }
        printf("Case #%d: ", t+1);
        if(flag){
            cout<<0<<endl;
            continue;
        }
        
        int ans = 0;
        int perm[N];
        for (int i = 0; i < N; ++i)
        {
            perm[i] = i;
        }
        string str = "";
        int flg[26];
        do{
            flag = 1;
            str = "";
            char ch = 'A';
            memset(flg,0,sizeof(flg));
            for(int i=0;i<N;i++){
                str = str + store[perm[i]];
                for (int j = 0; j < store[perm[i]].size(); ++j)
                {
                    if(store[perm[i]][j]!=ch && flg[store[perm[i]][j]-'a']){
                        flag = 0;
                        break;
                    }
                    flg[store[perm[i]][j]-'a'] = 1;
                    ch = store[perm[i]][j];
                }
            }
            ans += flag;
        }while(next_permutation(perm,perm+N));
        cout<<ans<<endl;
    }
    return 0;
}