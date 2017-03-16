import sys

def is_power_two(n):
    count = sum([int(c) for c in bin(n)[2:]])
    if count == 1:
        return True
    else:
        return False
def gcd(a, b):
    r = a % b
    if r == 0:
        return b
    else:
        return gcd(b,r)

if __name__ == "__main__":
    filename = str(sys.argv[1])
    with open(filename, "r") as f:
        T = int(f.readline())
        output = open(filename.split('.')[0]+'.out', 'w')
        for t in range(1,T+1):
            output.write("Case #%d: " % t)
            print("Case #%d: " % t)
            P, Q = [int(c) for c in f.readline().split('/')]
            divisor = gcd(P,Q)
            if divisor != 1:
                P = P / divisor
                Q = Q / divisor
            if not is_power_two(Q):
                output.write('impossible\n')
                print('impossible')
            else:
                if P == 1:
                    n = len(bin(Q)[2:]) - 1
                else:
                    n = 1
                    p = pow(2, len(bin(P)[2:])-1)
                    N = (Q/2)/p
                    print('largest power of 2 subtracted from P is %d' % N)
                    n += len(bin(N)[2:]) - 1
                output.write(str(n)+'\n')
                print(n)