#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string nums[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int ** numLetterCounts;

int* countLettersGuaranteed(string s){
    int * res = new int[10];
    for(int i=0;i<10;i++){
        res[i]=0;
    }
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='Z') res[0]++;
        if(s[i]=='W') res[2]++;
        if(s[i]=='U') res[4]++;
        if(s[i]=='X') res[6]++;
        if(s[i]=='G') res[8]++;
    }
    
    return res;
}

int* countLetters(string s){
    int * res = new int[26];
    for(int i=0;i<26;i++){
        res[i]=0;
    }
    
    for(int i=0;i<s.length();i++){
        res[s[i]-'A']++;
    }
    
    return res;
}

string deleteNum(string s, string num){
    string ret = "";
    int lastSplit = 0;
    int lenSplit = 0;
    int* del = new int[num.length()];
    for(int i=0;i<num.length();i++){
        del[i]=0;
    }
    
    for(int i=0;i<s.length();i++){
        for(int j=0;j<num.length();j++){
            if(s[i]==num[j] && del[j] == 0){
                del[j]=1;
                ret+=s.substr(lastSplit,lenSplit);
                lastSplit=i+1;
                lenSplit=-1;
                break;
            }
        }
        lenSplit++;
    }
    ret+=s.substr(lastSplit,lenSplit);
    
    return ret;
}

void upLetters(int* original, int* toAdd){
    for(int i=0;i<26;i++){
        original[i]+=toAdd[i];
    }
}

vector<int> inefficient(string s, int* letters, int* doneLetters, vector<int> partial){
    string cpy(s);
    
    for(int i=0;i<26;i++){
        if(doneLetters[i]>letters[i]) return vector<int>(1,-1);
    }
    int notComplete = false;
    for(int i=0;i<26;i++){
        if(doneLetters[i]!=letters[i]) notComplete=true;
    }
    if(!notComplete) return partial;
    for(int i=0;i<10;i++){
        int * doneLetters2 = new int[26];
        vector<int> partio(partial);
        for(int j=0;j<26;j++){
            doneLetters2[j]=doneLetters[j];
        }
        upLetters(doneLetters2, numLetterCounts[i]);
        partio.push_back(i);
        
        vector<int> res = inefficient(deleteNum(cpy,nums[i]), letters, doneLetters2, partio);
        if(res.size() == 0 || res[0] == -1){}
        else{return res;}
    }
    
    return vector<int>(1,-1);
}

void doStuff(int cas, string in){
    string ay(in);
    
    numLetterCounts = new int*[10];
    for(int i=0;i<10;i++){
        numLetterCounts[i] = countLetters(nums[i]);
    }
    
    int* guaranteed = countLettersGuaranteed(ay);
    vector<int> partial;
    for(int i=0;i<10;i++){
        for(int j=0;j<guaranteed[i];j++){
            ay = deleteNum(ay, nums[i]);
            partial.push_back(i);
        }
    }
    
    int* letters = countLetters(ay);
    int* doneLetters = new int[26]; for(int i=0;i<26;i++){doneLetters[i]=0;}
    
    vector<int> result = inefficient(ay, letters, doneLetters, partial);
    sort(result.begin(), result.end());
    
    cout << "Case #" << (cas) << ": ";
    
    for(int i=0;i<result.size();i++){
        cout << result[i];
    }
    
    cout << endl;
}

int main(){
    int T;
    string nothing;
    
    cin >> T;
    getline(cin, nothing);
    
    for(int i=0;i<T;i++){
        string in;
        
        getline(cin,in);
        
        doStuff(i+1, in);
    }
    
    return 0;
}