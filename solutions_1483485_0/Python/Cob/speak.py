import sys
f = sys.stdin

mp = {' ' : ' ',
'a' : 'y',
'c' : 'e',
'b' : 'h',
'e' : 'o',
'd' : 's',
'g' : 'v',
'f' : 'c',
'i' : 'd',
'h' : 'x',
'k' : 'i',
'j' : 'u',
'm' : 'l',
'l' : 'g',
'o' : 'k',
'n' : 'b',
'q' : 'z',
'p' : 'r',
's' : 'n',
'r' : 't',
'u' : 'j',
't' : 'w',
'w' : 'f',
'v' : 'p',
'y' : 'a',
'x' : 'm',
'z' : 'q',
'\n': '\n'}

cases = int(f.readline())
for caseno in range(1, cases + 1):
    ln = f.readline()
    lnout = ''
    for ch in ln:
        lnout += mp[ch]
    print("Case #{0}: {1}".format(caseno, lnout.strip()))
    
        