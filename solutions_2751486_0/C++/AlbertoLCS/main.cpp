#include <iostream>
#include <fstream>

using namespace std;

#define MAXL 100

bool isNotVowel(char x)
{
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return false;
    return true;
}

int albertoAlgorithm (string name, int l, int n, int sub[MAXL/2+1][2])
{
	int maxEnding = 0, subs = 1;
	for(int i = 0; i < l; i++){
	    if(isNotVowel(name[i]))
            maxEnding++;
	    else{
            if(maxEnding >= n){
                //cout << name << " " << i << " " << maxEnding << endl;
                sub[subs][0] = i - maxEnding;
                sub[subs][1] = maxEnding;
                subs++;
            }
            maxEnding = 0;
	    }
    }
    if(maxEnding >= n){
        //cout << name << " " << l << " " << maxEnding << endl;
        sub[subs][0] = l - maxEnding;
        sub[subs][1] = maxEnding;
        subs++;
    }
    return subs;
}

int main()
{
    ifstream ent;
    ofstream sal;
    ent.open("input.txt");
    sal.open("output_R1C_A.txt");
    int casos, n, sub[MAXL/2+1][2];
    sub[0][0] = 0;
    string name;
    ent >> casos;
    for(int i = 0; i < casos; i++){
        ent >> name >> n;
        sub[0][1] = n-1;
        int l = name.length(), total = 0;
        int x = albertoAlgorithm(name, l, n, sub);
        for(int j = 1; j < x; j++){
            int start, end;
            start = sub[j][0] - (sub[j-1][0] + sub[j-1][1]) + n;
            end = l - sub[j][0] - n + 1;
            //cout << " " << start << " " << end << endl;
            total += start*end;
            for(int m = 1; m <= sub[j][1] - n; m++){
                total += --end;
            }
        }
        sal << "Case #" << i+1 << ": " << total << endl;
    }
    ent.close();
    sal.close();
    return 0;
}
