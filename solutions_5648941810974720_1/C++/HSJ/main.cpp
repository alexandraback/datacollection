#include<stdio.h>
#include<string.h>
char s[10][100]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int cnt[10][26]={0};
int main()
{
    int i,j,len;
    int t,test;
    char in[2010]={0};
    int incnt[26]={0};
    int ans[10]={0};
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    for(i=0;i<10;i++){
        for(j=0;j<strlen(s[i]);j++){
            cnt[i][ s[i][j]-'A']++;
        }
    }
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%s",in);
        len = strlen(in);
        for(i=0;i<26;i++) incnt[i] = 0;
        for(i=0;i<10;i++) ans[i] = 0;
        for(i=0;i<len;i++) incnt[ in[i]-'A']++;

        printf("Case #%d: ",t);
        //for(i=0;i<incnt['Z'-'A'];i++) printf("0");
        ans[0] = incnt['Z'-'A'];
        incnt['E'-'A'] -= incnt['Z'-'A'];
        incnt['R'-'A'] -= incnt['Z'-'A'];
        incnt['O'-'A'] -= incnt['Z'-'A'];
        incnt['Z'-'A'] = 0;
        ans[2] = incnt['W'-'A'];
        incnt['T'-'A'] -= incnt['W'-'A'];
        incnt['O'-'A'] -= incnt['W'-'A'];
        incnt['W'-'A'] = 0;
        ans[4] = incnt['U'-'A'];
        incnt['F'-'A'] -= incnt['U'-'A'];
        incnt['O'-'A'] -= incnt['U'-'A'];
        incnt['R'-'A'] -= incnt['U'-'A'];
        incnt['U'-'A'] = 0;
        ans[1] = incnt['O'-'A'];
        incnt['N'-'A'] -= incnt['O'-'A'];
        incnt['E'-'A'] -= incnt['O'-'A'];
        incnt['O'-'A'] = 0;
        ans[5] = incnt['F'-'A'];
        incnt['I'-'A'] -= incnt['F'-'A'];
        incnt['V'-'A'] -= incnt['F'-'A'];
        incnt['E'-'A'] -= incnt['F'-'A'];
        incnt['F'-'A'] = 0;
        ans[6] = incnt['X'-'A'];
        incnt['S'-'A'] -= incnt['X'-'A'];
        incnt['I'-'A'] -= incnt['X'-'A'];
        incnt['X'-'A'] = 0;
        ans[7] = incnt['V'-'A'];
        incnt['S'-'A'] -= incnt['V'-'A'];
        incnt['E'-'A'] -= 2*incnt['V'-'A'];
        incnt['N'-'A'] -= incnt['V'-'A'];
        incnt['V'-'A'] = 0;
        ans[8] = incnt['G'-'A'];
        incnt['E'-'A'] -= incnt['G'-'A'];
        incnt['I'-'A'] -= incnt['G'-'A'];
        incnt['H'-'A'] -= incnt['G'-'A'];
        incnt['T'-'A'] -= incnt['G'-'A'];
        incnt['G'-'A'] = 0;
        ans[3] = incnt['H'-'A'];
        incnt['T'-'A'] -= incnt['H'-'A'];
        incnt['R'-'A'] -= incnt['H'-'A'];
        incnt['E'-'A'] -= 2*incnt['H'-'A'];
        incnt['H'-'A'] = 0;
        ans[9] = incnt['E'-'A'];
        for(i=0;i<10;i++){
            for(j=0;j<ans[i];j++) printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
