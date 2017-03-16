#include <iostream>
#include <cstdio>
/*
Problem

I have a really long password, and sometimes I make a mistake when I type it. Right now I've typed part of my password, but I might have made some mistakes. In particular, I might have pressed the wrong key while typing one or more of the previous characters. Given how likely I was to get each character right, what should I do?

I have three options:

    Finish typing the password, then press "enter". I know I'll type the rest of the characters perfectly. If it turns out that one of the earlier characters was wrong, I'll have to retype the whole thing and hit "enter" again -- but I know I'll get it right the second time.
    Hit "backspace" some number of times, deleting the last character(s) I typed, and then complete the password and press "enter" as in option 1. If one of the characters I didn't delete was wrong, I'll have to retype the whole thing and press "enter", knowing I'll get it right the second time.
    Give up by pressing "enter", retyping the password from the start, and pressing "enter" again. I know I'll get it right this time.

I want to minimize the expected number of keystrokes needed. Each character in the password costs 1 keystroke; each "backspace" costs 1 keystroke; pressing "enter" to complete an attempt or to give up costs 1 keystroke.

Note: The "expected" number of keystrokes is the average number of keystrokes that would be needed if the same situation occurred a very large number of times. See the example below.
Example

Suppose my password is "guest" and I have already typed the first two characters, but I had a 40% chance of making a mistake when typing each of them. Then there are four cases:

    I typed "gu" without error. This occurs with probability 0.6 * 0.6 = 0.36.
    I typed the 'g' correctly but I made a mistake typing the 'u'. Then I have two letters typed still, but the second one is wrong: "gX". (Here, the 'X' character represents a mistyped letter.) This occurs with probability 0.6 * 0.4 = 0.24.
    I typed the 'u' correctly but I made a mistake typing the 'g': "Xu". This occurs with probability 0.4 * 0.6 = 0.24.
    I made a mistake typing both letters, so I have two incorrect letters: "XX". This occurs with probability 0.4 * 0.4 = 0.16.

I don't know how many mistakes I actually made, but for any strategy, I can calculate the expected number of keys required to use it. This is shown in the table below:

	"gu"    	"gX"    	"Xu"    	"XX"    	Expected
Probability	0.36	0.24	0.24	0.16	-
Keystrokes if I keep typing	4	10	10	10	7.84
Keystrokes if I press backspace once	6	6	12	12 	8.4
Keystrokes if I press backspace twice  	8	8	8	8	8
Keystrokes if I press enter right away	7	7	7	7	7

If I keep typing, then there is an 0.36 probability that I will need 4 keystrokes, and an 0.64 probability that I will need 10 keystrokes. If I repeated the trial many times, then I would use 4 keystrokes 36% of the time, and 10 keystrokes the remaining 64% of the time, so the average number of keystrokes needed would be 0.36 * 4 + 0.64 * 10 = 7.84. In this case however, it is better to just press enter right away, which requires 7 keystrokes.
*/
using namespace std;

double z[100003],f[100003],g[100003];
int main(){
int n,ii;scanf("%d",&n);for(ii=1;ii<=n;ii++){int a,b,i;double a1,a2,ans=99999999,a3;scanf("\n%d %d",&a,&b);f[0]=1;
z[0]=0;for(i=a;i>=1;i--){scanf("%lf",&z[i]);f[0]*=z[i];}g[0]=f[0];for(i=1;i<=a;i++){f[i]=((f[i-1]/(1-z[i-1]))*(1-z[i]))/z[i];
g[i]=g[i-1]+f[i];}a1=f[0]*(b-a+1)+(1-f[0])*(2*b-a+2);if(a1<ans){ans=a1;}a2=b+2;if(a2<ans){ans=a2;}for(i=1;i<=a;i++){a3=(
b-a+2*i+1)*(f[0]+g[i]-g[0])+(b-a+2*i+1+b+1)*(1-f[0]-g[i]+g[0]);if(a3<ans){ans=a3;}}printf("Case #%d: %.6lf\n",ii,ans);}return 0;
}
