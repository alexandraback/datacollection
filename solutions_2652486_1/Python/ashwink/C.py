from random import randint
import sys

def factorize(n):
    ret = []
    while n > 1:
        if n % 8 == 0:
            ret.extend([2, 2, 2])
            n = n / 8
        if n % 7 == 0:
            ret.extend([7])
            n = n / 7
        if n % 6 == 0:
            ret.extend([2, 3])
            n = n / 6
        if n % 5 == 0:
            ret.extend([5])
            n = n / 5
        if n % 4 == 0:
            ret.extend([2, 2])
            n = n / 4 
        if n % 3 == 0:
            ret.extend([3])
            n = n / 3
        if n % 2 == 0:
            ret.extend([2])
            n = n / 2 
    return ret

f = open(sys.argv[1], 'r')
T = int(f.readline())
assert T == 1
print "Case #1:"
(R, N, M, K) = [int(x) for x in f.readline().split()]
for case in range(0, R):
    products = [int(x) for x in f.readline().split()]
    
    products = [factorize(x) for x in products]

    for product in products:
        if len(product) > N:
            while len(product) > N:
                if len(product) > N + 1:
                    num_2 = product.count(2)
                    num_3 = product.count(3)
                    if num_2 >= 3:
                        product.remove(2)
                        product.remove(2)
                        product.remove(2)
                        product.append(8)
                    else:
                        product.remove(2)
                        product.remove(2)
                        product.remove(3)
                        product.remove(3)
                        product.append(6)
                        product.append(6)
                elif len(product) > N:
                    product.remove(2)
                    product.remove(2)
                    product.append(4)
            for digit in product:
                sys.stdout.write("%d" % digit)
            print
            break
    else:
        # make a guess
        count = 0
        for product in products:
            for digit in product:
                sys.stdout.write("%d" % digit)
                count += 1
                if count == N:
                    break
            if count == N:
                break
        while count < N:
            sys.stdout.write("%d" % randint(1, 5))
            count += 1
        print

    sys.stdout.flush()
