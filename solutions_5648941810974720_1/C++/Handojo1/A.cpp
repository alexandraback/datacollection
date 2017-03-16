#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char kata[5000];
int T,banyak[255],jawab[10];

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%s",kata);
        int panjang = strlen(kata);
        memset(banyak,0,sizeof(banyak));
        memset(jawab,0,sizeof(jawab));
        
        for (int i=0;i<panjang;++i) ++banyak[kata[i]];
        
        //ZERO
        int temp = banyak['Z'];
        banyak['Z'] -= temp;banyak['E']-=temp;banyak['R']-=temp;banyak['O'] -= temp;
        jawab[0] = temp;
        
        //TWO
        temp = banyak['W'];
        banyak['T'] -= temp;banyak['W']-=temp;banyak['O'] -= temp;
        jawab[2] = temp; 
        //cout<<temp<<endl;

        //SIX
        temp = banyak['X'];
        banyak['S'] -= temp;banyak['I']-=temp;banyak['X']-=temp;
        jawab[6] = temp;
        //cout<<temp<<endl;
        
        //EIGHT
        temp = banyak['G'];
        banyak['E'] -= temp;banyak['I']-=temp;banyak['G']-=temp;banyak['H'] -= temp;banyak['T']-=temp;
        jawab[8] = temp;  
        //cout<<temp<<endl;
        
        //FOUR
        temp = banyak['U'];
        //printf("%d %d %d %d\n",banyak['F'],banyak['O'],banyak['U'],banyak['R']);
        banyak['F'] -= temp;banyak['O']-=temp;banyak['U']-=temp;banyak['R'] -= temp;
        jawab[4] = temp;
        //cout<<temp<<endl;
        
        //FIVE
        temp = banyak['F'];
        banyak['F'] -= temp;banyak['I']-=temp;banyak['V']-=temp;banyak['E'] -= temp;
        jawab[5] = temp;
        //cout<<temp<<endl;
        
        //SEVEN
        temp = banyak['S'];
        banyak['S'] -= temp;banyak['E']-=temp;banyak['V']-=temp;banyak['E'] -= temp;banyak['N']-=temp;
        jawab[7] = temp;
        //cout<<temp<<endl;
        
        //THREE
        temp = banyak['T'];
        banyak['T'] -= temp;banyak['H']-=temp;banyak['R']-=temp;banyak['E'] -= 2*temp;
        jawab[3] = temp;
        //cout<<temp<<endl;
        
        //ONE
        temp = banyak['O'];
        //printf("%d %d %d\n",banyak['O'],banyak['N'],banyak['E']);
        banyak['O'] -= temp;banyak['N']-=temp;banyak['E']-=temp;
        jawab[1] = temp;
        //cout<<temp<<endl;
        
        //NINE
        temp = banyak['I'];
        banyak['N'] -= temp;banyak['I']-=temp;banyak['N']-=temp;banyak['E'] -= temp;
        jawab[9] = temp;
        //cout<<temp<<endl;
        
        printf("Case #%d: ",l);
        for (int i=0;i<10;++i) {
            for (int j=1;j<=jawab[i];++j) printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
