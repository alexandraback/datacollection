def parse_ints(f):
    return map(int, f.readline().split())

def parse_int(f):
    return int(f.readline())

def main():
    fi = open('C.in', 'r')
    fo = open('C.out', 'w')
    T = parse_int(fi)
    for i in range(T):
        A, B = parse_ints(fi)
        result = recycled_pairs(A, B)
        fo.write('Case #{0}: {1}\n'.format(i+1, result))

def recycled_pairs(A, B):
    r = 0
    for i in range(A, B+1):
        s = str(i)
        v = set()
        for d in range(len(s)):
            s = s[1:] + s[0]
            j = int(s)
            if j in range(A, i) and j not in v:
                r += 1
                v.add(j)
    return r
