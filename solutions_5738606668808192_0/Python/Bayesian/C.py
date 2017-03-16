import math

def find_divisor(n):
    if n % 2 == 0:
        return 2
    elif n % 3 == 0:
        return 3
    elif n % 5 == 0:
        return 5
    else:
        for k in range(6, math.ceil(math.sqrt(n)), 6):
            if n % (k + 1) == 0:
                return k + 1
            elif n % (k + 5) == 0:
                return k + 5
    return 0

def jamcoin(b):
    N = len(b)
    divs = []
    bints = []
    for base in range(2, 11):
        bint = sum([int(b[N - i - 1])*base**i for i in range(N)])
        bints.append(bint)
        d = find_divisor(bint)
        if d != 0:
            divs.append(d)
        else:
            break
    if len(divs) == 9:
        return b + " " + " ".join([str(x) for x in divs])
    else:
        return None

def solve(fout, N, J):
    print("Case #1:")
    fout.write("Case #1:\n")
    K = 2**N
    j_count = 0
    for c in range(K//2 + 1, K, 2):
        b = bin(c)[2:]
        j = jamcoin(b)
        if j:
            print(j)
            fout.write(j + "\n")
            j_count += 1
            if j_count >= J:
                break
            
##file_out = "C-test.out"
##N, J = 6, 3

file_out = "C-small.out"
N, J = 16, 50

##file_out = "C-large.out"
##N, J = 32, 500

with open(file_out, "w") as fout:
    solve(fout, N, J)
