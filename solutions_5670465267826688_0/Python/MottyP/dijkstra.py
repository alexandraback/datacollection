import sys

def neg(quatr):
    return ('-'+quatr).replace('--','')

multigrid = { '1': {'i': 'i', 'j': 'j', 'k': 'k'},
              'i': {'i': '-1', 'j': 'k', 'k': '-j'},
              'j': {'i': '-k', 'j': '-1', 'k': 'i'},
              'k': {'i': 'j', 'j': '-i', 'k': '-1'}}

multigrid.update( {neg(op1): {op2: neg(result) for op2, result in op1row.items()}
                                               for op1, op1row in multigrid.items()} )

def isIJK(text, repeat):
    if repeat >= 12:
        repeat = repeat % 4 + 8
    # If the string repeats 12 times or more, one of the three substrings contains at least 4 
    # repetitions of it, which evaluate to 1 and thus can be reduced.

    remaining = 'ijk$'
    # Thanks to the associativity, a greedy algorithm (accept the first substring that evaluates to
    # what we need next) will do.
    # After finding the three substrings, we can accept the rest only if it evaluates to 1 (and consider
    # it a part of the last substring).

    current = '1'
    for i in range(repeat):
        for letter in text:
            current = multigrid[current][letter]
            if current==remaining[0]:
                remaining = remaining[1:]
                current = '1'
    return remaining=='$' and current=='1'

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for i in range(ncases):
        line = sys.stdin.readline()
        length, repeat = [int(part) for part in line.split()]
        text = sys.stdin.readline().strip()
        assert len(text) == length
        print "Case #%d: %s" % (i+1, "YES" if isIJK(text, repeat) else "NO")

