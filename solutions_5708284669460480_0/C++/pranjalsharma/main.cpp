#include <iostream>
#include <fstream>

using namespace std;

//fout<<"Case #"<<i+1<<": "<< answer <<"\n";

int main()
{
    int t, k, l, s;
    int bananas;
    char kb[101], w[101], c[101];
    int flag1, flag2;
    double chances;
    double casespos;
    int pos, pos1, pos2;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> k >> l >> s;
        fflush(stdin);
        gets(kb);
        fflush(stdin);
        gets(w);
        flag1 = flag2 = 0;

        for(int j = 0; j < l; j++){ //testing the keyboard keys for having the word's letters.
            flag2 = 0;
            for(int p = 0; p < k; p++){
                if(w[j] == kb[p]){
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0){
                flag1 = 1;
                break;
            }
        }

        if(flag1){ //output statement if above gives true.
            cout<<"Case #"<<i+1<<": "<< 0.0 <<"\n";
            continue;
        }

        if(l == 1) bananas = s; //to find the number of bananas to be brought.
        else{
            pos = 0;
            for(int j = 1; j < l; j++){
                if(w[j] == w[0]){
                    pos1 = j+1;
                    pos2 = 1;
                    while(w[pos1] == w[pos2]){
                        if(pos1 == (l-1)){
                            flag1 = 1;
                            break;
                        }
                        pos1++; pos2++;
                    }
                }
                if(flag1){
                    pos = j;
                    break;
                }
            }

            if(pos == 0) bananas = (int)(s/l);
            else{
                bananas = (int)((s - (l - pos))/pos);
            }

        }

        for(int j = 0; j < l; j++){ //to find the number of occurences in the keyboard of a letter of the word.
            flag1 = 0;
            for(int p = 0; p < k; p++){
                if(w[j] == kb[p]) flag1++;
            }
            c[j] = flag1;
        }

        chances = 1; flag1 = 0;
        for(int j = 0; j < l; j++){ // chances of making the word from the keyboard.
            chances *= (c[j]/l);
            if(chances < (0.000001)){
                flag1 = 1; break;
            }
        }
        if(flag1){
            cout<<"Case #"<<i+1<<": "<< (float) bananas <<"\n";
        }
        else{
            casespos = 1.0;
            for(int j = 0; j < s; j++){
                casespos *= k;
            }
            chances *= (bananas/casespos);
            cout<<"Case #"<<i+1<<": "<< (float) (bananas - chances) <<"\n";
        }
    }

    return 0;
}
