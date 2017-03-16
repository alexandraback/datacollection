#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    int T,tc,n,s,p,a,c,x,y,z,skor;
    vector<int> v;
    bool able;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        skor = 0;
        v.clear();
        scanf("%d%d%d",&n,&s,&p);
        for(c=0;c<n;c++)
        {
            scanf("%d",&a);
            able = false;
            for(x=0;x<=10;x++) for(y=0;y<=10;y++) for(z=0;z<=10;z++) if(x+y+z==a)
            {
                if(abs(x-y)<=1 && abs(x-z)<=1 && abs(y-z)<=1 && (x>=p||y>=p||z>=p))
                {
                    able = true;
                    goto done1;
                }
            }
            done1 :
            if(able) skor++;
            else v.push_back(a);
        }
        for(c=v.size()-1;c>=0;c--)
        {
            if(s<=0) break;
            able = false;
            for(x=0;x<=10;x++) for(y=0;y<=10;y++) for(z=0;z<=10;z++) if(x+y+z==v[c])
            {
                if(abs(x-y)<=2 && abs(x-z)<=2 && abs(y-z)<=2 && (x>=p||y>=p||z>=p))
                {
                    able = true;
                    s--;
                    goto done2;
                }
            }
            done2 :
            if(able) skor++;
        }
        printf("Case #%d: %d\n",tc,skor);
    }
    return 0;
}
