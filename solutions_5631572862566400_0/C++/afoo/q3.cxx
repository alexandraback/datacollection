#include <stdio.h>
#include <string.h>
#include <assert.h>

int get_max_len(int *line, int *visited, int  *pair, int N) 
{
}
int trace_reverse(int *line, int cur, int *level, int N) {
    int max=level[cur];
    for (int i=0;i<N;i++) {
        if (level[i]==0 && line[i]==cur) {
            level[i] = level[cur]+1;
            int max_level = trace_reverse(line, i, level, N);
            if (max<max_level) {
                max = max_level;
            }
            level[i]=0;
        }
    }
    return max;
}
int get_chain(int *line, int *level, int N) {
    int max=0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            level[j] = 0;
        }
        int cur=i;
        level[cur] = 1;
        while(level[line[cur]]==0) {
            level[line[cur]] = level[cur]+1;
            cur = line[cur];
        }
        if (line[line[cur]]==cur) {

            int max_level = trace_reverse(line, cur, level, N);
            if (max < max_level) {
                max = max_level;
            }
        }
        else if (max < level[cur]-level[line[cur]]+1)
            max = level[cur]-level[line[cur]]+1;
        
    }
    return max;
}
int main()
{
    int T;
    int N; 
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%d\n", &N);
        int line[2000];
        int visited[2000];
        int level[2000];
        int pair[2000];
        for (int i=0;i<N;i++) { 
            scanf("%d", &line[i]);
            line[i]--;
            visited[i]=0;
            pair[i] =0;
            level[i]=0;
        }
        int ans =0;
        int max=0;
        ans = get_chain(line, level, N);
        for (int i=0;i<N;i++) { 
            if (line[line[i]]=i) {
                pair[i] = 1;
                pair[line[i]]=1;
//                ans+=2;
            }
        }
//        ans += get_max_len(line, visited, pair, N);
        printf("%d\n", ans);

    }
    return 0;
}


