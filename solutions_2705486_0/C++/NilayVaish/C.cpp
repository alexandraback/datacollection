#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<char *> > D;

void process_dict()
{
    FILE *fp = fopen("garbled_email_dictionary.txt", "r");
    while(!feof(fp))
    {
        char *st = new char[15];
        memset(st, 0, 15);
        fscanf(fp, "%s\n", st);
        D[(unsigned int)strlen(st)].push_back(st);
//        fprintf(stderr, "%s\n", st);
    }
}

unsigned int CC[4005][4005];

int count(char *st, int i, int j)
{
    int l = j - i + 1;
    int cc = l;
    for(int k = 0; k < D[l].size(); ++k)
    {
        char *ed = D[l][k];
        int xx = 0;
        for(int g= 0 ; g < l; ++g)
        {
            if(ed[g] != st[i+g]) xx++;
        }
        cc = min(cc, xx);
    }
    return cc;
}

int main()
{
    int T;
    scanf("%d\n", &T);

    for (int i = 0 ; i < 11; ++i) D.push_back(vector<char *>());
    process_dict();
    //for (int i = 0 ; i < 11; ++i) printf("%d\n", D[i].size());

    for(int ii = 1; ii <= T; ++ii)
    {
        memset(CC, 1 , sizeof(CC));

        char st[4005];
        scanf("%s\n", st);
        int L = strlen(st);
        for(int i = 0; i < L; ++i) for(int j = i; j < L; ++j) if (j - i + 1 <= 10)
            CC[i][j-i+1] = count(st, i, j);

        for(int i = 0 ; i < L; ++i) for(int l = 2; i + l <= L; ++l)
        {
           for(int k = 1; k <= 10 && l-k >= 1; ++k)
           {
               CC[i][l] = min(CC[i][l], CC[i][l-k] + CC[i+l-k][k]);
           }
        }

        printf("Case #%d: %d\n", ii, CC[0][L]);
    }
    return 0;
}
