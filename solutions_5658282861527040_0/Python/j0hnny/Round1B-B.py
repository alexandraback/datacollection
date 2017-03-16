__author__ = 'j0hnny'


if __name__ == '__main__':
    results = []

    with open('B-small-attempt0.in', 'r') as input:
        cases = int(input.readline())
        for case in range(cases):
            (A, B, K) = input.readline().split()
            A = int(A)
            B = int(B)
            K = int(K)

            res = 0
            for a in range(A):
                for b in range(B):
                    if a & b < K:
                        res += 1

            results.append(res)

    with open('output', 'w') as output:
        for case in range(cases):
            res = results[case]
            s = 'Case #%d: %d\n' % (case+1, res)
            print s
            output.write(s)