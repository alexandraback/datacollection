#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define MAXN 105

using namespace std;

typedef long long int llint;

int N, M;
llint box[MAXN][2], toy[MAXN][2]; // [0]: number , [1]: type
llint ans;

llint dp[MAXN][MAXN];
bool isfind[MAXN][MAXN];

void trace(int box_index, llint box_rest, int toy_index, llint toy_rest, llint com_number)
{
    if(box_rest == 0)
    {
        box_index++;
        box_rest = box[box_index][0];
    }

    if(toy_rest == 0)
    {
        toy_index++;
        toy_rest = toy[toy_index][0];
    }

    // no box or no toy can use, update answer and return
    if(box_index == N || toy_index == M)
    {
        ans = max(ans, com_number);
        return ;
    }

    // same type
    if(box[box_index][1] == toy[toy_index][1])
    {
        llint tmp_num = min(box_rest, toy_rest);

        trace(box_index, box_rest-tmp_num, toy_index, toy_rest-tmp_num, com_number+tmp_num);
    }else{

        // give up box or give up toys
        trace(box_index, 0, toy_index, toy_rest, com_number);
        trace(box_index, box_rest, toy_index, 0, com_number);
    }
}

void process(int case_number)
{
    scanf("%d%d", &N, &M);

    for(int i=0;i<N;i++)
        scanf("%lld%lld", &box[i][0], &box[i][1]);

    for(int i=0;i<M;i++)
        scanf("%lld%lld", &toy[i][0], &toy[i][1]);

    ans = 0;
    trace(0, box[0][0], 0, toy[0][0], 0);

    printf("Case #%d: %lld\n", case_number, ans);
}

int main(int argc, char *argv[])
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
        process(i);
	return 0;
}
