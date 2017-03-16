import sys

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

T = int(f.readline())
for t in xrange(T):
    s = f.readline().strip()

    words = [s[0]]
    for c in s[1:]:
        new_words = []
        for word in words:
            new_words.append( c + word )
            new_words.append( word + c )
        words = new_words

    print sorted(words)[-1]

    outf.write("Case #{0}: {1}\n".format(t+1, sorted(words)[-1]))


f.close()
outf.close()
