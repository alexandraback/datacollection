import sys, os, math

def main(N, J):
    num = ['1'] + ['0'] * (N - 2) + ['1']
    factors = find_primes(1000000)

    res = []
    while True:
        rs = ["".join(num)]
        #print(rs, len(res))
        for base in range(2, 11):
            divisor = 1
            m = int(rs[0], base)
            for factor in factors:
                if factor < m and m % factor == 0:
                    divisor = factor
                    break

            if divisor > 1:
                rs.append(divisor)
            else:
                break

        if len(rs) == 10:
            res.append(rs)
            #print(rs)
            if len(res) == J:
                break

        # move to next
        plus = 1
        for i in reversed(range(N-1)):
            if plus == 1:
                if num[i] == '1':
                    num[i] = '0'
                else:
                    num[i] = '1'
                    plus = 0
            else:
                break

        if plus == 1:
            raise Exception("Not enough numbers")

    return res

def find_primes(n):
    primes = [2]
    is_prime = [True] * (n//2 + 1)
    for i in range(3, n + 1, 2):
        if is_prime[i//2]:
            primes.append(i)
            m = i * 3
            while m <= n:
                is_prime[m // 2] = False
                m += 2 * i
    return primes

if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        N, J = [int(z) for z in in_file.readline().rstrip().split(' ')]
        res = main(N, J)
        print("Case #{}:".format(case_idx + 1))
        for row in res:
            print(" ".join([str(i) for i in row]))

