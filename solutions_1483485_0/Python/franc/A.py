import sys
D={'a':'y',
   'b':'h',
   'c':'e',
   'd':'s',
   'e':'o',
   'f':'c',
   'g':'v',
   'h':'x',
   'i':'d',
   'j':'u',
   'k':'i',
   'l':'g',
   'm':'l',
   'n':'b',
   'o':'k',
   'p':'r',
   'q':'z',
   'r':'t',
   's':'n',
   't':'w',
   'u':'j',
   'v':'p',
   'w':'f',
   'x':'m',
   'y':'a',
   'z':'q'}

N=int(raw_input())
for i in range(N):
    line = raw_input()
    sys.stdout.write('Case #'+str(i+1)+': ')
    for j in range(len(line)):
        try:
            sys.stdout.write(D[line[j]])
        except:
            sys.stdout.write(line[j])
    print
