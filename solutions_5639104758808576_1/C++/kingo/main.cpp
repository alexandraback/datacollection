#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    //freopen("A-large.in", "r", stdin);
    //freopen("AA.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int max;
        string people;
        cin >> max >> people;
        int result = 0, cumulate = 0;
        for(int j = 0; j < people.size() - 1; j++){
            cumulate += (people[j] - '0');
            if(cumulate < j+1){
                result += (j+1 - cumulate);
                cumulate = j+1;
            }
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
