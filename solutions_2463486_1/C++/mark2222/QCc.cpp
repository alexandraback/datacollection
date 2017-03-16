#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct palin{
    string orig,sq;
    palin(){}
    palin(string oa,string sa){orig=oa;sq=sa;}
};
vector<palin> palins;
int palinstartlen;
int palinstart[25];
int fullpalinlen;
int fullpalin[50];
int squarepalinreslen;
int squarepalinres[100];
bool checksquarepalin(){
    for(int i=0;i<squarepalinreslen/2;i++){
        if(squarepalinres[i]!=squarepalinres[squarepalinreslen-i-1]) return false;
    }
    return true;
}
bool squarepalin(){
    squarepalinreslen=fullpalinlen*2-1;
    for(int i=0;i<squarepalinreslen;i++) squarepalinres[i]=0;
    for(int i=0;i<fullpalinlen;i++){
        for(int i2=0;i2<fullpalinlen;i2++){
            squarepalinres[i+i2]+=fullpalin[i]*fullpalin[i2];
            if(squarepalinres[i+i2]>=10) return false;
        }
    }
    return true;
}
void expandpalin0(){
    fullpalinlen=palinstartlen*2;
    for(int i=0;i<palinstartlen;i++){
        fullpalin[i]=fullpalin[palinstartlen*2-i-1]=palinstart[palinstartlen-i-1];
    }
}
void expandpalin1(){
    fullpalinlen=palinstartlen*2-1;
    for(int i=0;i<palinstartlen;i++){
        fullpalin[i]=fullpalin[palinstartlen*2-i-2]=palinstart[palinstartlen-i-1];
    }
}
void initpalinstart(){
    palinstartlen=1;
    memset(palinstart,0,sizeof(palinstart));
}
bool incpalinstart(){
    for(int i=0;i<25;i++){
        if(i+1>palinstartlen) palinstartlen=i+1;
        palinstart[i]++;
        if(palinstart[i]<3) return false;
        else palinstart[i]=0;
    }
    return true;
}
bool testsquarepalin(){
    return squarepalin()&&checksquarepalin();
}
void outputres(){
    /*for(int i=0;i<fullpalinlen;i++){
        printf("%d",fullpalin[i]);
    }
    printf(" ");
    for(int i=0;i<squarepalinreslen;i++){
        printf("%d",squarepalinres[i]);
    }
    printf("\n");*/
    string corig,csq;
    for(int i=0;i<fullpalinlen;i++){
        corig.append(1,fullpalin[i]+'0');
    }
    for(int i=0;i<squarepalinreslen;i++){
        csq.append(1,squarepalinres[i]+'0');
    }
    palins.push_back(palin(corig,csq));
}
void setpalinstartlen(){
    for(int i=24;i>=0;i--){
        if(palinstart[i]!=0){
            palinstartlen=i+1;
            return;
        }
    }
    palinstartlen=0;
}
void testpalinstart(){
    setpalinstartlen();
    expandpalin0();
    if(testsquarepalin()) outputres();
    expandpalin1();
    if(testsquarepalin()) outputres();
}
bool cmp(palin a,palin b){
    if(a.orig.length()==b.orig.length()) return a.orig<b.orig;
    else return a.orig.length()<b.orig.length();
}
int main(){
    freopen("palins.txt","w",stdout);
    palins.push_back(palin("3","9"));
    for(int i=0;i<25;i++){
		for(int i2=0;i2<25;i2++){
			if(i2!=i){
				initpalinstart();
				palinstart[i]=1;palinstart[i2]=2;
				testpalinstart();
			}
		}
        for(int i2=i+1;i2<25;i2++){
			for(int i3=0;i3<25;i3++){
				if(i3!=i&&i3!=i2){
					initpalinstart();
					palinstart[i]=palinstart[i2]=1;palinstart[i3]=2;
					testpalinstart();
				}
			}
            for(int i3=i2+1;i3<25;i3++){
                for(int i4=i3+1;i4<25;i4++){
                    for(int i5=i4+1;i5<25;i5++){
                        initpalinstart();
                        palinstart[i]=palinstart[i2]=palinstart[i3]=palinstart[i4]=palinstart[i5]=1;
                        testpalinstart();
                    }
                    initpalinstart();
                    palinstart[i]=palinstart[i2]=palinstart[i3]=palinstart[i4]=1;
                    testpalinstart();
                }
                initpalinstart();
                palinstart[i]=palinstart[i2]=palinstart[i3]=1;
                testpalinstart();
            }
            initpalinstart();
            palinstart[i]=palinstart[i2]=1;
            testpalinstart();
        }
        initpalinstart();
        palinstart[i]=1;
        testpalinstart();
        initpalinstart();
        palinstart[i]=2;
        testpalinstart();
    }
    sort(palins.begin(),palins.end(),cmp);
    for(int i=1;i<palins.size();i++){
        if(palins[i].orig==palins[i-1].orig) {cout<<"ERROR "<<palins[i].orig<<" "<<palins[i-1].orig<<endl; return 0;}
    }
    for(int i=0;i<palins.size();i++){
        cout<<palins[i].orig<<" "<<palins[i].sq<<endl;
    }
    return 0;
}
