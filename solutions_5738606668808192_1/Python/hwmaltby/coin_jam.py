#Henry Maltby
#Code Jam 2016

f = open('C-small.out', 'w')
g = open('C-large.out', 'w')

def mknum(l, ones):
    """
    Returns a jamcoin of length l and ones at spots indicated.
    """
    s = ""
    for i in range(1, l+1):
        if i in ones:
            s = "1" + s
        else:
            s = "0" + s
    return s

def small():
    """
    Creates numbers divisible by b+1, where b is the base.
    We are given N=16 and J=50.
    """
    lst = []
    for i1 in range(2, 16, 2):
        for j1 in range(3, 16, 2):
            for i2 in range(i1+2, 16, 2):
                for j2 in range(j1+2, 16, 2):
                    lst.append(mknum(16, {1, i1, i2, j1, j2, 16}))
    divs = [str(b+1) for b in range(2, 11)]
    f.write("Case #1:\n")
    f.write("\n".join([" ".join([s] + divs) for s in lst[:50]]))

def large():
    """
    Creates numbers divisible by b^6+b^5+b^4+b^3+b^2+b+1, where b is the base.
    We are given N=32 and J=500.
    """
    lst = []
    for i1 in range(2, 32, 7):
        for i2 in range(3, 32, 7):
            for i3 in range(5, 32, 7):
                for i4 in range(6, 32, 7):
                    for i5 in range(7, 32, 7):
                        lst.append(mknum(32, {1, i1, i2, i3, i4, i5, 32}))
    divs = [str(b*b*b*b*b*b + b*b*b*b*b + b*b*b*b + b*b*b + b*b + b \
        + 1) for b in range(2, 11)]
    g.write("Case #1:\n")
    g.write("\n".join([" ".join([s] + divs) for s in lst[:500]]))

small()
large()