def count(x, base):
    ans = 0
    mul = 1
    for alpha in x[::-1]:
        ans += mul * (alpha == '1')
        mul *= base
    return ans

def prime(x):
    cur = 2
    while cur * cur <= x:
        if x % cur == 0:
            return cur
        cur += 1
    return None

def solve(N, J, g):
    number = 0
    for i in range(2**(N - 1) + 1, 2**N, 2):
        print('number is %d from %d' % (number, J))
        x = bin(i)[2:]
        print(x)
        flag = True
        ans = [x]

        for i in range(2, 11):
            cur = count(x, i)
            divisor = prime(cur)
            if divisor is None:
                flag = False
                break
            ans.append(str(divisor))
        print()
        print(flag)
        if flag:
            g.write(' '.join(ans) + '\n')
            number += 1

        if number == J:
            break

test_number = 0
with open('c.txt', 'r') as f, open('c.out', 'w') as g:
    for line in f:
        if test_number == 0:
            test_number += 1
            continue
        g.write('Case #' + str(test_number) + ':' + '\n')
        N, J = map(int, line.split())
        solve(N, J, g)
