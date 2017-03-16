def check_prime(x):
    for i in xrange(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return i
    return True


def check(x):
    lst = []
    for i in xrange(2, 11):
        lst.append(check_prime(int(x, i)))
        if lst[-1] == True:
            return False

    return lst


N = 16
J = 50
print 'Case #1:'
cnt = 0

for i in xrange(1 + (1 << (N-1)), 1 << N, 2):
    lst = check(format(i, 'b'))
    if lst != False:
        print format(i, 'b'),
        print ' ' .join(map(str, lst))
        cnt += 1
        if cnt == J:
            break

        
    

