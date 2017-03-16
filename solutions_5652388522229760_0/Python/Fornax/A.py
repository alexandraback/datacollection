#!/usr/bin/python3

from codejam import CodeJam

def sheep(f):
    last = n = int(f.readline())
    if n == 0:
        return 'INSOMNIA'
    digs = set(str(n))
    while len(digs) < 10:
        last += n
        digs |= set(str(last))
    return last



cj = CodeJam(2016, 'qual', 'A', sheep)

# After importing cj into an interactive terminal, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
