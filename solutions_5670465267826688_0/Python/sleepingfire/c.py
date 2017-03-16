import sys

def negtive(a):
    if a == 1 or a == -1:
        return -1 * a
    if len(a) == 2:
        return a[1]
    else:
        return '-'+a

def multiply(a, b):
    if a == 1:
        return b
    if a == -1:
        return negtive(b)
    if b == 1:
        return a
    if b == -1:
        return negtive(a)

    neg = False
    if a[0] == '-' and b[0] == '-':
        neg == False
        a, b = a[1], b[1]
    elif a[0] == '-':
        neg = True
        a = a[1]
    elif b[0] == '-':
        neg = True
        b = b[1]

    if a == b:
        r = -1
    elif a == 'i':
        if b == 'j':
            r = 'k'
        else:
            r = '-j'
    elif a == 'j':
        if b == 'i':
            r = '-k'
        elif b == 'k':
            r = 'i'
    elif a == 'k':
        if b == 'i':
            r = 'j'
        elif b == 'j':
            r = '-i'
    if neg:
        return negtive(r)
    return r

def run(L, X, string):
    length = L * X
    i, r = -1, 1
    while i < length and r != 'i':
        i += 1
        r = multiply(r, string[i % L])
    if r != 'i':
        return False

    k, r = length, 1
    while k > i and r != 'k':
        k -= 1
        r = multiply(string[k % L], r)
    if r != 'k':
        return False
    if k <= i:
        return False

    r = 1
    for j in range(i+1, k):
        r = multiply(r, string[j % L])
    return r == 'j'


#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    N = int(in_file.readline())
    for case_num in range(N):
        L, X = [int(z) for z in in_file.readline().strip().split()]
        string = in_file.readline().strip()
        result = run(L, X, string)
        result_out = 'YES' if result else 'NO'
        print "Case #{}: {}".format(case_num+1, result_out)

    in_file.close()
