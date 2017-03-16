#include <stdio.h>
#include <limits.h>

int E, R, N;
int value[11000];
int right[11000];
int ending[11000];

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int i;
        long long ans;
        scanf("%d%d%d", &E, &R, &N);
        for(i=0; i<N; i++) {
            scanf("%d", value+i);
        }
        right[N-1]=INT_MAX;
        for(i=N-2; i>=0; i--) {
            if(value[i+1]>value[i]) {
                right[i]=i+1;
            } else {
                right[i]=right[i+1];
                while(right[i]<N && value[right[i]]<=value[i]) {
                    right[i]=right[right[i]];
                }
            }
        }
        ans=0;
        for(i=0; i<N; i++) {
            int start;
            int recover, dec;
            if(i==0) {
                start=E;
            } else {
                start=ending[i-1]+R;
                if(start>E) start=E;
            }
            recover = (E-start)/R;
            if((E-start)%R) recover++;
            dec=right[i]-i-recover;
            if(dec<0) dec=0;
            if((long long)dec*R>start) {
                ending[i]=0;
            } else {
                ending[i]=start-dec*R;
                if((E-ending[i])%R) {
                    ending[i]=E-((E-ending[i])/R+1)*R;
                }
            }
            if(i==N-1) {
                ending[i]=0;
            }
            ans += (long long)(start-ending[i])*value[i];
        }
        printf("Case #%d: %lld\n", ++Tcnt, ans);
    }
    return 0;
}
