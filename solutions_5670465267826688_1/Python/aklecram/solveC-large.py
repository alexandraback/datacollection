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
ENOUGH = 20

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

def reduce_lot(char, repeat):
    if repeat == 0: return '1'
    pw = 1
    res = char
    while True:
        if pw * 2 > repeat:
            return quat(res, reduce_lot(char, repeat-pw))
        pw *= 2
        res = quat(res, res)

def find(letter, chars, start):
    x = '1'
    for i in range(start, len(chars)):
        x = quat(x,chars[i])
        if x == letter: return True, i
    return False, None

def find_ijk(chars):
    found, posi = find('i', chars, 0)
    if not found: return False, None
    found, posj = find('j', chars, posi+1)
    if not found: return False, None
    found, posk = find('k', chars, posj+1)
    if not found: return False, None
    return True, reduce(chars[posk+1:])

def solve(chars, repeat):
    found, remainder = find_ijk(chars * min(repeat, ENOUGH))
    if not found: return NO
    if repeat <= ENOUGH: return YES if remainder == '1' else NO
    if quat(remainder, reduce_lot(reduce(chars), repeat - ENOUGH)) == '1':
        return YES
    return NO

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        charcount, repeat = tuple([int(i) for i in f.readline().split(" ")])
        chars = f.readline()[:charcount]
        out.write("Case #%s: %s\n" % (c+1,solve(chars, repeat)))
