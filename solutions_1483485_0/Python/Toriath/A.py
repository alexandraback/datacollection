##g_a = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'
##g_b = 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
##g_c = 'de kr kd eoya kw aej tysr re ujdr lkgc jv'
##
##s_a = 'our language is impossible to understand'
##s_b = 'there are twenty six factorial possibilities'
##s_c = 'so it is okay if you want to just give up'
##
##d = {}
##d['y'] = 'a'
##d['e'] = 'o'
##d['q'] = 'z'
##
##l = [(g_a, s_a),
##     (g_b, s_b),
##     (g_c, s_c)]
##
##for x in l:
##    for a, b in zip(*x):
##        d[a] = b
##

d = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o',
     'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x',
     'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k',
     'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't',
     'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a',
     'x': 'm', 'z': 'q'}

T = input()

for c in range(1,T+1):
    i = raw_input().strip()
    string = ''.join(map(lambda x: d[x], i))
    print 'Case #%d:' % c, string
