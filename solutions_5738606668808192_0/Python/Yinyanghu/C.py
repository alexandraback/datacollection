import math

def divisor(X):
    if X % 2 == 0:
        return 2
    for k in range(3, int(math.sqrt(X)) + 1, 2):
        if X % k == 0:
            return k
    return -1

def solve(N, J):
    lower_str = '1' + '0' * (N - 2)
    upper_str = '1' + '1' * (N - 2)
    lower = int(lower_str, base = 2)
    upper = int(upper_str, base = 2)
    count = 0
    for K in range(lower, upper + 1):
        K_str = bin(K)[2:] + '1'
        found = True
        divisor_lst = []
        for b in range(2, 11):
            X = int(K_str, base = b)
            D = divisor(X)
            if D == -1:
                found = False
                break
            else:
                divisor_lst.append(D)
        if found:
            str_lst = [str(x) for x in divisor_lst]
            print K_str + ' ' + ' '.join(str_lst)
            count += 1
        if count == J:
            break

print "Case #1:"
#solve(6, 3)
solve(16, 50)