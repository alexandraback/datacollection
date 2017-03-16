import sys

inp=sys.argv[1]
out="%s.out" % inp.split(".")[0]

QUAT = { #{{{
    ('1', '1'): '1',
    ('1', 'i'): 'i',
    ('1', 'j'): 'j',
    ('1', 'k'): 'k',
    ('i', '1'): 'i',
    ('i', 'i'): '-1',
    ('i', 'j'): 'k',
    ('i', 'k'): '-j',
    ('j', '1'): 'j',
    ('j', 'i'): '-k',
    ('j', 'j'): '-1',
    ('j', 'k'): 'i',
    ('k', '1'): 'k',
    ('k', 'i'): 'j',
    ('k', 'j'): '-i',
    ('k', 'k'): '-1',
}
#}}}
YES = "YES"
NO = "NO"

def expand(a): return (-1, a[1]) if ('-' in a) else (1, a)

def pack(sgn, val):
    if sgn == 1: return val
    if sgn == -1: return val[1] if ('-' in val) else '-'+val

def quat(a,b):
    sgna, absa = expand(a)
    sgnb, absb = expand(b)
    return pack(sgna*sgnb, QUAT[(absa,absb)])

def reduce(chars):
    res = '1'
    for c in chars:
        res = quat(res,c)
    return res

def find(letter, chars, start):
    x = '1'
    for i in range(start, len(chars)):
        x = quat(x,chars[i])
        if x == letter: return True, i
    return False, None

def solve_small(chars):
    found, posi = find('i', chars, 0)
    if not found: return NO
    found, posj = find('j', chars, posi+1)
    if not found: return NO
    found, posk = find('k', chars, posj+1)
    if not found: return NO
    if reduce(chars[posk+1:]) == '1': return YES
    return NO

def solve(chars, repeat):
    return solve_small(chars * repeat)

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        charcount, repeat = tuple([int(i) for i in f.readline().split(" ")])
        chars = f.readline()[:charcount]
        out.write("Case #%s: %s\n" % (c+1,solve(chars, repeat)))
