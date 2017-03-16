#include <bits/stdc++.h>

#define LEN 2013
char str[LEN];
int count[26];
int num[10];

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d\n", &n);
  for(int i=0;i<n;i++){
    printf("Case #%d: ", i+1); 
    for(int j=0;j<26;j++){
      count[j]=0;
    }
    scanf("%s\n", str);
    int temp_len = strlen(str);
    for(int j=0;j<temp_len;j++){
      count[str[j]-'A']++;
    }
    num[0]=count['Z'-'A'];
    count['Z'-'A']-=num[0];
    count['E'-'A']-=num[0];
    count['R'-'A']-=num[0];
    count['O'-'A']-=num[0];

    num[2]=count['W'-'A'];
    count['T'-'A']-=num[2];
    count['W'-'A']-=num[2];
    count['O'-'A']-=num[2];

    num[6]=count['X'-'A'];
    count['S'-'A']-=num[6];
    count['I'-'A']-=num[6];
    count['X'-'A']-=num[6];

    num[7]=count['S'-'A'];
    count['S'-'A']-=num[7];
    count['E'-'A']-=num[7];
    count['V'-'A']-=num[7];
    count['E'-'A']-=num[7];
    count['N'-'A']-=num[7];

    num[5]=count['V'-'A'];
    count['F'-'A']-=num[5];
    count['I'-'A']-=num[5];
    count['V'-'A']-=num[5];
    count['E'-'A']-=num[5];

    num[4]=count['F'-'A'];
    count['F'-'A']-=num[4];
    count['O'-'A']-=num[4];
    count['U'-'A']-=num[4];
    count['R'-'A']-=num[4];

    num[3]=count['R'-'A'];
    count['T'-'A']-=num[3];
    count['H'-'A']-=num[3];
    count['R'-'A']-=num[3];
    count['E'-'A']-=num[3];
    count['E'-'A']-=num[3];

    num[1]=count['O'-'A'];
    count['O'-'A']-=num[1];
    count['N'-'A']-=num[1];
    count['E'-'A']-=num[1];

    num[8]=count['T'-'A'];
    count['E'-'A']-=num[8];
    count['I'-'A']-=num[8];
    count['G'-'A']-=num[8];
    count['H'-'A']-=num[8];
    count['T'-'A']-=num[8];

    num[9]=count['I'-'A'];
    for(int j=0;j<10;j++){
      for(int k=0;k<num[j];k++){
        printf("%d", j);
      }
    }
    printf("\n");
  }
  return 0;
}
