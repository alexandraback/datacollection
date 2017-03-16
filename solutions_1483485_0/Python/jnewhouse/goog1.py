L1= ['a',	'b',	'c',	'd',	'e',	'f',	'g',	'h',	'i',	'j',	'k',	'l',	'm',	'n',	'o',	'p',	'q',	'r',	's',	't',	'u',	'v',	'w',	'x',	'y',	'z']
L2=['y',	'n',	'f',	'i',	'c',	'w',	'l',	'b',	'k',	'u',	'o',	'm',	'x',	's',	'e',	'v',	'z',	'p',	'd',	'r',	'j',	'g',	't',	'h',	'a',	'q']
D = {}
for t in range(26):
    D[L2[t]] = L1[t]
T = int(raw_input())
for t in range(T):
    print "Case #"+str(t+1)+":",
    words = raw_input().split()
    s="".join([ " "+"".join([D[x] for x in word])for word in words])
    print s[1:]
