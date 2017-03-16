#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

char data[ 20000 ];

int main(void){

    int T;
    scanf("%d",&T);

    for(int round = 0;round < T;++round){
        // ƒXƒ‚[ƒ‹“Á‰»B
        // ‚Ü‚¸¶‰E•ûŒü‚ÉƒKƒKƒKƒKƒb‚ÆU‚Á‚ÄAX‚ð‚ ‚í‚¹‚éB
        // ŽŸ‚ÉAc•ûŒü‚ÍA–Ú“I’n‚ª”ò‚Ñ‰z‚¦”ÍˆÍ‚É“ü‚Á‚Ä‚µ‚Ü‚Á‚Ä‚¢‚é‚È‚çA
        // 2‰ñ”ò‚Ñ‰z‚¦‚ÄAƒKƒKƒKƒKƒb‚Æ‚â‚éB
        // “ü‚Á‚Ä‚È‚¢‚È‚çA–Ú“I’n•ûŒü‚É”ò‚ñ‚ÅƒKƒKƒKƒKƒb‚Æ‚â‚éB
        int x = 0;
        int y = 0;
        int gx;
        int gy;
        scanf("%d %d",&gx,&gy);
        int turn = 0;
        // X •ûŒü
        while(x != gx){
            data[ turn ] = 'E';
            x += ++turn;
            if( x == gx ) break;
            data[ turn ] = 'W';
            x -= ++turn;
            if( x == gx ) break;
        }
        // Y •ûŒü
        // turn + 1 ‚ÅƒWƒƒƒ“ƒv‚µ‚ÄA
        // ”ò‚Ñ‰z‚¦‚È‚¢‚È‚çA‚»‚ê‚Å‚¢‚¢B
        // ”ò‚Ñ‰z‚¦‚é‚æ‚¤‚È‚çA‹t‚É”ò‚ÔB
        int sig = gy < 0 ? -1 : 1;
        if( y != gy ){
            if( sig > 0 ){
                if( y < y + turn + 1 ){
                    // ”ò‚Ñ‰z‚¦‚¿‚á‚¤
                    sig = -sig;
                }
            }else{
                if( y > y - turn - 1 ){
                    sig = -sig;
                }
            }
            while(y != gy){
                if( sig > 0 ){
                    data[ turn ] = 'N';
                }else{
                    data[ turn ] = 'S';
                }
                y += ++turn * sig;
                sig = -sig;
            }
        }
        data[ turn ] = 0;
        printf("Case #%d: %s\n",round+1,data);
   }
   return 0;
}