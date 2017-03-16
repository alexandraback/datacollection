# mapping the two languages
googlerese = ''.join('ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv'.split(' '))

english = ''.join('our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up'.split(' '))

trans = {'y':'a', 'e':'o', 'q':'z'}
def find_missing(googlerese, english):
    for i in range(97, 97+26):
        if chr(i) not in english:
            e_missing = chr(i)
        if chr(i) not in googlerese:
            g_missing = chr(i)
    return g_missing, e_missing

for i in range(len(googlerese)):
    if googlerese[i] not in trans:
        trans[googlerese[i]] = english[i]
g_missing, e_missing = find_missing(trans.keys(), trans.values())
trans[g_missing] = e_missing

#the actual program
input_file = open('/Users/arisha/Downloads/A-small-attempt0.in')
T = int(input_file.readline())

def translate(G, trans):
    E = []
    for i in range(len(G)):
        if G[i] == " ":
            E.append(' ')
        else:
            E.append(trans[G[i]])
    return ''.join(E)

for i in range(T):
    G = list(input_file.readline().strip())
    print "Case #%d: %s" %(i+1, translate(G, trans))
