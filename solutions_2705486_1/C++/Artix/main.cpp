#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int T;
const int NBMOTS = 521196+1;
const int MAXS = 4000+1;
const int inf = MAXS;
char S[MAXS];

struct Elem
{
    Elem* next[27];
    char end;

    Elem()
    {
        for(int i = 0; i < 27; i++)
            next[i]=0;
        end=0;
    }
};

Elem racine;

void addArbre(char *mot)
{
    Elem *ptr=&racine;
    int ind=0;

    while(mot[ind]!='\0')
    {
        char c=mot[ind]-'a';
        if(ptr->next[c] == 0)
        {
            ptr->next[c]=new Elem;
        }
        ptr=ptr->next[c];
        ind++;
    }
    ptr->end=1;
}

int N;
int dyn[MAXS][6];

int enumereArc(int pos, int lastChange, Elem* ptr);

int dynMinNb(int pos, int lastChange)
{
    if(pos==N)
        return 0;

    int& vc=dyn[pos][lastChange];

    if(!vc)
    {
        vc=enumereArc(pos, lastChange, &racine);
        //for(int i = 0; i <
    }

    return vc;
}

int enumereArc(int pos, int lastChange, Elem* ptr)
{
    if(pos == N)
        return ptr->end ? 0 : inf;
    char c = S[pos]-'a';
    //if(ptr->next[c]==0 && lastChange != 5)
    //    return inf;

    int res = inf;
    if(ptr->end)
        res=dynMinNb(pos, lastChange);
    if(ptr->next[c]!=0)
        res=min(res, enumereArc(pos+1, min(lastChange+1, 5), ptr->next[c]));
    if(lastChange==5 && ptr->next[26]!=0)
        res=min(res, 1+enumereArc(pos+1, 1, ptr->next[26]));
    return res;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    FILE *dic = fopen("garbled_email_dictionary.txt", "r");

    for(int i = 0; i < NBMOTS; i++)
    {
        char mot[12];
        fscanf(dic, "%s", mot);
        int sz = strlen(mot);
        addArbre(mot);

        for(int pos = 0; pos < sz; pos++)
        {
            char prec1=mot[pos];
            mot[pos]='z'+1;
            addArbre(mot);

            for(int pos2 = pos+5; pos2 < sz; pos2++)
            {
                char prec2=mot[pos2];
                mot[pos2]='z'+1;
                addArbre(mot);
                mot[pos2]=prec2;
            }

            mot[pos]=prec1;
        }
    }

    //if(racine.next[0]==0 || racine.next[0]->end != 1) printf("debug : fait chier\n");

    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%s", S);
        N=strlen(S);

        //reset
        for(int i = 0; i < N; i++)
            for(int j = 1; j <= 5; j++)
                dyn[i][j]=0;

        int res=dynMinNb(0, 5);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
