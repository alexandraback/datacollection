# https://code.google.com/codejam/contest/1460488/dashboard#s=p0
import sys

def readline():
    return sys.stdin.readline().rstrip()

mapping = {'a':'y', 'b':'h', 'c':'e', 'd':'s', 'e':'o', 'f':'c', 'g':'v', 'h':'x', 'i':'d', 'j':'u', 'k':'i', 'l':'g', 'm':'l', 'n':'b', 'o':'k', 'p':'r', 'q':'z', 'r':'t', 's':'n', 't':'w', 'u':'j', 'v':'p', 'w':'f', 'x':'m', 'y':'a', 'z':'q', ' ':' '}

t = int(readline())
for x in range(t):
    line = readline()
    print 'Case #{}: {}'. format(x+1, ''.join([mapping[l] for l in line]))

