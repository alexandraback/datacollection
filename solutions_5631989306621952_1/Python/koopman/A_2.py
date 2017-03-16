import sys

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

T = int(f.readline())
for t in xrange(T):
    s = f.readline().strip()

    word = s[0]
    for c in s[1:]:
        if ord(c) >= ord(word[0]):
            word = c + word
        else:
            word = word + c

        print word

    outf.write("Case #{0}: {1}\n".format(t+1, word))


f.close()
outf.close()
