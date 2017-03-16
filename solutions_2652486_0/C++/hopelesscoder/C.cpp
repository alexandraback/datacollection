#include <cstdio>
#include <vector>

using namespace std;

int angka[15];

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int num = 1; num <= T; num++)
    {
        int r,n,m,k;
        scanf("%d %d %d %d",&r,&n,&m,&k);
        printf("Case #%d:\n",num);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < n; j++)
                angka[j] = 2;
            
            int x[k+5];
            for (int j = 0; j < k; j++)
                scanf("%d",&x[j]);
            bool finish = false;
            while (!finish)
            {
                vector<int> v;
                for (int j = 0; j < n; j++)
                    v.push_back(angka[j]);
                v.push_back(angka[0]*angka[1]);
                v.push_back(angka[0]*angka[2]);
                v.push_back(angka[1]*angka[2]);
                v.push_back(angka[0]*angka[1]*angka[2]);
                bool can = false;
                for (int j = 0; j < k; j++)
                {
                    can = false;
                    for (int l = 0; l < v.size(); l++)
                    {
                        if (v[l] == x[j] || x[j] == 1)
                            can = true;
                    }
                    if (!can)
                        break;
                }
                
                if (can)
                {
                    finish = true;
                    break;
                }
                
                angka[n-1]++;
                int idx = n-1;
                while (angka[idx] > m)
                {
                    if (idx == 0)
                    {
                        finish = true;
                        break;
                    }
                    angka[idx] = 2;
                    angka[idx-1]++;
                    idx--;
                }
            }
            for (int j = 0; j < n; j++)
                printf("%d",angka[j]);
            printf("\n");
        }
    }
    return 0;
}
