d = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', 'q':'z'}
print sorted(d.values())

f = open('in.txt')
of = open('out.txt', 'w')
lines = f.readlines()[1:]
for i in xrange(len(lines)):
    print lines[i]
    o = 'Case #' + str(i+1) + ': '
    for c in lines[i].strip():
        o += d[c]
    of.write(o + '\n')
print 'done'
of.close()
