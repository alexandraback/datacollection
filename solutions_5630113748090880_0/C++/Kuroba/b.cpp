#include <bits/stdc++.h>
using namespace std;

int T;

string s;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);
        int n;
        vector<vector<int> > a;
        scanf("%d", &n);

        for(int i = 0; i<2*n-1; i++){ // max 100
            vector<int> v;
            for(int j = 0; j<n; j++){
                int x;
                scanf("%d", &x);
                v.push_back(x);
            }
            a.push_back(v);
        }



        int arr[50][50] = {0};

        // top down
        int i1 = 0;
        int i2 = 0;
        vector<int> m;
        int k0 = -1;
        int k = -1;
        int prev = 0;
        while(k < n){
            k++;
            //cout << "CHECKING " << k << endl;
            // find (k,k)
            i1 = -1;
            i2 = -1;
            int hi = 2501; // highest;

            for(int i = 0; i<a.size(); i++){

                if (a[i][k] <= prev) continue;
                //cout << a[i][k] << endl;
                if (a[i][k] < hi){
                    i1 = i;
                    hi = a[i][k];
                    i2 = -1;
                }
                else if (a[i][k] == hi){
                    i2 = i;
                }
            }


            //cout << i1 << " " << i2 << endl;
            if (i2 == -1){
                m = a[i1];
                k0 = k;
                break;
            }
            else{
                prev = hi;
                bool match = true;
                for(int i = 0; i<k; i++){
                    if (a[i1][i] != arr[i][k]) match = false;
                }

                if (!match){
                    for(int i = 0; i<n; i++){
                        arr[i][k] = a[i1][i];
                        arr[k][i] = a[i2][i];
                    }
                }
                else{
                    for(int i = 0; i<n; i++){
                        arr[i][k] = a[i2][i];
                        arr[k][i] = a[i1][i];
                    }
                }
                a.erase(a.begin()+i2);
                a.erase(a.begin()+i1);
            }
        }
        // bottom up
        k = n;
        prev = 9000;
        while(k >= 0){
            k--;
            //cout << "CHECKING " << k << endl;
            // find (k,k)
            i1 = -1;
            i2 = -1;
            int hi = 0; // highest;

            for(int i = 0; i<a.size(); i++){
                if (a[i][k] >= prev) continue;
                if (a[i][k] > hi){
                    i1 = i;
                    hi = a[i][k];
                    i2 = -1;
                }
                else if (a[i][k] == hi){
                    i2 = i;
                }
            }
            //cout << i1 << " " << i2 << endl;
            if (i2 == -1){
                m = a[i1];
                k0 = k;
                break;
            }
            else{
                prev = hi;
                bool match = true;
                for(int i = n-1; i>k; i--){
                    if (a[i1][i] != arr[i][k]) match = false;
                }
                for(int i = 0; i< k0; i++){
                    if (a[i1][i] != arr[i][k]) match = false;
                }

                if (!match){
                    for(int i = 0; i<n; i++){
                        arr[i][k] = a[i1][i];
                        arr[k][i] = a[i2][i];
                    }
                }
                else{
                    for(int i = 0; i<n; i++){
                        arr[i][k] = a[i2][i];
                        arr[k][i] = a[i1][i];
                    }
                }
                a.erase(a.begin()+i2);
                a.erase(a.begin()+i1);
            }
        }

        bool match = true;
        for(int i = 0; i<n; i++){
            if (i!=k0 && m[i] != arr[i][k0]) match = false;
        }

        if (match){
            for(int i = 0; i<n; i++){
                if (i == k0) printf("%d ", m[i]);
                else printf("%d ", arr[k0][i]);
            }
        }
        else{
            for(int i = 0; i<n; i++){
                if (i == k0) printf("%d ", m[i]);
                else printf("%d ", arr[i][k0]);
            }
        }
        printf("\n");



        a.clear();

    }


}
