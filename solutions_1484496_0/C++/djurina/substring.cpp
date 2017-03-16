#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int brtest;
    ofstream fout ("substring.out");
    ifstream fin ("substring.in");

    fin >> brtest;

    for (int brt=0; brt<brtest; ++brt) {
    int polje[20], broj[20], nj;
    long long suma1=0, suma2=0;
    fout << "Case #" << brt+1 << ":"<< endl;
    bool uspio = false;
    fin >> nj;

    for (int u=0; u<20; ++u) {
        fin >> broj[u];
        //cout << broj[u] << " ";
    }
    //cout << endl;

    for (int a=0; a<3; ++a) {
    polje[0]=a;
    if (uspio==false)
    for (int b=0; b<3; ++b) {
    polje[1]=b;
    if (uspio==false)
    for (int c=0; c<3; ++c) {
    polje[2]=c;
    if (uspio==false)
    for (int d=0; d<3; ++d) {
    polje[3]=d;
    if (uspio==false)
    for (int e=0; e<3; ++e) {
    polje[4]=e;
    if (uspio==false)
    for (int f=0; f<3; ++f) {
    polje[5]=f;
    if (uspio==false)
    for (int g=0; g<3; ++g) {
    polje[6]=g;
    if (uspio==false)
    for (int h=0; h<3; ++h) {
    polje[7]=h;
    if (uspio==false)
    for (int i=0; i<3; ++i) {
    polje[8]=i;
    if (uspio==false)
    for (int j=0; j<3; ++j) {
    polje[9]=j;
    if (uspio==false)
    for (int k=0; k<3; ++k) {
    polje[10]=k;
    if (uspio==false)
    for (int l=0; l<3; ++l) {
    polje[11]=l;
    if (uspio==false)
    for (int m=0; m<3; ++m) {
    polje[12]=m;
    if (uspio==false)
    for (int n=0; n<3; ++n) {
    polje[13]=n;
    if (uspio==false)
    for (int o=0; o<3; ++o) {
    polje[14]=o;
    if (uspio==false)
    for (int p=0; p<3; ++p) {
    polje[15]=p;
    if (uspio==false)
    for (int q=0; q<3; ++q) {
    polje[16]=q;
    if (uspio==false)
    for (int r=0; r<3; ++r) {
    polje[17]=r;
    if (uspio==false)
    for (int s=0; s<3; ++s) {
    polje[18]=s;
    if (uspio==false)
    for (int t=0; t<3; ++t) {
        polje[19]=t;

        suma1=0;
        suma2=0;
        for (int u=0; u<20; ++u) {
            if (polje[u] == 1)
                suma1 += broj[u];
            if (polje[u] == 2)
                suma2 += broj[u];
        }
        //cout << suma1 << " " << suma2 << endl;
        if (suma1 == suma2 && uspio == false && suma1 > 0) {
            for (int u=0; u<20; ++u)
                if (polje[u] == 1)
                    fout << broj[u] << " ";
            fout << endl;
            for (int u=0; u<20; ++u)
                if (polje[u] == 2)
                    fout << broj[u] << " ";
            fout << endl;
            uspio = true;
        }

    }}}}}}}}}}}}}}}}}}}}

    if (uspio == false)
        fout << "Impossible" << endl;
    }


    return 0;
}
