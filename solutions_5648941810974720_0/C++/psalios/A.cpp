#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<assert.h>

const int MAXS = 2010;

using namespace std;

int N;
char str[MAXS];
int nums[20];
int chars[30];
vector<int> row;

void init(){
    memset( nums, 0, sizeof nums );
    memset( chars, 0, sizeof chars );
}

void solve(){

    //Count
    for(int i=0;i<N;i++){
        chars[str[i]-'A']++;
    }

    //Zero
    int val = chars['Z'-'A'];
    nums[0] = val;
    chars['Z'-'A'] -= val;
    chars['E'-'A'] -= val;
    chars['R'-'A'] -= val;
    chars['O'-'A'] -= val;

    //Two
    val = chars['W'-'A'];
    nums[2] = val;
    chars['T'-'A'] -= val;
    chars['W'-'A'] -= val;
    chars['O'-'A'] -= val;

    //Six
    val = chars['X'-'A'];
    nums[6] = val;
    chars['S'-'A'] -= val;
    chars['I'-'A'] -= val;
    chars['X'-'A'] -= val;

    //Eight
    val = chars['G'-'A'];
    nums[8] = val;
    chars['E'-'A'] -= val;
    chars['I'-'A'] -= val;
    chars['G'-'A'] -= val;
    chars['H'-'A'] -= val;
    chars['T'-'A'] -= val;

    //THREE
    val = chars['H'-'A'];
    nums[3] = val;
    chars['T'-'A'] -= val;
    chars['H'-'A'] -= val;
    chars['R'-'A'] -= val;
    chars['E'-'A'] -= val;
    chars['E'-'A'] -= val;

    //Four
    val = chars['R'-'A'];
    nums[4] = val;
    chars['F'-'A'] -= val;
    chars['O'-'A'] -= val;
    chars['U'-'A'] -= val;
    chars['R'-'A'] -= val;

    //Five
    val = chars['F'-'A'];
    nums[5] = val;
    chars['F'-'A'] -= val;
    chars['I'-'A'] -= val;
    chars['V'-'A'] -= val;
    chars['E'-'A'] -= val;

    //One
    val = chars['O'-'A'];
    nums[1] = val;
    chars['O'-'A'] -= val;
    chars['N'-'A'] -= val;
    chars['E'-'A'] -= val;

    //Seven
    val = chars['V'-'A'];
    nums[7] = val;
    chars['S'-'A'] -= val;
    chars['E'-'A'] -= val;
    chars['V'-'A'] -= val;
    chars['E'-'A'] -= val;
    chars['N'-'A'] -= val;

    //Nine
    val = chars['I'-'A'];
    nums[9] = val;
    chars['N'-'A'] -= val;
    chars['I'-'A'] -= val;
    chars['N'-'A'] -= val;
    chars['E'-'A'] -= val;

    for(int i=0;i<30;i++)
        assert( chars[i] == 0 );

    row.clear();
    for(int i=0;i<=9;i++)
        for(int j=0;j<nums[i];j++)
            row.push_back(i);
}

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cin>>str;
        N = strlen(str);
        init();
        printf( "Case #%d: ", t );
        solve();
        for(int i=0;i<row.size();i++)
            cout<<row[i];
        cout<<'\n';
    }
}
