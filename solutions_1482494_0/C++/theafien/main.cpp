#include <cstdio>
#include <iostream>
/*Problem

Ryan is playing Kingdom Rush, a single-player tower defense game developed by Ironhide Game Studio. In Kingdom Rush, players earn stars by completing levels, in a way described below. Having more stars makes the player more powerful; so while Ryan might not be able to complete level 2 right away, he might be able to complete it after earning stars from level 1.

The real game Kingdom Rush doesn't work in quite the same way as this problem. It isn't important to have played the game in order to solve the problem.

In this problem's version of Kingdom Rush, when a player completes a level, he or she is given a 1-star rating or a 2-star rating. That rating might allow the player to earn stars as follows:

    If the player has never completed the level before and completes it with a 1-star rating, that player earns 1 star.
    If the player has never completed the level before and completes it with a 2-star rating, that player earns 2 stars.
    If the player has only completed the level before with a 1-star rating and completes it this time with a 2-star rating, the player earns 1 more star.

Otherwise there is no way for a player to earn stars.

Ryan might not be able to complete every level right away. For each level, before he can complete it with a 1-star rating, he needs to have earned a certain number of stars; and he will need a larger or equal number of stars to complete that level with a 2-star rating.

For example, suppose there are two levels:

    Level 1 requires 0 stars to complete with a 1-star rating, and 1 star to complete with a 2-star rating.
    Level 2 requires 0 stars to complete with a 1-star rating, and 2 stars to complete with a 2-star rating.

Here's a possible series of events for Ryan:

    Ryan starts with 0 stars. He can choose to complete either level 1 or level 2 with a 1-star rating. He chooses to complete level 1 with a 1-star rating. Now he has 1 star.
    Now Ryan can either complete level 2 with a 1-star rating, or level 1 with a 2-star rating. He chooses to complete level 1 with a 2-star rating. Now he has 2 stars.
    Now Ryan can complete level 2 with a 2-star rating. He does that, and now he has 4 stars.
    Now he is done, having completed all levels with 2-star ratings and earned 4 stars (2 per level). He has completed levels 3 times: level 1 twice, and level 2 once.

Ryan is great at tower defense games, but he needs some help to beat Kingdom Rush as quickly as possible. Your job is to figure out how many times he needs to complete levels in order to earn a 2-star rating on every level.
*/
using namespace std;
int main (){
bool b[1000][2],YN;int T,N,level[1000][2],stars,t,max,temp,i,j;scanf("%d",&T);for (i=1;i<=T;i++){scanf("%d",&N);
for (j=0;j<N;j++){scanf("%d %d",&level[j][0],&level[j][1]);b[j][0]=0;b[j][1]=0;}stars=0;t=0;while (stars!=2*N){
YN=0;for (j=0;j<N;j++){if (b[j][1]==0 && stars>=level[j][1]){if (b[j][0]==1){stars++;} else {stars+=2;}b[j][0]=1;
b[j][1]=1;YN=1;t++;}}if (YN==0){max=-1;for (j=0;j<N;j++){if (b[j][0]==0 && stars>=level[j][0]){if (level[j][1]>max){
max=level[j][1];temp=j;}YN=1;}}if (YN==1){stars++;t++;b[temp][0]=1;}}if (YN==0){t=-1;stars=2*N;}}if (t==-1){
printf("Case #%d: Too Bad\n",i);} else {
printf("Case #%d: %d\n",i,t);}}return 0;
}
