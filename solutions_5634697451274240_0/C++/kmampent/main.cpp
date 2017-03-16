#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    ifstream fin;
    ofstream fout;
    fin.open("in.txt",ios_base::in);
    fout.open("out.txt",ios_base::out);
    int t, T;
    fin>>T;
    for(t=1;t<=T;t++){
        string input;
        fin>>input;
        int ans = 0;
        int left = 0;
        int right = input.size()-1;
        while(right >= 0 && input[right] == '+') right--;
        if(left <= right){
            ans++;
            if(input[left] == '+'){
                while(input[left] == '+') left++;
                ans++;
            }
        }
        while(left < right){
            int i = left;
            while (i < right && input[i] == '-') {
                i++;
            }
            if(i < right)
                ans += 2;
            while (i < right && input[i] == '+') {
                i++;
            }
            left = i;
        }
        fout<<"Case #"<<t<<": "<<ans<<endl;
    }
    fin.close();
    fout.close();

}