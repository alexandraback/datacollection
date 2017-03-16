#!/usr/bin/python3

from codejam import CodeJam

def ordinal(base, digs):
    o = 0
    for dig in digs:
        o *= base
        o += dig
    return o
        

def fractiles(f):
    (origlen, complexity, chances) = (int(_) for _ in f.readline().split())
    necessary = (origlen-1) // complexity + 1
    if chances < necessary:
        return 'IMPOSSIBLE'
    picks = []
    for i in range(necessary-1):
        picks.append(ordinal(origlen, range(i*complexity, (i+1)*complexity)))
    picks.append(ordinal(origlen, range(max(0, origlen-complexity), origlen)))
    return ' '.join(str(_+1) for _ in picks)


cj = CodeJam(fractiles)

# After importing cj into an interactive terminal, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
