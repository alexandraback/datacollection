s = ["ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"]
e = ["our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"]

mapping = ['z' for i in xrange(26)]

mapping[0] = 'y'
mapping[25] = 'q'
mapping[ord('o')-ord('a')] = 'e'
#mapping[24] = 'a'
#mapping[4] = 'o'
#mapping[ord('q')-ord('a')] = 'z'

for i in xrange(3):
    for j in xrange(len(s[i])):
        if 'a' <= s[i][j] and s[i][j] <= 'z':
            mapping[ord(s[i][j])-ord('a')] = e[i][j]

#print sorted(mapping)

N = int(raw_input())
for i in xrange(N):
    k = raw_input().strip()
    r = ""

    for j in xrange(len(k)):
        if 'a' <= k[j] and k[j] <= 'z':
            r += mapping[ord(k[j])-ord('a')]
        else:
            r += k[j]
    print "Case #%d: %s" % (i+1, r)
