#include <cstdio>
#include <vector>

using namespace std;

char s[1010];

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%s",s);
        vector<char> ans;
        ans.clear();
        for (int i=0;s[i];i++)
        {
            if (ans.empty()) ans.push_back(s[i]);
            else
            {
                vector<char>::iterator it;
                it = ans.begin();
                while (*it == s[i])
                {
                    it++;
                }
                if (it==ans.end() || *it>s[i])
                    ans.push_back(s[i]);
                else
                    ans.insert(it,s[i]);
            }
        }
        int l = ans.size();
        printf("Case #%d: ",o);
        for (int i=0;i<l;i++)
            printf("%c",ans[i]);
        puts("");
    }
    return 0;
}
