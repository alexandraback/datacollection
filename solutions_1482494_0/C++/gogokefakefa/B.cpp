#include <iostream>
#include <set>
#include <cstring>

using namespace std;

pair < int, int > a[1024];
int used[1024];
int N;

// pyrvo gledam dali moga da namerq da napravq 2ra, ako ne moga
// vtoro gledam dali moga da resha nqkoq pyrva i ako moga - reshavam tazi pyrva, chiqto vtora iska nai - mnogo

void scan(){
    cin >> N;

    for ( int i = 0; i < N; ++i )
        cin >> a[i].first >> a[i].second;
}

int findSecond( int stars ){
    for ( int i = 0; i < N; ++i )
        if ( stars >= a[i].second && used[i] < 2 )
            return i;
    return -1;
}

int findFirst ( int stars ){
    int idx = -1;

    for ( int i = 0; i < N; ++i )
        if ( !used[i] && a[i].first <= stars ){
            if ( idx == -1 ) idx = i;

            if ( a[i].second > a[idx].second ) idx = i;
        }

    return idx;
}
void solve(int cs){
    int m = 0, res = 0, stars = 0;

    while ( m < N ){

        int idx = findSecond(stars);
        ++res;
        if ( idx != -1 ){
     //       cout << "Second " << idx << "\n";
            ++m;
            stars = stars + 2 - used[idx];
            used[idx] = 2;
            continue;
        }

        idx = findFirst(stars);

        if ( idx != -1 ){
            ++stars;
   //         cout << "First " << idx << "\n";
            used[idx] = 1;
            continue;
        }

        cout << "Case #" << cs << ": Too Bad\n";
        return;
    }


        cout << "Case #" << cs << ": " << res << "\n";
}

int main(){
    int tests;

    cin >> tests;

    for ( int i = 0; i < tests; ++i ){
        memset ( used, 0, sizeof ( used ) );
        scan();
        solve(i + 1);
    }
}
